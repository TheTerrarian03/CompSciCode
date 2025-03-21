#pragma once

#include "BSTNode.hpp"

#include <string>
#include <fstream>
#include <sstream>

class BST {

public:
    // constructor & destructor
    BST();
    ~BST();

    // general functions
    bool isEmpty() const;
    
    // in-order print
    void print() const;

    /* ---- public - facing interface for overloaded functions */

    // insert a node with the given char key and string value
    void insertNode(char _newKey, std::string _newValue);

    // find the value associated with a key
    std::string search(char _key) const;

    // normal binary tree stuff.
    void inOrderTransversal() const;
    void preOrderTransversal() const;  // unused
    void postOrderTransversal() const;  // unused
    void destroyTree();  // also unused

private:
    BSTNode* root;

    // overload for recursive calls

    // insert a node with the given char key and string value at the given node
    void insertNode(BSTNode** node, char _newKey, std::string _newValue);

    // return value associated with a key, in the given node's subtree
    std::string search(BSTNode* node, char _key) const;

    // normal binary tree stuff - prints
    void inOrderTransversal(BSTNode* node) const;
    void preOrderTransversal(BSTNode* node) const;  // unused
    void postOrderTransversal(BSTNode* node) const;  // unused
    void destroyTree(BSTNode** node);  // also unused
};
