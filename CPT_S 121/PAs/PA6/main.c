/*

*/

#include "pa6.h"

int main() {
    player_data_t player_data;

    int matrix[3][5] = {{0, 1, 2, 3, 4}, {0}, {0}};

    // rows, cols
    // char p1_board[MAX_ROWS][MAX_COLUMNS];
    player_data.hits = 5;
    player_data.losses = 69;

    init_board(player_data.board, MAX_ROWS, MAX_COLUMNS, '~');

    print_board(player_data.board, MAX_ROWS, MAX_COLUMNS);

    return 0;
}