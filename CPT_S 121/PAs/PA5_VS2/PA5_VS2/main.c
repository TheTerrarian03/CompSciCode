/*
- Name: Logan Meyers
- ID: 011881121
- Date Finished: 10/25/2024
- Assignment: PA 5
- TA: Awesome James

- Description: Let's play Yahtzee! 2 Player
*/

#include "pa5.h"

void test();

int main() {
    // seed random
    seed_rand();

    // main menu loop
    int program_running = 1, game_running = 0, main_menu_choice = -1;

    while (program_running) {
        // print game rules and ask for choice
        main_menu_choice = get_menu_option();

        switch (main_menu_choice) {
            // exit game
        case 3: program_running = 0;
            break;

            // Hand playing the game off to the play_game() function
        case 2: clear_scr();
            play_game();
            // test();
            break;

            // Print Rules
        case 1: clear_scr();
            print_game_rules();
            break;
        default: printf("Invalid option entered! Try again..\n\n");
        }
    }

    return 0;
}
