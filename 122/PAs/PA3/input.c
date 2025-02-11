/*
- Name: Logan Meyers
- TA: Martin "Double Factorial" Hundrup
- Assignment: PA 3
- [Mostly] Finished: 02/10/2025
- Description: Digital Music Manager!

- File: input.c
- Description: definitions for my input functions
*/

#include "input.h"

// this is all pretty simple stuff, though I've had a lot of issues
// wrestling with C to clear stdin buffers so i've given up and
// have resorted to my rocket launcher, named "Using fgets for everything
// instead of scanf", this baby fixes all.

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

    return choice;
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

    return choice;
}

void cpy_nstring(char *dest, int n) {
    char line[100] = "";

    fgets(line, sizeof(line), stdin);

    strncpy(dest, line, strlen(line));

    //strncpy(dest, line, n);

    dest[strlen(line)-1] = '\0';
}

void cpy_nstring_if_exist(char *dest, int n) {
    char line[100] = "";

    fgets(line, sizeof(line), stdin);

    if (line[0] == '\n') return;

    strncpy(dest, line, n);

    dest[strlen(line)-1] = '\0';
}

void set_int_in_range_if_exist(char *line_prompt, int *num, int min, int max) {
    int choice = min-1;

    printf("%s", line_prompt);

    while (choice == min-1) {
        char line[100] = "";

        fgets(line, sizeof(line), stdin);

        if (line[0] == '\n') return;

        if (sscanf(line, "%d", &choice) == 1) {
            printf("%d\n", choice);
            if (choice >= min && choice <= max) {
                // printf("num found of %d\n", choice);
                *num = choice;
                return;
            }

            printf("Out of range! Try again:\n%s", line_prompt);
            choice = min-1;
            continue;
        }

        printf("Invalid Input! Enter a number [%d, %d]:\n%s", min, max, line_prompt);

        choice = min-1;
    }
}