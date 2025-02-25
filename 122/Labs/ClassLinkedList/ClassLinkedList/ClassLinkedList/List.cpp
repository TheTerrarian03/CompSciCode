#include "List.h"

// default constructor; will always set mpHead to NULL or nullptr
List::List()
{
	mpHead = nullptr;
}

// copy constructor - implicitly invoked copying a List object during construction of 
// another List object, or when a List object is passed-by-value - must perform a deep copy, 
// which means create new memory for each node copied!
List::List(const List& copyList)
{
	this->mpHead = nullptr;

	ListNode* pCur = copyList.mpHead;
	while (pCur != nullptr) {
		this->insertAtEnd(pCur->getData());
		pCur = pCur->getNextPtr();
	}
}

List::~List()                   // destructor - implicitly invoked when a List object leaves scope
{
	cout << "Inside List's destructor! Freeing each ListNode in the List!" << endl;
	destroyList();
}

// this function must allocate new memory for each of the nodes in rhs to construct "this" object
List& List::operator= (const List& rhs) // overloaded assignment operator - must perform a deep copy
{
	// you must use a loop, which visits each of the nodes in List rhs, and assign the data to the new nodes
	// How to use new operator? ListNode *pMem = new ListNode; new is similar to the results of using malloc ()
	
	// ^^ this advice is taking into account for insertAtEnd() ^^

	if (this == &rhs) return (*this);

	this->destroyList();

	this->mpHead = nullptr;

	ListNode* pCur = rhs.mpHead;
	while (pCur != nullptr) {
		this->insertAtEnd(pCur->getData());
		pCur = pCur->getNextPtr();
	}

	return (*this);
}

// getter
ListNode* List::getHeadPtr() const     // returns a copy of the address stored in mpHead
{
	return mpHead;
}

// setter
void List::setHeadPtr(ListNode* const pNewHead) // modifies mpHead
{
	mpHead = pNewHead;
}

// This function creates a new ListNode on the heap, and uses the ListNode constructor to initialize the node!
bool List::insertAtFront(const int newData)     // inserts newData at the beginning or front of the list
{
	ListNode* pMem = makeNode(newData);
	bool success = false;                   // C++ has built in bool types - false, true

	if (pMem != nullptr)
	{
		success = true; // allocated memory successfully
		// pMem is pointing to a ListNode object, but a List object does not have direct access to it; must use a setter!
		pMem->setNextPtr(mpHead);
		mpHead = pMem;
	}

	return success;
}

// insert newData in ascending order
bool List::insertInOrder(const int newData)
{
	bool success = false;

	// try making space for new node
	ListNode* pMem = new ListNode(newData);

	if (pMem != nullptr) {
		success = true;  // allocated successfully

		// empty
		if (this->mpHead == nullptr) {
			this->mpHead = pMem;
		}
		// not empty
		else {
			ListNode* pCur = this->mpHead;

			// find where the new data fits
			while (pCur->getNextPtr() != nullptr && pCur->getNextPtr()->getData() < newData) {
				pCur = pCur->getNextPtr();
			}

			// add link
			pCur->setNextPtr(pMem);
		}
	}

	return success;
}

// inserts newData at the end of the list
bool List::insertAtEnd(const int newData)
{
	bool success = false;

	// try making space for new node
	ListNode* pMem = new ListNode(newData);

	if (pMem != nullptr) {
		success = true;  // allocated successfully

		// empty
		if (this->mpHead == nullptr) {
			this->mpHead = pMem;
		}
		// not empty
		else {
			ListNode* pCur = this->mpHead;

			// find end of list
			while (pCur->getNextPtr() != nullptr) {
				pCur = pCur->getNextPtr();
			}

			// set next to newly created pMem
			pCur->setNextPtr(pMem);
		}
	}
	
	return success;
}

// determines if the list is empty;  
// returns true if the list is empty; false otherwise
bool List::isEmpty()
{
	return (mpHead == nullptr);
}

// deletes the node at the front of the list and returns a copy of the data
// precondition: list must not be empty
int List::deleteAtFront()
{
	int data = 0;

	// precondition safety
	if (this->mpHead == nullptr) return data;

	ListNode* pNext = this->mpHead->getNextPtr();  // may be null or another *ListNode

	// get data and delete
	data = this->mpHead->getData();
	delete this->mpHead;

	// update head
	this->mpHead = pNext;  // may be null or another *ListNode

	return data;
}

// deletes the node with data == searchValue;
// returns true if the value was found; false otherwise
// precondition: list must not be empty
bool List::deleteNode(const int searchValue)
{
	if (this->mpHead == nullptr) return true;

	ListNode* pCur = this->mpHead;
	ListNode* pPrev = nullptr;  // for keeping track of dangling pointers

	// find matching ListNode
	while (pCur != nullptr && pCur->getData() != searchValue) {
		std::cout << "Cur: " << pCur->getData() << ", Search: " << searchValue << std::endl;
		pPrev = pCur;
		pCur = pCur->getNextPtr();
	}

	if (pCur == nullptr) return false;  // matching node not found, fail

	// get next, delete, and fix links
	ListNode* pNext = pCur->getNextPtr();  // may be null or another *ListNode
	delete pCur;
	
	if (pPrev != nullptr) pPrev->setNextPtr(pNext);  // middle/end of list
	else this->mpHead = pNext;  // start of list

	return true;  // success
}

// deletes the node at the end of the list and returns a copy of the data
// precondition: list must not be empty
int List::deleteAtEnd()
{
	int data = 0;

	if (this->mpHead == nullptr) return data;

	ListNode* pCur = this->mpHead;
	ListNode* pPrev = nullptr;  // for keeping track of dangling pointers

	// find end of list
	while (pCur->getNextPtr() != nullptr) {
		pPrev = pCur;
		pCur = pCur->getNextPtr();
	}

	// get data and delete
	data = pCur->getData();
	delete pCur;

	// fix dangling pointers
	if (pPrev != nullptr) pPrev->setNextPtr(nullptr);  // list still full
	else this->mpHead = nullptr;  // list now empty

	return data;
}

// visits each node, print the node's data
void List::printList()
{
	ListNode* pCur = mpHead;

	while (pCur != nullptr)
	{
		cout << pCur->getData() << endl;
		pCur = pCur->getNextPtr();
	}
}


//////////// private member functions! //////////////

// allocates memory for a Listnode; initializes the memory with newData
ListNode* List::makeNode(const int newData)    // will only call within insert functions
{
	ListNode* pMem = new ListNode(newData);  // ListNode constructor is invoked!

	return pMem;
}

// we created this function so that we could use recursion to delete the nodes!
void List::destroyListHelper(ListNode* const pMem)
{
	if (pMem != nullptr)
	{
		destroyListHelper(pMem->getNextPtr());
		delete pMem;    // delete from the back of list to the front!
	}
}

// deletes each node to free memory; will call in the destructor
void List::destroyList()
{
	destroyListHelper(mpHead);
}