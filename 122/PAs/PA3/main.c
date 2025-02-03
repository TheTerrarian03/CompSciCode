/*
- Name: Logan Meyers
- TA: Martin Double Factorial
- Assignment: PA 3
- "Finished": 02/02/2025
- Description: Digital Music Manager!

- Note: Better comments and headers will be added for the third PA, next submission.

- File: main.c
- Description: main entry point of the program.
*/

#include "pa3.h"

int main() {
    // Playlist of songs in doubly linked list
    Node *pHead = NULL;
    init_list(&pHead);

    int choice = 0;
    for (;;) {
        choice = main_menu();

        if (choice == 1) {
            int success = load_menu(&pHead);
        } else if (choice == 2) {
            store_menu(pHead);
        } else if (choice == 3) {
            display_menu(pHead);
        } else if (choice == 6) {
            edit_menu(pHead);
        } else if (choice == 8) {
            rate_menu(&pHead);
        } else if (choice == 11) {
            return 0;
        } else {
            printf("Not implemented!\n");
        }
    }
    
    return 0;
}