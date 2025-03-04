#pragma once

#include "iostream"

using std::string;

template<typename T> class QueueNode {

private:
    T data;
    QueueNode<T>* mpNext;

public:
    QueueNode();
    QueueNode(T newData);
    ~QueueNode();

    T getData();
    void setData(T newData);

    QueueNode<T>* getNext();
    void setNext(QueueNode<T>* newNext);
};

template <typename T> QueueNode<T>::QueueNode() {
    this->data = T();
    this->mpNext = nullptr;
}
template <typename T> QueueNode<T>::QueueNode(T newData) : data(newData), mpNext(nullptr) {}
template <typename T> QueueNode<T>::~QueueNode() {}

template <typename T> T QueueNode<T>::getData() {
    return this->data;
}
template <typename T> void QueueNode<T>::setData(T newData) {
    this->data = newData;
}

template <typename T> QueueNode<T>* QueueNode<T>::getNext() {
    return this->mpNext;
}
template <typename T> void QueueNode<T>::setNext(QueueNode<T>* newNext) {
    this->mpNext = newNext;
}