#ifndef LAB8_H
#define LAB8_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_int_array(int *array, int length);
void print_int_array_nonzero(int *array, int length);
void print_char_array(char *array, int length);

// Task 1
int find_num_valid_ints(FILE *infile);
void populate_array(int *array, int num_ints, FILE *infile);
void reverse_array(int *array, int num_ints);

// Task 2
int remove_whitespace(char *array, int size);

// Tasks
void task1();
void task2();
void task3();
void task4();

#endif