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

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// starting code
void shuffle (int wDeck[][13]);
void deal (const int wDeck[][13], const char *wFace[], const char *wSuit[]);

#endif