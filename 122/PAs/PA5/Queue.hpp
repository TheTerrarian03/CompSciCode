#pragma once

#include "Data.hpp"
#include "QueueNode.hpp"

class Queue {

public:
    // constructors and destructors
    Queue() : pHead(nullptr), pTail(nullptr) {}
    Queue(const Queue &copy);
    ~Queue();
    Queue& operator= (const Queue& rhs) {
        // self-assignment check
        if (this == &rhs) {
            return *this;
        }
        
        // clear old queue
        while (!isEmpty()) {
            dequeue();
        }

        // copy from rhs to this queue
        QueueNode* pCur = rhs.pHead;
        while (pCur != nullptr) {
            Data d = pCur->getData();
            enqueue(d);
            pCur = pCur->getNext();
        }

        return *this;
    }

    // enqueue and dequeue
    void enqueue(Data &copy);
    Data dequeue();

    // other user-faced functions
    void print();
    bool isEmpty();
    Data getHeadData();
    int getLength();

    // simulation-related functions
    bool isCurrentDone() { return this->pHead != nullptr && this->pHead->getDataPtr()->getServiceTime() <= 0; }
    void decrementCurrentST() { if (this->pHead != nullptr) return this->pHead->getDataPtr()->decrementST(); }
    void incrementAllTT();

private:
    QueueNode *pHead,
              *pTail;

    void print(QueueNode *pNode);
    void print(std::ostream& outfile, QueueNode *pNode);
};

Queue::Queue(const Queue &copy) {
    // self check
    if (copy.pHead == nullptr) return;

    QueueNode* pCur = copy.pHead;
    
    while (pCur != nullptr) {
        enqueue(pCur->getData());
        pCur = pCur->getNext();
    }
}

Queue::~Queue() {}

void Queue::enqueue(Data &copy) {
    // try to allocate space for the new node
    QueueNode* pMem = new QueueNode(copy);
    if (pMem == nullptr) return;  // fail
    
    if (this->pHead == nullptr) {
        // empty queue
        this->pHead = this->pTail = pMem;
    } else {
        // non-empty queue
        this->pTail->setNext(pMem);
        this->pTail = pMem;
    }
}

Data Queue::dequeue() {
    if (isEmpty()) return Data();

    QueueNode *toDel = this->pHead;
    this->pHead = this->pHead->getNext();
    Data d = toDel->getData();

    delete(toDel);

    if (this->pHead == nullptr) this->pTail = nullptr;

    return d;
}

bool Queue::isEmpty() {
    return this->pHead == nullptr;
}

void Queue::print() {
    print(this->pHead);
}

void Queue::print(QueueNode *pNode) {
    if (pNode == nullptr) return;

    print(std::cout, pNode);

    print(pNode->getNext());
}

void Queue::print(std::ostream& outfile, QueueNode *pNode) {
    Data *d = pNode->getDataPtr();
    int tt_min = d->getTotalTime();
    
    outfile << "{ #" << d->getCustomerNumber()
        << " (-" << d->getServiceTime()
        << "min) [" << tt_min / 60
        << (((tt_min % 60) < 10) ? ":0" : ":")
        << tt_min % 60
        << "] } ";
}

Data Queue::getHeadData() {
    if (this->pHead == nullptr) return Data();
    return this->pHead->getData();
}

int Queue::getLength() {
    int len = 0;

    QueueNode *pCur = pHead;

    while (pCur != nullptr) {
        len++;
        pCur = pCur->getNext();
    }

    return len;
}

void Queue::incrementAllTT() {
    QueueNode* pCur = pHead;  // may be null

    while (pCur != nullptr) {
        pCur->getDataPtr()->incerementTT();
        pCur = pCur->getNext();
    }
}

// string insertion operator overload
std::ostream& operator<< (std::ostream& lhs, Queue& rhs) {
    if (!rhs.isEmpty()) rhs.print();
    return lhs;
}
