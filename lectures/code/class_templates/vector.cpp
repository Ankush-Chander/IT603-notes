#include <iostream>
#include "vectorTemplate.hpp"

int main() {
    Vector<int> vec;
    vec.push_back(0);
    vec.push_back(1);
    vec.push_back(2);


    std::cout << "Size: " << vec.getSize() << std::endl;
    std::cout << "Capacity: " << vec.getCapacity() << std::endl;

    vec.insert(1, 4);
    std::cout << "After insert(1,4): ";
    for (size_t i = 0; i < vec.getSize(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    vec.erase(2);
    std::cout << "After erase(2): ";
    for (size_t i = 0; i < vec.getSize(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    // Vector<int> vec2 = vec;
    // std::cout << "After copy constructor: ";
    // for (size_t i = 0; i < vec2.getSize(); ++i) {
    //     std::cout << vec2[i] << " ";
    // }
    // std::cout << std::endl;

    vec.clear();
    std::cout << "After clear, size: " << vec.getSize() << std::endl;
    
    return 0;
}