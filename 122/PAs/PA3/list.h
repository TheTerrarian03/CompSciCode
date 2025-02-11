#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_NAME_LEN 64
#define MAX_LINE_LEN ((MAX_NAME_LEN*4) + 16)
#define PLAYLIST_FILE "musicPlayList.csv"

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
    struct node *pPrev;
} Node;

/* ----- Standard Doubly-Linked-List Functions ----- */

// start of standard doubly linked list stuff
void init_list(Node **pList);
Node *create_node(Record new_data);
int insert_front(Node **pList, Record new_data);
void destroy_list(Node **pList);
void print_list(Node *pList);
// end of standard funcs

/* ----- Custom Functions ----- */

int get_list_length(Node *pList);

// given a name and the list, return the pointer to the first node
// that matches
Node *get_song_node(Node *pList, char *name);

// find if a given artist has any songs in the playlist
int get_artist_exists(Node *pList, char *artist);

int print_songs_matching_artist(Node *pList, char *artist);

// similar to get_song_node, but with indexed songs matching artist
Node *get_nth_song_of_artist(Node *pList, char *artist, int n);

int remove_song(Node **pList, char *song_name);

// cool function I wrote to print the addresses of pointers,
// to visibly see how they point to each other
void print_list_p(Node *pList);

/* ----- Sort Functions ----- */

void sort_artist(Node **pList);
void sort_album(Node **pList);
void sort_rating(Node **pList);
void sort_plays(Node **pList);

#endif