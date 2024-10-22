#include <stdio.h>

void reverse_matrix(int to_reverse[][], int rows, int columns);

int main() {
    int to_reverse[4][5] = {{6, 1, 7, 4, 2},
                            {7, 5, 2, 3, 8},
                            {9, 9, 1, 1, 5},
                            {1, 2, 3, 4, 5}};

    reverse_matrix(to_reverse, 4, 5);
    
    return 0;
}

void reverse_matrix(int to_reverse[][], int rows, int columns) {
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 5; col++) {
            printf("yeah");
        }
    }
}