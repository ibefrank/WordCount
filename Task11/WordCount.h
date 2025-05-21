#pragma once
#include "AVLTree.h"
#include <string>
#include <fstream>
#include <cctype>

/**
 * @brief Node structure for word counting.
 * @note New implementation for Task 3, not derived from lecture material.
 */
struct WordNode {
    std::string word;
    int count;
    WordNode* left;
    WordNode* right;
    int height;
    WordNode(const std::string& w, int c = 1)
        : word(w), count(c), left(nullptr), right(nullptr), height(0) {
    }
};

/**
 * @brief AVL tree specialized for word counting.
 * @note Extends AVLTree from Lecture 2 (Pages 13-21) and Lecture 3 (Pages 29-32). Modified to handle WordNode.
 */
class WordTree {
private:
    AVLNode<WordNode>* root;

    int height(AVLNode<WordNode>* t) const;
    int max(int lhs, int rhs) const;
    void rotateWithLeftChild(AVLNode<WordNode>*& k2) const;
    void rotateWithRightChild(AVLNode<WordNode>*& k1) const;
    void doubleWithLeftChild(AVLNode<WordNode>*& k3) const;
    void doubleWithRightChild(AVLNode<WordNode>*& k1) const;
    void insert(const std::string& word, AVLNode<WordNode>*& t) const;
    void printTree(AVLNode<WordNode>* t) const;
    void makeEmpty(AVLNode<WordNode>*& t);

public:
    WordTree() : root(nullptr) {}
    ~WordTree() { makeEmpty(root); }
    void insert(const std::string& word) { insert(word, root); }
    void printTree() const { printTree(root); }
};

/**
 * @brief Class to count words in a file using an AVL tree.
 * @note New implementation for Task 3, not derived from lecture material.
 */
class WordCount {
private:
    WordTree tree;

public:
    void readFile(const std::string& filename);
    void printWordCounts() const { tree.printTree(); }
};