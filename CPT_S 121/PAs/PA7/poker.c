/*
- Name:      Logan Meyers
- Date:      11/20/2024
- TA:        JAMES!
- Assigment: PA 7
- Project:   Poker! Player vs Computer

- Description: Play poker against a computer!
*/

#include "poker.h"
#include "funcs.h"  // should this be included here? or in poker.h?

/* ----- Starting Code ----- */
void shuffle (int wDeck[4][13]) {
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
void deal_to_hand(const int wDeck[4][13], Hand *hand, int num_to_deal, int *start_card) {
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
void deal_next_card(const int wDeck[4][13], Hand *hand, int hand_slot, int *start_card) {
	int row = 0;    /* row number */
	int column = 0; /*column number */
 
	/* loop through rows of wDeck */
	for (row = 0; row <= 3; row++) {
		/* loop through columns of wDeck for current row */
		for (column = 0; column <= 12; column++) {
			/* if slot contains current card, display card */
			if (wDeck[row][column] == (*start_card)) {
				// printf("Found card %d at row %d and column %d\n", *start_card, row, column);
				(*hand).cards[hand_slot].row_idx = row;
				(*hand).cards[hand_slot].col_idx = column;
			}
		}
	}

	(*start_card)++;
}

/* ----- Card Functions ----- */
void print_all_cards(const char *wFace[], const char *wSuit[], Hand hand) {
	for (int i=0; i<5; i++) {
		printf("%5s of %-8s  ", wFace[hand.cards[i].col_idx], wSuit[hand.cards[i].row_idx]);
	}
	putchar('\n');
}
void print_card(const char *wFace[], const char *wSuit[], Card to_print) {
	printf("%5s of %-8s  ", wFace[to_print.col_idx], wSuit[to_print.row_idx]);
}
void print_card_num(int num) {
	printf("     [%2d]          ", num);
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
	// Buuuuut this is funny (and it works)
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
						if ((i_idx != -1) && (j_idx != -1) && (k_idx != -1)) continue;
						
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
	if ((i_idx == -1) || (j_idx == -1) || (k_idx == -1)) return 0;

	// other wise, determine two other indexes
	int other_1_idx = 0, other_2_idx = 0;

	while ((other_1_idx == i_idx) || (other_1_idx == j_idx) || (other_1_idx == k_idx)) {
		other_1_idx++;
	}

	while ((other_2_idx == i_idx) || (other_2_idx == j_idx) || (other_2_idx == k_idx) || (other_2_idx == other_1_idx)) {
		other_2_idx++;
	}

	if (hand.cards[other_1_idx].col_idx == hand.cards[other_2_idx].col_idx) return 1;
	return 0;
}
int check_flush(Hand hand) {
	// check if they all have the same suit, easy
	int suit = hand.cards[0].row_idx;
	if ((hand.cards[1].row_idx == suit) &&
	    (hand.cards[2].row_idx == suit) &&
		(hand.cards[3].row_idx == suit) &&
		(hand.cards[4].row_idx == suit)) return 1;

	return 0;
}
int check_straight(Hand hand) {
	// make array for faces and fill with data from hand, then sort
	int faces[5] = {0};
	for (int i=0; i < 5; i++) { faces[i] = hand.cards[i].col_idx; }
	selection_sort(faces, 5);

	// get smallest face
	int current = faces[0];

	// loop through all 4 remaining cards
	for (int i=0; i < 4; i++) {
		// get next face.
		// if next-1 is not the same as current, then
		// not all cards are consecutive
		int next = faces[1+i];
		if (next-1 != current) return 0;
		current++;
	}

	// no false cases, return true; hand is a straight
	return 1;
}

/* ----- Play Turns ----- */
void player_turn(const int wDeck[4][13], const char *wFace[], const char *wSuit[], Hand *hand, int *start_card) {
	// display cards
	printf("Your current cards:\n");
	for (int i=0; i < 5; i++) print_card(wFace, wSuit, hand->cards[i]);
	putchar('\n');
	for (int i=0; i < 5; i++) print_card_num(i+1);
	putchar('\n');

	// ask for up to 3 replacements
	printf("Please enter (up to 3) card positions to replace, on seperate lines ('0' to stop early)\n");
	
	int replace_idxs[3] = {0};
	int num_to_replace = 0;
	while (num_to_replace < 3) {
		// scanf into next slot and break if 0 entered
		printf("$ ");
		scanf("%d", &replace_idxs[num_to_replace]);
		if (replace_idxs[num_to_replace] == 0) break;

		// if an input is invalid, deal with it
		if (replace_idxs[num_to_replace] > 5 || replace_idxs[num_to_replace] < 0) {
			printf("%d is out of bounds! Please enter a number between 0 and 5, inclusive.\n");
			replace_idxs[num_to_replace] = 0;
			continue;
		}

		// increment num_to_replace, since a valid number has been entered
		// and the user wants to enter more
		num_to_replace++;
	}

	// replace requested cards
	for (int i=0; i < 3; i++) {
		if (replace_idxs[i] != 0) deal_next_card(wDeck, hand, replace_idxs[i]-1, start_card);
	}

	// re-display cards and possible points
	printf("Your new cards:\n");
	for (int i=0; i < 5; i++) print_card(wFace, wSuit, hand->cards[i]);
	putchar('\n');
	for (int i=0; i < 5; i++) print_card_num(i+1);
	putchar('\n');

	// wait for user to continue
	printf("Press enter to continue...");
	while(getchar() != '\n');  // clear from previous entries
	getchar();                 // wait for user to enter something with enter
}
void dealer_turn(const int wDeck[4][13], const char *wFace[], const char *wSuit[], Hand *hand, int *start_card) {
	// if the dealer has a full house, straight, or flush:
	// keep all cards and continue on
	if (check_full_house(*hand) || check_straight(*hand) || check_flush(*hand) || check_4_kind(*hand)) {
		printf("Dealer makes no changes to their cards\n");
	} else {
		dealer_change_cards(wDeck, wFace, wSuit, hand, start_card);

		printf("Dealer made changes to their cards\n");
	}

	// show cards and possible points
	printf("Dealer's cards:\n");
	for (int i=0; i < 5; i++) print_card(wFace, wSuit, hand->cards[i]);
	putchar('\n');
	for (int i=0; i < 5; i++) print_card_num(i+1);
	putchar('\n');

	// wait for user to continue
	printf("Press enter to continue...");
	getchar();
}
void dealer_change_cards(const int wDeck[4][13], const char *wFace[], const char *wSuit[], Hand *hand, int *start_card) {
	// make frequency tables for faces and suits
	int face_freqs[13] = {0};
	int suit_freqs[4] = {0};
	hand_to_frequency_tables(face_freqs, suit_freqs, hand->cards);

	/* ----- choices to make to redraw ----- */
	if (check_3_kind(*hand)) {
		int triplet_face_id = get_index_of_freq(face_freqs, 13, 3);

		// re-draw the other two cards
		// hoping for 4-kind or full house
		for (int i=0; i<5; i++) {
			if (hand->cards[i].col_idx != triplet_face_id) deal_next_card(wDeck, hand, i, start_card);
		}

		return;
	}

	if (check_2_pairs(*hand)) {
		int first_pair_face_id = get_index_of_freq(face_freqs, 13, 2);
		int second_pair_face_id = get_2nd_index_of_freq(face_freqs, 13, 2);

		// re-draw last card
		// hoping for full house
		for (int i=0; i<5; i++) {
			if ((hand->cards[i].col_idx != first_pair_face_id) && (hand->cards[i].col_idx != second_pair_face_id))
				deal_next_card(wDeck, hand, i, start_card);
		}

		return;
	}

	if (check_pair(*hand)) {
		int pair_id = get_index_of_freq(face_freqs, 13, 2);

		// re-draw other three cards
		// hoping for another pair, full house, or whatever
		for (int i=0; i<5; i++) {
			if (hand->cards[i].col_idx != pair_id) deal_next_card(wDeck, hand, i, start_card);
		}

		return;
	}

	// otherwise, keep highest card and redraw everything else
	int highest_id = get_highest_freq(face_freqs, 13);

	for (int i=0; i<5; i++) {
		if (hand->cards[i].col_idx != highest_id) deal_next_card(wDeck, hand, i, start_card);
	}
}
