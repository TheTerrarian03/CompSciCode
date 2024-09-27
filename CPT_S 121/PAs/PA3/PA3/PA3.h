/*
- Logan Meyers
- 09/08/2024
- Lab #12
- PA3

- Description:  This program is my solution to Programming Assignment 3.

				In this program, we'll focus on manipulating files and conditionals.

				This program will read 'data from 'records' from a file and perform opertions on the data,
					spitting out the results to an output file. The operations done on the data include
					calculating sums, means, std devs, variance, maxes and mins.

				The end goal of the program is to output the GPA mean, class standing mean, age mean, GPA std. dev.,
					GPA min and GPA max.
*/

#ifndef PA3
#define PA3

// defines - these file names should never change, so I made them a constant
#define INFILE_NAME "input.dat"
#define OUTFILE_NAME "output.dat"

// defines - printf and scanf warnings disable
#define _CRT_SECURE_NO_WARNINGS

// includes
#include <stdio.h>
#include <math.h>

// ----- file manipulation - reading -----

/// <summary>
/// read_double reads and returns the next double in a file stream
/// </summary>
/// <param name="infile">: The file to read from.</param>
/// <returns>double from stream</returns>
double read_double(FILE* infile);

/// <summary>
/// read_integer reads and returns the next integer in a file stream
/// </summary>
/// <param name="infile">: The file to read from.</param>
/// <returns>integer from stream</returns>
int read_integer(FILE* infile);

// ----- calculations -----

/// <summary>
/// calculate_sum calculates and returns the sum of the numbers given
/// </summary>
/// <param name="number1">: First number to add.</param>
/// <param name="number2">: Second number to add.</param>
/// <param name="number3">: Third number to add.</param>
/// <param name="number4">: Fourth number to add.</param>
/// <param name="number5">: Fifth number to add.</param>
/// <returns>double, sum of data.</returns>
double calculate_sum(double number1, double number2, double number3, double number4, double number5);

/// <summary>
/// calculate_mean calculates and returns the mean/average of data
/// </summary>
/// <param name="sum">: Sum of data.</param>
/// <param name="number">: How many data points there are.</param>
/// <returns>double, mean/average of data.</returns>
double calculate_mean(double sum, int number);

/// <summary>
/// calculate_deviation calculates and returns the deviation of a data point from the mean
/// </summary>
/// <param name="number">: data point to find deviation of.</param>
/// <param name="mean">: mean value of data.</param>
/// <returns>double, deviation from mean the data point is.</returns>
double calculate_deviation(double number, double mean);

/// <summary>
/// calculate_variance calculates and returns the variation of the data points are from each other
/// </summary>
/// <param name="deviation1">: First data point.</param>
/// <param name="deviation2">: Second data point.</param>
/// <param name="deviation3">: Third data point.</param>
/// <param name="deviation4">: Fourth data point.</param>
/// <param name="deviation5">: Fifth data point.</param>
/// <param name="number">: How many data points there are.</param>
/// <returns>double, variance data points have from each other.</returns>
double calculate_variance(double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number);

/// <summary>
/// calculate_standard_deviation calculates and returns the standard deviation given variance
/// </summary>
/// <param name="variance">: variance of data from `calculate_variance()`.</param>
/// <returns>double, variance data points have from each other.</returns>
double calculate_standard_deviation(double variance);

/// <summary>
/// find_max finds and returns the max value
/// </summary>
/// <param name="number1">: First data number.</param>
/// <param name="number2">: Second data number.</param>
/// <param name="number3">: Third data number.</param>
/// <param name="number4">: Fourth data number.</param>
/// <param name="number5">: Fifth data number.</param>
/// <returns>double, max value.</returns>
double find_max(double number1, double number2, double number3, double number4, double number5);

/// <summary>
/// find_min finds and returns the min value
/// </summary>
/// <param name="number1">: First data number.</param>
/// <param name="number2">: Second data number.</param>
/// <param name="number3">: Third data number.</param>
/// <param name="number4">: Fourth data number.</param>
/// <param name="number5">: Fifth data number.</param>
/// <returns>double, min value.</returns>
double find_min(double number1, double number2, double number3, double number4, double number5);

// ----- file manipulation - writing -----

/// <summary>
/// print_double writes a double to the file stream, including trailing newline
/// </summary>
/// <param name="outfile">: The file to write to.</param>
/// <param name="number">: The number to write.</param>
void print_double(FILE* outfile, double number);

/// <summary>
/// print_newline writes a single newline to the file stream given
/// </summary>
/// <param name="outfile">: The file to write to.</param>
void print_newline(FILE* outfile);

#endif
