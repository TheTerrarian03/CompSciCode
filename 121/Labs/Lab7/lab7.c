/*
- Logan Meyers
- 10/10/2024
- LAB 7
*/

#include "lab7.h"

double read_double(FILE* infile) {
    double tmp = 0.0;
    fscanf(infile, "%lf", &tmp);
    return tmp;
}

int read_int(FILE* infile) {
    int tmp = 0;
    fscanf(infile, "%d", &tmp);
    return tmp;
}

void get_initials(char* first_ptr, char* middle_ptr, char* last_ptr) {
    // prompt user for initials and
    // return the characters indirectly through the output parameters
    printf("Enter a first initial: ");
    scanf(" %c", first_ptr);

    printf("\nEnter a middle initial: ");
    scanf(" %c", middle_ptr);
    
    printf("\nEnter a last initial: ");
    scanf(" %c", last_ptr);
}

void charges(double* total_charge, double hours_per_month, double* average_cost) {
    if (hours_per_month <= 10) {
        *total_charge = 7.99;
        *average_cost = 7.99 / hours_per_month;
    } else if (hours_per_month > 10) {
        *total_charge = 7.99 + (1.99 * (hours_per_month - 10));
        *average_cost = *total_charge / hours_per_month;
    }
}