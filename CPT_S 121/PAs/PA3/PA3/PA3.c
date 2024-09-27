/*
- Logan Meyers
- 09/08/2024
- Lab #12
- PA3

- Description:  This program is my solution to Programming Assignment 3.

				In this program, we'll focus on manipulating files and conditionals.

				This program will read 'data from 'records' from a file and perform opertions on the data,
					spitting out the results to an output file. The operations done on the data include
					calculating sums, means, std devs, variance, maxes and mins.

				The end goal of the program is to output the GPA mean, class standing mean, age mean, GPA std. dev.,
					GPA min and GPA max.
*/

#include "PA3.h"

// file manipulation - reading
double read_double(FILE* infile) {
	double temp = 0.0;

	fscanf(infile, "%lf", &temp);

	return temp;
}
int read_integer(FILE* infile) {
	int temp = 0;

	fscanf(infile, "%d", &temp);

	return temp;
}

// calculations
double calculate_sum(double number1, double number2, double number3, double number4, double number5) {
	return number1 + number2 + number3 + number4 + number5;
}
double calculate_mean(double sum, int number) {
	return sum / number;
}
double calculate_deviation(double number, double mean) {
	return number - mean;
}
double calculate_variance(double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number) {
	double sum_devs = calculate_sum(pow(deviation1, 2), pow(deviation2, 2), pow(deviation3, 2), pow(deviation4, 2), pow(deviation5, 2));
	double mean_devs = calculate_mean(sum_devs, 5);

	return mean_devs;
}
double calculate_standard_deviation(double variance) {
	return sqrt(variance);
}
double find_max(double number1, double number2, double number3, double number4, double number5) {
	double max = number1;

	if (number2 > max) { max = number2; }
	if (number3 > max) { max = number3; }
	if (number4 > max) { max = number4; }
	if (number5 > max) { max = number5; }

	return max;
}
double find_min(double number1, double number2, double number3, double number4, double number5) {
	double min = number1;

	if (number2 < min) { min = number2; }
	if (number3 < min) { min = number3; }
	if (number4 < min) { min = number4; }
	if (number5 < min) { min = number5; }

	return min;
}

// file manipulation - writing
void print_double(FILE* outfile, double number) {
	fprintf(outfile, "%.2lf\n", number);
}
void print_newline(FILE* outfile) {
	fprintf(outfile, "\n");
}
