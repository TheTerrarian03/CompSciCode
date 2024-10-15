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
#include <math.h>

// constants
#define DEBUG 1
#define CLEAR_COMMAND "clear"
// #define DISABLE_CLEAR_SCR  // un-comment to disable clearing screen, if you want history

#define START_OPTIONS ((const char*[]){"Play Game", "Print Rules", "Exit"})
#define BALANCE_OPTIONS ((const char*[]){"Keep Current Balance", "Enter New Balance", "Quit to Main Menu"})

/* ---------- print/display methods ---------- */

// Name: print_game_rules
// Description: Prints game rules
void print_game_rules();

// Name: print_welcome_screen
// Description: prints the welcome screen
void print_welcome_screen();
// void print_decision_box(char* choices[])

// 
void chatter_messages(int number_rolls,
                      int win_loss_neither,
                      double initial_bank_balance,
                      double current_bank_balance);

// Name: clear_scr
// Description: clears the terminal screen
// Adjustment: Adjust CLEAR_COMMAND to change the command to run, for different OS's
// Adjustment: define DISABLE_CLEAR_SCR to disable clearing the screen
void clear_scr();

/* --------- input getter methods ----------*/

// Name: get_bank_balance
// Description: prompts and asks for player's bank balance
double get_bank_balance();

// Name: get_wager_amount
// Description: prompts and asks for the player's wager
double get_wager_amount();

// Name: get_choice
// Description: Prompts and asks for the player's choice
// Parameter: char* choices[], an array of strings for choices to give the player
// Parameter: int num_choices, the number of prompts to print from the choices array
// Returns: integer choice with range [1, num_choices+]
int get_choice(char* choices[], int num_choices);

/* --------- calculation methods ---------*/

// Name: roll_die
// Description: rolls a die
// Returns: int result, with range [1, 6]
int roll_die();

// Name: adjust_bank_balance
// Description: Adjusts the bank balance based on wager and whether to add or sub
// Notes: unused
double adjust_bank_balance(double bank_balance,
                           double wager_amount,
                           int add_or_subtract);

/* --------- comparison methods ---------*/

// Name: check_wager_amount
// Description: Makes sure the wager is withing the bounds of the balance
// Parameter: double wager, the player's wager
// Parameter: double balance, the player's balance
// Returns: int 1 if it is within bounds, int 0 all else
int check_wager_amount(double wager, double balance);

// Name: calculate_sum_dice
// Description: Sums dice values
// Parameter: int die1_value
// Parameter: int die2_value
// Returns: int sum of die1_value and die2_value
int calculate_sum_dice(int die1_value, int die2_value);

// 
int is_win_loss_or_point(int sum_dice);
int is_point_loss_or_neither(int sum_dice, int point_value);

// gameplay abstractions
void handle_player_win(double* balance, double wager);
void handle_player_loss(double* balance, double wager);
void handle_player_make_point(int dice_sum, int* point);
void handle_player_continue(int sum, int point);

#endif