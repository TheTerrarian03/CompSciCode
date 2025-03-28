/*
- Logan Meyers
- 011881121
- 09/05/2024
- CptS 121
- Lab #07

- Description: This is my program for Programming Assignment 1. It will cover the following:
               - Newton's Second Law of Motion
               - Volume of a cylinder
               - Charcter encoding
               - Gravity
               - F to C conversion
               - Distance between two points
               - An equation
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

#define PI (double) 3.1415926536
#define G (double) 6.67e-11

int main() {
    // ------------------------------ #1 - Newton's ------------------------------

    // 0. declare and initialize variables to default values
    double mass = 0, accel = 0, force = 0;
    
    // 1. prompt for user input for mass and acceleration
    printf("----- Newton's Second Law of Motion -----\n");
    printf("Enter values for mass and acceleration: ");
    scanf("%lf%lf", &mass, &accel);

    // 2. calculate force from user inputs
    force = mass * accel;

    // 3. output results
    printf("force = mass * acceleration = %lf * %lf = %lf\n\n", mass, accel, force);

    // ------------------------------ #2 - Cylinder ------------------------------

    // 0. declare variables with default values
    double radius = 0, height = 0, volume_cylinder = 0;

    // 1. prompt user for values for the radius and height
    printf("----- Volume of a Cylinder -----\n");
    printf("Enter values for your radius and height: ");
    scanf("%lf%lf", &radius, &height);

    // 2. calculate the volume from the values given, and the PI const
    volume_cylinder = PI * (radius * radius) * height;

    // 3. output results
    printf("volume = PI * radius * height = %lf * %lf^2 * %lf = %lf", PI, radius, height, volume_cylinder);

    // ------------------------------ #3 - Character s------------------------------

    // 0. declare and instantiate variables
    int offset = 0;
    char plaintext_character = 0, encoded_character = 0;

    // 1. prompt user for inputs for offset and a character
    printf("\n\n----- Character encoding -----\n");

    printf("Please enter the offset for the character (whole number): ");
    scanf("%d", &offset);

    printf("Please enter a plantext character (from your keyboard): ");
    scanf(" %c", &plaintext_character);

    // 2. calculate your encoded character
    encoded_character = offset + (plaintext_character - 'a') + 'A';
    
    // 3. output results
    printf("\nencoding your character with the formula: offsest + (plaintext - 'a') + 'A'");
    printf("\n=> %d + ('%c' - 'a') + 'A'", offset, plaintext_character);
    printf("\nYour encoded character: %c", encoded_character);

    // enc_char = offset + (plaintext_char - 'a') + 'A'

    // ------------------------------ #4 - Gravity ------------------------------

    // 0. declare vars and instantiate
    double mass1 = 0, mass2 = 0, distance = 0;
    force = 0;  // reset force variable because it was used in previous problems

    // 1. prompt user for inputs for masses and distance
    printf("\n\n----- Gravity -----");
    printf("\nPlease enter your first mass: ");
    scanf("%lf", &mass1);
    printf("Please enter your second mass: ");
    scanf("%lf", &mass2);
    printf("Please eneter your distance: ");
    scanf("%lf", &distance);

    // 2. calculate force
    force = (G * mass1 * mass2) / (distance * distance);

    // 3. print results
    printf("\nCalculating your forces from the equation:");
    printf("\nforce = (g * mass1 * mass2) / (distance^2)");
    printf("\n=> force = (%lf * %lf * %lf) / (%lf * %lf)", G, mass1, mass2, distance, distance);
    printf("\n=> force = %e", force);

    // ------------------------------ #5 - Fahrenheit to Celcius ------------------------------

    // 0. declare vars and instantiate
    float fahrenheit = 0, celcius = 0;

    // 1. prompt user for inputs for their Fahrenheit temperature
    printf("\n\n----- Fahrenheit -> Celcius -----");
    printf("\nPlease enter your temperature in Fahrenheit: ");
    scanf("%f", &fahrenheit);

    // 2. convert to celcius
    celcius = (fahrenheit - 32) / (9 / (float)5);

    // 3. display results
    printf("Using the formula below, here's your temperature in Celcius:");
    printf("\ncelcius = (fahrenheit - 32) * (9/5)");
    printf("\n=> celcius = (%f - 32) * (9/5)", fahrenheit);
    printf("\n=> celcius = %f", celcius);

    // ------------------------------ #6 - Distance between Two Points  ------------------------------

    // 0. declare vars and instantiate
    float x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    distance = 0;  // might as well re-use the distance variable for this problem

    // 1. ask for input from users for point coords
    printf("\n\n----- Distance between Two Points -----");
    printf("\nPlease enter the x and y coords for your first point: ");
    scanf("%f%f", &x1, &y1);
    printf("Please enter the x and y coords for your second point: ");
    scanf("%f%f", &x2, &y2);

    // 2. calculate distance with sqrt((x1 - x2)^2 + (y1 - y2)^2
    distance = sqrt(pow(x1 - x2, 2) + (pow(y1 - y2, 2)));

    // 3. print results
    printf("\n\nUsing the formula below, here is the distance between your points:");
    printf("\ndistance = sqrt((x1 - x2)^2 + (y1 - y2)^2");
    printf("\n=> distance = sqrt((%f - %f)^2 + (%f - %f)^2)", x1, x2, y1, y2);
    printf("\n=> distance = %lf", distance);

    // ------------------------------ #7 - General Equation ------------------------------

    // 0. declare vars and instantiate
    double x = 0, z = 0, y = 0;
    int a = 0;

    // 1. ask for input from users for 
    printf("\n\n-----  General Equation -----");
    printf("\nPlease enter your z value (may be decimal): ");
    scanf("%lf", &z);
    printf("Please enter your x value (may also be decimal): ");
    scanf("%lf", &x);
    printf("Please enter your a value (whole number): ");
    scanf("%d", &a);

    // 2. calculate
    y = (89 / (float) 27) - z * x + a / (a % 2);  // same equation put in the instructions with no parenthesis added

    // 3. print results
    printf("\n\nUsing the following equation, here is your y-value:");
    printf("\ny = (89 / 27) - z * x + a / (a %% 2)");
    printf("\n=> y = (89 / 27) - %lf * %lf + %d / (%d %% 2)", z, x, a, a);
    printf("\n=> y = %lf", y);

    // I noticed that if you put an even number in for a it divides by 0 and gives you the error code -1073741676, nice

    // the end
    printf("\n\n----- The End of PA 1, by Logan Meyers -----\n");

    return 0;
}