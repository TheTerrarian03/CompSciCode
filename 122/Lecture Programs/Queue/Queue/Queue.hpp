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
	bool enqueue(string& newData);
};

bool Queue::enqueue(string& newData) {
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