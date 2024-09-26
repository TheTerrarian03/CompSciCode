/*
- Logan Meyers
- 09/19/2024
- Lab 4, Section #12
- Lab 4 Solution

- This is my solution for Lab 4. It calculates the calorie need based on a person's characteristics.
*/

#ifndef LAB4_H
#define LAB4_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define INFILE_NAME "stats.txt"

double read_double(FILE* infile);
int read_int(FILE* infile);
char read_char(FILE* infile);

double calc_women_bmr(double weight_lbs, double height_in, double age);
double calc_men_bmr(double weight_lbs, double height_in, double age);

double calculate_cal_from_activity_and_bmr(int activity_lvl, double bmr);

#endif