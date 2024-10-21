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

// Tasks
void task1() {
    FILE* infile = fopen("inputs.txt", "r");

    int valid_ints = find_num_valid_ints(infile);

    int array[150];

    fclose(infile);
    FILE* infile2 = fopen("inputs.txt", "r");

    populate_array(array, valid_ints, infile2);

    printf("Before array:\n");
    print_int_array(array, valid_ints);

    reverse_array(array, valid_ints);

    printf("\nAfter Reversal:\n");
    print_int_array(array, valid_ints);
}

void task2() {
    char array[17] = {'C', 'p', 't', 'S', ' ', ' ', ' ', '1', '2', '1', ' ', 'i', 's', ' ', 'f', 'u', 'n'};
    int array_size = sizeof(array) / sizeof(array[0]);

    printf("Before Whitespace Removal:\n- ");
    print_char_array(array, array_size);
    printf("\n\n");

    int removed_whitespaces = remove_whitespace(array, array_size);
    printf("Removed whitespaces: %d\n", removed_whitespaces);

    printf("\nAfter Whitespace Removal:\n- ");
    print_char_array(array, array_size);
    printf("\n\n");
}

void task3() {
    srand((unsigned int) time(NULL));
    
    int num_array[20] = {0};
    int freaky_array[101] = {0};
    
    for (int i=0; i<20; i++) {
        num_array[i] = (rand() % 100) + 1;
    }

    printf("Number array:\n");
    print_int_array(num_array, 20);
    
    for (int i=0; i<20; i++) {
        freaky_array[num_array[i]]++;
    }

    printf("\nFreaky array:\n");
    // print_int_array(freaky_array, 101);
    print_int_array_nonzero(freaky_array, 101);
}

void task4() {
    printf("----- Welcome to Hangman! -----\n");
    printf("You have to guess a random 6-letter word.\n");

    // char word = ['']
}
