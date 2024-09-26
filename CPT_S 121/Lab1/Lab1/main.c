#define _CRT_SECURE_NO_WARNINGS // necessary to ignore scanf_s () warnings

#include <stdio.h> // necessary to use printf () and scanf ()
#define PI (float) 3.14159

int main(void) // the starting point for all C programs
{
	printf("---------- Task 2a ----------\n");

	// we need to request memory for
	int number1_int = 0, number2_int = 0; // 2 variable declarations - reserves two memory blocks for integers and sets them to 0's
	double number1_float = 0.0, number2_float = 0.0; // reserves two memory blocks for
	// numbers with high precision (floating-point)

	printf("Enter two integer values: ");	   // prompt/ask the user
	scanf("%d%d", &number1_int, &number2_int); // read the integers typed through the
	// keyboard - %d is for "decimal", i.e. integers

	printf("Enter two floating-point values: ");     // prompt/ask the user
	scanf("%lf%lf", &number1_float, &number2_float); // read the integers typed through
	// the keyboard - %lf is for "long float", i.e.
	// double precision numbers

	// place all code for the subtasks/operations below here

	// add nunmber1_int and number2_int together, and print
	printf("int added: %d\n", number1_int + number2_int);

	// subtract number1_float and number2_float, and print
	printf("float subbed: %lf\n", number1_float - number2_float);

	// multiply number1_int * number1_float
	printf("num 1 mult: %lf\n", number1_int * number1_float);

	// divide number1_int by number2_int
	printf("int1 / int2: %d\n", number1_int / number2_int);

	// divide number1_int by number2_float
	printf("int1 / float2 as int, float: %d, %lf\n", (int)(number1_int / number2_float), (float)(number1_int / number2_float));

	// divide number1_int as float by number2_int
	printf("(float) number1int / number2 int: %lf", (float)number1_int / number2_int);

	// determine if number1_int is even/odd
	printf("\nThe following determines if the int numbers are even or odd\n");
	printf("If `1` is printed, it's odd. If `0` is printed, it's even\n");
	printf("number 1: %d\n", number1_int % 2);
	printf("number 2: %d\n", number2_int % 2);

	printf("\n---------- Task 2b - Ohm's Law ----------\n\n");

	int current, resistance;

	printf("Welcome to the Ohm's Law Calculator! Please enter you current and resistance:\n");
	printf("Current (I): ");
	scanf("%d", &current);

	printf("Resistance (R): ");
	scanf("%d", &resistance);

	printf("Here is your Voltage (V): %dv", (current * resistance));

	printf("\n\n---------- Task 2c - Joule's Law ----------\n\n");

	int p, v, r;

	printf("Welcome to the Joule's Law calculator! P = (V^2) / R\n");

	printf("Voltage (V): ");
	scanf("%d", &v);

	printf("Resistance (R): ");
	scanf("%d", &r);

	p = (v * v) / r;

	printf("Your power: %d", p);

	// example: v=5, r=2
	// program gives: 12
	// actual answwer: 12.5
	// loss of precision from int

	printf("\n\n---------- Task 2d - Polynomial ----------\n\n");

	int a, b, c, d, x, y;

	printf("Welcome to the third-order polynomial solver! Here is the equation:\n");
	printf("y = 3(ax^3) + (1/4)(bx^2) + 10(cx) + -5d\n");
	printf("You must enter the values for a, b, c, d, and x..\n");

	printf("a: ");
	scanf("%d", &a);

	printf("b: ");
	scanf("%d", &b);

	printf("c: ");
	scanf("%d", &c);

	printf("d: ");
	scanf("%d", &d);

	printf("x: ");
	scanf("%d", &x);

	y = 3 * (a * (x * x * x)) + (1 / 4) * (b * (x * x)) + 10 * (c * x) + (-5 * d);

	printf("\your y-value at x=%d: %d", x, y);

	// example: a=5, b=6, c=7, d=8, x=2
	// program gives: 120+0+140-40 = 220
	// supposed to give: 120+6+140-40 = 226
	// due to inaccuracy from int, not float or double

	printf("\n\n---------- Task 2e - Circumference ----------\n\n");

	float radius;

	printf("Welcome to the circumference calculator! Please enter your circle's radius:\n");

	printf("Radius: ");
	scanf("%f", &radius);

	float circumference = 2 * PI * radius;

	printf("\nHere is your cicle's circumference: %lf\n\n", circumference);

	return 0; // return a success status (value 0) indicating the program worked fine
} // end of the main () function
