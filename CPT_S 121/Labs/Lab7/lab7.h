/*
- Logan Meyers
- 10/10/2024
- LAB 7
*/

#ifndef LAB7_H
#define LAB7_H

#include <stdio.h>

// basic functions
double read_double(FILE* infile);
int read_int(FILE* infile);


// problem 1
void get_initials(char* first_ptr, char* middle_ptr, char* last_ptr);

// problem 2
void charges(double* total_charge, double hours_per_month, double* average_cost);

// problem 3
void revenue(double t, double* R);
void predict()

#endif