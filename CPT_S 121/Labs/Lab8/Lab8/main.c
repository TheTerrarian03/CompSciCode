#include "lab8.h"

int main() {
    int task_choice = 0;
    
    printf("Welcome to Lab 8! Which task would you like to run?\n");
    printf("1. Read file\n");
    printf("2. Remove Whitespaces\n");
    printf("3. Populate Array and Frequencies\n");
    printf("4. Hangman\n");
    printf("$ ");

    scanf("%d", &task_choice);

    switch(task_choice) {
        case 1: task1();
                break;
        case 2: task2();
                break;
        case 3: task3();
                break;
        case 4: task4();
                break;
        default: printf("Ivalid choice! Please re-run program and enter valid choice.");

    }

    return 0;
}