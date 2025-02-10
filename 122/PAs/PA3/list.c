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
        pMem->pPref = NULL;
        pMem->data = new_data;
    }

    // return a possibly NULL pointer to a Node
    return pMem;
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
            (pMem->pNext)->pPref = pMem;
            *pList = pMem;
        }
    }

    return success;
}
void destroy_list(Node **pList) {
    // recursive step
    if (*pList != NULL) {
        destroy_list(&(*pList)->pNext);
        printf("freeing song %s\n", (*pList)->data.song);
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

void print_list_p(Node *pList) {
    if (pList == NULL) {
        putchar('\n');
    } else {
        printf("[%p <-- %p --> %p]\n", pList->pPref, pList, pList->pNext);
        print_list_p(pList->pNext);
    }
}