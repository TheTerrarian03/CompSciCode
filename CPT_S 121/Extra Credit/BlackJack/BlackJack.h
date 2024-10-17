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
void print_card(int card_num);
void print_array(int *to_print, int size);
void print_player_turn(int *dealer_cards, int num_dealer_cards, int dealer_sum, int *player_cards, int num_player_cards, int player_sum);
void print_dealer_turn(int *dealer_cards, int num_dealer_cards, int dealer_sum, int decision);

// card handling functions
int draw_card(int range); // range represents the card number range: 1 through range
int sum_cards(int card1, int card2);

// 
char ask_hit();

#endif