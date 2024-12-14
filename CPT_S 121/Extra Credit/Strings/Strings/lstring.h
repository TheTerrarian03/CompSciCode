/*
Name: Logan Meyers
Date: 12/13/2024
TA: James (he was awesome btw)
Assignment: Strings (Bonus)

Description: These are my custom, ground-up (mostly) functions to replace some of the
             basic functions for file and stream reading and writing, along with some
             string functions. Enjoy!
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
// Name: my_fgetc
// Description: Get a character from a file stream
// Parameter: FILE *stream, the file
// Returns: the int repr. of the character read
int my_fgetc(FILE *stream);
// Name: my_fputc
// Description: write a character to a file stream
// Parameter: int c, character to write
// Parameter: FILE *stream, the file
// Returns: the int repr. of the character written
int my_fputc(int c, FILE *stream);
// Name: my_getchar
// Description: get a character from the stdin stream
// Returns: the int repr. of the character read
int my_getchar(void);
// Name: my_putchar
// Description: write a character to the stdout stream
// Parameter: int c, character to write
// Returns: the int repr. of the character written
int my_putchar(int c);

// more advanced input/output functions - strings
char *my_fgets(char *s, int n, FILE *stream);
int my_fputs(const char *s, FILE *stream);
char *my_gets(char *s);
int my_puts(const char *s);

// string manipulation functions
char *my_strcpy(char *destination, const char *source);
char *my_strncpy(char *destination, const char *source, int n);
char *my_strcat(char *destination, const char *source);
char *my_strncat(char *destination, const char *source, int n);
int my_strcmp(const char *s1, const char *s2);
int my_strncmp(const char *s1, const char *s2, int n);
int my_strlen(const char *s);

// custom display functions
char *pad_string(char *destination, const char *source, int total_chars, int dir);

#endif