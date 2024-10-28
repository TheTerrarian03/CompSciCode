/*
- Name: Logan Meyers
- ID: 011881121
- Date Finished: 10/25/2024
- Assignment: PA 5
- TA: Awesome James

- Description: Let's play Yahtzee! 2 Player
*/

#ifndef PA5_H
#define PA5_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// until we officially learn about enums,
// combo and [sum, bonus, total] defines for readablity
#define ONES 0
#define TWOS 1
#define THREES 2
#define FOURS 3
#define FIVES 4
#define SIXES 5
#define UPPER_SUM 6
#define BONUS 7
#define KIND_3 8
#define KIND_4 9
#define FULL_HOUSE 10
#define SM_STRAIGHT 11
#define LG_STRAIGHT 12
#define CHANCE 13
#define YAHTZEE 14 
#define TOTAL 15

// other defines
#define SCORE_ARRAY_LENGTH 16
#define ROUNDS 13
#define CLEAR_COMMAND "cls"
// #define DISABLE_CLEAR_SCR  // un-comment to disable clearing screen, if you want history

// rand functions

// Name: seed_rand
// Description: Seed the numbers to use in rand calls
// Requirements: Only call once in the program
void seed_rand();

// Name: roll_die
// Description: Roll a number from 1 to 6 inclusive
// Returns: an int in range [1, 6]
int roll_die();

// input/output functions

// Name: print_game_rules
// Description: Prints the game rules
void print_game_rules();

// Name: get_menu_option
// Description: Asks the user for what to choose in the main menu
// Returns: int of range [1,3]
int get_menu_option();

// Name: print_score
// Description: Prints a score with a prefix combo name
// Param: int score, the score the player has currently for that category
// Param: char *combo, the string to prefix
void print_score(int score, char* combo);

// Name: print_score_w_pot
// Description: Prints the score with a prefix combo name, plus an optional potential score
// Param: int *dice, the array of player dice
// Param: int combo_id, combo id num
// Param: int score, current player score for that category
// Param: char *combo, the string to prefix
void print_score_w_pot(int* dice, int combo_id, int score, char* combo);

// Name: print_round_info
// Description: Prints the info the round, including round #, player turn, and all the scores
// Param: int p_turn, who's turn it is
// Param: int *p_scores, the array of player scores
// Param: int round, the round #
void print_round_info(int p_turn, int* p_scores, int* p_dice, int round);

// Name; print_dice
// Description: prints the player's dice in a nice format
// Param: int *dice, the array of player dice and what they rolled
void print_dice(int* dice);

// Name: clear_scr
// Description: clears the screen, if not defined otherwise
void clear_scr();

// Name: print_array
// Description: prints an array, used for debugging
// Param: int *array to print
// Param: int len of the array
void print_array(int* array, int len);

// game handling functions

// Name: play_game
// Description: main game loop, plays 13 rounds of alternating between 2 players
int play_game();

// Name: reroll_loop
// Description: Asks the user if they want to reroll and what dice to reroll, and validates inputs
// Param: int *p_dice, the player's current dice
// Param: int *p_held, the array to store hold choices into
void reroll_loop(int* p_dice, int* p_held);

// Name: combo_ask_loop
// Description: Asks the user what combo to score into, and validates input
// Param: int *p_scores, the player's current scores
int combo_ask_loop(int* p_scores);

// array functions - dice

// Name: fill_dice
// Description: Fills the dice array with a specified value
// Param: int *dice, the array of dice values
// Param: int value, the value to fill each dice with
void fill_dice(int* dice, int value);

// Name: roll_dice
// Description: Rolls each die in the dice array that is not held
// Param: int *dice, the array of dice values
// Param: int *held, the array indicating held dice (1 for held, 0 for roll)
void roll_dice(int* dice, int* held);

// Name: sum_dice
// Description: Sums all dice values in the dice array
// Param: int *dice, the array of dice values
// Return: int, the sum of the dice values
int sum_dice(int* dice);

// Name: get_has_sm_straight
// Description: Checks if there is a small straight (4 consecutive values) in the frequency array
// Param: int *freqs, the frequency array of dice values
// Return: int, 1 if small straight exists, otherwise 0
int get_has_sm_straight(int* freqs);

// Name: get_has_lg_straight
// Description: Checks if there is a large straight (5 consecutive values) in the frequency array
// Param: int *freqs, the frequency array of dice values
// Return: int, 1 if large straight exists, otherwise 0
int get_has_lg_straight(int* freqs);

// Name: get_has_yahtzee
// Description: Checks if there is a Yahtzee (5 of a kind) in the frequency array
// Param: int *freqs, the frequency array of dice values
// Return: int, 1 if Yahtzee exists, otherwise 0
int get_has_yahtzee(int* freqs);

// array functions - scores

// Name: fill_scores
// Description: Fills the score array with a specified value
// Param: int *score_array, the array of scores
// Param: int value, the value to fill each score with
void fill_scores(int* score_array, int value);

// Name: enter_score
// Description: Updates the score at a specific index in the score array
// Param: int *score_array, the array of scores
// Param: int score_index, the index to update
// Param: int new_score, the score to enter at the specified index
void enter_score(int* score_array, int score_index, int new_score);

// Name: get_score_for_combo
// Description: Calculates the score for a specified combination
// Param: int *dice, the array of dice values
// Param: int combo_id, the combination ID for scoring
// Return: int, the score for the specified combination
int get_score_for_combo(int* dice, int combo_id);

// Name: update_scores
// Description: Calculates and updates the upper sum, bonus, and total score in the score array
// Param: int *score_array, the array of scores
void update_scores(int* score_array);

// array functions - frequencies

// Name: pop_freq_array
// Description: Populates the frequency array based on dice values
// Param: int *dice, the array of dice values
// Param: int *freq_array, the frequency array to populate
void pop_freq_array(int* dice, int* freq_array);

// Name: get_any_with_freq
// Description: Checks if there is any dice value with a specific frequency
// Param: int *freqs, the frequency array of dice values
// Param: int num, the specific frequency to check for
// Return: int, the dice value with the specified frequency or 0 if none
int get_any_with_freq(int* freqs, int num);

// Name: get_any_ge_freq
// Description: Checks if there is any dice value with a frequency greater than or equal to a specific number
// Param: int *freqs, the frequency array of dice values
// Param: int num, the minimum frequency to check for
// Return: int, the dice value with the specified frequency or 0 if none
int get_any_ge_freq(int* freqs, int num);

#endif