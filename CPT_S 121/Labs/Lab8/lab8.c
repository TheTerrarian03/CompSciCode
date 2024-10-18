#include "lab8.h"

void print_int_array(int *array, int length) {
    for (int i=0; i<length; i++) {
        printf("%d: %d\n", i, array[i]);
    }
}

void print_int_array_nonzero(int *array, int length) {
    for (int i=0; i<length; i++) {
        if (array[i] != 0) printf("%d: %d\n", i, array[i]);
    }
}

void print_char_array(char *array, int length) {
    for (int i=0; i<length; i++) {
        printf("%c", array[i]);
    }
}

// Task 1
int find_num_valid_ints(FILE *infile) {
    int valid_ints = 0;
    
    while (1) {
        int num;
        int result = fscanf(infile, "%d", &num);

        if (result != 1) {
            break;
        }

        valid_ints++;
    }

    return valid_ints;
}

void populate_array(int *array, int num_ints, FILE *infile) {
    for (int i=0; i < num_ints; i++) {
        fscanf(infile, "%d", &array[i]);
    }
}

void reverse_array(int *array, int num_ints) {
    int left = 0, right = num_ints-1, temp = 0;

    while (left < right) {
        temp = array[right];
        array[right] = array[left];
        array[left] = temp;

        left++;
        right--;
    }
}

// Task 2
int remove_whitespace(char *array, int length) {
    int removed_whitespaces = 0;

    // interate through all pieces in the array
    for (int i=0; i<length; i++) {
        // deetermine if the char is whitespace
        if (array[i] == ' ' || array[i] == '\t' || array[i] == '\n') {
            printf("Found whitespace at index: %d\n", i);

            // if so, increment removed_whitespaces
            removed_whitespaces++;

            // iterate through all remainging characters and shift them over
            for (int j = i; j<length; j++) {
                array[j] = array[j+1];
            }

            // Decrement i to make sure to check the same spot again incase there are > 1 whitespace
            i--;
        }
    }

    return removed_whitespaces;
}