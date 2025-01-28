#include "pa2.h"

int main() {
    // Playlist of songs in doubly linked list
    Node *pHead = NULL;
    init_list(&pHead);

    Record r1 = {"Kidd G", "Karma EP", "Karma", "Pop Country", {3, 8}, 100, 5},
            r2 = {"Henry Moodie", "beat up car EP", "beat up car", "Pop", {3, 34}, 50, 4};

    pHead = create_node(r1);

    print_list(pHead);

    insert_front(&pHead, r2);

    print_list(pHead);
    
    return 0;
}