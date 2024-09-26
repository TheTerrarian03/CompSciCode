/*
- Logan Meyers
- 09/12/2024
- Lab 3, Section 12

- Description: This program computes the duration of a projectile's flight and it's height above the ground when it reaches the target.
               Takes the angle of elevation, distance to target, and projectile velocity.
               Outputs the time of flight in seconds and the height of impact.
*/

#include "functions.h"

// my side quest
//void get_theta_ref(double* pointer) {
//    printf("Please enter the angle of elevation of your projectile (radians): ");
//    scanf("%lf", pointer);
//}

int main() {
    double theta = 0.0;     /* initial projectile angle in radians */
    double distance = 0.0;  /* distance to target */
    double velocity = 0.0;  /* initial velocity of projective in ft/sec */
    double time = 0.0;
    double height = 0.0;

    // get inputs
    theta = get_theta();
    distance = get_distance();
    velocity = get_velocity();

    // do calculations
    time = calculate_time(distance, velocity, theta);
    height = calculate_height(velocity, theta, time);

    // output results
    display_time_and_height(time, height);

    return 0;
}