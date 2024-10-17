// We are designing and building a game of Blackjack. We are making some
// simplifications to our game. We'll not worry about the suit of a card.
// We'll get a start to the implementation and then this will become a bonus
// assignment.

// History: 9/27/24 - Started drawing a flowchart for Blackjack. Introduced
//                    random number generation using srand () and rand (), which
//                    is very helpful for PA 4 as well. Implemented functions
//                    draw_card () and print_card (). The function print_card ()
//                    is incomplete.

#include "BlackJack.h"

int main(void)
{
	// seed random
	srand((unsigned int) time(NULL));

	// init vars
	int p_card1 = 0, p_card2 = 0, p_sum = 0;
	int d_card1 = 0, d_card2 = 0, d_sum = 0;

	// draw the initial 2 cards for player 1
	p_card1 = draw_card(10); 
	p_card2 = draw_card(10);
	p_sum = sum_cards(p_card1, p_card2);

	// draw the initial 2 cards for dealer
	d_card1 = draw_card(10);
	d_card2 = draw_card(10);
	d_sum = sum_cards(d_card1, d_card2);

	// print the cards for player 1
	print_card(p_card1);
	print_card(p_card2);
	print_card(d_card1);
	print_card(d_card2);

	printf("\nPlayer sum: %d\n", p_sum);
	printf("Player sum: %d\n", d_sum);

	char player_draw_card = ask_hit();
	printf("Player choce: %c\n", player_draw_card);

	return 0;
}