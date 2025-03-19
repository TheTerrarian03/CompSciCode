#include <iostream>

template <typename T>
class BSTNode {

public:
    BSTNode() : data(), left(nullptr), right(nullptr) {}
    BSTNode(T data) : data(data), left(nullptr), right(nullptr) {}
    BSTNode(BSTNode& copy) {
        data = copy.data;
        left = copy.left;
        right = copy.right;
    }
    ~BSTNode() {}

    // getters
    T getData() { return data; }
    BSTNode* getLeft() { return left; }
    BSTNode* getRight() { return right; }
    BSTNode** getLeftP() { return &left; }
    BSTNode** getRightP() { return &right; }

    // setters
    void setData(T newData) { data = newData; }
    void setLeft(BSTNode* newLeft) { left = newLeft; }
    void setRight(BSTNode* newRight) { right = newRight; }

private:
    T data;
    BSTNode* left;
    BSTNode* right;
};

template <typename T>
std::ostream& operator<< (std::ostream& lhs, BSTNode<T>& rhs) {
    lhs << rhs.getData();

    return lhs;
}