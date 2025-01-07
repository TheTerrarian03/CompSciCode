#ifndef LAB_11_H
#define LAB_11_H

#define _CRT_SECURE_NO_WARNINGS

#define DEBUG_MESSAGES

#include <stdio.h>
#include <string.h>

typedef struct employee
{
    char name[100];      // employee's name - last, first
    char title;          // title 'B' or 'M'
    double hours_worked; // total number of hours worked
    double payrate;      // pay rate per hour
    double payment;      // total payment for the pay period – you will compute!
} Employee;

void read_name(FILE *infile, Employee *emp);
void read_type(FILE *infile, Employee *emp);
void read_hours(FILE *infile, Employee *emp);
void read_payrate(FILE *infile, Employee *emp);

double calc_payment(char title, double payrate, double hours);

#endif