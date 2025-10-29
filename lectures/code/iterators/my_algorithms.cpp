#include <iostream>
#include "linked_list.h"
#include "dynamic_array.h"

using namespace std;

template<class T>
T max_array(Vector<T> arr, size_t size) {
    T max = arr[0];
    for (size_t i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

template<class T>
T max_forward_list(ForwardList<T> fl){
    if (fl.empty()) {
        return 0;
    }
    T max = fl.head->data;
    auto current = fl.head;
    while (current) {
        if (current->data > max) {
            max = current->data;
        }
        current = current->next;
    }
    return max;
    
}


template<class T>
T min_array(Vector<T> arr, size_t size) {
    T min = arr[0];
    for (size_t i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

template<class T>
T min_forward_list(ForwardList<T> fl){
    if (fl.empty()) {
        return 0;
    }
    T min = fl.head->data;
    auto current = fl.head;
    while (current) {
        if (current->data < min) {
            min = current->data;
        }
        current = current->next;
    }
    return min;
    
}

template<class T>
T sum_array(Vector<T> arr, size_t size) {
    T sum = 0;
    for (size_t i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

template<class T>
T sum_forward_list(ForwardList<T> fl){
    if (fl.empty()) {
        return 0;
    }
    T sum = 0;
    auto current = fl.head;
    while (current) {
        sum += current->data;
        current = current->next;
    }
    return sum;
    
}

int main(int argc, char const *argv[])
{
    Vector<int> arr = {1, 2, 3, 4, 5};
    // max
    int max_of_darray = max_array(arr, arr.getSize());
    cout << "max_of_darray: "<< max_of_darray << endl;
    ForwardList<int> fl = {5, 4, 3, 2, 1};
    int max_of_fl = max_forward_list(fl);
    cout << "max_of_fl: "<< max_of_fl << endl;
    // min
    int min_of_darray = min_array(arr, arr.getSize());
    cout << "min_of_darray: "<< min_of_darray << endl;
    int min_of_fl = min_forward_list(fl);
    cout << "min_of_fl: "<< min_of_fl << endl;
    // sum
    int sum_of_darray = sum_array(arr, arr.getSize());
    cout << "sum_of_darray: "<< sum_of_darray << endl;
    int sum_of_fl = sum_forward_list(fl);
    cout << "sum_of_fl: "<< sum_of_fl << endl;

    return 0;
}


