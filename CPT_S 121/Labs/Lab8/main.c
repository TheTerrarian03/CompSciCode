#include "lab8.h"

int main() {
    printf("Welcome to Lab 8! Which task would you like to run?\n");
    printf("1. Read file\n");
    printf("2. Remove Whitespaces\n");
    

    /* ----- Task 1 ------- */
    // FILE* infile = fopen("inputs.txt", "r");

    // int valid_ints = find_num_valid_ints(infile);

    // int array[valid_ints];

    // fclose(infile);
    // FILE* infile2 = fopen("inputs.txt", "r");

    // populate_array(array, valid_ints, infile2);

    // printf("Before array:\n");
    // print_int_array(array, valid_ints);

    // reverse_array(array, valid_ints);

    // printf("\nAfter Reversal:\n");
    // print_int_array(array, valid_ints);

    /* ------ Task 2 ------- */
    // char array[17] = {'C', 'p', 't', 'S', ' ', ' ', ' ', '1', '2', '1', ' ', 'i', 's', ' ', 'f', 'u', 'n'};
    // int array_size = sizeof(array) / sizeof(array[0]);

    // printf("Before Whitespace Removal:\n- ");
    // print_char_array(array, array_size);
    // printf("\n\n");

    // int removed_whitespaces = remove_whitespace(array, array_size);
    // printf("Removed whitespaces: %d\n", removed_whitespaces);

    // printf("\nAfter Whitespace Removal:\n- ");
    // print_char_array(array, array_size);
    // printf("\n\n");

    /* --------- Task 3 -------- */
    // srand((unsigned int) time(NULL));
    
    // int num_array[20] = {0};
    // int freaky_array[101] = {0};
    
    // for (int i=0; i<20; i++) {
    //     num_array[i] = (rand() % 100) + 1;
    // }

    // printf("Number array:\n");
    // print_int_array(num_array, 20);
    
    // for (int i=0; i<20; i++) {
    //     freaky_array[num_array[i]]++;
    // }

    // printf("\nFreaky array:\n");
    // // print_int_array(freaky_array, 101);
    // print_int_array_nonzero(freaky_array, 101);

    /* --------- Task 4 --------- */
    printf("----- Welcome to Hangman! -----\n");
    printf("You have to guess a random 6-letter word.\n");

    char word = ['']
}