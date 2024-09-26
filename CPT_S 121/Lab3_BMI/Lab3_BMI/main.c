/*
- Logan Meyers
- 09/12/2024
- CptS 121

- Lab 12: BMI advanced (using functions)
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define BMI_CONST 703

double get_weight();
double get_height();
double convert_feet_to_inches(double height_in_feet);
double calculate_bmi(double weight_in_pounds, double height_in_feet);
void display_bmi(double bmi);
void classify_bmi(double bmi);

int main() {
	double weight_pounds = 0, height_feet = 0, bmi = 0;

	// get weight
	weight_pounds = get_weight();

	// get height
	height_feet = get_height();

	// calc bmi
	bmi = calculate_bmi(weight_pounds, height_feet);

	// output results
	display_bmi(bmi);

	// classify (and output) bmi
	classify_bmi(bmi);

	return 0;
}

double get_weight() {
	double weight;
	
	// prompt user for weight
	printf("Please enter your weight in pounds: ");
	scanf("%lf", &weight);

	return weight;
}

double get_height() {
	double height;

	// prompt user for height
	printf("Please enter your height in feet: ");
	scanf("%lf", &height);

	return height;
}

double convert_feet_to_inches(double height_in_feet) {
	return height_in_feet * 12;
}

double calculate_bmi(double weight_in_pounds, double height_in_feet) {
	double height_in_inches = convert_feet_to_inches(height_in_feet);

	return (weight_in_pounds / (height_in_inches * height_in_inches)) * BMI_CONST;
}

void display_bmi(double bmi) {
	printf("Your bmi is: %lf", bmi);
}

void classify_bmi(double bmi) {
	// 4. use if statements to classify their BMI
	if (bmi < 18) {
		printf("\nYou are underweight!");
	}
	else if ((bmi >= 18) & (bmi < 25)) {
		printf("\nYou are at a healthy weight!");
	}
	else {
		printf("\nYou are OBESE pal..");
	}
}
