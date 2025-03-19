#include "BST.hpp"
#include <fstream>

int main() {
    BST<int> tree;

    tree.insertNode(42);
    tree.insertNode(25);
    tree.insertNode(75);
    tree.insertNode(10);
    tree.insertNode(30);
    tree.insertNode(15);
    tree.insertNode(65);
    tree.insertNode(100);
    tree.insertNode(70);

    std::cout << "In Order:" << std::endl;
    tree.inOrderTransversal();

    std::cout << "\nPre Order:" << std::endl;
    tree.preOrderTransversal();
    
    std::cout << "\nPost Order:" << std::endl;
    tree.postOrderTransversal();

    std::cout << std::endl;
    
    // names

    BST<std::string> nameTree;
    std::ifstream infile;
    infile.open("names.txt");
    
    std::string name;
    while (getline(infile, name)) {
        std::cout << "Read name: " << name << std::endl;
        nameTree.insertNode(name);
    }

    std::cout << std::endl << "Names Sorted:" << std::endl;
    nameTree.inOrderTransversal();

    std::cout << std::endl;
}