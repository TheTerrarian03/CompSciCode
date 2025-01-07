#ifndef LAB_10_H
#define LAB_10_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define WORD_LEN 20

void miles_code();

// task 1
// make_sent

// task 2
typedef struct coordinate {
    int row;
    int column;
} Coordinate;

typedef struct cell {
    int occupied; // 1 if an X or O is in the cell, 0 otherwise
    char symbol; // X for one player, O for the other player
    Coordinate location;  // a struct defined above, the position of a cell in the game board
} Cell;

typedef struct game_info {
    int wins;
    int losses;
    int total_games_played;
} Game_info;

int ask_n();

void fill_board(Cell board[10][10], int n);

void place_symbol_p_pov(Cell board[10][10], int n, int row, int col, char symbol);

void print_board(Cell board[10][10], int n);

#endif