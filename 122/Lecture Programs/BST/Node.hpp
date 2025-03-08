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

class Node
{
public:
	Node(string newData) : data(newData), mpLeft(nullptr), mpRight(nullptr) {};

	string getData() const;

	Node* getLeftPtr() const;
	Node* getRightPtr() const;

	void setLeftPtr(Node* newLeftPtr);
	void setRightPtr(Node* newRightPtr);

private:
	string data;
	Node* mpLeft,
		* mpRight;
};

string Node::getData() const
{
    return this->data;
}

Node* Node::getLeftPtr() const
{
    return this->mpLeft;
}

Node* Node::getRightPtr() const
{
    return this->mpRight;
}

void Node::setLeftPtr(Node* newLeftPtr)
{
    this->mpLeft = newLeftPtr;
}

void Node::setRightPtr(Node* newRightPtr)
{
    this->mpRight = newRightPtr;
}
