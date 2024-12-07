#include "funcs.h"

int main() {
    // TASK 1 - String Concatenation
    char my_str[50] = {'H', 'e', 'l', 'l', 'o', '\0'};
    char *to_add = " World! :D";
    printf("+--- TASK 1 - String Concatenation -------------+\n");
    printf("| Destination String:    \"%-20s\" |\n", my_str);
    printf("| String to Concatenate: \"%-20s\" |\n", to_add);
    char *dest_ptr = my_str_n_cat(my_str, to_add, 13);
    printf("| Final string:          \"%-20s\" |\n", my_str);
    printf("+-----------------------------------------------+\n");

    // TASK 2 - Binary Search
    int vals[11] = {1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 45};
    int target = 7;
    putchar('\n');
    printf("+--- TASK 2 - Binary Search -----------------------------------+\n");
    printf("| Array of ints: ");
    int len = print_int_arr(vals, 11);
    printf("%*c |\n", 45-len, ' ');
    printf("| Target num:    %-45d |\n", target);
    printf("| Num's index:   %-45d |\n", binary_search(vals, 11, target));
    printf("+--------------------------------------------------------------+\n");

    // TASK 3 - Bubble Sort
    // char *to_sort[4] = {"logan", "zebra", "chaos", "apple"};
    // printf("Before: ");
    // print_str_arr(to_sort, 4);

    // bubble_sort(4, to_sort);

    // printf("After: ");
    // print_str_arr(to_sort, 4);

    // TASK 4 - Is Palindrome
    // char *palinstring = "race car";
    // char *palinstring = "was it a cat i saw";
    // char *palinstring = "eva can i see bees in a cave";
    // char *palinstring = "Eva can I see bees in a cave";
    // int result = is_palindrome(palinstring, strlen(palinstring));
    // if (result) {
    //     printf("\"%s\" IS a palindrome!\n", palinstring);
    // } else {
    //     printf("\"%s\" is NOT a palindrome!", palinstring);
    // }

    // TASK 5 - Sum Primes
    // int n = 13;
    // int result = sum_primes(n);
    // printf("Prime at %d: %d\n", n, nth_prime(n));
    // printf("Sum of first %d primes: %d\n", n, result);

    // TASK 6 - Max Occurences
    // char *test_string = "test string";
    // Occurences occ[128] = {};
    // int max_occ = 0;
    // int max_char = '\0';

    // maximum_occurences(test_string, occ, &max_occ, &max_char);

    // for (int i=0; i < 128; i++) {
    //     if (occ[i].frequency != 0.0) {
    //         printf("%c | occ: %d | freq: %.2lf | \n", i, occ[i].num_occurences, occ[i].frequency);
    //     }
    // }

    // printf("Max char '%c' with count: %d\n", max_char, max_occ);

    return 0;
}
