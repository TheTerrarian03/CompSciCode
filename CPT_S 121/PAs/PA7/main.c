/*
- Name:      Logan Meyers
- Date:      11/20/2024
- TA:        JAMES!
- Assigment: PA 7
- Project:   Poker! Player vs Computer

- Description: Play poker against a computer!
*/

#include "funcs.h"
#include "display.h"
#include "poker.h"

int main ()
{
	seed_rand();

	/* initialize suit array */
	const char *suit[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};

	/* initialize face array */
	const char *face[13] = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight",
		"Nine", "Ten", "Jack", "Queen", "King"};

	/* initalize deck array */
	//  4 rows: suits
	// 13 cols: faces
	int deck[4][13] = {0};
	int next_free_card = 1;

	/* initialize player and dealer hands */
	Hand player_hand, dealer_hand;

	/* shuffle deck and deal hands to player and dealer */
	shuffle (deck);
	deal_to_hand(deck, &player_hand, 5, &next_free_card);
	deal_to_hand(deck, &dealer_hand, 3, &next_free_card);

	printf("hand faces: %d, %d, %d, %d, %d\n", player_hand.cards[0].col_idx, player_hand.cards[1].col_idx, player_hand.cards[2].col_idx, player_hand.cards[3].col_idx, player_hand.cards[4].col_idx);
	printf("You have pair: %d\n", check_3_kind(player_hand));

	// game flow:
	// player chooses cards to replace

	// dealer chooses cards to replace

	// cards are shown and winner chosen

	return 0;
}
