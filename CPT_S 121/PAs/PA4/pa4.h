/*
- Logan Meyers
- 011881121
- 10/10/2024
- PA4

- Welcome to CRAPS!
*/

#ifndef PA4_H
#define PA4_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// print methods
void print_game_rules();
void chatter_messages(int number_rolls,
                      int win_loss_neither,
                      double initial_bank_balance,
                      double current_bank_balance);

// input getter methods
double get_bank_balance();
double get_wager_amout();
double get_double_safe_pos(char* prompt);
int read_int_safe(char* prompt);

// calculation methods
int roll_die();
double adjust_bank_balance(double bank_balance,
                           double wager_amount,
                           int add_or_subtract);

// comparison methods
int check_wager_amount(double wager, double balance);
int calculate_sum_dice(int die1_value, int die2_value);
int is_win_or_loss_point(int sum_dice);
int is_point_loss_or_neither(int sum_dice, int point_value);

#endif