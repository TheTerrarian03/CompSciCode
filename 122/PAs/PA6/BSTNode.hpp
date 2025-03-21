#include <iostream>

template <typename T1, typename T2>
class BSTNode {

public:
    BSTNode() : key(), value(), left(nullptr), right(nullptr) {}
    BSTNode(T1 _key, T2 _value) : key(_key), value(_value), left(nullptr), right(nullptr) {}
    BSTNode(BSTNode& copy) {
        key = copy.key;
        value = copy.value;
        left = copy.left;
        right = copy.right;
    }
    ~BSTNode() {}

    // getters
    T1 getKey() { return key; }
    T2 getValue() { return value; }
    BSTNode* getLeft() { return left; }
    BSTNode* getRight() { return right; }
    BSTNode** getLeftP() { return &left; }
    BSTNode** getRightP() { return &right; }

    // setters
    void setKey(T1 _key) { key = _key; }
    void setValue(T2 _value) { value = _value;}
    void setLeft(BSTNode* newLeft) { left = newLeft; }
    void setRight(BSTNode* newRight) { right = newRight; }

private:
    T1 key;    // like char for letter 'Q'
    T2 value;  // like string for moorse "--.-"
    BSTNode* left;
    BSTNode* right;
};

template <typename T1, typename T2>
std::ostream& operator<< (std::ostream& lhs, BSTNode<T1, T2>& rhs) {
    lhs << "'" << rhs.getKey() << "': \"" << rhs.getValue() << "\"";

    return lhs;
}