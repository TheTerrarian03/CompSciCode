#include <stdio.h>
#include <stdlib.h>  // malloc(), calloc(), free()
#include <string.h>

// malloc is manual allocation of memory
// calloc is allocation of arrays, and those arrays can change
// free for freeing memory

// Linked Lists are like arrays of Nodes,
// where any Node has data and a pointer to another Node.
// There is a head/start pointer to the first Node.

typedef struct node {
    char grocery_item[50];
    struct node *link_ptr;  // self-referential struct (not recursion)
} Node;

Node *create_node(char *item);
int insert_at_front(Node **list_ptr, char *item);  // list operation

int main() {
    Node *head_ptr = NULL;
    int success = 0;

    success = insert_at_front(head_ptr, "bananas");

    // printf("Success: %d, Item: %s\n", success, head_ptr->grocery_item);
    printf("This is horrible :D");

    return 0;
}

Node *create_node(char *item) {
    Node *mem_ptr = malloc(sizeof(Node));

    if (mem_ptr != NULL) {
        // we allocated space for a node successfully
        strcpy(mem_ptr->grocery_item, item);
        mem_ptr->link_ptr = NULL;
    }

    return mem_ptr;
}

int insert_at_front(Node **list_ptr, char *item) {
    Node *mem_ptr = create_node(item);
    int success = 0;

    if (mem_ptr != NULL) {
        // we allocated space successfully
        success = 1;
        if (*list_ptr == NULL) {  // list is empty
            *list_ptr = &mem_ptr;  // simply connect them
        } else {  // list is not empty
            mem_ptr->link_ptr = list_ptr;
            *list_ptr = &mem_ptr;
        }
    }

    return success;
}