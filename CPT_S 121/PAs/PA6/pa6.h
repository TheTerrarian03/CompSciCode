/*

*/

#ifndef PA6_H
#define PA6_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLUMNS 10

// player data struct
typedef struct {
    char board[MAX_ROWS][MAX_COLUMNS];
    int hits;
    int losses;
} player_data_t;

// board functions
void print_board(char board[][MAX_COLUMNS], int rows, int columns);
void init_board(char board[][MAX_COLUMNS], int rows, int columns, char fill_symbol);

#endif