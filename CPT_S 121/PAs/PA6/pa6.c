/*
- Logan Meyers
- 11/07/2024
- Lab Section 12
- TA: JAMESSS

- Description: Battle Ship game! Player vs computer
*/

#include "pa6.h"

/* ----- Random ----- */
void seed_rand() {
    srand((unsigned int) time(NULL));
}
int rand_range(int range) {
    return rand() % range;
}

/* ----- Display ----- */
void print_board(Cell board[MAX_ROWS][MAX_COLUMNS], char *name, int ignore_ships) {
    printf("   %*s%*s\n", 10 + strlen(name) / 2, name, 10 - strlen(name) / 2, "");
    printf("   1 2 3 4 5 6 7 8 9 10\n");
    for (int i = 0; i < MAX_ROWS; i++) {
        printf("%2d ", i+1);
        for (int j = 0; j < MAX_COLUMNS; j++) {
            char to_print = board[i][j].status_char;
            if (ignore_ships) {
                if (to_print == 'm' || to_print == '*') printf("%c ", to_print);
                else printf("%c ", WATER_CHAR);
            } else {
                printf("%c ", to_print);
            }
        }
        printf("\n");
    }
}
void manual_ship_placement(Cell board[MAX_ROWS][MAX_COLUMNS]) {
    // parallel arrays for ship char and length
    char ships_chars[5] = {'c', 'b', 'r', 's', 'd'};
    int ship_lens[5] = {5, 4, 3, 3, 2};

    // loop for each ship
    for (int i=0; i<5; i++) {
        print_board(board, "placement", 0);

        int x, y, vertical;

        // while loop for checking ship placement
        int valid = 0;
        while (!valid) {
            printf("You are placing a ship with char: %c\n", ships_chars[i]);
            printf("It's length is: %d\n\n", ship_lens[i]);

            printf("Please enter a left x for your ship:\n$ ");
            int res_x = scanf("%d", &x);
            
            printf("Please enter a top y for your ship:\n$ ");
            int res_y = scanf("%d", &y);

            printf("Please enter whether you want it horizontal (0) or vertical (1):\n$ ");
            int res_v = scanf("%d", &vertical);

            // check for invalid results from scanf
            if (res_x != 1 || res_y != 1 || res_v != 1) {
                x = 0; y = 0; vertical = 0;
                while(getchar() != '\n');
                printf("Ruh roh! One of your entries was invalid. Please make sure you enter in the right type of data.\n");
                continue;
            }

            // check for invalid ranges for x, y, and vertical
            if ((x < 1 || x > 10) || (y < 1 || y > 10) || (vertical < 0 || vertical > 1)) {
                x = 0; y = 0; vertical = 0;
                while(getchar() != '\n');
                printf("Ruh roh! One of your entries was out of bounds. Please make sure you enter in the right range of values for each question.\n");
                continue;
            }

            // check for ship placement validity
            valid = determine_ship_placement_valid(board, x-1, y-1, vertical, ship_lens[i]);

            // message to user based on validity
            if (valid) {
                printf("Success! Placing your ship.\n");
                place_single_ship(board, x-1, y-1, vertical, ship_lens[i], ships_chars[i]);
            } else {
                printf("Ruh roh! Ship placement is not valid. Please try again.\n");
            }
        }
    }
}
void ask_x_y_shot(int *x, int *y) {
    // x
    while (*x==0) {
        printf("Please enter an x pos to shoot at the computer's board:\n$ ");
        int res_x = scanf("%d", x);

        if (res_x != 1) {
            *x = 0;
            while(getchar() != '\n');
            printf("Please enter an integer number!\n\n");
            continue;
        }

        if (*x < 1 || *x > 10) {
            *x = 0;
            printf("Please enter a integer number from 1 to 10 inclusive!\n\n");
            continue;
        }
    }

    // y
    while (*y==0) {
        printf("Please enter an y pos to shoot at the computer's board:\n$ ");
        int res_y = scanf("%d", y);

        if (res_y != 1) {
            *y = 0;
            while(getchar() != '\n');
            printf("Please enter an integer number!\n\n");
            continue;
        }

        if (*y < 1 || *y > 10) {
            *y = 0;
            printf("Please enter a integer number from 1 to 10 inclusive!\n\n");
            continue;
        }
    }
}

