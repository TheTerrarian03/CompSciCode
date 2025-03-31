#pragma once

#include "Node.hpp"

template <typename T>
class List {

public:
    // constructors and destructor    
    List() : mpHead(nullptr) {}
    // List(const List& copy);
    ~List();

    // setters
    void insertAtFront(const T newData);
    void deleteList();

    // getters
    bool isEmpty();

    void printList();

private:
    // data members
    Node<T>* mpHead;

    // internal functions
    void deleteNode(Node<T> *node);
};

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
    deleteNode(mpHead);
    mpHead = nullptr;
}

template <typename T>
bool List<T>::isEmpty() {

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
void List<T>::deleteNode(Node<T> *node) {
    if (node == nullptr) return;

    deleteNode(node->getNext());

    delete node;
}