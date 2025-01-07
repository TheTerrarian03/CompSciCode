#ifndef FUNCS_H
#define FUNCS_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <time.h>
#include "poker.h"

/* ----- Definitions ----- */
#ifdef _WIN32
#define CLEAR_COMMAND "cls"
#else
#define CLEAR_COMMAND "clear"
#endif

/* ----- Display ----- */
// Name: clr_screen
// Description: clears the screen, depending on which OS you're on
void clr_screen();

/* ----- Random ----- */
void seed_rand();
int rand_range(int range);

/* ----- Array Manipulation ---- */
void selection_sort(int *to_sort, int length);
void hand_to_frequency_tables(int face_freq[4], int suit_freq[13], Card cards[5]);
int get_index_of_freq(int *freqs, int len_freqs, int freq);
int get_2nd_index_of_freq(int *freqs, int len_freqs, int freq);
int get_highest_freq(int *freqs, int len_freqs);

#endif
