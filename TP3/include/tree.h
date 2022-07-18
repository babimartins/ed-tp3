#ifndef TREE_H
#define TREE_H

#include <iostream>

template <typename T> class Node {
public:
    int key;
    T data;
    Node* left;
    Node* right;
    Node() {
        key = -1;
        left = nullptr;
        right = nullptr;
    };
};

template <typename T> class BinaryTree {
public:
    BinaryTree() {
        root = nullptr;
    };
    ~BinaryTree() {
        clean();
    }

    void insert(Node<T> leaf) {
        insertRecursive(root, leaf);
    }
    Node<T> search(int key) {
        return searchRecursive(root, key);
    }
    bool remove(int key) {
        return removeRecursive(root, key);
    }
    void clean() {
        cleanRecursive(root);
        root = nullptr;
    }

private:
    Node<T> *root;

    void insertRecursive(Node<T> *r, Node<T> leaf) {
        if (r == nullptr) {
            r = new Node<T>();
            r->data = leaf.data;
        } else {
            if (leaf.key < r->key) {
                insertRecursive(r->left, leaf);
            } else {
                insertRecursive(r->right, leaf);
            }
        }
    }
    Node<T> searchRecursive(Node<T> *r, int key) {
        Node<T> aux;
        aux.key = -1;
        if (r == nullptr) {
            return aux;
        }
        if (key < r->key) {
            return searchRecursive(r->left, key);
        } else if (key > r->key) {
            return searchRecursive(r->right, key);
        } else if (r->key == key) {
            return (*r);
        } else {
            return aux;
        }
    }
    bool removeRecursive(Node<T> *r, int key) {
        Node<T> *aux;
        if (r == nullptr) {
            return false;
        }
        if (key < r->key) {
            return removeRecursive(r->left, key);
        } else if (key > r->key) {
            return removeRecursive(r->right, key);
        } else if (key == r->key) {
            if (r->right == nullptr) {
                aux = r;
                r = r->left;
                free(aux);
            }
            else if (r->left == nullptr) {
                aux = r;
                r = r->right;
                free(aux);
            } else {
                predecessor(r, r->left);
            }
            return true;
        } else {
            return false;
        }
    }
    void cleanRecursive(Node<T> *r) {
        if(r != nullptr){
            cleanRecursive(r->left);
            cleanRecursive(r->right);
            delete r;
        }
    }
    void predecessor(Node<T> *q, T* &r) {
        if (r->right != nullptr) {
            predecessor(q, r->right);
            return;
        }
        q->data = r->data;
        q = r;
        r = r->left;
        free(q);
    }
};

#endif //TREE_H
