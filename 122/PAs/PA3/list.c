/*
- Name: Logan Meyers
- TA: Martin "Double Factorial" Hundrup
- Assignment: PA 3
- [Mostly] Finished: 02/10/2025
- Description: Digital Music Manager!

- File: list.c
- Description: Definitions for my list functions
*/

#include "list.h"

/* ----- Standard Doubly-Linked-List Functions ----- */

void init_list(Node **pList) {
    *pList = NULL;
}
Node *create_node(Record new_data) {
    // try to allocate space for a new Node
    Node *pMem = malloc(sizeof(Node));

    // set attributes if it exists
    if (pMem != NULL) {
        pMem->pNext = NULL;
        pMem->pPrev = NULL;
        //pMem->data = new_data;
        set_node_data(pMem, new_data);
    }

    // return a possibly NULL pointer to a Node
    return pMem;
}
void set_node_data(Node* pList, Record new_data) {
    if (!pList) return;

    strcpy(pList->data.album, new_data.album);
    strcpy(pList->data.artist, new_data.artist);
    strcpy(pList->data.genre, new_data.genre);
    strcpy(pList->data.song, new_data.song);
    pList->data.length.minutes = new_data.length.minutes;
    pList->data.length.seconds = new_data.length.seconds;
    pList->data.num_plays = new_data.num_plays;
    pList->data.rating = new_data.rating;
}
int insert_front(Node **pList, Record new_data) {
    Node *pMem = create_node(new_data);
    int success = 0;

    if (pMem != NULL) {
        success = 1;

        // if list is empty, set *pList to pMem
        if (*pList == NULL) {
            *pList = pMem;
        }
        // otherwise add to front and adjust links
        else {
            pMem->pNext = *pList;
            (pMem->pNext)->pPrev = pMem;
            *pList = pMem;
        }
    }

    return success;
}
void destroy_list(Node **pList) {
    // recursive step
    if (*pList != NULL) {
        destroy_list(&(*pList)->pNext);
        // printf("freeing song %s\n", (*pList)->data.song);
        free(*pList);
        *pList = NULL;
    }
}
void print_list(Node *pList) {
    if (pList == NULL) {
        printf("-->\n");
    } else {
        printf("--> \"%s\" by \"%s\" ", pList->data.song, pList->data.artist);
        print_list(pList->pNext);
    }
}

/* ----- Custom Functions ----- */

int get_list_length(Node *pList) {
    int len = 0;
    while (pList != NULL) {
        len++;
        pList = pList->pNext;
    }
    return len;
}
Node *get_song_node(Node *pList, char *name) {
    if (pList == NULL) return NULL;

    if (strcmp(pList->data.song, name) == 0) return pList;

    return get_song_node(pList->pNext, name);
}
int get_artist_exists(Node *pList, char *artist) {
    if (pList == NULL) return 0;

    if (strcmp(pList->data.artist, artist) == 0) return 1;

    return get_artist_exists(pList->pNext, artist);
}
int print_songs_matching_artist(Node *pList, char *artist) {
    int cur_num = 1;

    while (pList != NULL) {
        if (strcmp(pList->data.artist, artist) == 0) {
            printf("%3d - \"%s\" by \"%s\" [%s]\n        (%s), %d:%d, %d plays, %d/5 rating\n\n",
                cur_num,
                pList->data.song,
                pList->data.artist,
                pList->data.album,
                pList->data.genre,
                pList->data.length.minutes,
                pList->data.length.seconds,
                pList->data.num_plays,
                pList->data.rating);
            
            cur_num++;
        }

        pList = pList->pNext;
    }

    return cur_num-1;
}
Node *get_nth_song_of_artist(Node *pList, char *artist, int n) {
    int cur_num = 1;

    while (pList != NULL) {
        if (strcmp(pList->data.artist, artist) == 0) {
            if (cur_num == n) return pList;  // current in artist matching n
            
            cur_num++;
        }

        pList = pList->pNext;
    }

    // return NULL if nth song doesn't exist
    return NULL;
}

// recursive, based on Martin's deleteContact function from Lab3
int remove_song(Node **pList, char *song_name) {
    // empty list
    if (!*pList) return 0;  // did not remove a song

    // delete the first element if it matches
    if (!strcmp((*pList)->data.song, song_name)) {
        Node* pTemp = *pList;

		*pList = (*pList)->pNext;

        if ((pTemp)->pNext) (pTemp)->pNext->pPrev = (pTemp)->pPrev;
		
		if ((pTemp)->pPrev) (pTemp)->pPrev->pNext = (pTemp)->pNext;

		free(pTemp);

		return 1;  // found a song and removed it
    }

    // recursive call
    return remove_song(&(*pList)->pNext, song_name);
}

