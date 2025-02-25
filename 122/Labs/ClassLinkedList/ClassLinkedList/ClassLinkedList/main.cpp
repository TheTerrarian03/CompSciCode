#include "ListApp.h"

int main(void)
{
	// Start with debugging this project! "Step Into" each statement to answer the questions!
	// Question 1: what function is called in the statement below?
	ListNode n1;

	// the constructor ListNode(int newData = 0)

	// Question 2: what function is called in the statement below?
	ListNode n2(42); // shallow or deep copy?

	// constructor ListNode(int newData), deep copy

	// Question 3: what function is called in the statement below?
	ListNode n3(n2); // shallow or deep copy?

	// constructor, shallow copy

	// Question 4: what function is called in the statement below?
	ListNode n4 = n3; // shallow or deep copy?

	// copy constructor, shallow copy

	ListNode n5;
	// Question 5: what function/operator is called in the statement below?
	n5 = n4; // did we explicitly implement this function/operator?

	// It doesn't call anything and has been skipped, and there's no overloaded copy implemented

	// Question 6: what function is called in the statement below?
	List l1;
	// list constructor

	l1 = l1;

	// test values
	//l1.insertAtEnd(1);
	//l1.insertAtEnd(2);
	//l1.insertAtEnd(3);
	//l1.insertAtEnd(4);
	//l1.insertAtEnd(5);
	//l1.insertAtEnd(6);
	//l1.insertAtEnd(7);

	l1.printList();
	l1.deleteNode(1);
	l1.printList();


	// make sure that you finish implementing the copy constructor for the List object before you try to 
	// execute the next statement!
	// Question 7: what function is called in the statement below? What would happen if we did not 
	//             explicitly implement the function? Would the compiler generated one be good enough?
	List l2 = l1; // shallow or deep copy?
	// deep copy

	// the copy constructor, List(const List& copyList)
	// The compiler generated one may not be enough, especially for a linked list with pointers.
	// a shallow copy of a linked list makes an 'alias', where we want a deep copy
	// deep copy

	// Question 8: what would happen if a shallow copy constructor is used, instead of a deep copy constructor, 
	//             when the destructor for each list object is implicily invoked? l2 and l1 would have the same
	//             address stored in the head pointer, and thus, one of the lists would be freed and when the other went
	//             out of scope, the destructor would try to access already freed memory (a dangling pointer situation)!


	List l3;
	// make sure that you finish implementing the overloaded assignment for the List object before you try to 
	// execute the next statement!
	// Question 9: what function is called in the statement below? What would happen if we did not 
	//             explicitly implement the function? Would the compiler generated one be good enough?
	l3 = l2; // shallow or deep copy?

	// overloaded operator=
	// should be deep copy

	// Question 10: what would happen if a shallow copy assignment is used, instead of a deep copy assignment, 
	//              when the destructor for each list object is implicily invoked? l3 and l2 would have the same
	//              address stored in the head pointer, and thus, one of the lists would be freed and when the other went
	//              out of scope, the destructor would try to access already freed memory (a dangling pointer situation)!

	// Question 11: how does the List destructor free up the nodes? You will need to visit "List.cpp" to answer this question!

	// the List destructor frees up nodes by recursively destroying the nodes in reverse order
	// destroyList() is called, which does that

	ListApp app;

	app.runApp();

	return 0;
}
