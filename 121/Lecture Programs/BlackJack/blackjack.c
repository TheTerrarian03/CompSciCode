/*
- Logan Meyers
- 09/27/2024
- Lecture Program

- Description: This program is supposed to play the game BlackJack, which should be similar in feel
               to the PA 4 we are going to make soon.
*/

#include "blackjack.h"

int draw_card(int range) {
    return rand() % range + 1;
}

void print_card(int card_number) {
    char* to_print = "";

    printf("Card number: %d", card_number);
    
    switch (card_number) {
        case ACE: to_print = "ACE";
            break;
        case 2: to_print = "Two";
            break;
        case 3: to_print = "Three";
            break;
        case 4: to_print = "Four";
            break;
        case 5: to_print = "Five";
            break;
        case 6: to_print = "Six";
            break;
        case 7: to_print = "Seven";
            break;
        case 8: to_print = "Eight";
            break;
        case 9: to_print = "Nine";
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
            break;
        default: to_print = "other";
            break;
    }

    printf("Your card: %s\n", to_print);
}

int sum_card(int sum, int card_num) {
    return sum + card_num;
}

void divide(int n1, int n2, int *result_ptr, int *remainder_ptr) {
    int result = n1 / n2;
    int remainder = n1 % n2;

    // ...    
}

int calc_sum_digits(int number) {
    int sum = 0;

    while (number > 0) {
        sum += number % 10;
        number /= 10;
    }

    return sum;
}