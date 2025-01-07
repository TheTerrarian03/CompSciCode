#include "lab10.h"

void miles_code() {
    char choice, player_choice;
    int win_condition;
    
    do
    {
        player_choice = rand() % 2 + 1;

        do
        {
            if (player_choice == 1)
            {
                printf("Player 1, who uses X, goes first");


            }
            else
            {
                printf("Player 2, who uses O, goes first");

            }


        } while (win_condition != 1);

        printf("Do you want to keep playing?(answer y or n) \n");
        scanf(" %c", &choice);


    } while(choice != 'n');
}

int ask_n() {
    int n = -1;
    
    do {
        printf("Please enter how many nxn tiles you want to use:\nn: ");
        int result = scanf("%d", &n);

        if (result != 1) {
            while (getchar() != '\n');
            printf("Please enter a positive integer!\n\n");
            continue;
        }

        if (n < 1 || n > 10) {
            printf("Please enter a value of n between 1 and 10!\n\n");
            n = -1;
        }
    } while (n < 1 || n > 10);

    return n;
}

void fill_board(Cell board[10][10], int n) {
    for (int row=0; row<n; row++) {
        for (int col=0; col<n; col++) {
            Cell cell = {.location={.row=row, .column=col}, .occupied=0, .symbol='X'};
            board[row][col] = cell;
        }
    }
}

void place_symbol_p_pov(Cell board[10][10], int n, int row, int col, char new_sym) {
    board[row-1][col-1].symbol=new_sym;
}

void print_board(Cell board[10][10], int n) {
    for (int row=0; row<n; row++) {
        for (int col=0; col<n; col++) {
            if (board[row][col].symbol == '\0') printf("   ");
            else printf(" %c ", board[row][col].symbol);
            if (col < n-1) printf("|");
        }
        if (row<n-1) {
            printf("\n");
            for (int i=0; i<n; i++) {
                printf("---");
                if (i < n-1) printf("+");
            }
            printf("\n");
        }
        else printf("\n");
    }
}