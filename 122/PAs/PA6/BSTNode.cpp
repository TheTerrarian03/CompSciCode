#pragma once

#include "BSTNode.hpp"

BSTNode::BSTNode() : key(), value(), left(nullptr), right(nullptr) {}
BSTNode::BSTNode(char _key, std::string _value) : key(_key), value(_value), left(nullptr), right(nullptr) {}
BSTNode::BSTNode(BSTNode& copy) {
    key = copy.key;
    value = copy.value;
    left = copy.left;
    right = copy.right;
}
BSTNode::~BSTNode() {}

// getters
char BSTNode::getKey() { return key; }
std::string BSTNode::getValue() { return value; }
BSTNode* BSTNode::getLeft() { return left; }
BSTNode* BSTNode::getRight() { return right; }
BSTNode** BSTNode::getLeftP() { return &left; }
BSTNode** BSTNode::getRightP() { return &right; }

// setters
void BSTNode::setKey(char _key) { key = _key; }
void BSTNode::setValue(std::string _value) { value = _value; }
void BSTNode::setLeft(BSTNode* newLeft) { left = newLeft; }
void BSTNode::setRight(BSTNode* newRight) { right = newRight; }

std::ostream& operator<< (std::ostream& lhs, BSTNode& rhs) {
    lhs << "'" << rhs.getKey() << "': \"" << rhs.getValue() << "\"";

    return lhs;
}