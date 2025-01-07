/*
- Logan Meyers
- 011881121
- 10/10/2024
- PA4

- Welcome to CRAPS!
*/

#include "pa4.h"

int main() {
    // seed random
    srand((unsigned int)time(NULL));

    // initial variable declaration
    double player_balance = 0.0, player_wager = 0.0;
    int program_running = 1, playing_game = 0, playing_round = 0;

    // print welcome screen
    print_welcome_screen();

    while (program_running) {
        playing_game = 0;

        // ask for start menu choice
        int game_choice = get_choice(START_OPTIONS, 3);

        // decide on what to do at that point
        // --game_choice takes it from the user's range of [1-3]
        // to the program's [0-2]
        switch (--game_choice) {
            case 0: playing_game = 1;
                    clear_scr();
                    break;
            case 1: clear_scr();
                    print_game_rules(1);
                    break;
            case 2: return 0;
            default: clear_scr();
                     printf("!! Wrong choice entered! Please try again below: !!\n\n");
        }

        while (playing_game) {
            // clear_scr();

            // keep or ask for new balance
            if (player_balance > 0.0) {
                printf("Your current balance is: $%.2lf\n\n", player_balance);

                // also acts as re-start menu
                int balance_choice = get_choice(BALANCE_OPTIONS, 3);

                switch (--balance_choice) {
                    case 1: player_balance = get_bank_balance();
                            break;
                    case 2: playing_game = 0;
                            clear_scr();
                            break;
                    default: clear_scr();
                             printf("\nKeeping your balance of $%.2lf\n\n", player_balance);
                }
            }
            else {
                player_balance = get_bank_balance();
            }

            // i hate this
            if (playing_game == 0) break;

            // set initial values
            playing_round = 1;
            int player_point = -1;

            while (playing_round) {
                // ask for wager
                player_wager = get_wager_amount();

                // make sure wager is in the right range
                if (check_wager_amount(player_wager, player_balance) == 0) {
                    clear_scr();
                    printf("HEY! Your wager of $%.2lf is greater than your balance of $%.2lf, Please try again... >:(\n", player_wager, player_balance);
                    continue;
                }

                int die1 = roll_die(), die2 = roll_die();
                int sum = calculate_sum_dice(die1, die2);

                printf("You rolled:\nDie 1: %d\nDie 2: %d\nWith a sum of: %d\n\n", die1, die2, sum);

                if (player_point == -1) {
                    int first_roll_result = is_win_loss_or_point(sum);

                    switch (first_roll_result) {
                        case 1: handle_player_win(&player_balance, player_wager);
                                playing_round = 0;
                                break;
                        case 0: handle_player_loss(&player_balance, player_wager);
                                playing_round = 0;
                                break;
                        case -1: handle_player_make_point(sum, &player_point);
                                 break;
                    }
                }
                else {
                    int other_roll_result = is_point_loss_or_neither(sum, player_point);

                    switch (other_roll_result) {
                        case 1: handle_player_win(&player_balance, player_wager);
                                playing_round = 0;
                                break;
                        case 0: handle_player_loss(&player_balance, player_wager);
                                playing_round = 0;
                                break;
                        case -1: handle_player_continue(sum, player_point);
                                 break;
                    }
                }
            }
        }
    }

    return 0;
}
