#include <iostream>
#include <stdexcept> // to use std::out_of_range
#include <memory> // to use std::shared_ptr



class IntVector {
private:
    std::shared_ptr<int[]> data; // Use shared_ptr for the data
    size_t size; // Number of elements in the vector
    size_t capacity; // Current allocated capacity of the vector

    void resize() {
        size_t new_capacity = capacity == 0 ? 1 : capacity * 2;
        reserve(new_capacity);
    }

public:
    IntVector()
        : data(nullptr), size(0), capacity(0) {}

    // Explicit destructor is no longer needed due to shared_ptr handling memory

    size_t getSize() const {
        return size;
    }

    size_t getCapacity() const {
        return capacity;
    }

    void reserve(size_t new_capacity) {
        /*
        When std::shared_ptr is reassigned to point to the new array (new_data), the reference count of 
        the old array is decremented. When the reference count reaches zero, the memory used by the 
        original array decreases. If the reference count reaches zero, the original array is 
        automatically deleted using the custom deleter std::default_delete<int[]>, which properly calls 
        delete[] to free the memory.
        */
        
        if (new_capacity > capacity) {
            std::shared_ptr<int[]> new_data(new int[new_capacity], std::default_delete<int[]>());
            for (size_t i = 0; i < size; i++) {
                new_data[i] = data[i];
            }
            data = new_data;
            capacity = new_capacity;
        }
    }

    void push_back(const int& value) {
        if (size == capacity) {
            resize();
        }
        data[size] = value;
        size++;
    }

    void pop_back() {
        if (size == 0) {
            throw std::out_of_range("Cannot pop_back from an empty vector");
        }
        size--;
    }

    void insert(size_t index, const int& value) {
        if (index > size) {
            throw std::out_of_range("Index out of range");
        }

        if (size == capacity) {
            resize();
        }

        for (size_t i = size; i > index; i--) {
            data[i] = data[i - 1];
        }

        data[index] = value;
        size++;
    }

    void erase(size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        for (size_t i = index; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
        size--;
    }

    void clear() {
        size = 0;
    }

    int operator[](size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    // Enable the copy constructor
    IntVector(const IntVector& other)
        : data(other.data), size(other.size), capacity(other.capacity) {}

    // Enable the assignment operator
    IntVector& operator=(const IntVector& other) {
        if (this != &other) {
            data = other.data;
            size = other.size;
            capacity = other.capacity;
        }
        return *this;
    }
};

int main() {
    IntVector vec;
    vec.push_back(0);
    vec.push_back(1);
    vec.push_back(2);

    std::cout << "Size: " << vec.getSize() << std::endl;
    std::cout << "Capacity: " << vec.getCapacity() << std::endl;

    vec.insert(1, 4);
    std::cout << "vec: After insert(1,4): ";
    for (size_t i = 0; i < vec.getSize(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
 
    vec.erase(2);
    std::cout << "vec: After erase(2): ";
    for (size_t i = 0; i < vec.getSize(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    IntVector vec2 = vec;
    std::cout << "vec2: After assignment constructor: ";
    for (size_t i = 0; i < vec2.getSize(); ++i) {
        std::cout << vec2[i] << " ";
    }
    std::cout << std::endl;
    vec2.erase(1);

    std::cout << "vec after erase(1) on vec2: ";
    for (size_t i = 0; i < vec.getSize(); ++i) {
        std::cout << vec[i] << " ";
    }

    std::cout << std::endl;

    vec.clear();
    std::cout << "After clear, size: " << vec.getSize() << std::endl;

    return 0;
}