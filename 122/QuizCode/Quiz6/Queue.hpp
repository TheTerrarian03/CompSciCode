#include <iostream>

using std::string;

class Queue
{
public:
		Queue(int newSize = 0);
		~Queue();

		bool enqueue(string &newItem); 
		bool dequeue(string &removedItem);

		bool isEmpty();

private:
		int mSize; // represents the number of items in the queue
		int mMaxSize; // must not exceed the max size of our allocated array
// the heap (an array)
		string *mpFront; // will point to the beginning of contiguous memory on 

        void resizeQueue(int newSize);
};

// constructor
Queue::Queue(int newSize) {
    mMaxSize = (newSize > 0) ? newSize : 5;
    mpFront = new string[mMaxSize];
    mSize = 0;
}

// destructor
Queue::~Queue() {
    delete[] mpFront;
}

// Place your function definition for enqueue() below.

//  Description: Inserts the item at the end of the queue. A successful insert 
//             increases mSize by 1.
//
// Returns: True if the item was inserted into the contiguous memory; false otherwise.
//
// Precondition: mpFront must already point to contiguous memory; specifically 
//               item at index 0.
//
// Errors: Check that mSize does not exceed mMaxSize; if the item cannot be inserted because //         the mMaxSize is exceeded, then return false.
bool Queue::enqueue(string &newItem) {
    // stop if mpFront doesn't point to anything
    if (this->mpFront == nullptr) return false;

    // stop if we've reached the max size of our current array
    if (this->mSize == this->mMaxSize) return false;
    // optionally, we could resize the array to be one bigger and continue instead of returning

    // set string to it's spot and increment mSize
    this->mpFront[this->mSize] = newItem;
    this->mSize++;

    // success!
    return true;
}

// Dequeue and store into removedItem
bool Queue::dequeue(string &removedItem) {
    if (this->isEmpty()) return false;


}

// check if list empty
bool Queue::isEmpty() {
    return (this->mSize == 0) ? true : false;
}

// resize queue
// assuming newSize >= 1
void Queue::resizeQueue(int newSize) {
    // allocate new space
    string *newQueue = new string[newSize];

    // copy data to new queue
    for (int i=0; i < this->mSize; i++) {
        if (i > newSize) break;  // don't copy more than the new array can hold

        newQueue[i] = this->mpFront[i];
    }

    // deallocate old memory
    delete[] this->mpFront;

    // set new pointer and max size
    this->mpFront = newQueue;
    this->mMaxSize = newSize;
}
