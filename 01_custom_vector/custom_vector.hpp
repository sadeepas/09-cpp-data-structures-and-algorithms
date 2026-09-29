#ifndef CUSTOM_VECTOR_HPP
#define CUSTOM_VECTOR_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
class CustomVector {
private:
    T* data;
    size_t capacity;
    size_t length;

    void reallocate(size_t newCapacity) {
        T* newBlock = new T[newCapacity];
        for (size_t i = 0; i < length; ++i) {
            newBlock[i] = std::move(data[i]);
        }
        delete[] data;
        data = newBlock;
        capacity = newCapacity;
    }

public:
    CustomVector() : data(nullptr), capacity(0), length(0) {
        reallocate(2);
    }

    ~CustomVector() {
        delete[] data;
    }

    void push_back(const T& value) {
        if (length >= capacity) {
            reallocate(capacity * 2);
        }
        data[length++] = value;
    }

    size_t size() const { return length; }

    const T& operator[](size_t index) const {
        if (index >= length) throw std::out_of_range("Index out of bounds");
        return data[index];
    }
};

#endif
