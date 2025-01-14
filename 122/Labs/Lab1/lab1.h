/*
- Programmer: Logan Meyers
- Class: Cpts 122, Lab 02
- Assignment: Lab 1 Task 1
- Date: 01142024
- Description: Make a Hello World program
*/

#ifndef LAB1_H
#define LAB1_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// task 1 functions
void task1();
void printHello();

// task 2 functions
void task2();
char *my_strcat(char *destination, const char *source);
void reverseString(char *str, int len);
int char_in_str(char c, char *str);
char *my_strtok(char *str, const char *delim);

#endif