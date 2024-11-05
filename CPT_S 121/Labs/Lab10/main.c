#include "lab10.h"

// struct init inline: Student s = {.name: "Logan", .age: 18, .gpa: 3.2};

int main() {
    srand((unsigned int) time(NULL));

    // Task 1
    // char articles[5][WORD_LEN] = {"the", "a", "one", "some", "any"};
    // char noun[5][WORD_LEN] = {"boy", "girl", "dog", "town", "car"};
    // char verb[5][WORD_LEN] = {"drove", "jumped", "ran", "walked", "skipped"};
    // char preposition[5][WORD_LEN] = {"to", "from", "over", "under", "on"};

    // char sentences[20][50] = {""};
    
    // // make random sentences
    // for (int i=0; i<20; i++) {
    //     strcpy(sentences[i], articles[rand() % 5]);
    //     strcat(sentences[i], " ");
    //     strcat(sentences[i], noun[rand() % 5]);
    //     strcat(sentences[i], " ");
    //     strcat(sentences[i], verb[rand() % 5]);
    //     strcat(sentences[i], " ");
    //     strcat(sentences[i], preposition[rand() % 5]);
    //     strcat(sentences[i], " ");
    //     strcat(sentences[i], articles[rand() % 5]);
    //     strcat(sentences[i], " ");
    //     strcat(sentences[i], noun[rand() % 5]);
    //     strcat(sentences[i], "!\0");
    //     sentences[i][0] = toupper(sentences[i][0]);
    // }

    // // print sentences
    // for (int i=0; i<20; i++) {
    //     printf("%s\n", sentences[i]);
    // }

    // Task 2
    int n = ask_n();
    Cell board[10][10];
    Cell *board_ptr = &board;

    fill_board(board, n);
    place_symbol_p_pov(board, n, 2, 2, 'O');
    print_board(board, n);

    printf("\nX: %d, Y: %d, Symbol: %c", board[1][1].location.column, board[1][1].location.row, board[1][1].symbol);
    miles_code();

    return 0;
}