/* ----- Board Manipulation ----- */
void init_board(Player_data *p_data) {
    for (int row=0; row<MAX_ROWS; row++) {
        for (int col=0; col<MAX_COLUMNS; col++) {
            p_data->board[row][col].row = row;
            p_data->board[row][col].column = col;
            p_data->board[row][col].status_char = WATER_CHAR;
        }
    }
}
int determine_ship_placement_valid(Cell board[MAX_ROWS][MAX_COLUMNS], int left_x, int top_y, int vertical, int len) {
    int valid_fitment = 1;
    for (int j=0; j<len; j++) {
        int c_x = left_x+(j * !vertical);
        int c_y = top_y+(j * vertical);
        char current = board[c_y][c_x].status_char;
        if (current != WATER_CHAR) valid_fitment = 0;

        #ifdef DEBUG_MSGS
        printf("Checking (%d, %d), got: %c", c_x, c_y, current);
        #endif
    }
    return valid_fitment;
}
void place_single_ship(Cell board[MAX_ROWS][MAX_COLUMNS], int left_x, int top_y, int vertical, int len, char symbol) {
    for (int i=0; i<len; i++) {
        int c_x = left_x+(i * !vertical);
        int c_y = top_y+(i * vertical);
        board[c_y][c_x].status_char = symbol;

        #ifdef DEGUG_MSGS
        printf("Placing a '%c' at (%d, %d)\n", ships_chars[i], c_x, c_y);
        #endif
    }
}
void place_ships_randomly(Cell board[MAX_ROWS][MAX_COLUMNS]) {
    // parallel arrays for ship char and length
    char ships_chars[5] = {'c', 'b', 'r', 's', 'd'};
    int ship_lens[5] = {5, 4, 3, 3, 2};

    // loop for each ship
    for (int i=0; i<5; i++) {
        // loop to determine location (top left),
        // check fitment,
        // and place ship (down or right)
        int success = 0;
        while (!success) {
            // init x and y, and randomly determine horizontal (0)/vertical (1)
            int x, y, vertical = rand_range(2);

            // adjust bounds based on horizontal / vertical
            if (vertical) {
                x = rand_range(10);
                y = rand_range(10-ship_lens[i]);
            } else {
                x = rand_range(10-ship_lens[i]);
                y = rand_range(10);
            }

            #ifdef DEBUG_MSGS
            printf("vert: %d, len: %d, x: %d, y: %d\n", vertical, ship_lens[i], x+1, y+1);
            #endif

            // check fitment
            int valid_fitment = determine_ship_placement_valid(board, x, y, vertical, ship_lens[i]);

            // try again if it doesn't fit
            if (!valid_fitment) {
                #ifdef DEBUG_MSGS
                printf("invalid\n");
                #endif

                continue;
            }

            // otherwise, place ship
            place_single_ship(board, x, y, vertical, ship_lens[i], ships_chars[i]);

            success = 1;

            #ifdef DEBUG_MSGS
            print_board(board, "placement", 0);
            #endif
        }
    }
}
int count_symbols_left(Cell board[MAX_ROWS][MAX_COLUMNS], char symbol) {
    int count = 0;
    for (int i=0; i<MAX_ROWS; i++) {
        for (int j=0; j<MAX_COLUMNS; j++) {
            char current = board[i][j].status_char;
            if (current == symbol) count++;
            // printf("Checked board pos (%d, %d), found '%c', count is: %d\n", j+1, i+1, current, count);
        }
    }
    return count;
}
int count_all_symbols_left(Cell board[MAX_ROWS][MAX_COLUMNS]) {
    char ship_chars[5] = {'c', 'b', 'r', 's', 'd'};
    int total = 0;

    for (int i=0; i<5; i++) {
        total += count_symbols_left(board, ship_chars[i]);
    }

    return total;
}

/* ----- Player Data Manipulation ----- */
void init_player_data(Player_data* p_data) {
    p_data->hits = 0;
    p_data->misses = 0;
    p_data->win_loss_status = 0;
    init_board(p_data);
    update_player_stats(p_data);
}
void update_player_stats(Player_data* p_data) {
    p_data->total_shots = p_data->hits + p_data->misses;

    // if to avoid dividing by zero
    // note: if there are no misses, it will default to hits
    //   which, may become above 1 if hits > 1.
    //   which doesn't make sense; 200% hit-miss ratio?
    if (p_data->misses == 0) p_data->hit_miss_ratio = p_data->hits;
    else p_data->hit_miss_ratio = p_data->hits / p_data->misses;
}

/* ----- Game State Stuff ----- */
int detemine_winner(Player_data *p1_data, Player_data *p2_data) {
    int p1_total_chars = count_all_symbols_left(p1_data->board);
    int p2_total_chars = count_all_symbols_left(p2_data->board);

    if (p1_total_chars == 0) return 2;
    if (p2_total_chars == 0) return 1;
    else return 0;
}

/* ----- Input from Player ----- */


/* ----- Output to Files ----- */