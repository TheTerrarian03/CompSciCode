/*
- Logan Meyers
- 11/07/2024
- Lab Section 12
- TA: JAMESSS

- Description: Battle Ship game! Player vs computer
*/

#include "pa6.h"

/* ----- Display ----- */
void print_board(Cell *board, char *name) {
    printf("   %*s%*s\n", 10 + strlen(name) / 2, name, 10 - strlen(name) / 2, "");
    printf("   1 2 3 4 5 6 7 8 9 10\n");
    for (int i = 0; i < MAX_ROWS; i++) {
        printf("%2d ", i+1);
        for (int j = 0; j < MAX_COLUMNS; j++) {
            printf("%c ", board->status_char);
        }
        printf("\n");
    }
}

/* ----- Board Manipulation ----- */
void init_board(Player_data *p_data) {
    for (int row=0; row<MAX_ROWS; row++) {
        for (int col=0; col<MAX_COLUMNS; col++) {
            p_data->board[row][col].row = row;
            p_data->board[row][col].column = col;
            p_data->board[row][col].status_char = '-';
        }
    }
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

/* ----- Input from Player ----- */

/* ----- Output to Files ----- */