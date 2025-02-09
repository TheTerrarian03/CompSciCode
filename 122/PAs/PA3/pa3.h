/*
- Name: Logan Meyers
- TA: Martin Double Factorial
- Assignment: PA 2
- "Finished": 01/29/2025
- Description: Digital Music Manager!

- Note: Better comments and headers will be added for the third PA, next submission.

- File: pa2.h
- Description: function prototypes for pa2.c
*/

#ifndef PA3_H
#define PA3_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <conio.h> // For _kbhit() on Windows
#else
#include <unistd.h>
#include <sys/select.h> // For select() on POSIX systems
#endif

/* ----- Definintions ----- */
#define MAX_NAME_LEN 64
#define MAX_LINE_LEN ((MAX_NAME_LEN*4) + 16)
#define PLAYLIST_FILE "musicPlayList.csv"

/* ----- Types and Structs ----- */
typedef struct duration {
    int minutes;
    int seconds;
} Duration;

typedef struct record {
    char artist[MAX_NAME_LEN];
    char album[MAX_NAME_LEN];
    char song[MAX_NAME_LEN];
    char genre[MAX_NAME_LEN];
    Duration length;
    int num_plays;
    int rating;
} Record;

typedef struct node {
    Record data;
    struct node *pNext;
    struct node *pPref;
} Node;

/* ----- Menu Functions ----- */

// many of these are pretty self-explanatory.

int main_menu();
int load_menu(Node **pList);
void store_menu(Node *pList);
void display_menu(Node *pList);
// void insert_menu();
// void delete_menu();
void edit_menu(Node *pList);
// void sort_menu();
void rate_menu(Node **pList);
void play_menu();
// void shuffle_menu();
void exit_menu();

/* ----- File reading/writing ----- */

// writes the data from the list to the file
void store_song_to_playlist(Record song, FILE *outfile);

/* ----- Data Parsing Functions ----- */

// adds quotes around a string that needs it (contains commas)
void string_to_file_format(char dest[MAX_NAME_LEN+2], char *src);

// removes quotes from a string if necessary
char *extract_string(char dest[MAX_NAME_LEN], char line[MAX_LINE_LEN]);

// constructs a record given a line read from the csv
void record_from_line(Record *to_store, char line[MAX_LINE_LEN]);

/* ----- Doubly Linked List Functions ----- */

// start of standard doubly linked list stuff
void init_list(Node **pList);
Node *create_node(Record new_data);
int insert_front(Node **pList, Record new_data);
void destroy_list(Node **pList);
void print_list(Node *pList);
// end of standard funcs

int get_list_length(Node *pList);

// given a name and the list, return the pointer to the first node
// that matches
Node *get_song_node(Node *pList, char *name);

// find if a given artist has any songs in the playlist
int get_artist_exists(Node *pList, char *artist);

int print_songs_matching_artist(Node *pList, char *artist);

// similar to get_song_node, but with indexed songs matching artist
Node *get_nth_song_of_artist(Node *pList, char *artist, int n);

// cool function I wrote to print the addresses of pointers,
// to visibly see how they point to each other
void print_list_p(Node *pList);

/* ----- Input Helper Functions ----- */

void clear_stdin_buffer();

void cpy_clean_nstring(char *dest, int n);

void cpy_nstring_if_exist(char *dest, int n);

void set_int_in_range_if_exist(int *num, int min, int max);

#endif