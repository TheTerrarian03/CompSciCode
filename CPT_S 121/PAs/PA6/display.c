/*
- These are some functions abstracted into a serpate file,
    that have to do with displaying info!

- Some notable functions:
    - dbgjkbdkj
*/

#include "display.h"

/* ---------- System Calls ---------- */
void clr_screen() {
    system(CLEAR_COMMAND);
}

/* ---------- Simple Menus ---------- */
void disp_horizontal_border(int total_len) {
    printf("+");
    for (int i=0; i<total_len+4; i++) printf("-");
    printf("+\n");
}
void disp_message(char *message_str) {
    int message_len = strlen(message_str);

    disp_horizontal_border(message_len);
    printf("|  %s  |\n", message_str);
    disp_horizontal_border(message_len);
}
void disp_combo_ask(char *prompt_str, char **options_str_arr, int amnt_options) {
    int max_message_len = strlen(prompt_str);

    for (int i=0; i < amnt_options; i++) {
        int option_len = strlen(options_str_arr[i]);
        if (option_len > max_message_len) max_message_len = option_len;
    }

    disp_horizontal_border(max_message_len);
    printf("|  %-*s  |\n", max_message_len, prompt_str);
    printf("|  %*c  |\n", max_message_len, ' ');
    for (int i=0; i<amnt_options; i++) printf("|  %-*s  |\n", max_message_len, options_str_arr[i]);
    disp_horizontal_border(max_message_len);

    printf("\nEnter your choice here:\n$ ");
}

/* ---------- Complex Menus ---------- */
int ask_manual_vs_random_placement() {
    char* options[2] = {"1 - Manually", "2 - Randomly"};
    int choice = 0;

    while (choice == 0) {
        disp_combo_ask("How would you like to place your ships?", options, 2);

        int response = scanf("%d", &choice);

        if ((response != 1) || (choice < 1 || choice > 2)) {
            choice = 0;
            while (getchar() != '\n');
            clr_screen();
            disp_message("Please enter a number 1 or 2!");
            putchar('\n');
        }
    }
    
    return choice;
}
