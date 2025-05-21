#pragma once
#include "BinaryTree.h"

/**
 * @brief Node structure for the AVL tree.
 * @note Taken from Lecture 2 (Page 13) and Lecture 3 (Page 28, C++ AVLNode). Modified to use generic type T instead of int.
 * @tparam T The type of data stored in the node.
 */
template <typename T>
class AVLNode {
public:
    T element;
    AVLNode<T>* left;
    AVLNode<T>* right;
    int height;
    AVLNode(const T& theElement, AVLNode<T>* lt, AVLNode<T>* rt, int h = 0)
        : element(theElement), left(lt), right(rt), height(h) {
    }
    friend class AVLTree<T>;
};

/**
 * @brief Generic AVL tree class.
 * @note Based on AVLTree from Lecture 2 (Pages 13-21) and Lecture 3 (Pages 29-32, C++). Modified to use templates and inherit from BinaryTree.
 * @tparam T The type of data stored in the tree.
 */
template <typename T>
class AVLTree : public BinaryTree<T> {
private:
    AVLNode<T>* root;

    int height(AVLNode<T>* t) const;
    int max(int lhs, int rhs) const;
    void rotateWithLeftChild(AVLNode<T>*& k2) const;
    void rotateWithRightChild(AVLNode<T>*& k1) const;
    void doubleWithLeftChild(AVLNode<T>*& k3) const;
    void doubleWithRightChild(AVLNode<T>*& k1) const;
    void insert(const T& x, AVLNode<T>*& t) const;
    void remove(const T& x, AVLNode<T>*& t);
    void printTree(AVLNode<T>* t) const;
    void makeEmpty(AVLNode<T>*& t);

public:
    AVLTree() : root(nullptr) {}
    ~AVLTree() { makeEmpty(root); }
    bool isEmpty() const { return root == nullptr; }
    void insert(const T& x) { insert(x, root); }
    void remove(const T& x) { remove(x, root); }
    void printTree() const { printTree(root); }
};