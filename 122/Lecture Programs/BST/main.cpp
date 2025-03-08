// In this example we'll build a binary search tree (BST) from scratch. We'll use
// the BST to search for names.

// History: 2/28/25 - Add the private data members to the Node class.

#include "BST.hpp"

int main(void)
{
	BST tree;

	tree.insert("Max");
	tree.insert("Erin");
	tree.insert("Noah");
	tree.insert("Frank");
	tree.insert("Naomi");

	tree.inorderTraversal();

	return 0;
}

// in order traversal:
// recursive function to:
	// traverse left node if possible
	// process current node data
	// traverse right node if possible