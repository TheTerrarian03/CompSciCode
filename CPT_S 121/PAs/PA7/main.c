/*
- Name:      Logan Meyers
- Date:      11/20/2024
- TA:        JAMES!
- Assigment: PA 7
- Project:   Poker! Player vs Computer

- Description: Play poker against a computer!
*/

#include "poker.h"

int main ()
{
	/* initialize suit array */
	const char *suit[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};

	/* initialize face array */
	const char *face[13] = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight",
		"Nine", "Ten", "Jack", "Queen", "King"};

	/* initalize deck array */
	int deck[4][13] = {0};

	srand ((unsigned) time (NULL)); /* seed random-number generator */

	shuffle (deck);
	deal (deck, face, suit);

	return 0;
}
