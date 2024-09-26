/*
- Logan Meyers
- 09/19/2024
- Lab 4, Section #12
- Lab 4 Solution

- This is my solution for Lab 4. It calculates the calorie need based on a person's characteristics.
*/

#include "lab4.h"

int main() {
	// declare variables
	double age = 0.0, weight = 0.0, height = 0.0, bmr = 0.0, calories = 0.0;
	char gender = '\0';
	int activity = 0;

	// open file
	FILE* infile = fopen(INFILE_NAME, "r");

	// read data from file
	age = read_double(infile);
	gender = read_char(infile);
	weight = read_double(infile);
	height = read_double(infile);
	activity = read_int(infile);

	// close file
	fclose(infile);

	// printing data for inputs
	printf("Age:          %.2lf\nGender:       %c\nWeight:       %.2lf\nHeight:       %.2lf\nActivity Lvl: %d\n\n", age, gender, weight, height, activity);

	// calculate BMR
	if (gender == 'm') {
		bmr = calc_men_bmr(weight, height, age);
	}
	else if (gender == 'w') {
		bmr = calc_women_bmr(weight, height, age);
	}
	else {
		printf("INVALID GENDER TRY AGAIN");
		return -1;
	}

	printf("BMR Value: %lf\n\n", bmr);

	// calculate calories
	calories = calculate_cal_from_activity_and_bmr(activity, bmr);

	// print results
	printf("Your recommended calorie intake based on your stats is: %lf\n", calories);

	return 0;
}
