#pragma once

#include "Data.hpp"

template <typename T>
class Node {

public:
    // constructors, destructor    
    Node() : data(T()), pNext(nullptr) {}
    Node(T _data) : data(_data), pNext(nullptr) {}
    Node(T _data, Node* _pNext) : data(_data), pNext(_pNext) {}
    ~Node() {}

    // getters
    T getData() { return data; }
    Node* getNext() { return pNext; }

    // setters
    void setData(T newData) { data = newData; }
    void setNext(Node* newNext) { pNext = newNext; }

private:
    T data;
    Node* pNext;
};