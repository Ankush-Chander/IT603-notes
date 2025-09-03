#include <iostream>
#include <stdexcept> // to use std::out_of_range


class IntVector {
    private:
        int size;
        int capacity;
        int* data;

    public:
    IntVector(){
        this->size = 0;
        this->capacity = 0;
        this->data = nullptr;
    }
    ~IntVector(){
        std::cout << "calling deconstructor" << std::endl; 
        delete[] this->data;
        this->data = nullptr;
    }
    int getSize(){
        return this->size;
    }

    int getCapacity(){
        return this->capacity;
    }

    void resize(){
        size_t new_capacity = this->capacity >0? 2*this->capacity:1;
            int *new_data = new int[new_capacity];
            for(size_t i=0; i<this->size; i++){
                new_data[i] = data[i];
            }
            delete[] data;
            this->capacity = new_capacity;
            this->data = new_data;
    }
    
    void push_back(int val){
        if (this->size==this->capacity){
            // some heavylifting
            resize();
        }

        this->data[size] = val;
        this->size++;
    }

    void insert(size_t position, int val){
        if (this->size==this->capacity){
            // some heavylifting
            resize();
        }
        for(size_t i= this->getSize(); i> position; i--){
            this->data[i]=this->data[i-1]; 
        }
        this->data[position] = val;
        this->size++;
    }

    void erase(size_t position){
        for(size_t i=position;i<this->getSize();i++){
            this->data[i] = this->data[i+1]; 
        }
        this->size--;
    }

    int operator[](size_t i){
        if (i>this->getSize()){
            // throw std::out_of_range;
        }
        return this->data[i];
    }

    void clear(){
        this->size=0;
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
    // vec[1] = -4;
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

    // // IntVector<int> vec2 = vec;
    // // std::cout << "After copy constructor: ";
    // // for (size_t i = 0; i < vec2.getSize(); ++i) {
    // //     std::cout << vec2[i] << " ";
    // // }
    // // std::cout << std::endl;

    // // IntVector vec3 = vec;
    
    vec.clear();
    std::cout << "After clear, size: " << vec.getSize() << std::endl;
    IntVector v2 = vec;

    return 0;
}