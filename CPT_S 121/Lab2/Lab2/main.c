#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define BMI_CONST 703

int main() {
	// ---------- Problem 1 - Perpendicular Bisector Calculations ----------
	printf("-------------------- Perpendicular Bisector --------------------");

	// 0. declare variables
	double x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	double midx = 0, midy = 0;
	double slope = 0, perp_slope = 0;
	double perp_y_intercept = 0;

	// 1. prompt for coord inputs
	printf("\nplease enter the coordinates for the first point; x y: ");
	scanf("%lf%lf", &x1, &y1);

	printf("please enter the coordinates for the second point; x y: ");
	scanf("%lf%lf", &x2, &y2);
	printf("Your points are: (%lf, %lf) and (%lf, %lf).", x1, y1, x2, y2);

	// 2. compute slope of the line
	slope = (y2 - y1) / (x2 - x1);

	printf("\nSlope of the line between your two points: %lf", slope);

	// 3. compute coords of midpoint
	midx = (x1 + x2) / 2;
	midy = (y1 + y2) / 2;

	printf("\nYour midpoint: (%lf, %lf)", midx, midy);

	// 4. compute slope of perpendicular bisector
	perp_slope = -(1 / slope);

	printf("\nThe slope of the line of your perpendicular bisector: %lf", perp_slope);

	// 5. compute y intercept of perp bisector with (y_mid - m * x_mid)
	perp_y_intercept = (midy - (perp_slope * midx));

	printf("\nThe y-intercept of your perpendicular bisector: %lf", perp_y_intercept);

	// 6. output results: first point, second point, equation of perpendicular bisector
	printf("\n\nFirst point: (%lf, %lf)", x1, y1);
	printf("\nSecond point: (%lf, %lf)", x2, y2);
	printf("\nEq of Perpendicular Bisector: y = %lfx + %lf\n", perp_slope, perp_y_intercept);

	// ---------- Problem 2 - BMI Calculations ----------

	// 0. declare and instantiate variables to default values
	double weight = 0, height_ft = 0, height_in = 0, bmi = 0;

	printf("\n-------------------- BMI Calculations --------------------");
 
	// 1. prompt for user input for weight and height
	printf("\n\nPlease enter your weight in pounds: ");
	scanf("%lf", &weight);

	printf("Please enter your height in feet: ");
	scanf("%lf", &height_ft);

	// 2. convert height from feet to inches
	height_in = height_ft * 12;

	// 3. calculate BMI with formula BMI = ( (weight / height) ^ 2) * 703
	bmi = (weight / (height_in * height_in)) * BMI_CONST;

	printf("Your BMI: %lf", bmi);

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
	
	return 0;
}
