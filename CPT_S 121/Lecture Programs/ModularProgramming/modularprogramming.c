/*
yeah
*/

#include "modularprogramming.h"

void divide(int n1, int n2, int *result_ptr, int *remainder_ptr) {
    *result_ptr = n1 / n2;
    *remainder_ptr = n1 % n2;
}

void discount(double cost, int num_people, int* discount_ptr, double* amount_ptr) {
    if (cost > 2000) {
        *discount_ptr = 10;
        *amount_ptr = cost * ((double) *discount_ptr / 100);
    } else if (cost > 1000) {
        *discount_ptr = 5;
        *amount_ptr = cost * ((double) *discount_ptr / 100);
    }
}

// precondition: size < max size
void init_array(int arr[], int size) {
    int index = 0;

    while (index < size) {
        printf("Enter an integer please: ");
        scanf("%d", &arr[index]);
        index++;
    }
}

// precondition: size < max size
void print_array(int arr[], int size) {
    int index = 0;

    for (; index<size; index++) {
        printf("arr[%d]: %d\n", index, arr[index]);
    }
}
