/*
- Logan Meyers
- 011881121
- 10/10/2024
- PA4

- Welcome to CRAPS!
*/

#include "pa4.h"

/*
A player rolls two dice. Each die has six faces. These faces contain 1, 2, 3, 4, 5, and 6 spots.\
After the dice have come to rest, the sum of the spots on the two upward faces is calculated.\
If the sum is 7 or 11 on the first throw:\
- the player wins.\
If the sum is 2, 3, or 12 on the first throw (called "craps"):\
- the player loses\
- the "house" wins\
If the sum is 4, 5, 6, 8, 9, or 10 on the first throw:\
- sum becomes the player's "point."\
To win, you must continue rolling the dice until you "make your point."\
The player loses by rolling a 7 before making the point.\
*/

// print methods
void print_game_rules() {
    // shh.. I wantd it to look nice and this was my solution to that NOT
    // including 11 print statements.
    printf("%s%s%s%s%s%s%s%s%s%s%s",
           "A player rolls two dice. Each die has six faces. These faces contain 1, 2, 3, 4, 5, and 6 spots.",
           "\nAfter the dice have come to rest, the sum of the spots on the two upward faces is calculated.",
           "\nIf the sum is 7 or 11 on the first throw:",
           "\n- the player wins.",
           "\nIf the sum is 2, 3, or 12 on the first throw (called \"craps\"):",
           "\n- the player loses",
           "\n- the \"house\" wins",
           "\nIf the sum is 4, 5, 6, 8, 9, or 10 on the first throw:",
           "\n- sum becomes the player's \"point.\"",
           "\nTo win, you must continue rolling the dice until you \"make your point.\"",
           "\nThe player loses by rolling a 7 before making the point.");
}
void chatter_messages(int number_rolls,
                      int win_loss_neither,
                      double initial_bank_balance,
                      double current_bank_balance);

// input getter methods
double get_bank_balance() {
    return get_double_safe_pos("\nPlease enter in your starter bank balance: ");
}
double get_wager_amout();

// input validation loops
double get_double_safe_pos(char* prompt) {
    double val;
    
    while (1) {
        val = 0.0;

        if (scanf(" %lf", &val)) {
            if (val > 0.0) {
                break;
            }
        }
    }

    return val;
}
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