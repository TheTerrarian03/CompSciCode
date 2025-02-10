#include "input.h"

void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int get_pos_int_loop(const char *line_prompt) {
    int choice = -1;

    printf("%s", line_prompt);

    while (choice == -1) {
        char line[100] = "";

        fgets(line, sizeof(line), stdin);

        if (sscanf(line, "%d", &choice)) return choice;

        printf("Invalid input! Try again:\n%s", line_prompt);

        choice = -1;
    }
}

int get_pos_int_range_loop(const char *line_prompt, int min, int max) {
    int choice = min-1;

    printf("%s", line_prompt);

    while (choice == min-1) {
        char line[100] = "";

        fgets(line, sizeof(line), stdin);

        if (sscanf(line, "%d", &choice)) {
            if (choice >= min && choice <= max) return choice;

            printf("Out of range! Try again:\n%s", line_prompt);
            choice = min-1;
            continue;
        }

        printf("Invalid Input! Enter a number [%d, %d]:\n%s", min, max, line_prompt);

        choice = min-1;
    }
}

void cpy_nstring(char *dest, int n) {
    int c;
    int i = 0;
    while ((c = getchar()) != '\n' && c != EOF && i < n-1) {
        dest[i] = c;
        i++;
    }
    dest[i] = '\0';
}

void cpy_nstring_if_exist(char *dest, int n) {
    clear_buffer();

    int c = getchar();

    if (c == '\n') return;

    dest[0] = c;
    int i = 1;

    while ((c = getchar()) != '\n' && c != EOF && i < n-1) {
        dest[i] = c;
        i++;
    }
    dest[i] = '\0';
}

void set_int_in_range_if_exist(int *num, int min, int max) {
    int input = min;

    int result = scanf("%d", &input);

    if (result == 0) return;

    if (input < min || input > max) {
        // number out of range, skip
        return;
    }

    *num = input;
}