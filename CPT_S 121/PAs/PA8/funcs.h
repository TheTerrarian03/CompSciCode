#ifndef FUNCS_H
#define FUNCS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Occurences Struct
typedef struct occurences {
    int num_occurences;
    double frequency;
} Occurences;

// OTHER FUNCTIONS
void print_int_arr(int *arr, int len);
void print_str_arr(char **arr, int len);

// TASK FUNCTIONS
/*
Name: my_str_n_cat
Description: Concatenates at most n characters of a string to the end of another string (array)
Parameter: char *dest_arr: 
    PRE-REQ: must be an array (char array[#] = {...}), not a char *string = "stuff here" type.
    PRE-REQ: must terminate with a null character (ideally at the spot you want to concat to)
Parameter: char *src_string: 
    PRE-REQ: may be either a string or character array (should be terminate with null character)
Parameter: int n: the max amount of characters to concat. (<= n)
Returns: char *pointer to the destination array (same as pointer passed in)
*/
char *my_str_n_cat(char *dest_arr, char *src_string, int n);

/*
Name: binary_search
Description: Searched for the given value in the values
Parameter: int *sorted_values: the array of values to search through
    PRE-REQ: the length of the array MUST be >= num_values!
Parameter: int num_values: the max number of values to search
    PRE-REQ: should be >= 0
Parameter: int target: the target value to search for
Returns: integer for index of target. Offset by 1:
            0 means false, not fonud.
         >= 1 means true,  found at index of that number minus 1
*/
int binary_search(int *sorted_values, int num_values, int target);

/*
Name: bubble_sort
Description: Sort the given list of string pointers using the Bubble Sort algorithm
Parameter: int num_strings: length of your list of string pointers
    PRE-REQ: should be >= 0
Parameter: char *strings[]: list of pointers to your strings
    PRE-REQ: length of the list MUST be >= num_strings
*/
void bubble_sort(int num_strings, char *strings[]);


int is_palindrome(char *str, int len);
int sum_primes(unsigned int n);
void maximum_occurences(char *str, Occurences *occur_arr[], int *int_ptr, char *char_ptr);
void max_consequtive_integers(signed int *integer_arr, int rows, int columns, int **first_int, int *num_int_row);

#endif