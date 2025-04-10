/*
- Name: Logan Meyers
- TA: Martin Hundrup
- Date Finished: 04-09-2025
- Program: Student Absence Manager

- File: List.hpp
- What: Template class declaration (plus function definitions) for my singly linked List class
*/

#pragma once

#include "Node.hpp"

template <typename T>
class List {

public:
    /* ----- Constructors & Destructors ----- */
    List() : mpHead(nullptr) {}
    List(const List<T>& copy);
    ~List();

    /* ----- Getters ----- */
    void insertAtFront(const T newData);
    void deleteList();

    /* ----- Setters ----- */
    bool isEmpty();
    T pop();
    int length();

    /* ----- Helpers ----- */
    void printList();

private:
    /* ----- data members ----- */
    Node<T>* mpHead;

    /* ----- internal functions ----- */
    void deleteNode(Node<T> *node);
};

template <typename T>
List<T>::List(const List<T>& copy) : mpHead(nullptr) {
    this->deleteList();  // delete in case

    // stop if copy has no nodes
    if (copy.mpHead == nullptr) return;
    
    // root node
    mpHead = new Node<T>(copy.mpHead->getData());

    // loop through rest of nodes copy has, and made copies of nodes
    Node<T>* pCur = mpHead;
    Node<T>* pOther = copy.mpHead->getNext();  // pOther will be one node ahead of pCur

    while (pOther != nullptr) {
        // copy's next has data, set pCur next to new node with copy of that data
        pCur->setNext(new Node<T>(pOther->getData()));
                
        // shift pCur and pOther
        pCur = pCur->getNext();
        pOther = pOther->getNext();
    }
}

/*
 * Function: ~List
 * --------------------
 *   Destructor for List
 *
*/
template <typename T>
List<T>::~List() {
    deleteNode(mpHead);
}

/*
 * Function: insertAtFront
 * --------------------
 *   Insert a copy of newData to the front of the list
 *
 *   Parameters:
 *   - newData: constant data of type T to copy from
 *
*/
template <typename T>
void List<T>::insertAtFront(const T newData) {
    Node<T>* wasHead = mpHead;

    mpHead = new Node<T>(newData);

    mpHead->setNext(wasHead);
}

/*
 * Function: deleteList
 * --------------------
 *   Public deletion function for erasing a List
 *
*/
template <typename T>
void List<T>::deleteList() {
    if (mpHead != nullptr) deleteNode(mpHead);
    mpHead = nullptr;
}

/*
 * Function: isEmpty
 * --------------------
 *   Get whether or not the List contains 0 items
 *
 *   Returns:
 *   - bool, is empty (true) or not (false)
*/
template <typename T>
bool List<T>::isEmpty() {
    return mpHead == nullptr;
}

/*
 * Function: pop
 * --------------------
 *   Delete and return the frontmost item from the List
 *
 *   Returns:
 *   - copy of data of type T
*/
template <typename T>
T List<T>::pop() {
    // get data from top, including pointer for deletion
    T data = mpHead->getData();
    Node<T>* toDel = mpHead;
    
    // set new head to next
    mpHead = mpHead->getNext();

    // delete node and return data
    delete toDel;
    return data;
}

/*
 * Function: length
 * --------------------
 *   Get the length (number of nodes) in the List
 *
 *   Returns:
 *   - int, positive [0,inf)
*/
template <typename T>
int List<T>::length() {
    Node<T>* pCur = mpHead;
    int len = 0;

    while (pCur != nullptr) {
        len++;
        pCur = pCur->getNext();
    }

    return len;
}

/*
 * Function: printList
 * --------------------
 *   Print the list out to the screen, including all data inside the nodes
 *
*/
template <typename T>
void List<T>::printList() {
    Node<T>* pCur = mpHead;

    while (pCur != nullptr) {
        std::cout << pCur->getData();
        pCur = pCur->getNext();
    }

    std::cout << std::endl;
}

// side note: on my machine, it turns out that past 150000 records is too many
// for the list to be able to delete, and seg faults when trying. So,
// please don't have more than 150000 students you have to keep track of.
/*
 * Function: deleteNode
 * --------------------
 *   Internal function for deleting a node from the list.
 *   Recursively calls itself for next nodes until null.
 *
 *   Parameters:
 *   - node: the pointer of the node to delete
 *
*/
template <typename T>
void List<T>::deleteNode(Node<T> *node) {
    if (node == nullptr) return;

    deleteNode(node->getNext());

    delete node;
}