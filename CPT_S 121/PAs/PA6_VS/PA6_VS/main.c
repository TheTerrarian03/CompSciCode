/*
- Logan Meyers
- 11/07/2024
- Lab Section 12
- TA: JAMESSS

- Description: Battle Ship game! Player vs computer
*/

#include "pa6.h"

int main() {
    Player_data p1;  // player
    Player_data p2;  // computer

    // init player data (including boards)
    init_player_data(&p1);
    init_player_data(&p2);

    //printf("Player Hits: %d\n", p1.hits);

    //for (int i = 0; i < MAX_ROWS; i++) {
    //    for (int j = 0; j < MAX_COLUMNS; j++) {
    //        printf("Row: %d, Column: %d, State: %c\n", p1.board[i][j].row, p1.board[i][j].column, p1.board[i][j].status_char);
    //    }
    //}

    print_board(p1.board, "Player");
    print_board(p2.board, "Computer");


    return 0;
}
