#include <stdio.h>

#define ROWS 5
#define COLUMNS 5

void print_matrix(int rows, int columns, int matrix[rows][columns]);
void reverse_matrix(int rows, int columns, int to_reverse[rows][columns]);

int main() {
    int to_reverse[ROWS][COLUMNS] = {{6, 1, 7, 4, 2},
                                     {7, 5, 2, 3, 8},
                                     {9, 9, 1, 1, 5},
                                     {1, 2, 3, 4, 5},
                                     {9, 7, 5, 3, 1}};

    print_matrix(ROWS, COLUMNS, to_reverse);
    printf("\n\n");

    reverse_matrix(ROWS, COLUMNS, to_reverse);

    print_matrix(ROWS, COLUMNS, to_reverse);
    
    return 0;
}

void print_matrix(int rows, int columns, int matrix[rows][columns]) {
    for (int row=0; row < rows; row++) {
        for (int col=0; col < columns; col++) {
            printf("%2d ", matrix[row][col]);
        }
        printf("\n");
    }
}

void reverse_matrix(int rows, int columns, int to_reverse[rows][columns]) {
    // iterate through each row
    for (int row = 0; row < rows; row++) {
        // define what index the opposite row is at
        int back_row = rows-row-1;

        // break out of loop if past the halfway point
        if (back_row <= row) break;

        // iterate through each column
        for (int col = 0; col < columns; col++) {
            // reverse values by using a monkey in the middle
            int tmp = to_reverse[back_row][col];
            to_reverse[back_row][col] = to_reverse[row][col];
            to_reverse[row][col] = tmp;
        }
    }
}
