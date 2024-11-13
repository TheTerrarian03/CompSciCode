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
        clr_screen();

        #ifdef DEBUG_MSGS
        printf("Current winner: %d\n", who_won);
        printf("Player ship chars: %d\n", count_all_symbols_left(p1.board));
        printf("Computer ship chars: %d\n", count_all_symbols_left(p2.board));
        #endif

        // player's turn
        printf("Player's turn!\n\n");

        print_board(p1.board, "Player", 0);
        putchar('\n');
        print_board(p2.board, "Computer", !PLAYER_CHEAT);
        putchar('\n');

        int x = 0, y = 0;
        ask_x_y_shot(&x, &y);

        char shot_result = make_shot(p2.board, x, y);

        if      (shot_result == '*') printf("You hit a ship!");
        else if (shot_result == 's') printf("You sunk a ship!");
        else                         printf("You missed :(");

        ask_enter("Please press enter to continue... ");

        // computer's turn
        

        // at the end of the loop, determine new winner status
        who_won = detemine_winner(&p1, &p2);
    }

    clr_screen();
    if      (who_won == 3) printf("Congrats! You both lose! That shouldn't happen!\n");
    else if (who_won == 2) printf("Drats! The computer won and you lose.\n");
    else if (who_won == 1) printf("Congrats! You won against the computer!\n");
    else                   printf("Wow! You broke the game! Kudos to you.\n");

    return 0;
}
