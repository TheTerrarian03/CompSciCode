#include "funcs.h"

int main() {
    // TASK 1 - String Concatenation
    // char my_str[50] = {'H', 'e', 'l', 'l', 'o', '\0'};
    // char *to_add = " World! :D";
    // // or alternatively, an array:
    // //   char to_add[50] = {' ', 'W', 'o', 'r', 'l', 'd', '!', ' ', ':', 'D'};

    // char *dest_ptr = my_str_n_cat(my_str, to_add, 13);

    // printf("%s\n", my_str);

    // TASK 2 - Binary Search
    // int vals[11] = {1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 45};
    // int target = 7;
    // printf("Index of %d is: %d\n", target, binary_search(vals, 11, target));

    // TASK 3 - Bubble Sort
    char *to_sort[4] = {"logan", "zebra", "chaos", "apple"};
    printf("Before: ");
    print_str_arr(to_sort, 4);

    bubble_sort(4, to_sort);

    printf("After: ");
    print_str_arr(to_sort, 4);


    return 0;
}