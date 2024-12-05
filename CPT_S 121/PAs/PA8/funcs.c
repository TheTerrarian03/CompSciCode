#include "funcs.h"

// OTHER FUNCTIONS
void print_int_arr(int *arr, int len) {
    putchar('[');
    for (int i = 0; i < len; i++) printf("%d%s", arr[i], (i < len-1) ? ", " : "");
    printf("]\n");
}
void print_str_arr(char **arr, int len) {
    putchar('[');
    for (int i = 0; i < len; i++) printf("%s%s", arr[i], (i < len-1) ? ", " : "");
    printf("]\n");
}

// TASK FUNCTIONS
char *my_str_n_cat(char *dest_arr, char *src_string, int n) {
    // find index at the end of the array to copy to
    int null_idx = 0;
    for (; dest_arr[null_idx] != '\0'; null_idx++);

    // copy characters from source to destination, within limits
    int src_index = 0;
    while (src_index < n) {
        // get next character to copy
        char next = src_string[src_index];

        // if next is null, stop
        if (next == '\0') break;

        // otherwise, copy to the next index in the destination
        dest_arr[null_idx+src_index] = next;

        printf("Copied %c from src[%d] to dest[%d]\n", next, src_index, null_idx+src_index);

        src_index++;
    }
    
    // copy at most n characters

    // stop if null character found

    // copy character by character to end of destination array

    // return pointer to destination character array
    return dest_arr;
}
int binary_search(int *sorted_values, int num_values, int target) {
    // method mostly copied from instructions, but with the Classic Logan Twist [TM]
    int left = 0, right = num_values-1;
    int target_index = 0;

    // loop while not found and valid index
    while (target_index == 0 && left <= right) {
        int mid = (left + right) / 2;

        // printf("L[%d]=%d | M[%d]=%d | R[%d]=%d\n", left, sorted_values[left], mid, sorted_values[mid], right, sorted_values[right]);

        // NOTE: I have found that this has the weird quirk of
        //       not always finding the first occurence of a repeating value
        //       but this may just be the algorithm, I'm not sure.
        //       For example, for [1, 1, 1, 3, 4] it will return 3 (index 2) (the last one)
        //       For example, for [1, 2, 2, 2, 4] it will return 1 (index 0) (the first two)
        //       For example, for [1, 1, 1, 1, 5, 6] it will return 3 (index 2) (the third one)

        if (target == sorted_values[mid]) target_index = mid+1;
        if (target < sorted_values[mid])  right = mid-1;
        if (target > sorted_values[mid])  left = mid+1;
    }

    return target_index;
}
void bubble_sort(int num_strings, char *strings[]) {
    int u = num_strings-1;  // end of list, [-1]
    while (u > 0) {  // while more than nothing unsorted
        int c = 1;  // second element
        while (c <= u) {
            // may I use strcmp()?
            // otherwise, a simple copy + paste from the code I wrote for the
            //   `my_strcmp` function from Task 2 of Lab 9 should do.
            if (strcmp(strings[c], strings[c-1]) < 0) {
                // swap pointers to the two strings
                char *tmp = strings[c];
                strings[c] = strings[c-1];
                strings[c-1] = tmp;
            }
            c++;  // haha
        }
        u--;
    }
}
int is_palindrome(char *str, int len) {
    // indexes to check
    int str_length = strlen(str);
    int left = (str_length - len)/2;
    int right = str_length - left;

    if (left > right) return 0;

    printf("Comparing: %c and %c\n", str[left], str[right]);

    return is_palindrome(str, len-2);

    return 0;
}
int sum_primes(unsigned int n);
void maximum_occurences(char *str, Occurences *occur_arr[], int *int_ptr, char *char_ptr);
void max_consequtive_integers(signed int *integer_arr, int rows, int columns, int **first_int, int *num_int_row);
