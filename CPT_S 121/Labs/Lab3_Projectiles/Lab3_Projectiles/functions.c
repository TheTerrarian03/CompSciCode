/*
- Logan Meyers
- 09/12/2024
- Lab 3, Section 12

- Description: This program computes the duration of a projectile's flight and it's height above the ground when it reaches the target.
               Takes the angle of elevation, distance to target, and projectile velocity.
               Outputs the time of flight in seconds and the height of impact.
*/

#include "functions.h"

// functions to gather inputs
double get_theta() {
    double theta;

    printf("Please enter the angle of elevation of your projectile (radians): ");
    scanf("%lf", &theta);

    return theta;
}

double get_distance() {
    double distance;

    printf("Please enter the distance to the target in feet: ");
    scanf("%lf", &distance);

    return distance;
}

double get_velocity() {
    double velocity;

    printf("Please enter the starting velocity of your projectile in ft/sec: ");
    scanf("%lf", &velocity);

    return velocity;
}

// calculation functions
double calculate_time(double distance, double velocity, double theta) {
    // time = (distance) / (velocity * cos(theta)) /* make sure to include math.h to use cos() and sin()* /
    return (distance) / (velocity * cos(theta));
}

double calculate_height(double velocity, double theta, double time) {
    return velocity * sin(theta) * time - ((G * powf(time, 2)) / 2);
}

// functions to output results
double display_time_and_height(double time, double height) {
    printf("\nHere are your results:");
    printf("\nTime until projectile hits target: %lfs", time);
    printf("\nHeight projectile will hit target at: %lfft", height);
}
