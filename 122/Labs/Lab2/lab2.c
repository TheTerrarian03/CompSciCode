#include "lab2.h"

// TASK 1

// Description: Allocates space for a Node on the heap and initializes the Node with the information found in newData. 
// Returns: The address of the start of the block of memory on the heap or NULL if no memory was allocated  
Node *makeNode(Contact newData) {
    Node *node = malloc(sizeof(Node));

    if (node != NULL) {
        // pointer exists, init info
        node->pNext = NULL;
        node->data = newData;
    }
    else fprintf(stderr, "makeNode() failed to make space for node.\n");

    return node;
}
 
// Description: Uses makeNode () to allocate space for a new Node and inserts the new Node at the front 
// Returns: TRUE if memory was  allocated for a Node; FALSE otherwise 
Boolean insertAtFront(Node **pList, Contact newData) {
    Node *newNode = makeNode(newData);

    if (newNode == NULL) return FALSE;

    newNode->pNext = *pList;

    *pList = newNode;

    return TRUE;
}

// Description: Uses makeNode () to allocate space for a new Node and inserts the new Node into the list in alphabetic order ('a' - 'z') 
//              based on the name field 
// Returns: TRUE if memory was  allocated for a Node; FALSE otherwise 
Boolean insertContactInOrder(Node **pList, Contact newData) {
    Node *newNode = makeNode(newData);

    if (newNode == NULL) return FALSE;

    // // if there's an empty list, replace the pointer with the allocated space
    // if (*pList == NULL) *pList = newNode;

    // Node *pCur = *pList;

    // while (pCur->pNext != NULL) {
    //     if (strcmp(pCur->data.name, pCur->pNext->data.name) <= 0) {
    //         // insert in between pCur and pNext

    //         newNode->pNext = pCur->pNext;
    //         pCur->pNext = newNode;
    //     }
        
    //     pCur = pCur->pNext;
    // }

    // pCur->pNext = newNode;
    
    // return TRUE;
}

// Description: Deletes a Contact in the list based on the name field; deletes the first occurence of the name 
// Returns: TRUE if the Contact was found; FALSE otherwise 
Boolean deleteContact(Node **pList, Contact searchContact) {
    Node *current = *pList;
    Node *last = NULL;

    while (current != NULL) {
        printf("Sees: %s\n", current->data.name);

        if (strcmp(current->data.name, searchContact.name) == 0) {
            printf("Found!\n");
            if (last) {
                last->pNext = current->pNext;
            } else {
                *pList = current->pNext;
            }
            break;
        }

        last = current;
        current = current->pNext;
        // free(current);
    }

    return FALSE;
}
 
// Description: Edits a Contact in the list based on the name field; edits the first occurence of the name 
// Returns: TRUE if the Contact was found; FALSE otherwise 
Boolean editContact(Node *pList, Contact searchContact); 
 
// Description: Loads all Contact information from the given file, in alphabetic order, based on the name, into the list 
// Returns: TRUE if all Contacts were loaded; FALSE otherwise 
//
// create buffer
// fgets lines until feof
// strncpy to contact with strtok with ',' and ',\n'
Boolean loadContacts(FILE *infile, Node **pList); 
 
// Description: Stores all Contact information from the list into the given file 
// Returns: TRUE if all Contacts were stored; FALSE otherwise 
//
// can be done recursively
// just write data to the file
Boolean storeContacts(FILE *outfile, Node *pList);
 
// Description: Prints all contact information in the list 
// Returns: Nothing 
void printList(Node *pList) {
    if (pList == NULL) return;

    printf("%s\n- Title: %s\n- Phone: %s\n- Email: %s\n\n",
        pList->data.name,
        pList->data.title,
        pList->data.phone,
        pList->data.email);

    printList(pList->pNext);
}

// TASK 2