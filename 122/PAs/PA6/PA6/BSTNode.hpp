/*
- File: BSTNode.hpp
- Description: Function declerations and variables for the BSTNode class, plus definitions
- BSTNode class: This is the class for a Node in a BST, holding any KEY and VALUE variables

- Modified: 03/23/2025
*/

#pragma once

#include <iostream>

template <typename KEY, typename VALUE>
class BSTNode {

public:
    // constructor
    BSTNode() : key(), value(), left(nullptr), right(nullptr) {}

    // overloaded constructor with key and value given
    BSTNode(KEY _key, VALUE _value) : key(_key), value(_value), left(nullptr), right(nullptr) {}

    // copy constructor
    BSTNode(BSTNode<KEY, VALUE>& copy) {
        key = copy.key;
        value = copy.value;
        left = copy.left;
        right = copy.right;
    }

    // destructor
    ~BSTNode() {}

    /* ----- Getters ----- */

    // get key, like 'Q'
    KEY getKey() { return key; }

    // get value, like "--.-"
    VALUE getValue() { return value; }

    // get left node pointer
    BSTNode* getLeft() { return left; }

    // get right node pointer
    BSTNode* getRight() { return right; }

    // get left node double pointer for access (insertion)
    BSTNode** getLeftP() { return &left; }

    // get rightnode double pointer for access (insertion)
    BSTNode** getRightP() { return &right; }

    /* ----- Setters ----- */

    // set given key char, like "Q"
    void setKey(KEY _key) { key = _key; }

    // set given value string, like "--.-"
    void setValue(VALUE _value) { value = _value; }

    // set left node pointer
    void setLeft(BSTNode<KEY, VALUE>* newLeft) { left = newLeft; }

    // set right node pointer
    void setRight(BSTNode<KEY, VALUE>* newRight) { right = newRight; }

private:
    KEY key;    // like char for letter 'Q'
    VALUE value;  // like string for moorse "--.-"
    BSTNode<KEY, VALUE>* left;
    BSTNode<KEY, VALUE>* right;
};

template <typename KEY, typename VALUE>
std::ostream& operator<< (std::ostream& lhs, BSTNode<KEY, VALUE>& rhs) {
    lhs << "'" << rhs.getKey() << "': \"" << rhs.getValue() << "\"";

    return lhs;
}
