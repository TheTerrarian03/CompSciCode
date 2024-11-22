/*
- Name:      Logan Meyers
- Date:      11/20/2024
- TA:        JAMES!
- Assigment: PA 7
- Project:   Poker! Player vs Computer

- Description: Play poker against a computer!
*/

#include "poker.h"
#include "funcs.h"

/* shuffle cards in deck */
void shuffle (int wDeck[4][13])
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */

	/* for each of the 52 cards, choose slot of deck randomly */
	for (card = 1; card <= 52; card++)
	{
		/* choose new random location until unoccupied slot found */
		do
		{
			row = rand_range(4);
			column = rand_range(13);
		} while (wDeck[row][column] != 0);

		/* place card number in chosen slot of deck */
		wDeck[row][column] = card;
	}
}

/* deal cards in deck */
// void deal (const int wDeck[][13], const char *wFace[], const char *wSuit[])
// {
// 	int row = 0;    /* row number */
// 	int column = 0; /*column number */
// 	int card = 0;   /* card counter */
 
// 	/* deal each of the 52 cards */
// 	for (card = 1; card <= 52; card++)
// 	{
// 		/* loop through rows of wDeck */
// 		for (row = 0; row <= 3; row++)
// 		{
// 			/* loop through columns of wDeck for current row */
// 			for (column = 0; column <= 12; column++)
// 			{
// 				/* if slot contains current card, display card */
// 				if (wDeck[row][column] == card)
// 				{
// 					printf ("%5s of %-8s%c", wFace[column], wSuit[row], card % 2 == 0 ? '\n' : '\t');
// 				}
// 			}
// 		}
// 	}
// }
void deal_to_hand(const int wDeck[4][13], Hand *hand, int num_to_deal, int *start_card)
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */
 
	/* deal each of the 52 cards */
	for (card = *start_card; card < (*start_card)+num_to_deal; card++)
	{
		/* loop through rows of wDeck */
		for (row = 0; row <= 3; row++)
		{
			/* loop through columns of wDeck for current row */
			for (column = 0; column <= 12; column++)
			{
				/* if slot contains current card, display card */
				if (wDeck[row][column] == card)
				{
					int hand_replace_index = 5 - (num_to_deal + (*start_card - card));
					// printf("Found card %d at row %d and column %d\n", card, row, column);
					(*hand).cards[hand_replace_index].row_idx = row;
					(*hand).cards[hand_replace_index].col_idx = column;
				}
			}
		}
	}

	(*start_card) += num_to_deal;
	
}

/* ----- Hand Checks ----- */
int check_pair(Hand hand) {
	for (int i=0; i < 5; i++) {
		for (int j=0; j < 5; j++) {
			if (j != i) {
				// return 1 if a pair found
				// NOTE: the pair found may not be the highest rank,
				//       but there is still a pair found
				if (hand.cards[i].col_idx == hand.cards[j].col_idx) return 1;
			}
		}
	}

	// return 0 otherwise, no pairs found
	return 0;
}
int check_2_pairs(Hand hand) {
	int pair1_idx1 = -1, pair1_idx2 = -1;
	int pairs_found = 0;
	
	for (int i=0; i < 5; i++) {
		for (int j=0; j < 5; j++) {
			// make sure i and j don't match each other or previous pair indexes
			if ((j != i) &&
					(i != pair1_idx1) &&
					(i != pair1_idx2) &&
					(j != pair1_idx2) &&
					(j != pair1_idx1)) {

				if (hand.cards[i].col_idx == hand.cards[j].col_idx) {
					if (pairs_found == 0) {
						// set first pair info
						pairs_found++;
						pair1_idx1 = i;
						pair1_idx2 = j;
					} else {
						// return 1 because both pairs found
						return 1;
					}
				}
			}
		}
	}

	// return 0 otherwise, no pairs found
	return 0;
}
int check_3_kind(Hand hand) {
	// this is so ugly, you're welcome :)
	for (int i=0; i < 5; i++) {
		for (int j=0; j < 5; j++) {
			if (j != i) {
				for (int k=0; k < 5; k++) {
					if ((k != i) && (k != j)) {
						// return 1 if a triplet found
						// NOTE: the pair found may not be the highest rank,
						//       but there is still a pair found
						if ((hand.cards[i].col_idx == hand.cards[j].col_idx) &&
						    (hand.cards[j].col_idx == hand.cards[k].col_idx)) return 1;
					}
				}
			}
		}
	}

	// return 0 otherwise, no pairs found
	return 0;
}
int check_4_kind(Hand hand) {
	// I'm really sorry James
	// There are better ways to do this (frequency table, thanks Kenny)
	// Buuuuut this is funny
	for (int i=0; i < 5; i++) {
		for (int j=0; j < 5; j++) {
			if (j != i) {
				for (int k=0; k < 5; k++) {
					if ((k != i) && (k != j)) {
						for (int l=0; l < 5; l++) {
							if ((l != k) && (l != j) && (l != i)) {
								// return 1 if a quadruplet found
								// NOTE: the pair found may not be the highest rank,
								//       but there is still a pair found
								if ((hand.cards[i].col_idx == hand.cards[j].col_idx) &&
									(hand.cards[j].col_idx == hand.cards[k].col_idx) &&
									(hand.cards[k].col_idx == hand.cards[l].col_idx)) return 1;
							}
						}
					}
				}
			}
		}
	}

	// return 0 otherwise, no pairs found
	return 0;
}
int check_full_house(Hand hand) {
	int i_idx = -1, j_idx = -1, k_idx = -1;
	
	// check for 3 of a kind
	for (int i=0; i < 5; i++) {
		for (int j=0; j < 5; j++) {
			if (j != i) {
				for (int k=0; k < 5; k++) {
					if ((k != i) && (k != j)) {
						// return 1 if a triplet found
						// NOTE: the pair found may not be the highest rank,
						//       but there is still a pair found
						if ((hand.cards[i].col_idx == hand.cards[j].col_idx) &&
						    (hand.cards[j].col_idx == hand.cards[k].col_idx)) {
								i_idx = i;
								j_idx = j;
								k_idx = k;
						}
					}
				}
			}
		}
	}

	// if a triplet has not been found, return false
	if ((i_idx == -1) || (j_idx == -1) || (k_idx = -1)) return 0;

	// other wise, determine two other indexes
	int other_1_idx = -1, other_2_idx = -1;

	for (int i = 0; i < 5; i++) {

	}
}
int check_flush(Hand hand);
int check_straight(Hand hand);
