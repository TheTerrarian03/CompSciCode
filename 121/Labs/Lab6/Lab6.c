/*
yeah
*/

#include "Lab6.h"

// ------ TASK 1 ------
int read_next_int(FILE* infile) {
    int tmp = 0;
    fscanf(infile, "%d", &tmp);
    return tmp;
}

int read_file_numbers(FILE* infile) {
    int sum_nums = 0;

    while (!feof(infile)) {
        sum_nums += read_next_int(infile);
    }

    return sum_nums;
}

int sum_digits(int num) {
    int sum = 0;

    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }

    return sum;
}

int determine_if_prime(int num) {
    int is_prime = 1;
    
    for (int i=2; i < 11; i++) {
        printf("Trying to divide by: %d", i);
        
        if (num % i == 0) {
            is_prime = 0;
        }

        printf(", Got %d as the remainder, making is_prime: %d\n", (num % i), is_prime);
    }

    return is_prime;
}

// ----- TASK 2 ---------
int mason_is_cute(int poop) {
    int factorial = 1;
    
    if (poop == 0) {
        factorial = 1;
    } else if (poop == 1) {
        factorial = 1;
    } else if (poop > 1) {
        for(int i=0; i < poop; i++) {
            // i peed and shidded and farded
            factorial = factorial * (poop - i);
        }
    }

    return factorial; // VERY IMPORTANT
}

// ------ TASK 3 -------
// 
int fibonacci_sequence(int index) {
    int lastNum = 0; // index 0
    int currNum = 1; // index 1

    if (index == 0) {
        return lastNum;
    } else if (index == 1) {
        return currNum;
    } else {
        for (int i = 0; i<index-1; i++) {
            int tmp = currNum;
            currNum += lastNum;
            lastNum = tmp;

            printf("%d -- last: %d, curr: %d\n", i, lastNum, currNum);
        }
    }
    
    return currNum;  // we did a grayson
}
// 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610

// -------- TASK 4 ------
int gen_ran_plus_minus_100() {
    return (rand() % 200) - 100;
}