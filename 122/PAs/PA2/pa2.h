#ifndef PA2_H
#define PA2_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

/* ----- Definintions ----- */
#define MAX_NAME_LEN 64


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

void load_menu();
void store_menu();
void display_menu();
// void insert_menu();
// void delete_menu();
void edit_menu();
// void sort_menu();
void rate_menu();
void play_menu();
// void shuffle_menu();
void exit_menu();

/* ----- File reading/writing ----- */

void check_playlist_exists();
void load_from_playlist();
void store_to_playlist();

/* ----- Data Parsing Functions ----- */

/* ----- Doubly Linked List Functions ---- */

void init_list(Node **pList);
Node *create_node(Record new_data);
int insert_front(Node **pList, Record new_data);
void destroy_list(Node **pList);
void print_list(Node *pList);

#endif