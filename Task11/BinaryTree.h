#pragma once
#include <iostream>

/**
 * @brief Node structure for the binary search tree.
 * @note Taken from Lecture 1 (Page 1) and Lecture 2 (Page 32, C++ Node struct). Modified to use generic type T instead of int.
 * @tparam T The type of data stored in the node.
 */
template <typename T>
struct Node {
    T Data;
    Node<T>* left;
    Node<T>* right;
    Node() : left(nullptr), right(nullptr) {}
    Node(const T& data) : Data(data), left(nullptr), right(nullptr) {}
};

/**
 * @brief Generic binary search tree class.
 * @note Based on SearchTree from Lecture 1 (Pages 14-16) and Lecture 2 (Pages 34-39, C++). Modified to use templates for generic types.
 * @tparam T The type of data stored in the tree.
 */
template <typename T>
class BinaryTree {
private:
    Node<T>* Root;

    void insert(const T& data, Node<T>*& n);
    void remove(const T& data, Node<T>*& n);
    T findMin(Node<T>* n) const;
    T findMax(Node<T>* n) const;
    bool contains(const T& data, Node<T>* n) const;
    void printTree(Node<T>* n) const;
    void makeEmpty(Node<T>*& n);

public:
    BinaryTree() : Root(nullptr) {}
    ~BinaryTree() { makeEmpty(Root); }
    bool isEmpty() const { return Root == nullptr; }
    void insert(const T& data) { insert(data, Root); }
    void remove(const T& data) { remove(data, Root); }
    T findMin() const { return findMin(Root); }
    T findMax() const { return findMax(Root); }
    bool contains(const T& data) const { return contains(data, Root); }
    void printTree() const { printTree(Root); }
};