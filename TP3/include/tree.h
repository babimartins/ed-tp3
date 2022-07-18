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
        left = NULL;
        right = NULL;
    };
    explicit Node(T d) {
        key = -1;
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
        root = NULL;
    }

private:
    void insertRecursive(Node<T>* &r, Node<T> leaf) {
        if (r == NULL) {
            r = new Node<T>();
            r->key = leaf.key;
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
        if (r == NULL) {
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
        if (r == NULL) {
            return false;
        }
        if (key < r->key) {
            return removeRecursive(r->left, key);
        } else if (key > r->key) {
            return removeRecursive(r->right, key);
        } else if (key == r->key) {
            if (r->right == NULL) {
                aux = r;
                r = r->left;
                if (r->key == root->key) {
                    root = r->left;
                }
                delete(aux);
            }
            else if (r->left == NULL) {
                aux = r;
                if (r->key == root->key) {
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
    void cleanRecursive(Node<T> *r) {
        if(r != NULL){
            cleanRecursive(r->left);
            cleanRecursive(r->right);
            delete r;
        }
    }
    void predecessor(Node<T> *q, Node<T>* &r) {
        if (r->right != NULL) {
            predecessor(q, r->right);
            return;
        }
        q->data = r->data;
        q = r;
        r = r->left;
        delete(q);
    }
};

#endif //TREE_H
