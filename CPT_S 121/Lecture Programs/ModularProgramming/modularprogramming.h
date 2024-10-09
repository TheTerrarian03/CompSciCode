/*
yeah
*/

#ifndef MODULER_PROGRAMMING_H
#define MODULER_PROGRAMMING_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void divide(int n1, int n2, int *result_ptr, int *remainder_ptr);
void discount(double cost, int num_people, int* discount_ptr, double* amount_ptr);

void init_array(int arr[], int size);
void print_array(int arr[], int size);

#endif