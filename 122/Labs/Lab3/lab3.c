#include "lab3.h"

// TASK 1

// Description: Allocates space for a Node on the heap and initializes the Node with the information found in newData. 
// Returns: The address of the start of the block of memory on the heap or NULL if no memory was allocated  
Node *makeNode(Contact newData) {
    Node *node = malloc(sizeof(Node));

    if (node != NULL) {
        // pointer exists, init info
        node->data = newData;
        node->pNext = NULL;
        node->pPrev = NULL;
    }
    else fprintf(stderr, "makeNode() failed to make space for node.\n");

    return node;
}
 
// Description: Uses makeNode () to allocate space for a new Node and inserts the new Node at the front 
// Returns: TRUE if memory was  allocated for a Node; FALSE otherwise 
Boolean insertAtFront(Node **pList, Contact newData) {
    // empty list
    if (*pList == NULL) {
        *pList = makeNode(newData);
        return TRUE;
    }

    // not empty
    Node *pMem = makeNode(newData);
    pMem->pNext = *pList;
    (*pList)->pPrev = pMem;
    *pList = pMem;

    return TRUE;
}

Boolean insertAtBack(Node **pList, Contact newData) {
    // empty list
    if (*pList == NULL) {
        *pList = makeNode(newData);
        return TRUE;
    }

    // non empty
    Node *pCur = *pList;

    // find back
    while (pCur->pNext != NULL) {
        pCur = pCur->pNext;
    }

    // allocate space
    Node *pMem = makeNode(newData);

    // make links
    pCur->pNext = pMem;
    pMem->pPrev = pCur;

    return TRUE;
}

// Description: Uses makeNode () to allocate space for a new Node and inserts the new Node into the list in alphabetic order ('a' - 'z') 
//              based on the name field 
// Returns: TRUE if memory was  allocated for a Node; FALSE otherwise 
Boolean insertContactInOrder(Node **pList, Contact newData) {
    // empty list
    if (*pList == NULL) {
        *pList = makeNode(newData);
        printf("inserted to empty\n");
        return TRUE;
    }

    // inserting at front
    // next > new
    // call insert at front
    if (strcmp((*pList)->data.name, newData.name) > 0) {
        insertAtFront(pList, newData);
        printf("inserted front\n");
        return TRUE;
    }

    // non empty
    Node *pCur = *pList;

    // find back
    // while next data < data
    // less than prioritizes efficiency inserting at front rather than back
    while (pCur->pNext != NULL && strcmp(pCur->pNext->data.name, newData.name) < 0) {
        pCur = pCur->pNext;

        if (pCur->pNext == NULL) {
            insertAtBack(pList, newData);
            printf("inserted back\n");
            return TRUE;
        }
    }

    // allocate space
    Node *pMem = makeNode(newData);

    // make links
    // next and prev of mem to cur
    pMem->pNext = pCur->pNext;
    pMem->pPrev = pCur;

    // set next and prev of cur to mem
    // if pnew has p next, then make the reverse link
    pCur->pNext = pMem;
    if (pMem->pNext) {
        pMem->pNext->pPrev = pMem;
    }

    return TRUE;

    // // inserting to a non-empty list
    // if (strcmp((*pList)->data.name, newData.name) > 0) {
    //     // allocate space
    //     Node *pMem = makeNode(newData);

    //     // set pMem next and prev pointers
    //     pMem->pNext = *pList;
    //     pMem->pPrev = (*pList)->pPrev;

    //     // replace old links
    //     pMem->pNext->pPrev = pMem;

    //     // 
    //     if (pMem->pPrev != NULL) {
    //         (*pList)->pPrev->pNext = pMem;
    //         *pList = pMem;
    //     }

    //     // set current pointer to pMem

    //     return TRUE;
    // }

    // // recursive call
    // return insertContactInOrder(&(*pList)->pNext, newData);
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

/*
print reverse

same as print list but given pTail

call reverse print recursively
give pTail->pPrev
*/


/*
get pTail

return NULL if NULL given

find end of the list like with insert back

return pCur
*/

// TASK 2