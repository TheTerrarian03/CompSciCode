#ifndef RECURSION_H
#define RECURSION_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h> // strcpy () and strtok ()
#include <stdlib.h> // atoi (), atof ()

// a struct is an aggregate type; can store many variable types within it; types should
// desribe a single kind of object
typedef struct student
{
	char last[50];
	char first[50];
	unsigned int id;
	double gpa;
}Student; // the typedef allows us to rename the struct so that we don't have to use "struct student",
          // but instead now "Student"

void print_records(Student* arr, int size);

// order smallest to largest based on gpa
Student *bubble_sort(Student *arr_students, int size);

#endif