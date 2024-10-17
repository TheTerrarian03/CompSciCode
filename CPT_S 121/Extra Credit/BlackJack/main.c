/*
Name: Logan Meyers
Date: 10/16/2024
Program: BlackJack

Description: Plays Black Jack!
*/

#include "BlackJack.h"

int main(void)
{
	// seed random
	srand((unsigned int)time(NULL));

	// init vars
	int player_cards[NUM_CARDS_IN_ARRAY] = { 0 };
	int dealer_cards[NUM_CARDS_IN_ARRAY] = { 0 };

	int p_sum = 0, d_sum = 0;
	int p_num_cards = 2, d_num_cards = 2;

	int game_result = 0;  // 1 = player, 2 = dealer, 3 = tie

	// draw the initial 2 cards for the player
	player_cards[0] = draw_card(10);
	player_cards[1] = draw_card(10);
	p_sum = sum_cards(player_cards[0], player_cards[1]);

	// draw the initial 2 cards for dealer
	dealer_cards[0] = draw_card(10);
	dealer_cards[1] = draw_card(10);
	d_sum = sum_cards(dealer_cards[0], dealer_cards[1]);

	// print_array(player_cards, NUM_CARDS_IN_ARRAY);
	// print_array(dealer_cards, NUM_CARDS_IN_ARRAY);

	// TODO: add deal win case
	if (p_sum == 21 && d_sum == 21) {
		game_result = 3;
	}
	if (p_sum == 21) {
		game_result = 1;
	}
	if (d_sum == 21) {
		game_result = 2;
	}

	int player_turn = !game_result;
	while (player_turn) {
		// Print player's turn screen
		print_player_turn(dealer_cards, d_num_cards, d_sum,
			player_cards, p_num_cards, p_sum);

		// ask for if they want to draw another card
		char y_n_draw = ask_hit();

		// if they stand, player's turn is over
		if (y_n_draw == 'n') {
			player_turn = 0;
			break;
		}

		// if they draw, continue
		p_num_cards++;
		player_cards[p_num_cards - 1] = draw_card(10);
		p_sum = sum_cards(p_sum, player_cards[p_num_cards - 1]);

		// Give feedback to the user about what they drew:
		printf("You drew a: ");
		print_card(player_cards[p_num_cards - 1]);

		// if they go over 21, end player's turn, dealer wins
		if (p_sum > 21) {
			player_turn = 0;
			game_result = 2;
			break;
		}

		// if they get exactly 21, end player's turn, player wins
		if (p_sum == 21) {
			player_turn = 0;
			game_result = 1;
			break;
		}
	}

	int dealer_turn = !game_result;
	while (dealer_turn) {
		// draw another card
		if (d_sum < 16) {
			d_num_cards++;
			dealer_cards[d_num_cards - 1] = draw_card(10);
			d_sum = sum_cards(d_sum, dealer_cards[d_num_cards - 1]);
			print_dealer_turn(dealer_cards, d_num_cards, d_sum, 1);
		}
		// stand
		else {
			dealer_turn = 0;
			print_dealer_turn(dealer_cards, d_num_cards, d_sum, 0);
			break;
		}

		// if dealer goes over 21, end dealer's turn, player wins
		if (d_sum > 21) {
			dealer_turn = 0;
			game_result = 1;
			break;
		}

		// if dealer gets exactly 21, end dealer's turn, dealer wins
		if (d_sum == 21) {
			dealer_turn = 0;
			game_result = 2;
			break;
		}
	}

	if (!game_result) {
		// the dealer has less than 21.
		// if the dealer and the player tie, they tie
		if (d_sum == p_sum) {
			game_result = 3;
		}

		// if dealer has more than the player, the dealer wins
		if (d_sum > p_sum) {
			game_result = 2;
		}

		// if player has more than the dealer, the player wins
		if (p_sum > d_sum) {
			game_result = 1;
		}
	}

	switch (game_result) {
	case 1: printf("You the player wins!!\n");
		break;
	case 2: printf("The dealer wins! (You lose)\n");
		break;
	case 3: printf("You both tie!!");
		break;
	default: printf("YOU BROKE THE GAME WAHOOOOO\n");
	}

	return 0;
}