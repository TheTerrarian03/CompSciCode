/*
- Name: Logan Meyers
- TA: Martin "Double Factorial" Hundrup
- Assignment: PA 3
- [Mostly] Finished: 02/10/2025
- Description: Digital Music Manager!

- File: pa3.h
- Description: headers and declerations for my main pa3 functions, mostly wrappers, input getters, and file reading
*/

#ifndef PA3_H
#define PA3_H

#include "list.h"
#include "input.h"
#include <time.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

/* ----- Menu Functions ----- */

/*
 * Function: create_node
 * --------------------
 *   Creates new node in heap and assigns new data
 * 
 *   Parameters:
 *   - new_data: new data to set to new Node's data
 * 
 *   Returns:
 *   - pointer to new Node on heap
*/
int main_menu();
int load_menu(Node **pList);
void store_menu(Node *pList);
void display_menu(Node *pList);
void insert_menu(Node **pList);
void delete_menu(Node **pList);
void edit_menu(Node *pList);
void sort_menu(Node **pList);
void rate_menu(Node **pList);
void play_menu(Node *pList);
void shuffle_menu(Node *pList);

void play_song(Node *pList);

/* ----- File reading/writing ----- */

/*
 * Function: store_song_to_playlist
 * --------------------
 *   Stores a single song entry to the outfile
 * 
 *   Parameters:
 *   - song: data to write
 *   - outfile: file stream to write to
 * 
*/
void store_song_to_playlist(Record song, FILE *outfile);

/* ----- Data Parsing Functions ----- */

/*
 * Function: string_to_file_format
 * --------------------
 *   Adds quotes to a string if there are commas in it
 * 
 *   Parameters:
 *   - dest: string to copy new formatted string back into
 *   - src: string to format if needed
 * 
*/
void string_to_file_format(char dest[MAX_NAME_LEN+2], char *src);

/*
 * Function: extract_string
 * --------------------
 *   Extracts a string from a line like strtok might do, but
 *   this removes the quotes if necessary. I liked this function quite a bit
 * 
 *   Parameters:
 *   - dest: destination char array to copy extracted string into
 *   - line: line to extract the next string from
 * 
 *   Returns:
 *   - pointer to the next spot to pickup from in line
*/
char *extract_string(char dest[MAX_NAME_LEN], char line[MAX_LINE_LEN]);

/*
 * Function: record_from_line
 * --------------------
 *   Parse a given line and put the data into the given pointer to a Record
 * 
 *   Parameters:
 *   - to_store: pointer to record to store parsed values into
 *   - line: line read from csv file, may include newline
 * 
*/
void record_from_line(Record *to_store, char line[MAX_LINE_LEN]);

#endif