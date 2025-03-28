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
    void insertAtFront(const Data newData);

    // getters
    bool isEmpty();

    void printList();

private:
    Node<Data>* mpHead;
};
