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
// #define DEBUG_MAX_ROUNDS 15
#define PLAYER_CHEAT     0  // set to 1 if you want to see the computer's board
#define MAX_ROWS        10  // precondition: 6 <= MAX_ROWS <= 99
#define MAX_COLUMNS     10  // precondition: 6 <= MAX_COLUMNS <= 99

#if (MAX_COLUMNS <= 10)
    #define COL_SPACING 2
#else
    #define COL_SPACING 3
#endif

#define WATER_CHAR   '-'

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
// Name: seeds random
// Description: seeds rand, duh (sorry)
void seed_rand();

// Name: rand_range
// Description: generates a random number within a given range
// Parameter: int range, max number (exclusive)
// Returns: 0 <= int result < range
int rand_range(int range);

/* ----- Display ----- */
// Name: print_board
// Description: Prints in a board in a nice format
// Parameter: Cell board[MAX_ROWS][MAX_COLUMNS], the board to print
// Parameter: char *name, the name to print above the board
//            (should be less that 20 chars long)
// Parameter: int ignore_ships; 0 for print ships, 1 for don't print ships
void print_board(Cell board[MAX_ROWS][MAX_COLUMNS], char *name, int ignore_ships);

// Name: manual_ship_placement
// Description: Entire process for guiding the user through placing all 5 ships
// Parameter: Cell board[MAX_ROWS][MAX_COLUMNS], board to place ships on
void manual_ship_placement(Cell board[MAX_ROWS][MAX_COLUMNS]);

// Name: ask_x_y_shot
// Description: Asks for x, y coordinate (player scope) to shoot at.
//              Re-asks for inputs if they're out of range or invalid
// Parameter: int *x, address to store x value in
// Parameter: int *y, address to store y value in
void ask_x_y_shot(int *x, int *y);

/* ----- Board Manipulation ----- */
// Name: init_board
// Description: inits player board to water char
// Parameter: Player_data* p_data, the address of the struct to init the board of
void init_board(Player_data* p_data);

// Name: determine_ship_placement_valid
// Description: determins if a ship placement is valid
//              (not out of bounds, and not colliding with existing ships)
// Parameter: Cell board[MAX_ROWS][MAX_COLUMNS], board for reference
// Parameter: int left_x of the ship to place
// Parameter: int top_y of the ship to place
// Parameter: int vertical; 1 for vertical, 0 for horizontal
// Parameter: int len of the ship
// Returns: 1 for valid, 0 for invalid
int determine_ship_placement_valid(Cell board[MAX_ROWS][MAX_COLUMNS], int left_x, int top_y, int vertical, int len);

// Name: place_single_ship
// Description: Places a ship on the board
// Parameter: Cell board[MAX_ROWS][MAX_COLUMNS], board for reference
// Parameter: int left_x of the ship to place
// Parameter: int top_y of the ship to place
// Parameter: int vertical; 1 for vertical, 0 for horizontal
// Parameter: int len of the ship
// Parameter: char symbol of the ship
void place_single_ship(Cell board[MAX_ROWS][MAX_COLUMNS], int left_x, int top_y, int vertical, int len, char symbol);

// Name: place_ships_randomly
// Description: Places ships on a board manually,
//              with out-of-bounds and overlap protection
// Parameter: Cell board[MAX_ROWS][MAX_COLUMNS] to place ships on
void place_ships_randomly(Cell board[MAX_ROWS][MAX_COLUMNS]);

// Name: make_ship
// Description: Makes a shot on a board, and determines results
// Parameter: Cell board[MAX_ROWS][MAX_COLUMNS] to shoot at
// Parameter: int x to shoot at
// Parameter: int y to shoot at
// Returns: 's' if sink, '*' if hit, 'm' if miss
char make_shot(Cell board[MAX_ROWS][MAX_COLUMNS], int x, int y);

// Name: count_symbols_left
// Description: Counts how many ship symbols left on a board
// Parameter: Cell board[MAX_ROWS][MAX_COLUMNS] to count ship symbols on
// Parameter: char symbol to count
// Returns: count of that symbol left on the board (> 0)
int count_symbols_left(Cell board[MAX_ROWS][MAX_COLUMNS], char symbol);

// Name: count_all_symbols_left
// Description: Counts all ship symbols left on a board
// Parameter: Cell board[MAX_ROWS][MAX_COLUMNS] to count ship symbols on
// Returns: count of all types of symbols left on the board (> 0)
int count_all_symbols_left(Cell board[MAX_ROWS][MAX_COLUMNS]);

/* ----- Player Data Manipulation ----- */
// Name: init_player_data
// Description: inits player struct data, all to zero's and water_chars for the board
// Parameter: Player_data* p_data, the address of the struct to init
// [UPDATED 11/13]
void init_player_data(Player_data *p_data);

// Name: update_player_stats
// Description: updates player stats (such as hit and miss data)
// Parameter: Player_data *p_data, address of player data to update
// Parameter: char shot_result, '*' or 's' or 'm'
// [UPDATED 11/13]
void update_player_stats(Player_data *p_data, char shot_result);

/* ----- Game State Stuff ----- */
// Name: determine_winner
// Description: Determines winner (if any)
// Parameter: Player_data *p1_data, address of player 1 data
// Parameter: Player_data *p2_data, address of computer data
// Returns: 3 if both lost, 2 if computer win, 1 if player 1, 0 if no winner yet
int determine_winner(Player_data *p1_data, Player_data *p2_data);

/* ----- Input from Player ----- */
// Name: ask_enter
// Description: Like a system("pause") for any OS. suppost to wait until enter is pressed
// Parameter: char *prompt_str, the prompt to display before waiting
void ask_enter(char *prompt_str);

/* ----- Output to Files ----- */
// Name: log_clearfile
// Description: Clears log file. Simply opens in write mode and closes.
void log_clearfile();

// Name: log_data
// Description: logs a play during the game
// Parameter: char *player_name_str, player name to display in data log
// Parameter: char shot_result, 's' or '*' or 'm' for which message to display
// Parameter: int x of shot
// Parameter: int y of shot
void log_data(char *player_name_str, char shot_result, int x, int y);

// Name: log_winner
// Description: logs the winner of a game
// Parameter: char *winner_name_str, name of who won
// Parameter: int ship_cells_left of winner
// [UPDATED 11/13]
void log_winner(char *winner_name_str, int ship_cells_left);

// Name: log_player_data
// Description: logs the struct data of the player in the logfile
// Parameter: Player_data *p_data to log
// Parameter: char *player_name_str of the player in question
// [ADDED 11/13]
void log_player_data(Player_data *p_data, char *player_name_str);

#endif