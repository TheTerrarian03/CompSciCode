#include "linkedlist.h"
#include "movieUtilities.h"

int main() {
    Node *pHead;  // we now have an (empty) list
    int success = 0;
    Movie r1 = {.title="Wicked", .year=2024},
        r2 = {.title="Interstellar", .year=2014},
        r3 = {.title="The Ray", .year=2004};

    initList(&pHead);  // sets list to empty

    success = insertAtFront(&pHead, r2);
    success = insertAtFront(&pHead, r1);

    printList(pHead);

    r1 = deleteFront(&pHead);

    printf("Title: %s, year: %d\n", r1.title, r1.year);

    printList(pHead);

    return 0;
}

// InsertFront(L, e): insert data at the front of the list
// - L: the first node in the list
// - e: the element to add