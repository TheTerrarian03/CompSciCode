/*
- 
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
                    // play_game();
                    test();
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

void test() {
    printf("Welcome to yahtzee!\n");

    // scores have all 13 point sections, plus upper section sum, upper section bonus, and total score
    int p1_scores[SCORE_ARRAY_LENGTH] = {0}, p2_scores[SCORE_ARRAY_LENGTH] = {0};
    // player dice include empty space at [0]
    int p1_dice[6] = {0}, p2_dice[6] = {0};
    // player holds for their dice, plus empty space at [0]
    int p1_held[6] = {0}, p2_held[6] = {0};

    // Reset scores for safety
    fill_scores(p1_scores, 0);
    fill_scores(p2_scores, 0);

    roll_dice(p1_dice, p1_held);

    printf("First roll:\n");
    print_array(p1_dice, 6);

    p1_held[1] = 1;
    p1_held[5] = 1;

    printf("Second roll:\n");
    roll_dice(p1_dice, p1_held);

    print_array(p1_dice, 6);

    p1_held[1] = 0;
    p1_held[5] = 0;
    p1_held[2] = 1;
    p1_held[3] = 1;
    p1_held[4] = 1;

    roll_dice(p1_dice, p1_held);

    printf("Last roll:\n");
    print_array(p1_dice, 6);
}
