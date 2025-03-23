/*
- File: BST.hpp
- Description: Function declerations and variables for the BST class, plus definitions
- BST class: This is the class for a BST, with any KEY and VALUE in the nodes

- Modified: 03/23/2025
*/

#pragma once

#include "BSTNode.hpp"

#include <string>
#include <fstream>
#include <sstream>

template <typename KEY, typename VALUE>
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
    void insertNode(KEY _newKey, VALUE _newValue);

    // find the value associated with a key
    VALUE search(KEY _key) const;

    // normal binary tree stuff.
    void inOrderTransversal() const;
    void preOrderTransversal() const;  // unused
    void postOrderTransversal() const;  // unused
    void destroyTree();  // also unused

private:
    BSTNode<KEY, VALUE>* root;

    // overload for recursive calls

    // insert a node with the given char key and string value at the given node
    void insertNode(BSTNode<KEY, VALUE>** node, KEY _newKey, VALUE _newValue);

    // return value associated with a key, in the given node's subtree
    VALUE search(BSTNode<KEY, VALUE>* node, KEY _key) const;

    // normal binary tree stuff - prints
    void inOrderTransversal(BSTNode<KEY, VALUE>* node) const;
    void preOrderTransversal(BSTNode<KEY, VALUE>* node) const;  // unused
    void postOrderTransversal(BSTNode<KEY, VALUE>* node) const;  // unused
    void destroyTree(BSTNode<KEY, VALUE>** node);  // also unused
};

// constructor
template <typename KEY, typename VALUE>
BST<KEY, VALUE>::BST() {
    root = nullptr;

    std::ifstream infile("MorseTable.txt");

    if (!infile.is_open()) {
        std::cerr << "Error opening MorseTable.txt file!" << std::endl;
        return;
    }

    std::string line;

    while (std::getline(infile, line)) {
        if (line.empty()) continue;

        std::istringstream iss(line);  // chatgpt showed me this cool thing. useful for making the BST use templates!
        std::string part1, part2;

        if (std::getline(iss, part1, ' ') && std::getline(iss, part2)) {
            std::istringstream iss2(part1);
            std::istringstream iss3(part2);

            KEY _t1;
            VALUE _t2;

            if (!(iss2 >> _t1)) {
                std::cerr << "Error reading key!" << std::endl;
                continue;
            }
            if (!(iss3 >> _t2)) {
                std::cerr << "Error reading value!" << std::endl;
                continue;
            }

            insertNode(&root, _t1, _t2);  // ERROR HERE
        }
        else {
            std::cerr << "Error parsing line: " << line << std::endl;
            continue;
        }
    }

    infile.close();
}

// destructor
template <typename KEY, typename VALUE>
BST<KEY, VALUE>::~BST() { destroyTree(); }

/* ----- General Functions ----- */
template <typename KEY, typename VALUE>
bool BST<KEY, VALUE>::isEmpty() const { return root == nullptr; }

template <typename KEY, typename VALUE>
void BST<KEY, VALUE>::print() const {
    inOrderTransversal();
}

/* ----- Public Interfaces for Overloads ----- */
template <typename KEY, typename VALUE>
void BST<KEY, VALUE>::insertNode(KEY _newKey, VALUE _newValue) { insertNode(&root, _newKey, _newValue); }

template <typename KEY, typename VALUE>
VALUE BST<KEY, VALUE>::search(KEY _key) const {
    return search(root, _key);  // ERROR HERE
}

template <typename KEY, typename VALUE>
void BST<KEY, VALUE>::inOrderTransversal() const { inOrderTransversal(root); }

template <typename KEY, typename VALUE>
void BST<KEY, VALUE>::preOrderTransversal() const { preOrderTransversal(root); }

template <typename KEY, typename VALUE>
void BST<KEY, VALUE>::postOrderTransversal() const { postOrderTransversal(root); }

template <typename KEY, typename VALUE>
void BST<KEY, VALUE>::destroyTree() { destroyTree(&root); }

/* ----- Overloads for Recursive Calls ----- */
template <typename KEY, typename VALUE>
void BST<KEY, VALUE>::destroyTree(BSTNode<KEY, VALUE>** node) {
    // go left
    if (*node != nullptr) destroyTree((*node)->getLeftP());

    // go right
    if (*node != nullptr) destroyTree((*node)->getRightP());

    // delete current
    if (*node != nullptr) {
        delete* node;
        *node = nullptr;
    }
}

template <typename KEY, typename VALUE>
void BST<KEY, VALUE>::insertNode(BSTNode<KEY, VALUE>** node, KEY _newKey, VALUE _newValue) {
    // insert if null
    if (*node == nullptr) { *node = new BSTNode<KEY, VALUE>(_newKey, _newValue); }

    // go left
    if (_newKey < (*node)->getKey()) { insertNode((*node)->getLeftP(), _newKey, _newValue); }

    // go right
    if (_newKey > (*node)->getKey()) { insertNode((*node)->getRightP(), _newKey, _newValue); }
}

template <typename KEY, typename VALUE>
VALUE BST<KEY, VALUE>::search(BSTNode<KEY, VALUE>* node, KEY _key) const {
    if (node == nullptr) {
        VALUE value = VALUE();

        return value;  // default value
    }

    if (node->getKey() == _key) {
        return node->getValue();
    }

    if (_key < node->getKey()) {
        // go left
        return search(node->getLeft(), _key);
    }

    if (_key > node->getKey()) {
        // go right
        return search(node->getRight(), _key);
    }

    VALUE value = VALUE();
    return value;  // default value
}

template <typename KEY, typename VALUE>
void BST<KEY, VALUE>::inOrderTransversal(BSTNode<KEY, VALUE>* node) const {
    if (node == nullptr) return;

    // try go left
    inOrderTransversal(node->getLeft());

    // print
    std::cout << "[" << *node << "] ";

    // try go right
    inOrderTransversal(node->getRight());
}

template <typename KEY, typename VALUE>
void BST<KEY, VALUE>::preOrderTransversal(BSTNode<KEY, VALUE>* node) const {
    if (node == nullptr) return;

    // print
    std::cout << "[" << *node << "] ";

    // try go left
    preOrderTransversal(node->getLeft());

    // try go right
    preOrderTransversal(node->getRight());
}

template <typename KEY, typename VALUE>
void BST<KEY, VALUE>::postOrderTransversal(BSTNode<KEY, VALUE>* node) const {
    if (node == nullptr) return;

    // try go left
    postOrderTransversal(node->getLeft());

    // try go right
    postOrderTransversal(node->getRight());

    // print
    std::cout << "[" << *node << "] ";
}
