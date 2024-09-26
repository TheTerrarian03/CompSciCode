/*
- Logan Meyers
- 09/19/2024
- Lab 4, Section #12
- Lab 4 Solution

- This is my solution for Lab 4. It calculates the calorie need based on a person's characteristics.
*/

#include "lab4.h"

double read_double(FILE* infile) {
	double temp = 0.0;
	fscanf(infile, "%lf", &temp);
	return temp;
}
int read_int(FILE* infile) {
	int temp = 0.0;
	fscanf(infile, "%d", &temp);
	return temp;
}
char read_char(FILE* infile) {
	char temp = '\0';
	fscanf(infile, " %c", &temp);
	return temp;
}

double calc_women_bmr(double weight_lbs, double height_in, double age) {
	return 655 + (4.35 * weight_lbs) + (4.7 * height_in) - (4.7 * age);
}
double calc_men_bmr(double weight_lbs, double height_in, double age) {
	return 66 + (6.23 * weight_lbs) + (12.7 * height_in) - (6.8 * age);
}

double calculate_cal_from_activity_and_bmr(int activity_lvl, double bmr) {
	double calories = 0.0;

	if (activity_lvl == 1) {
		calories = bmr * 1.2;
	}
	else if (activity_lvl == 2) {
		calories = bmr * 1.375;
	}
	else if (activity_lvl == 3) {
		calories = bmr * 1.55;
	}
	else if (activity_lvl == 4) {
		calories = bmr * 1.725;
	}
	else {
		calories = bmr * 1.9;
	}

	return calories;
}