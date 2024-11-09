/*
- Logan Meyers
- 11/07/2024
- Lab Section 12
- TA: JAMESSS

- Description: Battle Ship game! Player vs computer
*/

#include "pa6.h"

/* ----- Display ----- */
void print_board(char *player_data, int rows, int columns) {

}

/* ----- Board Manipulation ----- */
void init_board(Player_data *player_data) {
    for (int row=0; row<MAX_ROWS; row++) {
        for (int col=0; col<MAX_COLUMNS; col++) {
            *player_data->board[row][col]->row = row;
            *player_data->board[row][col]->column = col;
            *player_data->board[row][col]->status_char = '-';
        }
    }
}

/* ----- Player Data Manipulation ----- */
void init_player_data(Player_data *p_data);
void update_player_stats(Player_data *p_data);

/* ----- Input from Player ----- */

/* ----- Output to Files ----- */