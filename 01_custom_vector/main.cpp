#include <iostream>
#include "custom_vector.hpp"

int main() {
    std::cout << "=== HIGH PERFORMANCE CUSTOM VECTOR (C++) ===" << std::endl;
    CustomVector<int> vec;
    for (int i = 1; i <= 10; ++i) {
        vec.push_back(i * 10);
    }

    std::cout << "CustomVector elements (size = " << vec.size() << "): ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
