// In this example we'll build a binary search tree (BST) from scratch. We'll use
// the BST to search for names.

// History: 2/28/25 - Add the private data members to the Node class.

#include "BST.hpp"

int main(void)
{
	BST<string> tree;
	BST<int> tree2;

	tree.insert("Max");
	tree.insert("Erin");
	tree.insert("Noah");
	tree.insert("Frank");
	tree.insert("Naomi");

	tree2.insert(10);
	tree2.insert(15);
	tree2.insert(20);
	tree2.insert(5);
	tree2.insert(68);

	tree.inorderTraversal();
	tree2.inorderTraversal();
	tree2.preOrderTraversal();
	tree2.postOrderTraversal();

	return 0;
}

// in order traversal:
// recursive function to:
	// traverse left node if possible
	// process current node data
	// traverse right node if possible