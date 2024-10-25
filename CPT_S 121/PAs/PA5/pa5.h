/*
- 
*/

#ifndef PA5_H
#define PA5_H

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
#define CLEAR_COMMAND "clear"
// #define DISABLE_CLEAR_SCR  // un-comment to disable clearing screen, if you want history

// rand functions
void seed_rand();
int roll_die();

// input/output functions
void print_game_rules();
int get_menu_option();
void print_score(int score, char *combo);
void print_round_info(int p_turn, int *p_scores, int *p_dice, int *p_held, int rolls_left);
void clear_scr();
void print_array(int *array, int len);


// game handling functions
int play_game();

// array functions - dice
void fill_dice(int *dice, int value);
void roll_dice(int *dice, int *held);

// array functions - scores
void fill_scores(int *score_array, int value);
void enter_score(int *score_array, int score_index, int new_score);
int get_score_for_combo(int *dice, int combo_id);
void update_scores(int *score_array);

#endif