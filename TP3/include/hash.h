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

    void insert(int pos, Node<T> node) {
        table[pos].insert(node);
    }
    Node<T> search(int pos, int keyA, int keyB) {
        return table[pos].search(keyA, keyB);
    }
    bool remove(int pos, int keyA, int keyB) {
        return table[pos].remove(keyA, keyB);
    }
};

#endif //HASH_H
