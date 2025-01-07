#include "funcs.h"

// OTHER FUNCTIONS
int print_int_arr(int *arr, int len) {
    // initial array string with bracket
    char arr_str[50] = {'['};

    // loop through each num in the array
    for (int i = 0; i < len; i++) {
        // print number to string and add to array string
        char num_str[20];
        sprintf(num_str, "%d", arr[i]);
        strcat(arr_str, num_str);

        // add comma if there are more numbers
        if (i < len-1) strcat(arr_str, ", ");
    }

    // final bracket
    strcat(arr_str, "]");

    // print string, return length
    printf("%s", arr_str);
    return strlen(arr_str);
}
int print_str_arr(char **arr, int len) {
    // initial array string with bracket
    char arr_str[50] = {'['};

    // for (int i = 0; i < len; i++) printf("%s%s", arr[i], (i < len-1) ? ", " : "");
    for (int i = 0; i < len; i++) {
        // cat string to array string
        strcat(arr_str, arr[i]);

        // add comma if there are more numbers
        if (i < len-1) strcat(arr_str, ", ");
    }

    // final bracket
    strcat(arr_str, "]");

    // print string, return length
    printf("%s", arr_str);
    return strlen(arr_str);
}
int nth_prime(unsigned int n) {
    if (n == 0) return 0;
    if (n == 1) return 2;

    // first prime is 2
    int prime = 2;
    n--;

    while (n > 0) {
        prime++;

        int is_prime = 1;
        for (int div = 2; div <= prime/2; div++) {
            if (prime % div == 0) is_prime = 0;
        }

        if (is_prime == 1) n--;
    }

    return prime;
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

        src_index++;
    }
    
    // copy at most n characters

    // stop if null character found

    // copy character by character to end of destination array

    // return pointer to destination character array
    return dest_arr;
}
int binary_search(int *sorted_values, int n, int target) {
    // method mostly copied from instructions, but with the Classic Logan Twist [TM]
    int left = 0, right = n-1;
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
    // return success if checking the same middle character
    if (len <= 1) return 1;

    // check left for whitespace, increment right if whitespace found
    if (str[0] == ' ') {
        str = str+1;
        len--;
    }

    // return success if checking the same middle character
    if (len <= 1) return 1;

    // check right for whitespace, decrement left if whitespace found
    if (str[len-1] == ' ') {
        len--;
    }

    // return success if checking the same middle character
    if (len <= 1) return 1;

    // if the characters at the beginning and end don't match, quit
    // (makes both lowercase to make sure case doesn't matter)
    if (tolower(str[0]) != tolower(str[len-1])) return 0;

    // recursive call, adjust start pointer and string length
    return is_palindrome(str+1, len-2);
}
int sum_primes(unsigned int n) {
    // base case: n=0, return 0 to add
    if (n == 0) return 0;

    // otherwise, return the nth prime plus the sum of primes before it
    return nth_prime(n) + sum_primes(n-1);
}
void maximum_occurences(char *str, Occurences occur_arr[128], int *int_ptr, char *char_ptr) {
    // get length of string
    int len = strlen(str);

    // loop through all indexes in the string
    for (int i=0; i < len; i++) {
        // add one to the num_occurences at the corresponding (ascii value) 
        // Occurence struct in the array
        occur_arr[str[i]].num_occurences++;
    }

    // update frequencies and max int & char if necessary
    for (int i=0; i < 128; i++) {
        // frequency
        occur_arr[i].frequency = occur_arr[i].num_occurences / (double)len;

        // max int & char through pointer if new max found
        if (occur_arr[i].num_occurences > *int_ptr) {
            *int_ptr = occur_arr[i].num_occurences;
            *char_ptr = i;
        }
    }
}

// UNFINISHED (not even started)
void max_consequtive_integers(signed int *integer_arr, int rows, int columns, int **first_int, int *num_int_row) {
    // TODO
}
