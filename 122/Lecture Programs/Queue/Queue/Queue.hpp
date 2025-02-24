#pragma once

#include <iostream>
#include "Node.hpp"

using std::cin;
using std::cout;
using std::endl;

class Queue {

private:
	Node* mpHead, * mpTail;

public:
	// constructor
	Queue();

	// insert at tail/end of queue
	bool enqueue(string newData);
	// queue must not be empty
	string dequeue();

	// predicate function
	bool is_empty() const;
};

Queue::Queue() {
	this->mpHead = nullptr;
	this->mpTail = nullptr;
}

bool Queue::enqueue(string newData) {
	Node* pMem = new Node(newData);  // constructor for Node gets called here w/ new
	bool success = false;

	if (pMem != nullptr) {
		// allocated space on heap successfully
		if (this->mpHead == nullptr) {
			// empty queue
			this->mpHead = this->mpTail = pMem;
		}
		else {
			// queue not empty
			this->mpTail->setNextPtr(pMem);
			this->mpTail = pMem;
		}

		success = true;
	}
		
	return success;
}

string Queue::dequeue() {
	string data = this->mpHead->getData();
	Node* pTemp = this->mpHead;  // refers to Node to delete

	this->mpHead = this->mpHead->getNextPtr();

	if (mpHead == nullptr) {
		mpTail = nullptr;
	}

	delete pTemp;  // invokes a node's destructor the for the object that's removed
	cout << "finished removing job \"" << data << "\"." << endl;

	return data;
}

bool Queue::is_empty() const {
	return this->mpHead == nullptr && this->mpTail == nullptr;
}