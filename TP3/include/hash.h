#ifndef HASH_H
#define HASH_H

#include <iostream>
#include "tree.h"
#include "vector.h"

template <typename T> class Hash {
private:
    Vector<BinaryTree<T>> table;

public:
    Hash() {
        table = Vector<BinaryTree<T>>();
    };
    explicit Hash(int module) {
        table = Vector<BinaryTree<T>>(module);
    }

    void insert(Node<T> leaf, int key) {
        table[key].insert(leaf);
    }
    Node<T> search(int keyA, int keyB) {
        return table[keyA].search(keyB);
    }
    bool remove(int keyA, int keyB) {
        return table[keyA].remove(keyB);
    }
};

#endif //HASH_H
