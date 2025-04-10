/*
- Name: Logan Meyers
- TA: Martin Hundrup
- Date Finished: 04-09-2025
- Program: Student Absence Manager

- File: Node.hpp
- What: Template class declaration (plus function definitions) for the Node class, for my singly linked List
*/

#pragma once

#include "Data.hpp"

template <typename T>
class Node {

public:
    /* ----- Constructors & Destructors ----- */
    // constructor - blank
    Node() : data(T()), pNext(nullptr) {}
    // constructor - given data
    Node(T _data) : data(_data), pNext(nullptr) {}
    // constructor - given data & pNext
    Node(T _data, Node* _pNext) : data(_data), pNext(_pNext) {}
    // destructor
    ~Node() {}

    /* ----- Getters ----- */
    // return a copy of the data stored
    T getData() { return data; }
    // return a copy of the pNext Node* pointer
    Node* getNext() { return pNext; }

    /* ----- Setters ----- */
    // set the data
    void setData(T newData) { data = newData; }
    // set the new pointer
    void setNext(Node* newNext) { pNext = newNext; }

private:
    T data;
    Node* pNext;
};