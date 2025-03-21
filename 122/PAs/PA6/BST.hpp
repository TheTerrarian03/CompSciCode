#include "BSTNode.hpp"
#include "MorseFuncs.hpp"

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

template <typename T1, typename T2>
class BST {

public:
    // constructors, destructor
    BST();
    BST(BST<T1, T2>& copy);
    ~BST() { destroyTree(); }

    // general functions
    bool isEmpty();
    void print();

    // public facing interface for overloaded functions
    void insertNode(T1 _newKey, T2 _newValue);
    void inOrderTransversal();
    void preOrderTransversal();
    void postOrderTransversal();
    void destroyTree();

private:
    BSTNode<T1, T2>* root;

    // overload for recursive calls
    void insertNode(BSTNode<T1, T2>** node, T1 _newKey, T2 _newValue);
    void inOrderTransversal(BSTNode<T1, T2>* node);
    void preOrderTransversal(BSTNode<T1, T2>* node);
    void postOrderTransversal(BSTNode<T1, T2>* node);
    void destroyTree(BSTNode<T1, T2>** node);
};

// constructor
template <typename T1, typename T2>
BST<T1, T2>::BST() {
    std::ifstream infile("MorseTable.txt");

    if (!infile.is_open()) {
        std::cerr << "Error opening MorseTable.txt file!" << std::endl;
        return;
    }

    std::string line;

    while (std::getline(infile, line)) {
        if (line.empty()) continue;

        std::cout << "Line: " << line << std::endl;

        std::istringstream iss(line);  // chatgpt showed me this cool thing. useful for making the BST a template!
        std::string part1, part2;

        if (std::getline(iss, part1, ' ') && std::getline(iss, part2)) {
            std::cout << "Part1: " << part1 << ", Part2: " << part2 << std::endl;
            
            std::istringstream iss2(part1);
            std::istringstream iss3(part2);
            
            T1 _t1;
            T2 _t2;
            
            if (!(iss2 >> _t1)) {
                std::cerr << "Error reading key!" << std::endl;
                continue;
            }
            if (!(iss3 >> _t2)) {
                std::cerr << "Error reading value!" << std::endl;
                continue;
            }
            
            std::cout << "Got " << _t1 << " and " << _t2 << std::endl;

            line = "";
        } else {
            std::cerr << "Error parsing line: " << line << std::endl;
            continue;
        }
    }

    infile.close();
}

/* ----- General Functions ----- */
template <typename T1, typename T2>
bool BST<T1, T2>::isEmpty() { return root == nullptr; }

template <typename T1, typename T2>
void BST<T1, T2>::print() {
    inOrderTransversal();
}

/* ----- Public Interfaces for Overloads ----- */
template <typename T1, typename T2>
void BST<T1, T2>::insertNode(T1 _newKey, T2 _newValue) { insertNode(&root, _newKey, _newValue); }

template <typename T1, typename T2>
void BST<T1, T2>::inOrderTransversal() { inOrderTransversal(root); }

template <typename T1, typename T2>
void BST<T1, T2>::preOrderTransversal() { preOrderTransversal(root); }

template <typename T1, typename T2>
void BST<T1, T2>::postOrderTransversal() { postOrderTransversal(root); }

template <typename T1, typename T2>
void BST<T1, T2>::destroyTree() { destroyTree(&root); }

/* ----- Overloads for Recursive Calls ----- */
template <typename T1, typename T2>
void BST<T1, T2>::destroyTree(BSTNode<T1, T2>** node) {
    // go left
    if (*node != nullptr) destroyTree((*node)->getLeftP());

    // go right
    if (*node != nullptr) destroyTree((*node)->getRightP());

    // delete current
    if (*node != nullptr) {
        delete *node;
        *node = nullptr;
    }
}

template <typename T1, typename T2>
void BST<T1, T2>::insertNode(BSTNode<T1, T2>** node, T1 _newKey, T2 _newValue) {
    // insert if null
    if (*node == nullptr) { *node = new BSTNode(_newKey, _newValue); }

    // go left
    if (charToID(_newKey) < charToID((*node)->getKey())) { insertNode((*node)->getLeftP(), _newKey, _newValue); }

    // go right
    if (charToID(_newKey) > charToID((*node)->getKey())) { insertNode((*node)->getRightP(), _newKey, _newValue); }
}

template <typename T1, typename T2>
void BST<T1, T2>::inOrderTransversal(BSTNode<T1, T2>* node) {
    if (node == nullptr) return;
    
    // try go left
    inOrderTransversal(node->getLeft());

    // print
    std::cout << "[" << *node << "] ";

    // try go right
    inOrderTransversal(node->getRight());
}

template <typename T1, typename T2>
void BST<T1, T2>::preOrderTransversal(BSTNode<T1, T2>* node) {
    if (node == nullptr) return;
    
    // print
    std::cout << *node << " ";

    // try go left
    preOrderTransversal(node->getLeft());

    // try go right
    preOrderTransversal(node->getRight());
}

template <typename T1, typename T2>
void BST<T1, T2>::postOrderTransversal(BSTNode<T1, T2>* node) {
    if (node == nullptr) return;
    
    // try go left
    postOrderTransversal(node->getLeft());

    // try go right
    postOrderTransversal(node->getRight());

    // print
    std::cout << *node << " ";
}
