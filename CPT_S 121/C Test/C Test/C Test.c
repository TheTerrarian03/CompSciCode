// Simple C program to display "Hello World"

// Header file for input output functions
#include <stdio.h>

// Main function: entry point for execution
int main() {
    int favNum;

    // writing print statement to print hello world
    printf("Hello World!!!\nPlease enter in your favorite number:\n> ");
    
    scanf_s("%d", &favNum);

    printf("\nYour favorite number is: %d", favNum);

    return 0;
}