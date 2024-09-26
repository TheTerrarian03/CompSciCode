/*
*/

#include "ComputeGPA.h"

double get_grade_point(int class_num) {
	double gp = 0.0;

	// prompt user for grade point for a class
	printf("Enter the grade point for class %d: ", class_num);

	// get the gp for that class from the user
	scanf("%lf", &gp);

	return gp;  // a copy of the contents of variable gp gets sent back to
	// the calling function
}

int get_credits(int class_num) {
	int credits = 0;

	// prompt user for credits for a class
	printf("Enter the credits for class %d: ", class_num);

	// get the credits for that class from the user
	scanf("%d", &credits);

	return credits;
}

double compute_gpa(double w_gp, int sum_c) {  // function header
	double gpa = 0.0;

	gpa = w_gp / sum_c;

	return gpa;
}

int compute_sum_credits(int c1, int c2, int c3) {
	return c1 + c2 + c3;
}