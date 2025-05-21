#include "BinaryTree.h"
#include <stdexcept>

template <typename T>
void BinaryTree<T>::insert(const T& data, Node<T>*& n) {
    if (n == nullptr) {
        n = new Node<T>(data);
    }
    else if (data < n->Data) {
        insert(data, n->left);
    }
    else if (data > n->Data) {
        insert(data, n->right);
    }
}

template <typename T>
void BinaryTree<T>::remove(const T& data, Node<T>*& n) {
    if (n == nullptr) {
        return;
    }
    if (data < n->Data) {
        remove(data, n->left);
    }
    else if (data > n->Data) {
        remove(data, n->right);
    }
    else {
        if (n->left == nullptr && n->right == nullptr) {
            delete n;
            n = nullptr;
        }
        else if (n->left == nullptr) {
            Node<T>* temp = n;
            n = n->right;
            delete temp;
        }
        else if (n->right == nullptr) {
            Node<T>* temp = n;
            n = n->left;
            delete temp;
        }
        else {
            n->Data = findMin(n->right);
            remove(n->Data, n->right);
        }
    }
}

template <typename T>
T BinaryTree<T>::findMin(Node<T>* n) const {
    if (n == nullptr) {
        throw std::runtime_error("Tree is empty");
    }
    while (n->left != nullptr) {
        n = n->left;
    }
    return n->Data;
}

template <typename T>
T BinaryTree<T>::findMax(Node<T>* n) const {
    if (n == nullptr) {
        throw std::runtime_error("Tree is empty");
    }
    while (n->right != nullptr) {
        n = n->right;
    }
    return n->Data;
}

template <typename T>
bool BinaryTree<T>::contains(const T& data, Node<T>* n) const {
    if (n == nullptr) {
        return false;
    }
    if (data < n->Data) {
        return contains(data, n->left);
    }
    else if (data > n->Data) {
        return contains(data, n->right);
    }
    else {
        return true;
    }
}

template <typename T>
void BinaryTree<T>::printTree(Node<T>* n) const {
    if (n != nullptr) {
        printTree(n->left);
        std::cout << n->Data << std::endl;
        printTree(n->right);
    }
}

template <typename T>
void BinaryTree<T>::makeEmpty(Node<T>*& n) {
    if (n != nullptr) {
        makeEmpty(n->left);
        makeEmpty(n->right);
        delete n;
        n = nullptr;
    }
}

template class BinaryTree<int>;
template class BinaryTree<std::string>;