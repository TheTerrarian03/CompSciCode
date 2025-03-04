#pragma once

#include "QueueNode.hpp"

/*
template<typename T> class Node {

    T data;

}
*/

template<typename T>
class Queue {

private:
    QueueNode<T>* mpHead,
                * mpTail;

    void printQueueRecursive(QueueNode<T> *head);

public:
    ~Queue<T>();

    bool isEmpty();
    bool enqueue(T newData);
    T dequeue();
    void print();
};

template<typename T> Queue<T>::~Queue<T>() {
    while (this->mpHead != nullptr) {
        dequeue();
    }
}

template <typename T> bool Queue<T>::isEmpty() {
    return (this->mpHead == nullptr) ? true : false;
}
template <typename T> bool Queue<T>::enqueue(T newData) {
    QueueNode<T>* pMem = new QueueNode(newData);

    if (pMem == nullptr) return false;

    if (this->mpHead == nullptr) {
        this->mpHead = this->mpTail = pMem;
    } else {
        this->mpTail->setNext(pMem);
        this->mpTail = pMem;
    }

    return true;
}
template <typename T> T Queue<T>::dequeue() {
    if (isEmpty()) return T();

    QueueNode<T> *toDel = this->mpHead;
    this->mpHead = mpHead->getNext();
    T t = toDel->getData();

    delete(toDel);

    if (this->mpHead == nullptr) this->mpTail = nullptr;

    return t;
}
template <typename T> void Queue<T>::print() {
    this->printQueueRecursive(this->mpHead);
}
template<typename T> void Queue<T>::printQueueRecursive(QueueNode<T> *head) {
    if (head == nullptr) return;
    std::cout << head->getData() << std::endl;
    printQueueRecursive(head->getNext());
}