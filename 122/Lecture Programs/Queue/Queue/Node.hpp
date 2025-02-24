#pragma once

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Node {

public:
	// constructor
	Node(const string& newData = "");  // literal string of "" requires a constant reference

	// setters
	void setNextPtr(Node* newNextPtr);  // parameter considered constant, so the address stores is not constant.

	// getters
	string getData() const;
	Node* getNextPtr() const;

private:
	string mJob;
	Node* mpNext;
};

Node::Node(const string& newData) {
	// no validation required for newData
	this->mJob = newData;

	this->mpNext = nullptr;
}

void Node::setNextPtr(Node* newNextPtr) {
	this->mpNext = newNextPtr;
}
string Node::getData() const {
	return this->mJob;
}
Node* Node::getNextPtr() const {
	return this->mpNext;
}