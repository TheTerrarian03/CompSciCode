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
void print_game_rules() {  // works
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
           "\nThe player loses by rolling a 7 before making the point.\n\n");
}
void print_welcome_screen() {
    printf("╔═════════════════════════════════════════════════════╗\n");
    printf("║ ┌                                                 • ║\n");
    printf("║    Welcome to PA #4 - Craps [by Logan!] Enjoy :D    ║\n");
    printf("║ •                                                 ┘ ║\n");
    printf("╚═════════════════════════════════════════════════════╝\n\n");
}
// void print_decision_box(char* choices[]) {

// }
void chatter_messages(int number_rolls,
                      int win_loss_neither,
                      double initial_bank_balance,
                      double current_bank_balance);
void clear_scr() {
    #ifndef DISABLE_CLEAR_SCR
        system(CLEAR_COMMAND);
    #endif
}

// input getter methods
double get_bank_balance() {  // works
    double balance = 0.0;
    printf("\n> Please enter in your bank balance:\n$ ");
    scanf(" %lf", &balance);
    return balance;
}
double get_wager_amount() {  // works
    double wager = 0.0;
    printf("\nPlease enter in your wager balance: ");
    scanf("%lf", &wager);
    return wager;
}
int get_choice(char* choices[], int num_choices) {
    printf("Please choose an option by entering a number below and pressing enter:\n");

    for (int i=0; i < num_choices; i++) {
        printf("%d. %s\n", i+1, choices[i]);
    }

    int choice = 0;
    printf("$ ");
    scanf("%d", &choice);

    return choice;
}

// calculation methods
int roll_die() {  // works
    int dice_roll = 0;

    dice_roll = (rand() % 6) + 1;

    return dice_roll;
}
double adjust_bank_balance(double bank_balance,
                           double wager_amount,
                           int add_or_subtract);

// comparison methods
int check_wager_amount(double wager, double balance) {  // works
    return ((wager <= balance) ? 1 : 0);
}
int calculate_sum_dice(int die1_value, int die2_value) {  // works
    return die1_value + die2_value;
}
int is_win_loss_or_point(int sum_dice) {  // works
    // 7 or 11: 1 (win)
    if (sum_dice == 7 || sum_dice == 11) {
        return 1;
    }

    // 2, 3, or 12: 0 (lose)
    if (sum_dice == 2 || sum_dice == 3 || sum_dice == 12) {
        return 0;
    }

    // else: -1 (becomes point)
    return -1;
}
int is_point_loss_or_neither(int sum_dice, int point_value) {  // works
    // sum == point: 1
    if (sum_dice == point_value) return 1;

    // sum == 7: 0
    if (sum_dice == 7) return 0;

    // else: -1
    return -1;
}

// gameplay abstractions
void handle_player_win(double* balance, double wager) {
    clear_scr();

    *balance += wager;

    printf("Congratulations! You win!!\n\n");
}
void handle_player_loss(double* balance, double wager) {
    clear_scr();
    
    *balance -= wager;

    printf("Womp womp, you lose.\n\n");
}
void handle_player_make_point(int dice_sum, int* point) {
    clear_scr();
    
    *point = dice_sum;

    printf("Your point is now: %d", *point);
}
void handle_player_continue(int sum, int point) {
    clear_scr();

    printf("So close! (not really).\nYou rolled a:   %d\nbut you need a: %d\nto make your point.\nKeep rolling!\n", sum, point);
}
