/*
Name: Logan Meyers
Date: 10/16/2024
Program: BlackJack

Description: Plays Black Jack!
*/

#ifndef BLACK_JACK_H
#define BLACK_JACK_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h> // rand (), srand ()
#include <time.h> // time ()

#define ACE 1
#define TWO 2
#define THREE 3
#define FOUR 4
#define FIVE 5
#define SIX 6
#define SEVEN 7
#define EIGHT 8
#define NINE 9
#define SPECIAL 10

#define NUM_CARDS_IN_ARRAY 11

// printing functions

// Name: print_card
// Description: prints a card as a string using a switch case
// Parameter: int card_num for the value of a card
void print_card(int card_num);

// Name: print_array
// Description: prints an array of ints
// Parameter: int *to_print array of ints to print
// Parameter: int size, number of ints to print
void print_array(int* to_print, int size);

// Name: print_player_turn
// Description: prints information about the player's turn
// Parameter: int *dealer_cards, the array of ints representing the dealer's cards
// Parameter: int num_dealer_cards, how many to print from the array
// Parameter: int dealer_sum, the sum of their cards
// Parameter: int *player_cards, the array of ints representing the player's cards
// Parameter: int num_player_cards, how many to print from the array
// Parameter: int player_sum, the sum of their cards
void print_player_turn(int* dealer_cards, int num_dealer_cards, int dealer_sum, int* player_cards, int num_player_cards, int player_sum);

// Name: print_dealer_turn
// Description: prints information about the dealer's turn
// Parameter: int *dealer_cards, the array of ints representing the dealer's cards
// Parameter: int num_dealer_cards, how many to print from the array
// Parameter: int dealer_sum, the sum of their cards
// Parameter: int decision, 0 for the dealer stands, 1 for the dealer hits
void print_dealer_turn(int* dealer_cards, int num_dealer_cards, int dealer_sum, int decision);

// card handling functions

// Name: draw_card
// Description: draws a random card
// Parameter: int range, the range of values to draw from, [1, range]
// Returns: int representing card value
int draw_card(int range); // range represents the card number range: 1 through range

// Name: sum_cards
// Description: Sums two values
// Parameter: int card1, first num to sum
// Parameter: int card2, second num to sum
int sum_cards(int card1, int card2);

// Name: ask_hit
// Description: ask if the player wants to draw or stand
// Returns: char representing choice. y for hit, n for stand
char ask_hit();

#endif