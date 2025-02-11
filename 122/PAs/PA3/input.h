/*
- Name: Logan Meyers
- TA: Martin "Double Factorial" Hundrup
- Assignment: PA 3
- [Mostly] Finished: 02/10/2025
- Description: Digital Music Manager!

- File: input.h
- Description: headers and declerations for my input functions
*/

#ifndef INPUT_H
#define INPUT_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

/*
 * Function: clear_buffer
 * --------------------
 *   Simple while loop to get all characters until stdin has no
 *   more input to be read
 * 
*/
void clear_buffer();

/*
 * Function: get_pos_int_loop
 * --------------------
 *   Input verification loop for getting a positive (>0) integer from the user.
 * 
 *   Parameters:
 *   - line_prompt: the string to print at the beginning of getting input from the user
 * 
 *   Returns:
 *   - the user's choice number
*/
int get_pos_int_loop(const char *line_prompt);

/*
 * Function: get_pos_int_range_loop
 * --------------------
 *   Input verification loop for getting an int within a range
 * 
 *   Parameters:
 *   - line_prompt: the string to print at the beginning of input getting
 *   - min: min num for the range, must be 1 more than the absolute min of the type int
 *   - max: max number for the range
 * 
 *   Returns:
 *   - the user's choice number
*/
int get_pos_int_range_loop(const char *line_prompt, int min, int max);

/*
 * Function: copy_nstring
 * --------------------
 *   Copies a whole input line from the user, replacing the newline with a null char
 * 
 *   Parameters:
 *   - dest: string array to copy input to
 *   - n: max number of chars to read + copy
 * 
*/
void cpy_nstring(char *dest, int n);

/*
 * Function: cpy_nstring_if_exist
 * --------------------
 *   Copies a whole line from the user, with null char instead of newline, if text other than enter was entered
 * 
 *   Parameters:
 *   - dest: string array to copy input to
 *   - n: max number of chars to read + copy
 * 
*/
void cpy_nstring_if_exist(char *dest, int n);

/*
 * Function: set_int_in_range_if_exist
 * --------------------
 *   Combination of cpy_nstring_if_exist and get_pos_int_range_loop
 * 
 *   Parameters:
 *   - line_prompt: string to print at beginning of input getting
 *   - *num: pointer to int to set new data to
 *   - min: min of range
 *   - max: max of range
 * 
 *   Returns:
 *   - how many (valid) records were read
*/
void set_int_in_range_if_exist(char *line_prompt, int *num, int min, int max);

#endif