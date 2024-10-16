#ifndef BLACK_JACK_4_H
#define BLACK_JACK_4_H

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

// card handling functions
int draw_card(int range); // range represents the card number range: 1 through range
void print_card(int card_num);
int sum_cards(int card1, int card2);

// logic functions

// 0 for dealer
// 1 for player
// 2 for tie
int determine_winner(int dealer_sum, int player_sum);

char ask_hit();

#endif