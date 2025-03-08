#pragma once

#include "Data.hpp"

class QueueNode {

public:
    // constructors and destructor
    QueueNode() : pData(nullptr), pNext(nullptr) {};
    QueueNode(Data &data) : pNext(nullptr) { this->pData = new Data(data); }
    QueueNode(Data *newData, QueueNode *nextNode) : pData(newData), pNext(nextNode) {}
    QueueNode(QueueNode &rhs);

    // setters
    void setData(Data &data) {
        delete this->pData;
        this->pData = new Data(data);
    }
    void setNext(QueueNode *newNext) { this->pNext = newNext; }

    // getters
    Data& getData() { return *(this->pData); }
    Data *getDataPtr() { return this->pData; }
    QueueNode* getNext() { return this->pNext; }

private:
    Data *pData;  // allocated on the heap
    QueueNode *pNext;
};

// overloaded string insertion
std::ostream& operator<< (std::ostream& lhs, QueueNode &rhs) {
    if (rhs.getDataPtr()) lhs << rhs.getData() << std::endl;
    if (rhs.getNext() != nullptr) lhs << rhs.getNext() << std::endl;
    return lhs;
}

// bonus: grocery items
//  singly linked list of items
//  adjust serviceTime accordingly