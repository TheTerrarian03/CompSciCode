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

/* ----- Definitions ----- */
#define MAX_ROWS 10
#define MAX_COLUMNS 10

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

/* ----- Display ----- */
void print_board(Cell* board, char* name);

/* ----- Board Manipulation ----- */
void init_player_data(Player_data* p_data);

/* ----- Player Data Manipulation ----- */
void init_player_data(Player_data *p_data);
void update_player_stats(Player_data *p_data);

/* ----- Input from Player ----- */

/* ----- Output to Files ----- */

#endif PA6_H