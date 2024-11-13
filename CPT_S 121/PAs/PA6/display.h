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
// Name: clr_screen
// Description: clears the screen, depending on which OS you're on
void clr_screen();

/* ---------- Simple Menus ---------- */
// Name: disp_horizontal_border
// Description: Displays a horizontal border to a windows, abstracts an ugly for-loop
// Parameter: int total_len
void disp_horizontal_border(int total_len);

// Name: disp_message
// Description: displays a message in a nice box
// Parameter: char *message_str, the string to display
void disp_message(char *message_str);

// Name: disp_combo_ask
// Description: Displays a window to ask for a number option choice,
//              and prompts for input
// Parameter: char *prompt_str, the prompt for the user
// Parameter: char **options_str_arr, the array of strings to display as options
// Paramters: int amnt_options, the length of the options_str_arr
void disp_combo_ask(char *prompt_str, char **options_str_arr, int amnt_options);

/* ---------- Complex Menus ---------- */
// Name: ask_manual_vs_random_placement
// Description: a nice menu that asks for the user's choice in manual vs random
//              placement of their ships.
//              Re-asks incase their response is invalid
// Returns: the user's choice
int ask_manual_vs_random_placement();

#endif
