/*
- Logan Meyers
- 09/26/2024
- Lab 5 Section #12

- Description: bkjbgkdjrhde
*/

#include "Lab5.h"

int main() {
    /* ----- Task 1 ----- */

    // FILE* infile = fopen("salaries.txt", "r");

    // double sum_quarter_amount = 0;
    // double quater_amount = 0;

    // while(!feof(infile)) {
    //     fscanf(infile, "%lf", &quater_amount);
    //     sum_quarter_amount += quater_amount;
    //     printf("Got amount of: %lf\n", quater_amount);
    // }

    // printf("TOTAL: %lf\n", sum_quarter_amount);

    // char tax_bracket = determine_income_bracket(sum_quarter_amount);

    // fclose(infile);

    // printf("Your Tax Bracket: %c\n", tax_bracket);

    /* ----- Task 2 ----- */

    // FILE* infile = fopen("data.txt", "r");
    // FILE* outfile = fopen("output.txt", "w");

    // int sum_numbers = 0, count_numbers = 0;
    // int temp = 0;
    // int average = 0;

    // while (!feof(infile)) {
    //     fscanf(infile, "%d", &temp);
    //     sum_numbers += temp;
    //     count_numbers++;
    // }

    // printf("Sum: %d, Count: %d\n", sum_numbers, count_numbers);

    // average = calc_average(sum_numbers, count_numbers);

    // fprintf(outfile, "Average: %d", average);

    // printf("Your average of %d has been written to `output.txt`\n", average);

    // fclose(infile);
    // fclose(outfile);

    /* ----- Task 3 ----- */

    FILE* infile = fopen("divisor_numbers.txt", "r");

    int num1 = 0, num2 = 0;

    fscanf(infile, "%d", &num1);
    fscanf(infile, "%d", &num2);

    num1 = abs(num1);
    num2 = abs(num2);

    printf("Num 1: `%d`, Num 2: `%d`\n", num1, num2);

    fclose(infile);

    int gcd = greatest_common_divisor(num1, num2);

    printf("Your greatest common divisor: %d\n", gcd);

    return 0;
}

// clear; gcc -o program Lab5.c main.c && clear && ./program