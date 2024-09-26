/*
- Logan Meyers
- 011881121
- 09/05/2024
- CptS 121
- Lab #07

- Description: This is my program for Programming Assignment 2. It will cover the following:
               - Newton's Second Law of Motion
               - Volume of a cylinder
               - Charcter encoding
               - Gravity
               - F to C conversion
               - Distance between two points
               - An equation

               But this time, using the 3-file format, moving all equations into `equations.c`
                 which is also outlined by `equations.h`.

               Information is gathered from `main.c` like normal, and equations are solved by
                 calling functions from `equations.h` and output like the last PA. Again,
                 this time algorithms are abstracted away for ease of readability and maintainability.
*/

#include "equations.h"

double calculate_newtons_2nd_law(double mass, double accel) {
	return mass * accel;
}

double calculate_volume_cylinder(double radius, double height) {
	return PI * (radius * radius) * height;
}

char perform_character_encoding(int offset, char plaintext_char) {
	return offset + (plaintext_char - 'a') + 'A';
}

double gravity_force_calculations(double mass1, double mass2, double distance) {
	return (G * mass1 * mass2) / (distance * distance);
}

float convert_f_to_c(float fahrenheit) {
	return (fahrenheit - 32) / (9 / (float)5);
}

double distance_between_two_points(float x1, float y1, float x2, float y2) {
	return sqrt(pow(x1 - x2, 2) + (pow(y1 - y2, 2)));
}

double solve_general_equation(double x, double z, int a) {
	return (89 / (float)27) - z * x + a / (a % 2);  // same equation put in the instructions with no parenthesis added
}
