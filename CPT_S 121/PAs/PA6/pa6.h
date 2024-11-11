/*
- Logan Meyers
- 11/07/2024
- Lab Section 12
- TA: JAMESSS

- Description: Battle Ship game! Player vs computer
*/

#ifndef PA6_H
#define PA6_H

#define _CRT_SECURE_NO_WARNINGS

/* ----- Includes ----- */
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

/* ----- Definitions ----- */
// #define DEBUG_MSGS
#define MAX_ROWS 10
#define MAX_COLUMNS 10
#define WATER_CHAR '-'

/* ----- Structs ----- */
// board cell
typedef struct {
    int row;
    int column;
    char status_char;
} Cell;

// player stats
typedef struct {
    Cell board[MAX_ROWS][MAX_COLUMNS];
    int hits;
    int misses;
    int total_shots;
    int hit_miss_ratio;
    char win_loss_status;
} Player_data;

/* ----- Random ----- */
void seed_rand();
int rand_range(int range);

/* ----- Display ----- */
void print_board(Cell board[MAX_ROWS][MAX_COLUMNS], char *name, int ignore_ships);
void manual_ship_placement(Cell board[MAX_ROWS][MAX_COLUMNS]);
void ask_x_y_shot(int *x, int *y);

/* ----- Board Manipulation ----- */
void init_player_data(Player_data* p_data);
int determine_ship_placement_valid(Cell board[MAX_ROWS][MAX_COLUMNS], int left_x, int top_y, int vertical, int len);
void place_single_ship(Cell board[MAX_ROWS][MAX_COLUMNS], int left_x, int top_y, int vertical, int len, char symbol);
void place_ships_randomly(Cell board[MAX_ROWS][MAX_COLUMNS]);
int determine_hit(Cell board[MAX_ROWS][MAX_COLUMNS], int x, int y);
char make_shot(Cell board[MAX_ROWS][MAX_COLUMNS], int x, int y);
int count_symbols_left(Cell board[MAX_ROWS][MAX_COLUMNS], char symbol);
int count_all_symbols_left(Cell board[MAX_ROWS][MAX_COLUMNS]);

/* ----- Player Data Manipulation ----- */
void init_player_data(Player_data *p_data);
void update_player_stats(Player_data *p_data);

/* ----- Game State Stuff ----- */
int detemine_winner(Player_data *p1_data, Player_data *p2_data);

/* ----- Input from Player ----- */

/* ----- Output to Files ----- */

#endif