#include "WordCount.h"

int WordTree::height(AVLNode<WordNode>* t) const {
    return t == nullptr ? -1 : t->height;
}

int WordTree::max(int lhs, int rhs) const {
    return lhs > rhs ? lhs : rhs;
}

void WordTree::rotateWithLeftChild(AVLNode<WordNode>*& k2) const {
    AVLNode<WordNode>* k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = max(height(k2->left), height(k2->right)) + 1;
    k1->height = max(height(k1->left), k2->height) + 1;
    k2 = k1;
}

void WordTree::rotateWithRightChild(AVLNode<WordNode>*& k1) const {
    AVLNode<WordNode>* k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;
    k1->height = max(height(k1->left), height(k1->right)) + 1;
    k2->height = max(height(k2->right), k1->height) + 1;
    k1 = k2;
}

void WordTree::doubleWithLeftChild(AVLNode<WordNode>*& k3) const {
    rotateWithRightChild(k3->left);
    rotateWithLeftChild(k3);
}

void WordTree::doubleWithRightChild(AVLNode<WordNode>*& k1) const {
    rotateWithLeftChild(k1->right);
    rotateWithRightChild(k1);
}

void WordTree::insert(const std::string& word, AVLNode<WordNode>*& t) const {
    if (t == nullptr) {
        t = new AVLNode<WordNode>(WordNode(word), nullptr, nullptr, 0);
    }
    else if (word < t->element.word) {
        insert(word, t->left);
        if (height(t->left) - height(t->right) == 2) {
            if (word < t->left->element.word) {
                rotateWithLeftChild(t);
            }
            else {
                doubleWithLeftChild(t);
            }
        }
    }
    else if (t->element.word < word) {
        insert(word, t->right);
        if (height(t->right) - height(t->left) == 2) {
            if (t->right->element.word < word) {
                rotateWithRightChild(t);
            }
            else {
                doubleWithRightChild(t);
            }
        }
    }
    else {
        t->element.count++;
    }
    t->height = max(height(t->left), height(t->right)) + 1;
}

void WordTree::printTree(AVLNode<WordNode>* t) const {
    if (t != nullptr) {
        printTree(t->left);
        std::cout << t->element.word << " - " << t->element.count << std::endl;
        printTree(t->right);
    }
}

void WordTree::makeEmpty(AVLNode<WordNode>*& t) {
    if (t != nullptr) {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
        t = nullptr;
    }
}

void WordCount::readFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open file");
    }
    std::string word;
    while (file >> word) {
        std::string cleaned;
        for (char c : word) {
            if (std::isalpha(c)) {
                cleaned += std::tolower(c);
            }
        }
        if (!cleaned.empty()) {
            tree.insert(cleaned);
        }
    }
    file.close();
}