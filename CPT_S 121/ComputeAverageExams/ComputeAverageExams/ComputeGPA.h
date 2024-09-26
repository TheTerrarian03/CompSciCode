/*
- Logan Meyers
- Compute Average Exmans
*/

#define _CRT_SECURE_NO_WARNINGS  // ignore warning with scanf_c methods

#include <stdio.h>  // printf(), scanf()

#define NUM_SCORES 3.0  // NO SEMICOLON HEREEEEE

// function declarations - prototype
double get_grade_point(int class_num);
int compute_sum_credits(int c1, int c2, int c3);
int get_credits(int class_num);
double compute_gpa(double w_gp, int sum_c);
