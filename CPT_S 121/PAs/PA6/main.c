/*
- Logan Meyers
- 11/07/2024
- Lab Section 12
- TA: JAMESSS

- Description: Battle Ship game! Player vs computer
*/

#include "pa6.h"
#include "display.h"

int main() {
    // seed random once
    seed_rand();

    // declare game data
    Player_data p1;  // player
    Player_data p2;  // computer

    // init player & computer data (including boards)
    init_player_data(&p1);
    init_player_data(&p2);

    // Ask if the player would like to place ships manually or randomly
    int manual_placement = ask_manual_vs_random_placement();

    // Then place ships for player
    if (manual_placement == 1) {
        // place manually
        manual_ship_placement(p1.board);
    } else {
        // place randomly
        place_ships_randomly(p1.board);
    }

    // place computer board randomly
    place_ships_randomly(p2.board);

    // gameloop
    int who_won = detemine_winner(&p1, &p2);

    while (!who_won) {
        // player's turn
        clr_screen();
        printf("Player's turn!\n\n");

        print_board(p1.board, "Player", 0);
        putchar('\n');
        print_board(p2.board, "Computer", 1);

        int x = 0, y = 0;
        ask_x_y_shot(&x, &y);

        printf("Shooting at: (%d, %d)\n", x, y);

        

        // computer's turn
    }

    //printf("Player Hits: %d\n", p1.hits);

    //for (int i = 0; i < MAX_ROWS; i++) {
    //    for (int j = 0; j < MAX_COLUMNS; j++) {
    //        printf("Row: %d, Column: %d, State: %c\n", p1.board[i][j].row, p1.board[i][j].column, p1.board[i][j].status_char);
    //    }
    //}

    print_board(p1.board, "Player", 0);
    print_board(p2.board, "Computer", 0);

    return 0;
}
