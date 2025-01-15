#include "linkedlist.h"
#include "movieUtilities.h"

int main() {
    Node pHead;  // we now have an (empty) list

    initList(&pHead);

    return 0;
}

// InsertFront(L, e): insert data at the front of the list
// - L: the first node in the list
// - e: the element to add