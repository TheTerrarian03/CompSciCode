/*
- Logan Meyers
- 09/26/2024
- Lab 5 Section #12

- Description: bkjbgkdjrhde
*/

#include "Lab5.h"

char determine_income_bracket(double dollar_amount) {
    if (dollar_amount < 15000) {
        return 'l';
    }
    if (dollar_amount < 200000) {
        return 'm';
    }
    return 'h';
}

int calc_average(int sum, int count) {
    return sum/count;
}

int greatest_common_divisor(int num1, int num2) {
    int n1 = num1, n2 = num2;
    int remainder = 0;

    do {
        remainder = n1 % n2;
        n1 = n2;
        n2 = remainder;
        printf("remainder: %d\n", remainder);
    } while(remainder != 0);

    return n1;
}