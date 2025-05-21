#include "BinaryTree.h"
#include "AVLTree.h"
#include "WordCount.h"
#include <iostream>

int main() {
    // Test BinaryTree
    std::cout << "Testing BinaryTree with integers:\n";
    BinaryTree<int> bt;
    bt.insert(5);
    bt.insert(3);
    bt.insert(7);
    bt.insert(1);
    bt.insert(9);
    bt.printTree();
    std::cout << "Contains 3: " << (bt.contains(3) ? "Yes" : "No") << "\n";
    std::cout << "Min: " << bt.findMin() << "\n";
    std::cout << "Max: " << bt.findMax() << "\n";
    bt.remove(3);
    std::cout << "After removing 3:\n";
    bt.printTree();

    // Test AVLTree
    std::cout << "\nTesting AVLTree with integers:\n";
    AVLTree<int> avl;
    avl.insert(5);
    avl.insert(3);
    avl.insert(7);
    avl.insert(1);
    avl.insert(9);
    avl.printTree();
    std::cout << "Contains 3: " << (avl.contains(3) ? "Yes" : "No") << "\n";
    std::cout << "Min: " << avl.findMin() << "\n";
    std::cout << "Max: " << avl.findMax() << "\n";
    avl.remove(3);
    std::cout << "After removing 3:\n";
    avl.printTree();

    // Test WordCount
    std::cout << "\nTesting WordCount with Text.txt:\n";
    WordCount wc;
    try {
        wc.readFile("Text.txt");
        wc.printWordCounts();
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}