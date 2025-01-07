/*
- Logan Meyers
- 11/07/2024
- Lab Section 12
- TA: JAMESSS

- Description: Battle Ship game! Player vs computer

- NOTE: Printing of the player data into the logfile has been fixed,
        as of 11/13.
- NOTE: also, pretty windows aren't on every frame or prompt, so that's
        a future feature to implement.
- NOTE: The player and computer can still shoot at previous spots, that has
        yet to be fixed.

- UPDATE 11/13 #1: Fixed game breaking logic due to some debugging I didn't undo
- UPDATE 11/13 #2: Fixed logging, updated some comments, cleaned up a little
*/

#include "pa6.h"
#include "display.h"

int main() {
    // seed random once
    seed_rand();

    // clear file
    log_clearfile();

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

    // gameloop variable initiations
    int who_won = determine_winner(&p1, &p2);
    int round_count = 0;

    // gameloop
    while (!who_won) {
        round_count++;

        /* ----- player's turn ----- */
        clr_screen();
        printf("Player's turn!\n\n");

        // print both boards
        print_board(p1.board, "Player", 0);
        print_board(p2.board, "Computer", !PLAYER_CHEAT);

        // ask for where to shoot
        int x = 0, y = 0;
        ask_x_y_shot(&x, &y);

        char shot_result = make_shot(p2.board, x, y);

        // show player shot results, and log data
        clr_screen();
        printf("Updated view:\n\n");
        print_board(p1.board, "Player", 0);
        print_board(p2.board, "Computer", !PLAYER_CHEAT);

        if      (shot_result == '*') printf("You hit a ship!");
        else if (shot_result == 's') printf("You sunk a ship!");
        else printf("You missed :(");

        log_data("Player", shot_result, x, y);
        update_player_stats(&p1, shot_result);

        ask_enter("Please press enter to continue...");

        /* ----- computer's turn ----- */
        clr_screen();

        printf("Computer's turn!\n\n");

        // generate random place to shoot, and make shot
        x = rand_range(MAX_COLUMNS);
        y = rand_range(MAX_ROWS);

        shot_result = make_shot(p1.board, x+1, y+1);

        // print results and log data
        print_board(p1.board, "Player", 0);
        print_board(p2.board, "Computer", !PLAYER_CHEAT);

        if      (shot_result == '*') printf("Computer hit one of your ships!");
        else if (shot_result == 's') printf("Computer sunk one of your ships!");
        else                         printf("Computer missed.");

        log_data("Computer", shot_result, x, y);
        update_player_stats(&p2, shot_result);

        ask_enter("Please press enter to continue...");

        // at the end of the loop, determine new winner status (if any)
        who_won = determine_winner(&p1, &p2);

        // end game early if intended
        #ifdef DEBUG_MAX_ROUNDS
            if (round_count > DEBUG_MAX_ROUNDS) break;
        #endif
    }

    // display winner/loser message
    // when debug_max_rounds is set, this message may not display what you
    //   would expect. this is intended- error 404 "no effort found" lol
    clr_screen();
    if (who_won == 3) {
        printf("Congrats! You both lose! That shouldn't happen!\n");
    } else if (who_won == 2) {
        printf("Drats! The computer won and you lose.\n");
        log_winner("Computer", count_all_symbols_left(p2.board));
    } else if (who_won == 1) {
        printf("Congrats! You won against the computer!\n");
        log_winner("Player", count_all_symbols_left(p1.board));
    } else {
        printf("Wow! You broke the game! Kudos to you.\n");
    }

    // log struct data for each player
    log_player_data(&p1, "Player");
    log_player_data(&p2, "Computer");

    return 0;
}
