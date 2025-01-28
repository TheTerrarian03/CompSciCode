#include "pa2.h"

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

void checkPlaylistExists();
void loadFromPlaylist();
void storeToPlaylist();

/* ----- Data Parsing Functions ----- */

/* ----- Doubly Linked List Functions ---- */

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
void destroy_list(Node **pList);
void print_list(Node *pList) {
    // if (pList == NULL) {
    //     printf("-->\n");
    // } else {
    //     printf("--> \"%s\" by \"%s\" ", pList->data.song, pList->data.artist);
    //     print_list(pList->pNext);
    // }

    if (pList == NULL) {
        putchar('\n');
    } else {
        printf("[%p <-- %p --> %p]", pList->pPref, pList, pList->pNext);
        print_list(pList->pNext);
    }
}
