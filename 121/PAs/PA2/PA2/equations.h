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

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

#define PI (double) 3.1415926536
#define G (double) 6.67e-11

double calculate_newtons_2nd_law(double mass, double accel);
double calculate_volume_cylinder(double radius, double height);
char perform_character_encoding(int offset, char plaintext_char);
double gravity_force_calculations(double mass1, double mass2, double distance);
float convert_f_to_c(float fahrenheit);
double distance_between_two_points(float x1, float y1, float x2, float y2);
double solve_general_equation(double x, double z, int a);
