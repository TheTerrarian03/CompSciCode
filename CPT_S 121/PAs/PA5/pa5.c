/*
- 
*/

#include "pa5.h"

// rand functions
void seed_rand() {
    srand((unsigned int) time(NULL));
}
int roll_die() {
    return (rand() % 6) + 1;
}

// input/output functions
void print_game_rules() {
    printf("GAME RULES\n");
}
int get_menu_option(int min, int max) {
    int choice = -1;
    int result;

    while (choice < 1 || choice > 3) {
        printf("Please enter your main menu option:\n");
        printf("  1. Print Game Rules\n");
        printf("  2. Play Game\n");
        printf("  3. Exit\n");
        printf("$ ");

        result = scanf(" %d", &choice);

        if (result != 1 ||
            (result == 1 & (choice < 1 || choice > 3))) {
            while (getchar() != '\n');
            clear_scr();
            printf("Invalid input! Please try again.\n");
            choice = -1;
        }
    }

    return choice;
}
void clear_scr() {
    #ifndef DISABLE_CLEAR_SCR
        system(CLEAR_COMMAND);
    #endif
}
void print_array(int *array, int len) {
    printf("[");
    for (int i=0; i < len; i++) {
        printf("%d", array[i]);
        if (i < len-1) printf(", ");
    }
    printf("]\n");
}

// game handling functions
// main play game function.
int play_game() {
    printf("Welcome to yahtzee!\n");

    // scores have all 13 point sections, plus upper section sum, upper section bonus, and total score
    int p1_scores[SCORE_ARRAY_LENGTH] = {0}, p2_scores[SCORE_ARRAY_LENGTH] = {0};
    // player dice include empty space at [0]
    int p1_dice[7] = {0}, p2_dice[7] = {0};

    // Reset scores for safety
    fill_scores(p1_scores, 0);
    fill_scores(p2_scores, 0);

    // main loop, alternating players
    int current_round = 1;  // range [1, 13]
    int player_turn = 1;  // 1 or 2
    while (player_turn) {

    }

    return 0;
}

// array functions - dice
void fill_dice(int *dice, int value) {
    for (int i = 0; i < 6; i++) {
        dice[i] = value;
    }
}
// held: int array[7] where 0 is not held, 1 is held
// held means don't roll
void roll_dice(int *dice, int *held) {
    for (int i = 1; i < 6; i++) {
        if (held[i] == 0) {
            dice[i] = roll_die();
        }
    }
}

// array functions - scores
void fill_scores(int *score_array, int value) {
    for (int i = 0; i < SCORE_ARRAY_LENGTH; i++) {
        score_array[i] = value;
    }
}
void enter_score(int *score_array, int score_index, int new_score) {
    score_array[score_index] = new_score;
}
int get_score_for_combo(int *dice, int combo_id);
void update_scores(int *score_array);
