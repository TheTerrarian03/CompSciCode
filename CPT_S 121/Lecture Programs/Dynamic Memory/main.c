#include <stdio.h>
#include <stdlib.h>  // malloc(), calloc(), free()
#include <string.h>

// malloc is manual allocation of memory
// calloc is allocation of arrays, and those arrays can change
// free for freeing memory

// Linked Lists are like arrays of Nodes,
// where any Node has data and a pointer to another Node.
// There is a head/start pointer to the first Node.

// TYPEDEFS

typedef struct node {
    char grocery_item[50];
    struct node *link_ptr;  // self-referential struct (not recursion)
} Node;

// FUNCTION HEADERS

Node *create_node(char *item);
int insert_at_front(Node **list_ptr, char *item);  // list operation
char *delete_at_front(Node **list_ptr);
void print_list(Node *list_ptr);

// MAIN

int main() {
    Node *head_ptr = NULL;
    int success = 0;

    success = insert_at_front(&head_ptr, "bread");
    success = insert_at_front(&head_ptr, "eggs");
    success = insert_at_front(&head_ptr, "bananas");

    print_list(head_ptr);

    // printf("Success: %d, Item: %s\n", success, head_ptr->grocery_item);

    return 0;
}

// FUNCTIONS

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
        strcpy(mem_ptr->grocery_item, item);
    }

    return success;
}

char *delete_at_front(Node **list_ptr) {
    // make pointer refering to first node in list
    Node *tmp_ptr = *list_ptr;

    // Update head pointer through list pointer
    // Set head pointer to next node in sequence
    *list_ptr = tmp_ptr -> link_ptr;

    // copy string to return
    char data[50] = "";
    strcpy(data, (*list_ptr)->grocery_item);

    // delete node
    free(tmp_ptr);

    // return string removed
    return data;
}

void print_list(Node *list_ptr) {
    printf("-->");


    int c = 0;
    
    while (list_ptr != NULL) {
        printf("%s --> ", list_ptr->grocery_item);
        list_ptr = list_ptr->link_ptr;

    }
    putchar('\n');
}