#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "Node.hpp"

using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;

using std::string;

class BST
{
public:
	BST();

	void insert(string newData);
    void inorderTraversal() const;

private:
	void insert(string newData, Node* pTree);
    void inorderTraversal(Node* pTree) const;

	Node* mpRoot;
};

BST::BST()
{
	// empty tree
	this->mpRoot = nullptr;
}

void BST::insert(string newData)
{
	insert(newData, this->mpRoot);
}

void BST::inorderTraversal() const {
    inorderTraversal(this->mpRoot);
}

void BST::insert(string newData, Node* pTree)
{
	if (nullptr == pTree) // tree is empty
	{
		this->mpRoot = new Node(newData);
	}
	else // inserting into a non empty tree
	{
		if (newData < pTree->getData()) // left subtree
		{
			// inserting in left subtree
			if (pTree->getLeftPtr() == nullptr)
			{
				pTree->setLeftPtr(new Node(newData));
			}
			else
			{
				// we have to move further down the left subtree to find
				// the slot to insert into the tree
				insert(newData, pTree->getLeftPtr());
			}
		}
		else if (newData > pTree->getData()) // right subtree
		{
			if (pTree->getRightPtr() == nullptr)
			{
				// we found the place to insert in the right subtree
				pTree->setRightPtr(new Node(newData));
			}
			else
			{
				// we need to go further down right subtree
				insert(newData, pTree->getRightPtr());
			}
		}
		else // duplicate entry
		{
			cout << "trying to insert duplicate: " << newData << endl;
		}
	}
}

void BST::inorderTraversal(Node* pTree) const {
    // recursive step
    if (pTree != nullptr) {
        // go left
        inorderTraversal(pTree->getLeftPtr());

        // process
        cout << pTree->getData() << endl;

        // go right
        inorderTraversal(pTree->getRightPtr());
    }
}