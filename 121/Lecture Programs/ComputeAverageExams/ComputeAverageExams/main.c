/*
	Author: Logan Meyers
	Date: 08/26/2024

	Description: This program prompts the user for 3 exam scores, computes the average of the 3 exam scores,
	             and displays the average to the screen
*/

#include "ComputeGPA.h";

int main() {
	double gp1 = 0, gp2 = 0, gp3 = 0, gpa = 0, weighted_gp = 0;
	int credits1 = 0, credits2 = 0, credits3 = 0, sum_credits = 0;

	// get grade point & credits for class 1
	gp1 = get_grade_point(1);
	credits1 = get_credits(1);

	// get grade point & credits for class 2
	gp2 = get_grade_point(2);
	credits2 = get_credits(2);

	// get grade point & credits for class 3
	gp3 = get_grade_point(3);
	credits3 = get_credits(3);

	printf("\n%lf %lf %lf", gp1, gp2, gp3);
	printf("\n%d %d %d", credits1, credits2, credits3);

	//sum credits for each class

	sum_credits = compute_sum_credits(credits1, credits2, credits3);
	weighted_gp = ((gp1 * credits1) + (gp2 * credits2) + (gp3 * credits3)) / 3;

	gpa = compute_gpa(weighted_gp, sum_credits);

	printf("\n\nYour weighted gpa is: %lf", gpa);
	
	return 0;
}
