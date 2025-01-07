/*
- Logan Meyers
- 09/27/2024
- Lecture Program

- Description: This program is supposed to play the game BlackJack, which should be similar in feel
               to the PA 4 we are going to make soon.
*/

#ifndef BLACKJACK_H
#define BLACKJACK_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h> // rand(), srand()
#include <time.h>  // time()

#define ACE 1

int draw_card(int range);
void print_card(int card_number);
int sum_card(int sum, int card_num);

void divide(int n1, int n2, int *result_ptr, int *remainder_ptr);

int calc_sum_digits(int number);

#endif