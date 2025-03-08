#pragma once

#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;

using std::string;

template<class T>
class Node
{
public:
	Node(const T &newData) : data(newData), mpLeft(nullptr), mpRight(nullptr) {};

	T getData() const;

	Node<T>* getLeftPtr() const;
	Node<T>* getRightPtr() const;

	void setLeftPtr(Node<T>* newLeftPtr);
	void setRightPtr(Node<T>* newRightPtr);

private:
	T data;
	Node<T>* mpLeft,
		   * mpRight;
};

template<class T>
T Node<T>::getData() const
{
    return this->data;
}

template<class T>
Node<T>* Node<T>::getLeftPtr() const
{
    return this->mpLeft;
}

template<class T>
Node<T>* Node<T>::getRightPtr() const
{
    return this->mpRight;
}

template<class T>
void Node<T>::setLeftPtr(Node<T>* newLeftPtr)
{
    this->mpLeft = newLeftPtr;
}

template<class T>
void Node<T>::setRightPtr(Node<T>* newRightPtr)
{
    this->mpRight = newRightPtr;
}
