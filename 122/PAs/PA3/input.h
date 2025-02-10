#ifndef INPUT_H
#define INPUT_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

void clear_buffer();

int get_pos_int_loop(const char *line_prompt, const char *error_response);

void cpy_nstring(char *dest, int n);

void cpy_nstring_if_exist(char *dest, int n);

void set_int_in_range_if_exist(int *num, int min, int max);

#endif