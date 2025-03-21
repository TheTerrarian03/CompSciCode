#pragma once

#include "MorseFuncs.hpp"

class BSTNode {

public:
    // constructor
    BSTNode();

    // overloaded constructor with key and value given
    BSTNode(char _key, std::string _value);

    // copy constructor
    BSTNode(BSTNode& copy);

    // destructor
    ~BSTNode();

    /* ----- Getters ----- */

    // get key, like 'Q'
    char getKey();

    // get value, like "--.-"
    std::string getValue();

    // get left node pointer
    BSTNode* getLeft();

    // get right node pointer
    BSTNode* getRight();

    // get left node double pointer for access (insertion)
    BSTNode** getLeftP();

    // get rightnode double pointer for access (insertion)
    BSTNode** getRightP();

    /* ----- Setters ----- */

    // set given key char, like "Q"
    void setKey(char _key);

    // set given value string, like "--.-"
    void setValue(std::string _value);

    // set left node pointer
    void setLeft(BSTNode* newLeft);

    // set right node pointer
    void setRight(BSTNode* newRight);

    // overloader string insertion operator for printing
    friend std::ostream& operator<< (std::ostream& lhs, BSTNode& rhs);

private:
    char key;    // like char for letter 'Q'
    std::string value;  // like string for moorse "--.-"
    BSTNode* left;
    BSTNode* right;
};
