/*
- Logan Meyers
- 09/12/2024
- Lab #3, Section 12L

- Description: This program computes weighted scores from exams, labs, and projects
               Exams (2) are worth 30% each
               Labs (2) are worth 5% each
               Projects (2) are worth 15% each
*/

#include "functions.h"

// input functions
double get_score() {
    double temp = 0.0;

    printf("Enter a score here (out of 100): ");
    scanf("%lf", &temp);

    return temp;
}

void prompt_instructions() {
    printf("Hello! You're going to be prompted for 6 scores, one-by-one. Please enter:\n- 2 exams\n- 2 labs\n- 2 projects\n\n");
}

// calculation functions
double average_scores(double score1, double score2) {
    return (score1 + score2) / 2;
}

double calc_weighted_average(double exam_avg, double lab_avg, double proj_avg) {
    return (exam_avg * 0.6) + (lab_avg * 0.1) + (proj_avg * 0.3);
}

// output functions
void output_results(double exam_avg, double lab_avg, double proj_avg, double weighted_avg) {
    printf("\nHere are your results:");
    printf("\n- Exam Average: %lf", exam_avg);
    printf("\n- Lab Average: %lf", lab_avg);
    printf("\n- Project Average: %lf", proj_avg);
    printf("\n- Weighted Average: %lf", weighted_avg);
}