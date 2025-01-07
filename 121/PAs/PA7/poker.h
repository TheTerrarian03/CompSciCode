/*
- Name:      Logan Meyers
- Date:      11/20/2024
- TA:        JAMES!
- Assigment: PA 7
- Project:   Poker! Player vs Computer

- Description: Play poker against a computer!
*/

#ifndef POKER_H
#define POKER_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* ----- Definitions ----- */
typedef struct {
    int row_idx;
    int col_idx;
} Card;

typedef struct {
    Card cards[5];
} Hand;

/* ----- Starting Code ----- */
void shuffle (int wDeck[4][13]);
// void deal (const int wDeck[][13], const char *wFace[], const char *wSuit[]);
void deal_to_hand(const int wDeck[4][13], Hand *hand, int num_to_deal, int *start_card);
void deal_next_card(const int wDeck[4][13], Hand *hand, int hand_slot, int *start_card);

/* ----- Card Functions ----- */
void print_all_cards(const char *wFace[], const char *wSuit[], Hand hand);
void print_card(const char *wFace[], const char *wSuit[], Card to_print);
void print_card_num(int num);

/* ----- Hand Checks ----- */
int check_pair(Hand hand);
int check_2_pairs(Hand hand);
int check_3_kind(Hand hand);
int check_4_kind(Hand hand);
int check_full_house(Hand hand);
int check_flush(Hand hand);
int check_straight(Hand hand);

/* ----- Play Turns ----- */
void player_turn(const int wDeck[4][13], const char *wFace[], const char *wSuit[], Hand *hand, int *start_card);
void dealer_turn(const int wDeck[4][13], const char *wFace[], const char *wSuit[], Hand *hand, int *start_card);
void dealer_change_cards(const int wDeck[4][13], const char *wFace[], const char *wSuit[], Hand *hand, int *start_card);

#endif
