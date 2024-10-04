/*
yeah
*/

#include "Lab6.h"

int main() {
    srand((unsigned int) time(0));
    // ---------- TASK 1 ----------
    // FILE* infile = fopen("nums.txt", "r");

    // int sum_digits = read_file_sum_digits(infile);

    // printf("Read file with sum of digits: %d\n", sum_digits);

    // int is_prime = -1;

    // is_prime = determine_if_prime(sum_digits);

    // if (is_prime == 0) {
    //     printf("Your number is not prime!\n");
    // } else if (is_prime == 1) {
    //     printf("Your number is prime!\n");
    // } else {
    //     printf("There was an error!");
    // }

    // ---------- TASK 2 -----------
    // int n_from_user = 0;

    // do {
    //     printf("Give me an n (n >= 0): ");
    //     scanf("%d", &n_from_user);
    // } while (n_from_user <= 0);

    // int factorial = mason_is_cute(n_from_user);

    // printf("%d\n", factorial);

    // ------- TASK 3 ------
    // unsigned long long n1;
    
    // // input checker
    // do {
    //     printf("enter an input ≥ 1: ");
    //     scanf("%d", &n1);
    // } while (n1 < 1);

    // // calculations
    // printf("%llu\n", fibonacci_sequence(n1));

    // return 0;

    // --------- TASK 4 -----------
    int rand_num = gen_ran_plus_minus_100();
    
    printf("%d\n", rand_num);

    int guess = 69420;

    while ((guess < -100) || (guess > 100)) {
        printf("Please enter in a valid number in the range [-100, 100]: ");
        scanf("%d\n", &guess);
    }

    printf("%d", guess);
}

// 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610

// "i like the way your thing looks" -Mason, 2024

// monkeys on typewriters is this entire group ngl

// L: Logan is gay
// M: 