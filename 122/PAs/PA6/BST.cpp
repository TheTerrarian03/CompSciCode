#pragma once

#include "BST.hpp"

// constructor
BST::BST() {
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

            char _t1;
            std::string _t2;

            if (!(iss2 >> _t1)) {
                std::cerr << "Error reading key!" << std::endl;
                continue;
            }
            if (!(iss3 >> _t2)) {
                std::cerr << "Error reading value!" << std::endl;
                continue;
            }

            insertNode(&root, _t1, _t2);
        }
        else {
            std::cerr << "Error parsing line: " << line << std::endl;
            continue;
        }
    }

    infile.close();
}

// destructor
BST::~BST() { destroyTree(); }

/* ----- General Functions ----- */
bool BST::isEmpty() const { return root == nullptr; }

void BST::print() const {
    inOrderTransversal();
}

/* ----- Public Interfaces for Overloads ----- */
void BST::insertNode(char _newKey, std::string _newValue) { insertNode(&root, _newKey, _newValue); }

std::string BST::search(char _key) const {
    return search(root, _key);
}

void BST::inOrderTransversal() const { inOrderTransversal(root); }

void BST::preOrderTransversal() const { preOrderTransversal(root); }

void BST::postOrderTransversal() const { postOrderTransversal(root); }

void BST::destroyTree() { destroyTree(&root); }

/* ----- Overloads for Recursive Calls ----- */
void BST::destroyTree(BSTNode** node) {
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

void BST::insertNode(BSTNode** node, char _newKey, std::string _newValue) {
    // insert if null
    if (*node == nullptr) { *node = new BSTNode(_newKey, _newValue); }

    // go left
    if (charToID(_newKey) < charToID((*node)->getKey())) { insertNode((*node)->getLeftP(), _newKey, _newValue); }

    // go right
    if (charToID(_newKey) > charToID((*node)->getKey())) { insertNode((*node)->getRightP(), _newKey, _newValue); }
}

std::string BST::search(BSTNode* node, char _key) const {
    if (node == nullptr) {
        std::string value = std::string();

        return value;  // default value
    }

    if (charToID(node->getKey()) == charToID(_key)) {
        return node->getValue();
    }

    if (charToID(_key) < charToID(node->getKey())) {
        // go left
        return search(node->getLeft(), _key);
    }

    if (charToID(_key) > charToID(node->getKey())) {
        // go right
        return search(node->getRight(), _key);
    }

    std::string value = std::string();
    return value;  // default value
}

void BST::inOrderTransversal(BSTNode* node) const {
    if (node == nullptr) return;

    // try go left
    inOrderTransversal(node->getLeft());

    // print
    std::cout << "[" << *node << "] ";

    // try go right
    inOrderTransversal(node->getRight());
}

void BST::preOrderTransversal(BSTNode* node) const {
    if (node == nullptr) return;

    // print
    std::cout << "[" << *node << "] ";

    // try go left
    preOrderTransversal(node->getLeft());

    // try go right
    preOrderTransversal(node->getRight());
}

void BST::postOrderTransversal(BSTNode* node) const {
    if (node == nullptr) return;

    // try go left
    postOrderTransversal(node->getLeft());

    // try go right
    postOrderTransversal(node->getRight());

    // print
    std::cout << "[" << *node << "] ";
}
