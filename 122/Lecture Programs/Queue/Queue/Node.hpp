#pragma once

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Node {

public:
	Node(const string& newData = "");  // literal string of "" requires a constant reference
	void setNextPtr(Node* const newNextPtr);  // parameter considered constant, so the address stores is not constant.

private:
	string mJob;
	Node* mpNext;
};

Node::Node(const string& newData) {
	// no validation required for newData
	this->mJob = newData;

	this->mpNext = nullptr;
}

void Node::setNextPtr(Node* const newNextPtr) {
	this->mpNext = newNextPtr;
}