#ifndef HASH_H
#define HASH_H

#include <iostream>
#include "tree.h"
#include "vector.h"

template <typename T> class Hash {
private:
    int mod;
    Vector<BinaryTree<T>> table;

public:
    Hash() {
        mod = 0;
        table = nullptr;
    };
    explicit Hash(int module) {
        mod = module;
        table = nullptr;
    }

    int hash(int key) {
        return key % mod;
    }
    void insert(Node<T> leaf) {
        int pos = hash(leaf.key);
        table[pos].insert(leaf);
    }
    Node<T> search(int keyA, int keyB) {
        int pos = hash(keyA);
        return table[pos].search(keyB);
    }
    bool remove(int keyA, int keyB) {
        int pos = hash(keyA);
        return table[pos].remove(keyB);
    }
};

#endif //HASH_H
