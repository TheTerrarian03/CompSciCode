#pragma once

#include "Node.hpp"

template <typename T>
class List {

public:
    // constructors and destructor    
    List() : mpHead(nullptr) {}
    List(const List<T>& copy);
    ~List();

    // setters
    void insertAtFront(const T newData);
    void deleteList();

    // getters
    bool isEmpty();
    T pop();

    void printList();
    int length();

private:
    // data members
    Node<T>* mpHead;

    // internal functions
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

template <typename T>
List<T>::~List() {
    deleteNode(mpHead);
}

template <typename T>
void List<T>::insertAtFront(const T newData) {
    Node<T>* wasHead = mpHead;

    mpHead = new Node<T>(newData);

    mpHead->setNext(wasHead);
}

template <typename T>
void List<T>::deleteList() {
    if (mpHead != nullptr) deleteNode(mpHead);
    mpHead = nullptr;
}

template <typename T>
bool List<T>::isEmpty() {
    return mpHead == nullptr;
}

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

template <typename T>
void List<T>::printList() {
    Node<T>* pCur = mpHead;

    while (pCur != nullptr) {
        std::cout << pCur->getData();
        pCur = pCur->getNext();
    }

    std::cout << std::endl;
}

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

// side note: on my machine, it turns out that past 150000 records is too many
// for the list to be able to delete, and seg faults when trying. So,
// please don't have more than 150000 students you have to keep track of.
template <typename T>
void List<T>::deleteNode(Node<T> *node) {
    if (node == nullptr) return;

    deleteNode(node->getNext());

    delete node;
}