#include "BSTNode.hpp"
#include <string>

template <typename T>
class BST {

public:
    // constructors, destructor
    BST() : root(nullptr) {}
    BST(BST<T>& copy);
    ~BST() { destroyTree(); }

    // general functions
    bool isEmpty();

    // public facing interface for overloaded functions
    void insertNode(T newData);
    void inOrderTransversal();
    void preOrderTransversal();
    void postOrderTransversal();
    void destroyTree();

private:
    BSTNode<T>* root;

    // overload for recursive calls
    void insertNode(BSTNode<T>** node, T newData);
    void inOrderTransversal(BSTNode<T>* node);
    void preOrderTransversal(BSTNode<T>* node);
    void postOrderTransversal(BSTNode<T>* node);
    void destroyTree(BSTNode<T>** node);
};

/* ----- General Functions ----- */
template <typename T>
bool BST<T>::isEmpty() { return root == nullptr; }

/* ----- Public Interfaces for Overloads ----- */
template <typename T>
void BST<T>::insertNode(T newData) { insertNode(&root, newData); }

template <typename T>
void BST<T>::inOrderTransversal() { inOrderTransversal(root); }

template <typename T>
void BST<T>::preOrderTransversal() { preOrderTransversal(root); }

template <typename T>
void BST<T>::postOrderTransversal() { postOrderTransversal(root); }

template <typename T>
void BST<T>::destroyTree() { destroyTree(&root); }

/* ----- Overloads for Recursive Calls ----- */
template <typename T>
void BST<T>::destroyTree(BSTNode<T>** node) {
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

template <typename T>
void BST<T>::insertNode(BSTNode<T>** node, T newData) {
    // insert if null
    if (*node == nullptr) { *node = new BSTNode(newData); }

    // go left
    if (newData < (*node)->getData()) { insertNode((*node)->getLeftP(), newData); }

    // go right
    if (newData > (*node)->getData()) { insertNode((*node)->getRightP(), newData); }
}

template <typename T>
void BST<T>::inOrderTransversal(BSTNode<T>* node) {
    if (node == nullptr) return;
    
    // try go left
    inOrderTransversal(node->getLeft());

    // print
    std::cout << "[" << *node << "] ";

    // try go right
    inOrderTransversal(node->getRight());
}

template <typename T>
void BST<T>::preOrderTransversal(BSTNode<T>* node) {
    if (node == nullptr) return;
    
    // print
    std::cout << *node << " ";

    // try go left
    preOrderTransversal(node->getLeft());

    // try go right
    preOrderTransversal(node->getRight());
}

template <typename T>
void BST<T>::postOrderTransversal(BSTNode<T>* node) {
    if (node == nullptr) return;
    
    // try go left
    postOrderTransversal(node->getLeft());

    // try go right
    postOrderTransversal(node->getRight());

    // print
    std::cout << *node << " ";
}
