#include <iostream>
#include <stdexcept>
#include "linked_list.h"
#include "dynamic_array.h"

// Assuming the Vector class is defined as before

template<typename Iterator>
typename Iterator::value_type max_element(Iterator begin, Iterator end) {
    if (begin == end) {
        throw std::invalid_argument("Range cannot be empty");
    }

    auto max_val = *begin;
    for (Iterator iter = begin; iter != end; ++iter) {
        if (*iter > max_val) {
            max_val = *iter;
        }
    }
    return max_val;
}

// min
template<typename Iterator>
typename Iterator::value_type min_element(Iterator begin, Iterator end) {
    if (begin == end) {
        throw std::invalid_argument("Range cannot be empty");
    }

    auto min_val = *begin;
    for (Iterator iter = begin; iter != end; ++iter) {
        if (*iter < min_val) {
            min_val = *iter;
        }
    }
    return min_val; 
}

// sum 
template<typename Iterator>
typename Iterator::value_type sum_element(Iterator begin, Iterator end) {
    if (begin == end) {
        throw std::invalid_argument("Range cannot be empty");
    }

    auto sum_val = *begin;
    for (Iterator iter = begin; iter != end; ++iter) {
        sum_val += *iter;
    }
    return sum_val; 
}


int main() {
    Vector<int> vec = {10, 20, 30, 25, 5};
    ForwardList<int> list = {1, 2, 3, 4, 5};
    // max calls
    try {
        int max_val = max_element(vec.begin(), vec.end());
        std::cout << "Maximum element is: " << max_val << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }

 
    try {
        int max_val = max_element(list.begin(), list.end());
        std::cout << "Maximum element is: " << max_val << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }
    //min calls
    try {
        int min_val = min_element(vec.begin(), vec.end());
        std::cout << "Minimum element is: " << min_val << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        int min_val = min_element(list.begin(), list.end());
        std::cout << "Minimum element is: " << min_val << std::endl;        
    } catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }
    
    // sum calls
    try {
        int sum_val = sum_element(vec.begin(), vec.end());
        std::cout << "Sum of elements is: " << sum_val << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        int sum_val = sum_element(list.begin(), list.end());
        std::cout << "Sum of elements is: " << sum_val << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}