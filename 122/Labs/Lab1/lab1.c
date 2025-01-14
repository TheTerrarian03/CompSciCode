/*
- Programmer: Logan Meyers
- Class: Cpts 122, Lab 02
- Assignment: Lab 1 Task 1
- Date: 01142024
- Description: Make a Hello World program
*/

#include "lab1.h"

// task 1 functions
void task1() {
    printf("-- TASK 1 --\n");
    printHello();
}
void printHello() {
    printf("Hello World!");
}

// task 2 functions
void task2() {
    // char dest[10] = {'a', 'b', 'c', '\0'};
    char dest[10] = "abc";
    char *src = "defgh";

    printf("\n\n-- TASK 2A --\n");
    printf("Dest: %s\nSrc: %s\n", dest, src);
    my_strcat(dest, src);
    printf("After: %s\n", dest);

    printf("\n-- TASK 2B --\n");
    char rev[20] = "Hello World!";
    printf("Before: %s\n", rev);
    reverseString(rev, strlen(rev));
    printf("After: %s\n", rev);

    printf("\n-- TASB 2C --\n");
    char *string = "   Table banana mango";
    char *begin = my_strtok(string, " ");
    printf("Beginning of string: %p; First non-delim: %p\n", string, begin);

}
char *my_strcat(char *destination, const char *source) {
    int dest_len = strlen(destination);
    char next_c = source[0];

    for (int i=0; next_c != '\0'; i++) {
        destination[dest_len+i] = next_c;

        next_c = source[i+1];
    }

    destination[dest_len+strlen(source)] = '\0';

    return destination;
}
void reverseString(char *str, int len) {
    // base case
    if (len <= 1) return;

    // swap characters
    char tmp = str[0];
    str[0] = str[len-1];
    str[len-1] = tmp;

    // recursive call
    reverseString(str+1, len-2);
}
int char_in_str(char c, char *str) {
    for (int i=0; i < strlen(str); i++) {
        if (c == str[i]) return 1;
    }
    return 0;
}
char *my_strtok(char *str, const char *delim) {
    int i=0;
    
    // string passed in, find first non-delim char
    if (str != NULL) {
        while (char_in_str(str[i], delim) != 0) i++;

        printf("Start of non delim at index: %d\n", i);
    }

    int token_idx_begin = i;  // beginning of the token
        // search for char in delim
        // if found:
            // replace that char with \0
            // store the next char in static
        // not found: return null ptr
        

        // keep static ptr the same when null found
        // '\0' for back to back delims
        // NULL for end of string
    return str+token_idx_begin;
}