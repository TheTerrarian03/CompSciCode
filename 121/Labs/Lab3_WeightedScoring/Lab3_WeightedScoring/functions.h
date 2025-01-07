/*
- Logan Meyers
- 09/12/2024
- Lab #3, Section 12L

- Description: This program computes weighted scores from exams, labs, and projects
               Exams (2) are worth 30% each
               Labs (2) are worth 5% each
               Projects (2) are worth 15% each
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// input functions
double get_score();
void prompt_instructions();

// calculation functions
double average_scores(double score1, double score2);
double calc_weighted_average(double exam_avg, double lab_avg, double proj_avg);

// output functions
void output_results(double exam_avg, double lab_avg, double proj_avg, double weighted_avg);