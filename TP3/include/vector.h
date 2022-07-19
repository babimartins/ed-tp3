#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

template <typename T> class Vector {
private:
    T* arr;
    int size;
    int max;

public:
    Vector() {
        arr = new T[1];
        size = 0;
        max = 1;
    };

    explicit Vector(T data) {
        arr = new T[1];
        arr[0] = data;
        size = 1;
        max = 2;
    };

    explicit Vector(int s) {
        arr = new T[s];
        size = s;
        max = s;
    };

    void push(T data) {
        if (size == max) {
            T *temp = new T[2 * max];

            for (int i = 0; i < max; i++) {
                temp[i] = arr[i];
            }

            delete[] arr;
            max *= 2;
            arr = temp;
        }
        arr[size] = data;
        size++;
    };

    void push(T data, int index) {
        if (index >= max) {
            push(data);
        } else {
            arr[index] = data;
        }
    }

    void pop() {
        size--;
    };

    void pop(int index) {
        for (int i = index; i < size - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        size--;
    };

    int length() const { return size; };

    bool empty() const { return size <= 0; };

    T& operator[](int i) {
        return arr[i];
    }
};

#endif //VECTOR_H
