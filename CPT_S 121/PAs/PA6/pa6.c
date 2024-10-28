/*

*/

#include "pa6.h"

// board functions
void print_board(char board[][MAX_COLUMNS], int rows, int columns) {
    int row_idx = 0, col_idx = 0;

    printf("%3d%2d%2d%2d%2d%2d%2d%2d%2d%2d\n", 0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
    for (; row_idx<rows; row_idx++) {
        // printf("%d ", row_idx);
        printf("%-2d", row_idx);
        for (int col_idx=0; col_idx<columns; col_idx++) {
            printf("%c ", board[row_idx][col_idx]);
        }
        putchar('\n');  // from stdio.h
    }
}

void init_board(char board[][MAX_COLUMNS], int rows, int columns, char fill_symbol) {
    for (int r=0; r<rows; r++) {
        for (int c=0; c<columns; c++) {
            board[r][c] = fill_symbol;
        }
    }
}