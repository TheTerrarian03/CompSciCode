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
		case FOUR: printf("Three\n");
			break;
		case FIVE: printf("Three\n");
			break;
		case SIX: printf("Three\n");
			break;
		case SEVEN: printf("Three\n");
			break;
		case EIGHT: printf("Three\n");
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
	
	while(1) {
		printf("\nWould you like to draw another card? (y/n):\n$ ");
		scanf(" %c", &choice);

		if (choice == 'y' || choice == 'n') break;
	}
	
	return choice;
}