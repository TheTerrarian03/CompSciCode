/*
- Logan Meyers
- 09/12/2024
- Lab 3, Section 12

- Description: This program computes the duration of a projectile's flight and it's height above the ground when it reaches the target.
               Takes the angle of elevation, distance to target, and projectile velocity.
               Outputs the time of flight in seconds and the height of impact.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

/* gravitational const */
#define G 32.17

// functions to gather inputs
double get_theta();
double get_distance();
double get_velocity();

// calculation functions
double calculate_time(double distance, double velocity, double theta);
double calculate_height(double velocity, double theta, double time);

// functions to output results
double display_time_and_height(double time, double height);
