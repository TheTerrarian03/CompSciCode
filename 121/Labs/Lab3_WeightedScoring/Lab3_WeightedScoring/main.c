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

int main() {
    double exam1, exam2, lab1, lab2, project1, project2;
    double exam_avg, lab_avg, proj_avg;
    double weighted_avg;
    
    // prompt instructions
    prompt_instructions();

    // get inputs from user
    // exams
    exam1 = get_score();
    exam2 = get_score();
    // labs
    lab1 = get_score();
    lab2 = get_score();
    // projects
    project1 = get_score();
    project2 = get_score();

    // calculate averages
    // exams
    exam_avg = average_scores(exam1, exam2);
    // labs
    lab_avg = average_scores(lab1, lab2);
    // projects
    proj_avg = average_scores(project1, project2);

    // calculate weighted average
    weighted_avg = calc_weighted_average(exam_avg, lab_avg, proj_avg);

    // output results
    output_results(exam_avg, lab_avg, proj_avg, weighted_avg);

    return 0;
}