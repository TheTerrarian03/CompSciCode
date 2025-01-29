#ifndef PA2_H
#define PA2_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ----- Definintions ----- */
#define MAX_NAME_LEN 64
#define MAX_LINE_LEN 256
#define PLAYLIST_FILE "mpl.csv"

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

int main_menu();
int load_menu(Node **pList);
void store_menu(Node *pList);
void display_menu(Node *pList);
// void insert_menu();
// void delete_menu();
void edit_menu();
// void sort_menu();
void rate_menu();
void play_menu();
// void shuffle_menu();
void exit_menu();

/* ----- File reading/writing ----- */

void store_song_to_playlist(Record song, FILE *outfile);

/* ----- Data Parsing Functions ----- */

void string_to_file_format(char dest[MAX_NAME_LEN+2], char *src);
char *extract_string(char dest[MAX_NAME_LEN], char line[MAX_LINE_LEN]);
void record_from_line(Record *to_store, char line[MAX_LINE_LEN]);

/* ----- Doubly Linked List Functions ---- */

void init_list(Node **pList);
Node *create_node(Record new_data);
int insert_front(Node **pList, Record new_data);
void destroy_list(Node **pList);
int get_list_length(Node *pList);
void print_list(Node *pList);
void print_list_p(Node *pList);

#endif