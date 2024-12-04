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

// TASK FUNCTIONS
char *my_str_n_cat(char *dest_arr, char *src_string, int n);
int binary_search(int *sorted_values, int target);
void bubble_sort(int num_strings, char *strings[]);
int is_palindrome(char *str, int len);
int sum_primes(unsigned int n);
void maximum_occurences(char *str, Occurences *occur_arr[], int *int_ptr, char *char_ptr);
void max_consequtive_integers(signed int *integer_arr, int rows, int columns, int **first_int, int *num_int_row);

#endif