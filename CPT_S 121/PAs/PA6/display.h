/*
- These are some functions abstracted into a serpate file,
    that have to do with displaying info!

- Some notable functions:
    - dbgjkbdkj
*/

#ifndef DISPLAY_H
#define DISPLAY_H

/* ---------- Definitions ---------- */
#define _CRT_SECURE_NO_WARNINGS

#ifdef _WIN32
#define CLEAR_COMMAND "cls"
#else
#define CLEAR_COMMAND "clear"
#endif

/* ---------- Inludes ---------- */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* ---------- System Calls ---------- */
void clr_screen();

/* ---------- Simple Menus ---------- */
void disp_horizontal_border(int total_len);
void disp_message(char *message_str);
int disp_combo_ask(char *prompt_str, char **options_str_arr, int amnt_options);

/* ---------- Complex Menus ---------- */
int ask_manual_vs_random_placement();

#endif