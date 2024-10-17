/*
Name: Logan Meyers
Date: 10/16/2024
Program: BlackJack

Description: Plays Black Jack!
*/

#include "BlackJack.h"

int draw_card(int range) // range represents the card number range: 1 through range
{
	return rand() % range + 1;
}

// the below function is incomplete
void print_card(int card_num) {
	switch (card_num) {
	case ACE: printf("Ace\n"); // we'd want to have #defines for each card value
		break;
	case TWO: printf("Two\n");
		break;
	case THREE: printf("Three\n");
		break;
	case FOUR: printf("Four\n");
		break;
	case FIVE: printf("Five\n");
		break;
	case SIX: printf("Six\n");
		break;
	case SEVEN: printf("Seven\n");
		break;
	case EIGHT: printf("Eight\n");
		break;
	case NINE: printf("Nine\n");
		break;
	case SPECIAL:
		switch (draw_card(4))
		{
		case 1: printf("Ten\n");
			break;
		case 2: printf("Jack\n");
			break;
		case 3: printf("Queen\n");
			break;
		case 4: printf("King\n");
			break;
		}
		break;
	}
}

void print_array(int* to_print, int size) {
	for (int i = 0; i < size; i++) {
		printf(" %d\n", to_print[i]);
	}
}

void print_player_turn(int* dealer_cards, int num_dealer_cards, int dealer_sum, int* player_cards, int num_player_cards, int player_sum) {
	// Seperator
	printf("\n---------- Player's Turn ---------\n");

	// Dealer cards
	printf("\nThe Dealer has the following cards:\n");
	for (int i = 0; i < num_dealer_cards; i++) {
		print_card(dealer_cards[i]);
	}
	printf("with a sum of: [%d]\n", dealer_sum);

	// Player cards
	printf("\nAnd you, the Player, have the following cards:\n");
	for (int i = 0; i < num_player_cards; i++) {
		print_card(player_cards[i]);
	}
	printf(".. With a sum of: [%d]\n", player_sum);
}

void print_dealer_turn(int* dealer_cards, int num_dealer_cards, int dealer_sum, int decision) {
	// Seperator
	printf("\n---------- Dealer's Turn ----------\n");

	// Decision 0, stand
	if (decision == 0) {
		printf("\nThe dealer has chosen to stand!\nThe dealer ends with the following cards:\n");
	}
	else {
		printf("\nThe dealer has chosen to draw!\nThe dealer now has the following cards:\n\n");
	}

	// Dealer Cards
	for (int i = 0; i < num_dealer_cards; i++) {
		print_card(dealer_cards[i]);
	}
	printf("with a sum of: [%d]\n", dealer_sum);
}

int sum_cards(int card1, int card2) {
	return card1 + card2;
}

// -1 for tie
// 0 for player
// 1 for dealer
int determine_winner(int dealer_sum, int player_sum) {
	// player wins
	if (dealer_sum > 21 && player_sum <= 21) return 0;
	// dealer wins
	if (dealer_sum <= 21 && player_sum > 21) return 1;
	// tie
	if (dealer_sum == player_sum) return -1;
}

char ask_hit() {
	char choice = '\0';

	while (1) {
		printf("\nWould you like to draw another card? (y/n):\n$ ");
		scanf(" %c", &choice);

		if (choice == 'y' || choice == 'n') break;
	}

	return choice;
}