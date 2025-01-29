#include "pa2.h"

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
        } else if (choice == 11) {
            return 0;
        } else {
            printf("Not implemented!\n");
        }
    }
    
    return 0;
}