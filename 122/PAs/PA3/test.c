/*
- Name: Logan Meyers
- TA: Martin "Double Factorial" Hundrup
- Assignment: PA 3
- [Mostly] Finished: 02/10/2025
- Description: Digital Music Manager!

- File: test.c
- Description: definitions for my so few test functions
*/

#include "test.h"

// everything works, trust :sunglasses: :thumbs_up:

void test_insert() {
    Node *head;
    init_list(&head);

    Record new_data = {.album = "abc", .artist = "def", .genre = "hij", .length = {.minutes = 3, .seconds = 42}, .num_plays = 15, .rating = 3, .song = "xyz"};

    insert_front(&head, new_data);

    if (head == NULL) {
        printf("Test insert: FAIL\n");
        return;
    }

    if (strcmp(head->data.song, new_data.song) != 0) {
        printf("Test insert: FAIL\n");
        return;
    }

    printf("Test insert: SUCCESS\n");
}
void test_delete() {
    Node *head;
    init_list(&head);

    Record new_data = {.album = "Witness", .artist = "Katy Perry", .genre = "pop", .length = {.minutes = 4, .seconds = 36}, .num_plays = -1, .rating = 6, .song = "Chained to the Rhythm"};

    insert_front(&head, new_data);

    remove_song(&head, new_data.song);

    if (head != NULL) {
        printf("Test delete: FAIL\n");
        return;
    }

    printf("Test delete: SUCCESS\n");
}
void test_shuffle();
void test_all() {
    test_insert();
    test_delete();
}