#include <iostream>
#include <stdexcept> // to use std::out_of_range


class IntVector {
private:
    int* data;           // Pointer to the first element of the vector
    size_t size;       // Number of elements in the vector
    size_t capacity;   // Current allocated capacity of the vector

    void resize() {
        size_t new_capacity = capacity == 0? 1: capacity *2;
        reserve(new_capacity);
    }

public:
    IntVector(){
        data = nullptr;
        size = 0;
        capacity = 0;
    } 

    ~IntVector() {
        // deallocate underlying memory
        delete[] data;
    }

    size_t getSize() const {
        // return current size of the vector
        return size;
    }

    size_t getCapacity() const {
        // return current capacity of the vector
        return capacity;
    }

    void reserve(size_t new_capacity) {
        if(new_capacity > capacity) {
            int *new_data = new int[new_capacity];
            for(size_t i=0;i<size;i++){
                new_data[i]=data[i];
            } 
            delete[] data;
            capacity = new_capacity;
            data = new_data;
            
        }
    }

    
    void push_back(const int& value) {
        // check if capacity is full
        if(size==capacity){
            resize();
        }
        
        // insert value at the end
        data[size]= value;
        size++;
        
    }

    void pop_back() {
        // remove the last element
        size--;
    }

    void insert(size_t index, const int& value) {
        // if index > size raise exception
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        
        if(size==capacity){
            resize();
        }
        
        size++;

        // shift all elements after index to the right
        for(size_t i=size;i>=index;i--){
            data[i] = data[i-1];
        }

        data[index] = value;
        // insert value
    }

    void erase(size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        // move all elements after index to the left
        for(size_t i=index;i<size-1;i++){
            data[i] = data[i+1];
        }
        size--;
        // decrement size
    }

    void clear() {
        size = 0;
    }

    int operator[](size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        // apply index operator on the underlying data
        return data[index];
    }

    // allow deep copying
    IntVector(const IntVector& other) {
        size = other.size;
        capacity = other.capacity;
        data = new int[capacity];
        for(size_t i=0;i<size;i++){
            data[i] = other.data[i];
        }
    }

    IntVector& operator=(const IntVector& other) {
        // check for self-assignment
        if (this != &other) {
            size = other.size;
            capacity = other.capacity;
            // deallocate old memory
            delete[] data;
            // allocate new memory
            data = new int[capacity];
            // copy elements
            for(size_t i=0;i<size;i++){
                data[i] = other.data[i];
            }
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

    // IntVector<int> vec2 = vec;
    // std::cout << "After copy constructor: ";
    // for (size_t i = 0; i < vec2.getSize(); ++i) {
    //     std::cout << vec2[i] << " ";
    // }
    // std::cout << std::endl;

    // IntVector vec3 = vec;
    
    vec.clear();
    std::cout << "After clear, size: " << vec.getSize() << std::endl;
    
    return 0;
}