#include "linkedlist.h"
#include "movieUtilities.h"

int main() {
	Node* pHead; // we now have a list, we'll use initList () to init list to empty
	int success = 0;
	Movie r1 = { .title = "Wicked", .year = 2024 },
		r2 = { .title = "Interstellar", .year = 2014 },
        r3 = { .title = "G", .year = 2012};

	initList(&pHead); // sets list to empty

	// success = insertFront(&pHead, r1);
	// success = insertFront(&pHead, r2);

    success = insertInOrder(&pHead, r2);
    success = insertInOrder(&pHead, r3);
    success = insertInOrder(&pHead, r1);

	printList(pHead);

	destroyList(&pHead);

	printList(pHead);

	return 0;
}

// InsertFront(L, e): insert data at the front of the list
// - L: the first node in the list
// - e: the element to add