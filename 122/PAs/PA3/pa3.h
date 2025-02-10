#ifndef PA3_H
#define PA3_H

#include "list.h"
#include "input.h"

/* ----- Menu Functions ----- */

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

#endif