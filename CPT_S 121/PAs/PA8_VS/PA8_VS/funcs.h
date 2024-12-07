#ifndef FUNCS_H
#define FUNCS_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Occurences Struct
typedef struct occurences {
    int num_occurences;
    double frequency;
} Occurences;

// OTHER FUNCTIONS
int print_int_arr(int *arr, int len);
int print_str_arr(char **arr, int len);
int nth_prime(unsigned int n);

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
int binary_search(int *sorted_values, int n, int target);

/*
Name: bubble_sort
Description: Sort the given list of string pointers using the Bubble Sort algorithm
Parameter: int num_strings: length of your list of string pointers
    PRE-REQ: should be >= 0
Parameter: char *strings[]: list of pointers to your strings
    PRE-REQ: length of the list MUST be >= num_strings
*/
void bubble_sort(int num_strings, char *strings[]);

/*
Name: is_palindrome
Description: Determine if a given string is a palindrome, excludes whitespace and case doesn't matter
Parameter: char *str: the string up for judging
Parameter: int len: the length of the string (such as from strlen(str))
    PRE-REQ: MUST be <= the actual length of str
*/
int is_palindrome(char *str, int len);

/*
Name: sum_primes
Description: sum of all prime numbers, up to the nth prime number
Parameter: unsigned int n: the nth number cap
Returns: the integer sum of those numbers
*/
int sum_primes(unsigned int n);

/*
Name: maximum_occurences
Description: Determines the occurences and frequencies for each character,
             and their frequency.
Parameter: char *str: the string to count characters of
Parameter: Occurnces occur_arr[128]: the array of struct Occurences, of size ASCII limit
Parameter: int *int_ptr: max count return pointer
Parameter: char *char_ptr: char of max count return pointer
*/
void maximum_occurences(char *str, Occurences occur_arr[128], int *int_ptr, char *char_ptr);
void max_consequtive_integers(signed int *integer_arr, int rows, int columns, int **first_int, int *num_int_row);

#endif