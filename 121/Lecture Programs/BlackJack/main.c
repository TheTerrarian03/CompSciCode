/*
- Logan Meyers
- 09/27/2024
- Lecture Program

- Description: This program is supposed to play the game BlackJack, which should be similar in feel
               to the PA 4 we are going to make soon.
*/

#include "blackjack.h"

int main() {
    int p_card1 = 0, p_card2 = 0, sum_c = 0;

    // call srand once to seed the value
    // based on the time value so you will
    // get truly unique values
    srand((unsigned int) time(NULL));
    
    // p_card1 = draw_card(10);
    // p_card2 = draw_card(10);

    // print_card(p_card1);
    // print_card(p_card2);

    // sum_c = sum_card(p_card1, p_card2);

    // printf("Sum: %d\n", sum_c);

    // int i = 4, j = 4, k = 4;

    // printf("i: %d, j++: %d, ++k: %d\n", i, j++, ++k);
    // printf("j: %d\n", j);

    // for (int i = 0; i < 1000; i++) {
    //     printf("Rand number: %d\n", draw_card());
    // }

    int test_num = 0106;

    int sum_digits = calc_sum_digits(test_num);

    printf("Sum of digits: %d\n", sum_digits);

    return 0;
}

// 1,458,777,923