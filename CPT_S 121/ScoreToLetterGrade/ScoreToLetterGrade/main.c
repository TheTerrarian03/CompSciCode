/*
- Logan Meyers
- 09/11/2024
- Score To Letter Grade example code from during lectures

- Description:
*/

#include "LetterGrade.h"

int main(void) {
	int score1 = 0, score2 = 0, score3 = 0;
	char lg_1 = '\0', lg_2 = '\0', lg_3 = '\0';
	FILE *input_stream = NULL, *output_stream = NULL;

	// open scores file in read mode
	// fopen is from stdio.h
	input_stream = fopen("scores.txt", "r");

	// assuming the file is opened successfully,
	// read file and extract scores
	fscanf(input_stream, "%d", &score1);
	fscanf(input_stream, "%d", &score2);
	fscanf(input_stream, "%d", &score3);

	// finally, close file.
	fclose(input_stream);

	// calculate letter grade for each score
	lg_1 = determine_letter_grade(score1);
	lg_2 = determine_letter_grade(score2);
	lg_3 = determine_letter_grade(score3);

	// open results file in write mode
	output_stream = fopen("results.txt", "w");

	// print to file the results
	fprintf(output_stream, "Score 1: %c\nScore 2: %c\nScore 3: %c\n", lg_1, lg_2, lg_3);

	// finally, close the results file
	fclose(output_stream);

	return 0;
}