/*
- Logan Meyers
- 09/27/2024
- Lecture Program

- Description: This program is supposed to play the game BlackJack, which should be similar in feel
               to the PA 4 we are going to make soon.
*/

#include "blackjack.h"

int draw_card(int range) {
    return rand() % 10 + range;
}

void print_card(int card_number) {
    char* to_print = "";
    
    switch (card_number) {
        case ACE: to_print = "ACE";
            break;
        case 2: to_print = "Two";
            break;
        case 3: to_print = "Three";
            break;
        case 10:
            switch (draw_card(4)) {
                case 1: to_print = "10";
                    break;
                case 2: to_print = "Jack";
                    break;
                case 3: to_print = "Queen";
                    break;
                case 4: to_print = "King";
                    break;
            }
    }

    printf("Your card: %s\n", to_print);
}