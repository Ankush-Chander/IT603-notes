#include <iostream>
#include "generic_programming.hpp"

template <typename Iterator>
typename Iterator::value_type sum(Iterator begin, Iterator end) {
    typename Iterator::value_type total = 0;
    for (Iterator it = begin; it != end; ++it) {
        total += *it;
    }
    return total;
}

// template for min function
template <typename Iterator>
typename Iterator::value_type min(Iterator begin, Iterator end) {
    typename Iterator::value_type min = *begin;
    for (Iterator it = begin; it != end; ++it) {
        if (*it < min) {
            min = *it;
        }
    }
    return min;
}

// template for max function
template <typename Iterator>
typename Iterator::value_type max(Iterator begin, Iterator end) {
    typename Iterator::value_type max = *begin;
    for (Iterator it = begin; it != end; ++it) {
        if (*it > max) {
            max = *it;
        }
    }
    return max;
}


int main() {
    // Custom contiguous container
    Array<int> arr(5);
    for (size_t i = 0; i < arr.size(); ++i) arr[i] = i + 1;

    // Custom non-contiguous container
    LinkedList<int> ll;
    for (int i = 1; i <= 5; ++i) ll.push_back(i);

    // Calculate the sum using the generic algorithm
    int array_sum = sum(arr.begin(), arr.end());
    int list_sum = sum(ll.begin(), ll.end());

    std::cout << "Sum of array elements: " << array_sum << std::endl;
    std::cout << "Sum of linked list elements: " << list_sum << std::endl;

    // Calculate the minimum using the generic algorithm
    int array_min = min(arr.begin(), arr.end());
    int list_min = min(ll.begin(), ll.end());

    std::cout << "Minimum of array elements: " << array_min << std::endl;
    std::cout << "Minimum of linked list elements: " << list_min << std::endl;

    // Calculate the maximum using the generic algorithm
    int array_max = max(arr.begin(), arr.end());
    int list_max = max(ll.begin(), ll.end());

    std::cout << "Maximum of array elements: " << array_max << std::endl;
    std::cout << "Maximum of linked list elements: " << list_max << std::endl;
    return 0;
}