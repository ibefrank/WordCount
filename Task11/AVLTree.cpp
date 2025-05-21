#include "AVLTree.h"

template <typename T>
int AVLTree<T>::height(AVLNode<T>* t) const {
    return t == nullptr ? -1 : t->height;
}

template <typename T>
int AVLTree<T>::max(int lhs, int rhs) const {
    return lhs > rhs ? lhs : rhs;
}

template <typename T>
void AVLTree<T>::rotateWithLeftChild(AVLNode<T>*& k2) const {
    AVLNode<T>* k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = max(height(k2->left), height(k2->right)) + 1;
    k1->height = max(height(k1->left), k2->height) + 1;
    k2 = k1;
}

template <typename T>
void AVLTree<T>::rotateWithRightChild(AVLNode<T>*& k1) const {
    AVLNode<T>* k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;
    k1->height = max(height(k1->left), height(k1->right)) + 1;
    k2->height = max(height(k2->right), k1->height) + 1;
    k1 = k2;
}

template <typename T>
void AVLTree<T>::doubleWithLeftChild(AVLNode<T>*& k3) const {
    rotateWithRightChild(k3->left);
    rotateWithLeftChild(k3);
}

template <typename T>
void AVLTree<T>::doubleWithRightChild(AVLNode<T>*& k1) const {
    rotateWithLeftChild(k1->right);
    rotateWithRightChild(k1);
}

template <typename T>
void AVLTree<T>::insert(const T& x, AVLNode<T>*& t) const {
    if (t == nullptr) {
        t = new AVLNode<T>(x, nullptr, nullptr);
    }
    else if (x < t->element) {
        insert(x, t->left);
        if (height(t->left) - height(t->right) == 2) {
            if (x < t->left->element) {
                rotateWithLeftChild(t);
            }
            else {
                doubleWithLeftChild(t);
            }
        }
    }
    else if (t->element < x) {
        insert(x, t->right);
        if (height(t->right) - height(t->left) == 2) {
            if (t->right->element < x) {
                rotateWithRightChild(t);
            }
            else {
                doubleWithRightChild(t);
            }
        }
    }
    t->height = max(height(t->left), height(t->right)) + 1;
}

template <typename T>
void AVLTree<T>::remove(const T& x, AVLNode<T>*& t) {
    if (t == nullptr) {
        return;
    }
    if (x < t->element) {
        remove(x, t->left);
        if (height(t->right) - height(t->left) > 1) {
            if (height(t->right->right) >= height(t->right->left)) {
                rotateWithRightChild(t);
            }
            else {
                doubleWithRightChild(t);
            }
        }
    }
    else if (x > t->element) {
        remove(x, t->right);
        if (height(t->left) - height(t->right) > 1) {
            if (height(t->left->left) >= height(t->left->right)) {
                rotateWithLeftChild(t);
            }
            else {
                doubleWithLeftChild(t);
            }
        }
    }
    else {
        if (t->left == nullptr || t->right == nullptr) {
            AVLNode<T>* temp = t->left ? t->left : t->right;
            if (temp == nullptr) {
                temp = t;
                t = nullptr;
            }
            else {
                *t = *temp;
            }
            delete temp;
        }
        else {
            AVLNode<T>* minNode = t->right;
            while (minNode->left != nullptr) {
                minNode = minNode->left;
            }
            t->element = minNode->element;
            remove(t->element, t->right);
        }
    }
    if (t != nullptr) {
        t->height = max(height(t->left), height(t->right)) + 1;
    }
}

template <typename T>
void AVLTree<T>::printTree(AVLNode<T>* t) const {
    if (t != nullptr) {
        printTree(t->left);
        std::cout << t->element << std::endl;
        printTree(t->right);
    }
}

template <typename T>
void AVLTree<T>::makeEmpty(AVLNode<T>*& t) {
    if (t != nullptr) {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
        t = nullptr;
    }
}

template class AVLTree<int>;
template class AVLTree<std::string>;