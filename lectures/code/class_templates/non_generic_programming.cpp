#include <iostream>
#include "generic_programming.hpp"

using namespace std;

// sum function for int array
template <typename T> T
Array<T>::sum() {
    T total = 0;
    for (T i = 0; i < this->size(); i++) {
        total += this->data_[i];
    }
    return total;
}

// min function for int array
template <typename T> T
Array<T>::min() {
    T min = this->data_[0];
    for (T i = 1; i < this->size(); i++) {
        if (this->data_[i] < min) {
            min = this->data_[i];
        }
    }
    return min;
}

// max function for int array
template <typename T> T
Array<T>::max() {
    T max = this->data_[0];
    for (T i = 1; i < this->size(); i++) {
        if (this->data_[i] > max) {
            max = this->data_[i];
        }
    }
    return max;
}

// sum function for linked list
template <typename T>
T LinkedList<T>::sum() {
    T total = 0;
    auto  current = this->head_;
    while (current != nullptr) {
        total += current->data;
        current = current->next;
    }
    return total;
}


// min function for linked list
template <typename T>
T LinkedList<T>::min() {
    T min = this->head_->data;
    auto current = this->head_;
    while (current != nullptr) {
        if (current->data < min) {
            min = current->data;
        }
        current = current->next;
    }
    return min;
}

// max function for linked list
template <typename T>
T LinkedList<T>::max() {
    T max = this->head_->data;
    auto current = this->head_;
    while (current != nullptr) {
        if (current->data > max) {
            max = current->data;
        }
        current = current->next;
    }
    return max;
}


int main() {
    Array<int> intArray(5);
    for (int i = 0; i < intArray.size(); i++) {
        intArray[i] = i + 1;
    }
    

    cout << "Sum of int array: " << intArray.sum() << endl;
    cout << "Min of int array: " << intArray.min() << endl;
    cout << "Max of int array: " << intArray.max() << endl;
    
    LinkedList<int> linkedlist;
    linkedlist.push_back(1);
    linkedlist.push_back(2);
    linkedlist.push_back(3);

    cout << "Sum of linked list: " << linkedlist.sum() << endl;
    cout << "Min of linked list: " << linkedlist.min() << endl;
    cout << "Max of linked list: " << linkedlist.max() << endl;
}