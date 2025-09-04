#include <iostream>
#include <stdexcept>
#include <memory>

class IntVector {
private:
    struct SharedData {
        std::shared_ptr<int[]> data;
        size_t size;
        size_t capacity;
    };
    
    std::shared_ptr<SharedData> sharedData;
    
    void resize() {
        size_t new_capacity = sharedData->capacity == 0 ? 1 : sharedData->capacity * 2;
        reserve(new_capacity);
    }

public:
    IntVector(){
        sharedData = std::make_shared<SharedData>();
        sharedData->data = nullptr;
        sharedData->size = 0;
        sharedData->capacity = 0;
    }

    size_t getSize() const {
        return sharedData->size;
    }

    size_t getCapacity() const {
        return sharedData->capacity;
    }

    void reserve(size_t new_capacity) {
        if (new_capacity > sharedData->capacity) {
            std::shared_ptr<int[]> new_data(new int[new_capacity], std::default_delete<int[]>());
            for (size_t i = 0; i < sharedData->size; ++i) {
                new_data[i] = sharedData->data[i];
            }
            sharedData->data = new_data;
            sharedData->capacity = new_capacity;
        }
    }

    void push_back(const int& value) {
        if (sharedData->size == sharedData->capacity) {
            resize();
        }
        sharedData->data[sharedData->size] = value;
        sharedData->size++;
    }

    void pop_back() {
        if (sharedData->size == 0) {
            throw std::out_of_range("Cannot pop_back from an empty vector");
        }
        sharedData->size--;
    }

    void insert(size_t index, const int& value) {
        if (index > sharedData->size) {
            throw std::out_of_range("Index out of range");
        }

        if (sharedData->size == sharedData->capacity) {
            resize();
        }

        for (size_t i = sharedData->size; i > index; i--) {
            sharedData->data[i] = sharedData->data[i - 1];
        }

        sharedData->data[index] = value;
        sharedData->size++;
    }

    void erase(size_t index) {
        if (index >= sharedData->size) {
            throw std::out_of_range("Index out of range");
        }
        for (size_t i = index; i < sharedData->size - 1; i++) {
            sharedData->data[i] = sharedData->data[i + 1];
        }
        sharedData->size--;
    }

    void clear() {
        sharedData->size = 0;
    }

    int operator[](size_t index) {
        if (index >= sharedData->size) {
            throw std::out_of_range("Index out of range");
        }
        return sharedData->data[index];
    }

    // Enable the copy constructor
    IntVector(const IntVector& other)
        : sharedData(other.sharedData) {}

    // Enable the assignment operator
    IntVector& operator=(const IntVector& other) {
        if (this != &other) {
            sharedData = other.sharedData;
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
    std::cout << "vec2: After copy constructor: ";
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