void print_list_p(Node *pList) {
    if (pList == NULL) {
        putchar('\n');
    } else {
        printf("[%p <-- %p --> %p]\n", pList->pPrev, pList, pList->pNext);
        print_list_p(pList->pNext);
    }
}

/* ----- Sort Functions ----- */

// welcome to my copy+pasted+change_1_thing -ified bubble sort functions, enjoy your stay
// like the hotel california you might be here a while and beginning to question  things
// everything starts to look the same but something's off..

void sort_artist(Node **pList) {
    if (!pList || !*pList) return; // Check for empty list

    int swapped;
    Node *current;
    Node *lastPtr = NULL; // Keep track of the last sorted node

    do {
        swapped = 0;
        current = *pList;

        while (current->pNext != lastPtr) {
            // Compare the artists
            if (strcmp(current->data.artist, current->pNext->data.artist) > 0) {
                // Swap the nodes instead of the data
                Node *temp = current->pNext;

                // Adjust the pointers for the swap
                current->pNext = temp->pNext;
                temp->pPrev = current->pPrev;

                if (current->pPrev) {
                    current->pPrev->pNext = temp;
                } else {
                    *pList = temp; // Update pList if needed
                }

                if (temp->pNext) {
                    temp->pNext->pPrev = current;
                }

                temp->pNext = current;
                current->pPrev = temp;

                swapped = 1; // A swap occurred
            } else {
                current = current->pNext; // Move to the next node
            }
        }
        lastPtr = current; // Update the last sorted node
    } while (swapped); // Continue until no swaps are made
}
void sort_album(Node **pList) {
    if (!pList || !*pList) return; // Check for empty list

    int swapped;
    Node *current;
    Node *lastPtr = NULL; // Keep track of the last sorted node

    do {
        swapped = 0;
        current = *pList;

        while (current->pNext != lastPtr) {
            // Compare the albums
            if (strcmp(current->data.album, current->pNext->data.album) > 0) {
                // Swap the nodes instead of the data
                Node *temp = current->pNext;

                // Adjust the pointers for the swap
                current->pNext = temp->pNext;
                temp->pPrev = current->pPrev;

                if (current->pPrev) {
                    current->pPrev->pNext = temp;
                } else {
                    *pList = temp; // Update pList if needed
                }

                if (temp->pNext) {
                    temp->pNext->pPrev = current;
                }

                temp->pNext = current;
                current->pPrev = temp;

                swapped = 1; // A swap occurred
            } else {
                current = current->pNext; // Move to the next node
            }
        }
        lastPtr = current; // Update the last sorted node
    } while (swapped); // Continue until no swaps are made
}
void sort_rating(Node **pList) {
    if (!pList || !*pList) return; // Check for empty list

    int swapped;
    Node *current;
    Node *lastPtr = NULL; // Keep track of the last sorted node

    do {
        swapped = 0;
        current = *pList;

        while (current->pNext != lastPtr) {
            // Compare the ratings
            if (current->data.rating > current->pNext->data.rating) {
                // Swap the nodes instead of the data
                Node *temp = current->pNext;

                // Adjust the pointers for the swap
                current->pNext = temp->pNext;
                temp->pPrev = current->pPrev;

                if (current->pPrev) {
                    current->pPrev->pNext = temp;
                } else {
                    *pList = temp; // Update pList if needed
                }

                if (temp->pNext) {
                    temp->pNext->pPrev = current;
                }

                temp->pNext = current;
                current->pPrev = temp;

                swapped = 1; // A swap occurred
            } else {
                current = current->pNext; // Move to the next node
            }
        }
        lastPtr = current; // Update the last sorted node
    } while (swapped); // Continue until no swaps are made
}
void sort_plays(Node **pList) {
    if (!pList || !*pList) return; // Check for empty list

    int swapped;
    Node *current;
    Node *lastPtr = NULL; // Keep track of the last sorted node

    do {
        swapped = 0;
        current = *pList;

        while (current->pNext != lastPtr) {
            // Compare the plays
            if (current->data.num_plays > current->pNext->data.num_plays) {
                // Swap the nodes instead of the data
                Node *temp = current->pNext;

                // Adjust the pointers for the swap
                current->pNext = temp->pNext;
                temp->pPrev = current->pPrev;

                if (current->pPrev) {
                    current->pPrev->pNext = temp;
                } else {
                    *pList = temp; // Update pList if needed
                }

                if (temp->pNext) {
                    temp->pNext->pPrev = current;
                }

                temp->pNext = current;
                current->pPrev = temp;

                swapped = 1; // A swap occurred
            } else {
                current = current->pNext; // Move to the next node
            }
        }
        lastPtr = current; // Update the last sorted node
    } while (swapped); // Continue until no swaps are made
}
