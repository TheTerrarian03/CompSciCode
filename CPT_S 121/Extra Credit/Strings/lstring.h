/*

*/

#ifndef LSTRING_H
#define LSTRING_H

#define _CRT_SECURE_NO_WARNINGS

// includes
#include <stdio.h>
#include <stdlib.h>

// defines
#define MY_EOF -1

// basic input/output functions - single character
int my_fgetc(FILE *stream);
int my_fputc(int c, FILE *stream);
int my_getchar(void);
int my_putchar(int c);

// more advanced input/output functions - strings
char *my_fgets(char *s, int n, FILE *stream);
int my_fputs(const char *s, FILE *stream);
char *my_gets(char *s);
int my_puts(const char *s);

// string manipulation functions
char *mystrcpy(char *destination, const char *source);
char *my_strncpy(char *destination, const char *source, int n);
char *my_strcat(char *destination, const char *source);
char *my_strncat(char *destination, const char *source, int n);
int my_strcmp(const char *s1, const char *s2);
int my_strncmp(const char *s1, const char *s2, int n);
int my_strlen(const char *s);

#endif