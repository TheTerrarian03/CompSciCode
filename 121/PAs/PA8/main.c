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
    printf("+-----------------------------------------------+\n\n");

    // TASK 2 - Binary Search
    int vals[11] = {1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 45};
    int target = 7;
    printf("+--- TASK 2 - Binary Search -----------------------------------+\n");
    printf("| Array of ints: ");
    int p_len = print_int_arr(vals, 11);
    printf("%*c |\n", 45-p_len, ' ');
    printf("| Target num:    %-45d |\n", target);
    printf("| Num's index:   %-45d |\n", binary_search(vals, 11, target));
    printf("+--------------------------------------------------------------+\n\n");

    // TASK 3 - Bubble Sort
    char *to_sort[4] = {"logan", "zebra", "chaos", "apple"};
    printf("+--- TASK 3 - Bubble Sort ---------------------------------------------+\n");
    printf("| Original String Array: ");
    p_len = print_str_arr(to_sort, 4);
    printf("%*c |\n", 45-p_len, ' ');
    bubble_sort(4, to_sort);
    printf("| Sorted String Array:   ");
    p_len = print_str_arr(to_sort, 4);
    printf("%*c |\n", 45-p_len, ' ');
    printf("+----------------------------------------------------------------------+\n\n");

    // TASK 4 - Is Palindrome
    printf("+--- TASK 4 - Is Palindrome? ---------+\n");
    printf("| Tests (1=yes, 0=no):                |\n");
    printf("| - \"Race car\":                     %d |\n", is_palindrome("Race car", strlen("Race car")));
    printf("| - \"James is Awesome\":             %d |\n", is_palindrome("James is Awesome", strlen("James is Awesome")));
    printf("| - \"Was it a cat I saw\":           %d |\n", is_palindrome("Was it a cat I saw", strlen("Was it a cat I saw")));
    printf("| - \"Eva can I see bees in a cave\": %d |\n", is_palindrome("Eva can I see bees in a cave", strlen("Eva can I see bees in a cave")));
    printf("| - \"Logan 1 Meyers\":               %d |\n", is_palindrome("Logan 1 Meyers", strlen("Logan 1 Meyers")));
    printf("+-------------------------------------+\n\n");

    // TASK 5 - Sum Primes
    printf("+--- TASK 5 - Sum Primes ---+\n");
    printf("| Tests: [num: sum]         |\n");
    printf("| - 0:   %-18d |\n", sum_primes(0));
    printf("| - 1:   %-18d |\n", sum_primes(1));
    printf("| - 2:   %-18d |\n", sum_primes(2));
    printf("| - 3:   %-18d |\n", sum_primes(3));
    printf("| - 4:   %-18d |\n", sum_primes(4));
    printf("| - 10:  %-18d |\n", sum_primes(10));
    printf("| - 13:  %-18d |\n", sum_primes(13));
    printf("| - 50:  %-18d |\n", sum_primes(50));
    printf("| - 101: %-18d |\n", sum_primes(101));
    printf("| - 234: %-18d |\n", sum_primes(234));  // this takes a noticable amount of time lol, my code is NOT efficient for nth_prime
    // printf("| - 999: %-18d |\n", sum_primes(999));  // took 6s
    printf("+---------------------------+\n\n");

    // TASK 6 - Max Occurences
    printf("+--- TASK 6 - Max Occurences ---------------------------------+\n");
    Occurences occ[128] = {};
    int max_count = 0;
    char max_char = '\0';
    maximum_occurences("test string", occ, &max_count, &max_char);
    printf("| - \"test string\":                                   %3dx '%c' |\n", max_count, max_char);

    Occurences occ2[128] = {};
    max_count = 0;
    max_char = '\0';
    maximum_occurences("CptS iS aweSome Sauce", occ2, &max_count, &max_char);
    printf("| - \"CptS iS aweSome Sauce\":                         %3dx '%c' |\n", max_count, max_char);

    Occurences occ3[128] = {};
    max_count = 0;
    max_char = '\0';
    maximum_occurences("CptS 121 waS pretty Super duper aweSome Sauce", occ3, &max_count, &max_char);
    printf("| - \"CptS 121 waS pretty Super duper aweSome Sauce\": %3dx '%c' |\n", max_count, max_char);

    Occurences occ4[128] = {};
    max_count = 0;
    max_char = '\0';
    maximum_occurences("AAAAAAAAAAAAAAAAAAAAAH", occ4, &max_count, &max_char);
    printf("| - \"AAAAAAAAAAAAAAAAAAAAAH\":                        %3dx '%c' |\n", max_count, max_char);

    printf("+-------------------------------------------------------------+\n\n");

    printf("> Bonus [Task 7] Unfinished.\n\n");

    printf("> The end!\n    -LM\n\n");

    return 0;
}
