#ifndef TREE_H
#define TREE_H

#include <iostream>

template <typename T> class Node {
public:
    int keyA, keyB;
    T data;
    Node* left;
    Node* right;
    Node() {
        keyA = -1;
        keyB = -1;
        left = NULL;
        right = NULL;
    };
    explicit Node(T d) {
        keyA = -1;
        keyB = -1;
        data = d;
        left = NULL;
        right = NULL;
    };
};

template <typename T> class BinaryTree {
public:
    Node<T> *root;

    BinaryTree() {
        root = NULL;
    }

    void insert(Node<T> leaf) {
        insertRecursive(root, leaf);
    }
    Node<T> search(int keyA, int keyB) {
        return searchRecursive(root, keyA, keyB);
    }
    bool remove(int keyA, int keyB) {
        return removeRecursive(root, keyA, keyB);
    }

private:
    void insertRecursive(Node<T>* &r, Node<T> leaf) {
        if (r == NULL) {
            r = new Node<T>();
            r->keyA = leaf.keyA;
            r->keyB = leaf.keyB;
            r->data = leaf.data;
        } else {
            if (leaf.keyA < r->keyA) {
                insertRecursive(r->left, leaf);
            } else {
                insertRecursive(r->right, leaf);
            }
        }
    }
    Node<T> searchRecursive(Node<T> *r, int keyA, int keyB) {
        Node<T> aux;
        aux.keyA = -1;
        aux.keyB = -1;
        if (r == NULL) {
            return aux;
        }
        if (keyA < r->keyA) {
            return searchRecursive(r->left, keyA, keyB);
        } else if (keyA > r->keyA) {
            return searchRecursive(r->right, keyA, keyB);
        } else if (r->keyA == keyA && r->keyB == keyB) {
            return (*r);
        } else {
            return aux;
        }
    }
    bool removeRecursive(Node<T> *r, int keyA, int keyB) {
        Node<T> *aux;
        if (r == NULL) {
            return false;
        }
        if (keyA < r->keyA) {
            return removeRecursive(r->left, keyA, keyB);
        } else if (keyA > r->keyA) {
            return removeRecursive(r->right, keyA, keyB);
        } else if (keyA == r->keyA && keyB == r->keyB) {
            if (r->right == NULL) {
                aux = r;
                if (keyA == root->keyA && keyB == root->keyB) {
                    root = r->left;
                }
                r = r->left;
                delete(aux);
            }
            else if (r->left == NULL) {
                aux = r;
                if (keyA == root->keyA && keyB == root->keyB) {
                    root = r->right;
                }
                r = r->right;
                delete(aux);
            } else {
                predecessor(r, r->left);
            }
            return true;
        } else {
            return false;
        }
    }
    void predecessor(Node<T> *q, Node<T>* &r) {
        if (r->right != NULL) {
            predecessor(q, r->right);
            return;
        }
        q = r;
        q->keyA = r->keyA;
        q->keyB = r->keyB;
        q->data = r->data;
        r = r->left;
        delete(q);
    }
};

#endif //TREE_H
