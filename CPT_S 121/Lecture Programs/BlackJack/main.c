/*
- Logan Meyers
- 09/27/2024
- Lecture Program

- Description: This program is supposed to play the game BlackJack, which should be similar in feel
               to the PA 4 we are going to make soon.
*/

#include "blackjack.h"

int main() {
    int p_card1 = 0, p_card2 = 0;

    // call srand once to seed the value
    // based on the time value so you will
    // get truly unique values
    srand((unsigned int) time(NULL));
    
    p_card1 = draw_card(10);
    p_card2 = draw_card(10);

    print_card(p_card1);
    print_card(p_card2);

    // for (int i = 0; i < 1000; i++) {
    //     printf("Rand number: %d\n", draw_card());
    // }

    return 0;
}

// 1,458,777,923