#ifndef LAB9_H
#define LAB9_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// lib funcs
int find_str_len(char *src, int include_null_char);

// Task 1
char *string_reverse_arrnot(char *src);
char *string_reverse_ptrnot(char *src);

// Task 2
char *my_strcpy(char *destination, const char *source);
char *my_strcat(char *destination, const char *source);
int my_strcmp(char *s1, char *s2);
int my_strln(char *s);
int my_strln_wnull(char *s);

#endif