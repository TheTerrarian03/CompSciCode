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

int main() {
	printf("----- Welcome to PA3! Beginning program... -----\n\n");

	// variable declarations for inputs
	int id1 = 0, id2 = 0, id3 = 0, id4 = 0, id5 = 0;								// student IDs
	double gpa1 = 0.0, gpa2 = 0.0, gpa3 = 0.0, gpa4 = 0.0, gpa5 = 0.0;				// student GPAs
	int standing1 = 0, standing2 = 0, standing3 = 0, standing4 = 0, standing5 = 0;  // class standings
	double age1 = 0, age2 = 0, age3 = 0, age4 = 0, age5 = 0;						// student ages

	// variable declerations for calculations
	double sum_gpas = 0.0, sum_ages = 0.0;
	int sum_class_standings = 0;
	double mean_gpas = 0.0, mean_class_standings = 0.0, mean_ages = 0.0;
	double gpa1_deviation = 0.0, gpa2_deviation = 0.0, gpa3_deviation = 0.0, gpa4_deviation = 0.0, gpa5_deviation = 0.0;
	double variance_of_gpas = 0.0, gpa_standard_deviation = 0.0;
	double max_gpa = 0.0, min_gpa = 0.0;

	// open file for reading
	FILE* infile = fopen(INFILE_NAME, "r");

	printf("Reading in data from file `%s`...\n", INFILE_NAME);

	// record 1
	id1 = read_integer(infile);
	gpa1 = read_double(infile);
	standing1 = read_integer(infile);
	age1 = read_double(infile);

	// record 2
	id2 = read_integer(infile);
	gpa2 = read_double(infile);
	standing2 = read_integer(infile);
	age2 = read_double(infile);

	// record 3
	id3 = read_integer(infile);
	gpa3 = read_double(infile);
	standing3 = read_integer(infile);
	age3 = read_double(infile);

	// record 4
	id4 = read_integer(infile);
	gpa4 = read_double(infile);
	standing4 = read_integer(infile);
	age4 = read_double(infile);

	// record 5
	id5 = read_integer(infile);
	gpa5 = read_double(infile);
	standing5 = read_integer(infile);
	age5 = read_double(infile);

	//printf("ID: %d, GPA: %lf, standing: %d, age: %lf\n", id1, gpa1, standing1, age1);
	//printf("ID: %d, GPA: %lf, standing: %d, age: %lf\n", id2, gpa2, standing2, age2);
	//printf("ID: %d, GPA: %lf, standing: %d, age: %lf\n", id3, gpa3, standing3, age3);
	//printf("ID: %d, GPA: %lf, standing: %d, age: %lf\n", id4, gpa4, standing4, age4);
	//printf("ID: %d, GPA: %lf, standing: %d, age: %lf\n", id5, gpa5, standing5, age5);

	// close file for reading, no longer needed.
	fclose(infile);

	// open file for writing results
	FILE* outfile = fopen(OUTFILE_NAME, "w");

	// first 3 calculations - sums
	sum_gpas = calculate_sum(gpa1, gpa2, gpa3, gpa4, gpa5);
	sum_class_standings = (int)calculate_sum(standing1, standing2, standing3, standing4, standing5);
	sum_ages = calculate_sum(age1, age2, age3, age4, age5);

	//printf("sum of: (gpas: %lf, standings: %d, ages: %lf", sum_gpas, sum_class_standings, sum_ages);  // making sure we get the right numbers
	printf("Summed GPAs, Class Standings, and Ages...\n");

	// next 3 calculations - means
	mean_gpas = calculate_mean(sum_gpas, 5);
	mean_class_standings = calculate_mean(sum_class_standings, 5);
	mean_ages = calculate_mean(sum_ages, 5);

	//printf("mean of: (gpas: %lf, standings: %lf, ages: %lf", mean_gpas, mean_class_standings, mean_ages);  // making sure we get the right numbers
	printf("Found mean of GPAs, Class Standings, and Ages...\n");

	// write those results to the output file
	print_double(outfile, mean_gpas);
	print_double(outfile, mean_class_standings);
	print_double(outfile, mean_ages);
	print_newline(outfile);  // add another sneaky newline to match expected output

	printf("Output the means to the results file `%s`\n", OUTFILE_NAME);

	// deviation of each gpa from the mean
	gpa1_deviation = calculate_deviation(gpa1, mean_gpas);
	gpa2_deviation = calculate_deviation(gpa2, mean_gpas);
	gpa3_deviation = calculate_deviation(gpa3, mean_gpas);
	gpa4_deviation = calculate_deviation(gpa4, mean_gpas);
	gpa5_deviation = calculate_deviation(gpa5, mean_gpas);

	// next 2 calculations - variance of gpas and standard deviation
	variance_of_gpas = calculate_variance(gpa1_deviation, gpa2_deviation, gpa3_deviation, gpa4_deviation, gpa5_deviation, 5);
	gpa_standard_deviation = calculate_standard_deviation(variance_of_gpas);

	//printf("variance: %.2lf, std dev: %.2lf", variance_of_gpas, gpa_standard_deviation);  // making sure we get the right numbers
	printf("Found deviations, variance, and standard deviation...\n");

	// write the gpa std dev to the file
	print_double(outfile, gpa_standard_deviation);

	printf("Output standard deviation to file `%s`\n", OUTFILE_NAME);

	// next 2 calculations - min and max
	min_gpa = find_min(gpa1, gpa2, gpa3, gpa4, gpa5);
	max_gpa = find_max(gpa1, gpa2, gpa3, gpa4, gpa5);

	printf("Found maxes of GPAs...\n");

	// write min and max out to file
	print_double(outfile, min_gpa);
	print_double(outfile, max_gpa);

	printf("Output mins and maxes to file `%s`\n", OUTFILE_NAME);

	// close results file - all done!
	fclose(outfile);

	printf("\nOkay! Your inputs have been taken from `%s`, processed, and results output to `%s`.\n\nEnjoy!\n\n----- End of PA3 by Logan Meyers -----\n", INFILE_NAME, OUTFILE_NAME);

	return 0;
}