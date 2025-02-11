/*
- Name: Logan Meyers
- TA: Martin "Double Factorial" Hundrup
- Assignment: PA 3
- [Mostly] Finished: 02/10/2025
- Description: Digital Music Manager!

- File: main.c
- Description: main entry point of the program. Runs your amazing DMM.
*/

#include "pa3.h"  // includes list.h and input.h as well
#include "test.h"

int main() {    
    test_all();

    srand((unsigned int)time(NULL));
    
    // Playlist of songs in doubly linked list
    Node *pHead = NULL;
    init_list(&pHead);

    int choice = 0;
    for (;;) {
        choice = main_menu();

        if (choice == 1) {
            int success = load_menu(&pHead);
            //print_list_p(pHead);
        } else if (choice == 2) {
            store_menu(pHead);
        } else if (choice == 3) {
            display_menu(pHead);
        } else if (choice == 4) {
            insert_menu(&pHead);
        } else if (choice == 5) {
            delete_menu(&pHead);
        } else if (choice == 6) {
            edit_menu(pHead);
        } else if (choice == 7) {
            sort_menu(&pHead);
        } else if (choice == 8) {
            rate_menu(&pHead);
        } else if (choice == 9) {
            play_menu(pHead);
        } else if (choice == 10) {
            shuffle_menu(pHead);
        } else if (choice == 11) {
            return 0;
        } else {
            printf("Not implemented!\n");
        }
    }
    
    return 0;
}
