/*
- Name: Logan Meyers
- ID: 011881121
- Date Finished: 10/25/2024
- Assignment: PA 5
- TA: Awesome James

- Description: Let's play Yahtzee! 2 Player
*/

#include "pa5.h"

// rand functions
void seed_rand() {
    srand((unsigned int)time(NULL));
}
int roll_die() {
    return (rand() % 6) + 1;
}

// input/output functions

// this was straight from ChatGPT, I won't lie.
// The Game Rules are NOT my focus. I care more about the game
// actually working like you was it to, not some fancy rule formatting.
void print_game_rules() {
    printf("GAME RULES:\n");
    printf("1. Each player rolls five dice per turn.\n");
    printf("2. A turn consists of three rolls, with the option to keep or reroll any dice.\n");
    printf("3. The goal is to create specific combinations for points, such as:\n");
    printf("   - Three of a kind\n");
    printf("   - Four of a kind\n");
    printf("   - Full House (three of one number, two of another)\n");
    printf("   - Small Straight (four consecutive numbers)\n");
    printf("   - Large Straight (five consecutive numbers)\n");
    printf("   - Yahtzee (five of a kind)\n");
    printf("   - Chance (any combination)\n");
    printf("4. Scoring is based on these combinations, with each having specific points.\n");
    printf("5. The game continues until all scoring categories are filled.\n");
    printf("6. The player with the highest total score wins.\n");
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
void print_score(int score, char* combo) {
    if (score != -1) {
        printf("%s |  %d\n", combo, score);
    }
    else {
        printf("%s |  -- \n", combo);
    }
}
void print_score_w_pot(int* dice, int combo_id, int score, char* combo) {
    if (score != -1) {
        printf("%s |  %d\n", combo, score);
    }
    else {
        int pot_score = get_score_for_combo(dice, combo_id);
        if (pot_score > 0) printf("%s | [%d]\n", combo, pot_score);
        else printf("%s |  -- \n", combo);
    }
}
void print_round_info(int p_turn, int* p_scores, int* p_dice, int round) {
    // round section
    printf("Round  [ %d ]\n", round);

    // player turn section
    printf("Player [ %d ]'s turn!\n\n", p_turn);

    // game and score info
    printf("---- Your Scores ----\n");
    print_score_w_pot(p_dice, 1, p_scores[ONES], "1  | Ones        ");
    print_score_w_pot(p_dice, 2, p_scores[TWOS], "2  | Twos        ");
    print_score_w_pot(p_dice, 3, p_scores[THREES], "3  | Threes      ");
    print_score_w_pot(p_dice, 4, p_scores[FOURS], "4  | Fours       ");
    print_score_w_pot(p_dice, 5, p_scores[FIVES], "5  | Fives       ");
    print_score_w_pot(p_dice, 6, p_scores[SIXES], "6  | Sixes       ");
    printf("   |              |\n");
    print_score(p_scores[UPPER_SUM], "   | Sum         ");
    print_score(p_scores[BONUS], "   | Bonus       ");
    printf("   |              |\n");
    print_score_w_pot(p_dice, 9, p_scores[KIND_3], "7  | 3 of a Kind ");
    print_score_w_pot(p_dice, 10, p_scores[KIND_4], "8  | 4 of a Kind ");
    print_score_w_pot(p_dice, 11, p_scores[FULL_HOUSE], "9  | Full House  ");
    print_score_w_pot(p_dice, 12, p_scores[SM_STRAIGHT], "10 | Sm. Straight");
    print_score_w_pot(p_dice, 13, p_scores[LG_STRAIGHT], "11 | Lg. Straight");
    print_score_w_pot(p_dice, 14, p_scores[CHANCE], "12 | Chance      ");
    print_score_w_pot(p_dice, 15, p_scores[YAHTZEE], "13 | Yahtzee!    ");
    printf("   |              |\n");
    print_score(p_scores[TOTAL], "Total            ");
    printf("\n");
}
void print_dice(int* dice) {
    printf("Your dice:\n");
    printf("+---+  +---+  +---+  +---+  +---+\n");
    printf("| %d |  | %d |  | %d |  | %d |  | %d |\n", dice[1], dice[2], dice[3], dice[4], dice[5]);
    printf("+---+  +---+  +---+  +---+  +---+\n");
}
void clear_scr() {
#ifndef DISABLE_CLEAR_SCR
    system(CLEAR_COMMAND);
#endif
}
void print_array(int* array, int len) {
    printf("[");
    for (int i = 0; i < len; i++) {
        printf("%d", array[i]);
        if (i < len - 1) printf(", ");
    }
    printf("]\n");
}

// game handling functions
// main play game function.
int play_game() {
    printf("Welcome to yahtzee!\n");

    // scores have all 13 point sections, plus upper section sum, upper section bonus, and total score
    int p1_scores[SCORE_ARRAY_LENGTH] = { 0 }, p2_scores[SCORE_ARRAY_LENGTH] = { 0 };
    // player dice and held include empty space at [0]
    int p1_dice[6] = { 0 }, p2_dice[6] = { 0 };
    int p1_held[6] = { 0 }, p2_held[6] = { 0 };

    // Reset scores for safety
    fill_scores(p1_scores, -1);
    fill_scores(p2_scores, -1);

    // main loop, alternating players
    int current_round = 1;  // range [1, 13]
    for (int round = 1; round <= ROUNDS; round++) {
        // player 1
        clear_scr();
        int player_turn = 1;
        fill_dice(p1_held, 0);
        roll_dice(p1_dice, p1_held);

        // print round info
        print_round_info(player_turn, p1_scores, p1_dice, round);

        // reroll loop
        reroll_loop(p1_dice, p1_held);

        // re-print round for combo ask
        print_round_info(player_turn, p1_scores, p1_dice, round);
        print_dice(p1_dice);

        // ask for combo
        int combo_choice = combo_ask_loop(p1_scores);

        // set score for combo
        p1_scores[combo_choice - 1] = get_score_for_combo(p1_dice, combo_choice);

        // update scores
        update_scores(p1_scores);

        // player 2
        clear_scr();
        player_turn = 2;
        fill_dice(p2_held, 0);
        roll_dice(p2_dice, p2_held);

        // print round info
        print_round_info(player_turn, p2_scores, p2_dice, round);

        // reroll loop
        reroll_loop(p2_dice, p2_held);

        // re-print round for combo ask
        print_round_info(player_turn, p2_scores, p2_dice, round);
        print_dice(p2_dice);

        // ask for combo
        combo_choice = combo_ask_loop(p2_scores);

        // set score for combo
        p2_scores[combo_choice - 1] = get_score_for_combo(p2_dice, combo_choice);

        // update scores
        update_scores(p2_scores);
    }

    return 0;
}

void reroll_loop(int* p_dice, int* p_held) {
    for (int rerolls_left = 2; rerolls_left > 0; rerolls_left--) {
        print_dice(p_dice);

        char reroll_choice = '\0';

        while (reroll_choice == '\0') {
            printf("\nWould you like to re-roll your dice? (y/n)\nYou have %d rerolls left.\n$ ", rerolls_left);
            int result = scanf(" %c", &reroll_choice);

            // check for invalid input and clear buffer if so
            if (result != 1 ||
                !(reroll_choice == 'y' || reroll_choice == 'n')) {
                while (getchar() != '\n');
                printf("Please enter y or n!\n\n");
                reroll_choice = '\0';
            }
        }

        if (reroll_choice == 'y') {
            int valid_selections = 0;
            while (!valid_selections) {
                printf("\nPlease enter in which dice you'd like to hold from rolling.\n");
                printf("0 = roll, 1 = hold. For example: 1 0 1 1 0\n$ ");
                int result = scanf("%d%d%d%d%d", &p_held[1], &p_held[2], &p_held[3], &p_held[4], &p_held[5]);

                if (result != 5 ||
                    !(p_held[1] == 0 || p_held[1] == 1) ||
                    !(p_held[2] == 0 || p_held[2] == 1) ||
                    !(p_held[3] == 0 || p_held[3] == 1) ||
                    !(p_held[4] == 0 || p_held[4] == 1) ||
                    !(p_held[5] == 0 || p_held[5] == 1)) {
                    while (getchar() != '\n');
                    printf("Please enter only 0's and 1's with spaces between!\n\n");
                    fill_dice(p_held, 0);
                }
                else {
                    valid_selections = 1;
                }
            }
        }
        else {
            clear_scr();
            break;
        }

        // reroll dice
        roll_dice(p_dice, p_held);

        // clear at the end
        clear_scr();
    }
}
int combo_ask_loop(int* p_scores) {
    int combo_choice = -1;
    while (combo_choice == -1) {
        printf("\nPlease enter a category to enter your score into [1-13]\n$ ");
        int result = scanf("%d", &combo_choice);

        if (result != 1 ||
            (result == 1 && combo_choice < 1) ||
            (result == 1 && combo_choice > 13)) {
            printf("Please enter a number from 1 to 13, inclusive\n");
            while (getchar() != '\n');
            combo_choice = -1;
        }

        // add 2 to combo choice if they chose past Sixes,
        // to account for sum and bonus being in the score array
        if (combo_choice > 6) combo_choice += 2;

        if (p_scores[combo_choice - 1] > -1) {
            printf("Please enter a combo you haven't entered a score into yet!\n");
            while (getchar() != '\n');
            combo_choice = -1;
        }
    }

    return combo_choice;
}

// array functions - dice
void fill_dice(int* dice, int value) {
    for (int i = 0; i < 6; i++) {
        dice[i] = value;
    }
}
// held: int array[7] where 0 is not held, 1 is held
// held means don't roll
void roll_dice(int* dice, int* held) {
    for (int i = 1; i <= 6; i++) {
        if (held[i] == 0) {
            dice[i] = roll_die();
        }
    }
}
int sum_dice(int* dice) {
    int sum = 0;
    for (int i = 1; i <= 5; i++) {
        sum += dice[i];
    }
    return sum;
}
int get_has_sm_straight(int* freqs) {
    // case 1: 1, 2, 3, 4 - offset 0
    // case 2: 2, 3, 4, 5 - offset 1
    // case 3: 3, 4, 5, 6 - offset 2

    for (int offset = 0; offset <= 2; offset++) {
        if (
            freqs[1 + offset] == 1 &&
            freqs[2 + offset] == 1 &&
            freqs[3 + offset] == 1 &&
            freqs[4 + offset] == 1
            ) return 1;
    }

    return 0;
}
int get_has_lg_straight(int* freqs) {
    // case 1: 1, 2, 3, 4, 5 - offset 1
    // case 2: 2, 3, 4, 5, 6 - offset 2

    for (int offset = 0; offset <= 1; offset++) {
        if (
            freqs[1 + offset] == 1 &&
            freqs[2 + offset] == 1 &&
            freqs[3 + offset] == 1 &&
            freqs[4 + offset] == 1 &&
            freqs[5 + offset] == 1
            ) return 1;
    }

    return 0;
}
int get_has_yahtzee(int* freqs) {
    for (int i = 1; i <= 5; i++) {
        if (freqs[i] == 5) return 1;
    }
    return 0;
}

// array functions - scores
void fill_scores(int* score_array, int value) {
    for (int i = 0; i < SCORE_ARRAY_LENGTH; i++) {
        score_array[i] = value;
    }
}
void enter_score(int* score_array, int score_index, int new_score) {
    score_array[score_index] = new_score;
}
int get_score_for_combo(int* dice, int combo_id) {
    // make array of dice number frequencies, empty at [0]
    int freqs[7] = { 0 };
    pop_freq_array(dice, freqs);

    // printf("%d, %d, %d, %d, %d, %d, %d\n", freqs[0], freqs[1], freqs[2], freqs[3], freqs[4], freqs[5], freqs[6]);

    if (combo_id <= 6) {
        return freqs[combo_id] * combo_id;
    }

    // remove the 2 indexes from sum and bonus
    combo_id -= 2;

    switch (combo_id) {
        // 3 of a kind
    case 7: {
        if (get_any_ge_freq(freqs, 3)) return sum_dice(dice);
        else return 0;
    }
          // 4 of a kind
    case 8: {
        if (get_any_ge_freq(freqs, 4)) return sum_dice(dice);
        else return 0;
    }
          // full house
    case 9: {
        if (get_any_with_freq(freqs, 3) &&
            get_any_with_freq(freqs, 2)) return 25;
        else return 0;
    }
          // Sm Straight
    case 10: {
        if (get_has_sm_straight(freqs)) return 30;
        return 0;
    }
           // Lg Striaght
    case 11: {
        if (get_has_lg_straight(freqs)) return 40;
        return 0;
    }
           // Chance
    case 12: return sum_dice(dice);
        // Yahtzee!
    case 13: {
        if (get_has_yahtzee(freqs)) return 50;
        return 0;
    }
    }

    return 0;
}
void update_scores(int* score_array) {
    // calc upper sum
    int upper_sum = 0;
    for (int i = 0; i < 6; i++) {
        if (score_array[i] != -1) upper_sum += score_array[i];
    }

    // calc bonus
    int bonus = (upper_sum >= 63) ? 35 : 0;

    // assign sum and bonus to the score array
    score_array[UPPER_SUM] = upper_sum;
    score_array[BONUS] = bonus;

    // calc total
    int total = 0;
    for (int i = UPPER_SUM; i < 15; i++) {
        if (score_array[i] != -1) total += score_array[i];
    }

    // assign total to its slot in score array
    score_array[TOTAL] = total;
}

// array functions - frequencies
void pop_freq_array(int* dice, int* freq_array) {
    for (int i = 1; i <= 5; i++) {
        freq_array[dice[i]]++;
    }
}
int get_any_with_freq(int* freqs, int num) {
    for (int i = 1; i <= 5; i++) {
        if (freqs[i] == num) return i;
    }
    return 0;
}
int get_any_ge_freq(int* freqs, int num) {
    for (int i = 1; i <= 5; i++) {
        if (freqs[i] >= num) return i;
    }
    return 0;
}