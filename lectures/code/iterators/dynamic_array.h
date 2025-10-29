#include <memory>
#include <iterator>

template<typename T>
class Vector {
private:
    struct SharedData {
        std::shared_ptr<T[]> data;
        size_t size;
        size_t capacity;
    };
    
    std::shared_ptr<SharedData> sharedData;
    
    void resize() {
        size_t new_capacity = sharedData->capacity == 0 ? 1 : sharedData->capacity * 2;
        reserve(new_capacity);
    }

public:
    Vector(){
        sharedData = std::make_shared<SharedData>();
        sharedData->data = nullptr;
        sharedData->size = 0;
        sharedData->capacity = 0;
    }

    // initializer list
    Vector(std::initializer_list<T> list) {
        sharedData = std::make_shared<SharedData>();
        sharedData->data = nullptr;
        sharedData->size = 0;
        sharedData->capacity = 0;
        for (const T& value : list) {
            push_back(value);
        }
    }

    
    size_t getSize() const {
        return sharedData->size;
    }

    size_t getCapacity() const {
        return sharedData->capacity;
    }

    void reserve(size_t new_capacity) {
        if (new_capacity > sharedData->capacity) {
            std::shared_ptr<T[]> new_data(new T[new_capacity], std::default_delete<T[]>());
            for (size_t i = 0; i < sharedData->size; ++i) {
                new_data[i] = sharedData->data[i];
            }
            sharedData->data = new_data;
            sharedData->capacity = new_capacity;
        }
    }

    void push_back(const T& value) {
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

    void insert(size_t index, const T& value) {
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

    T& operator[](size_t index) {
        if (index >= sharedData->size) {
            throw std::out_of_range("Index out of range");
        }
        return sharedData->data[index];
    }

    // Enable the copy constructor
    Vector(const Vector& other)
        : sharedData(other.sharedData) {}

    // Enable the assignment operator
    Vector& operator=(const Vector& other) {
        if (this != &other) {
            sharedData = other.sharedData;
        }
        return *this;
    }


    // iterator related code
    class Iterator {
    private:
        T* ptr;
    public:
        using iterator_category = std::random_access_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = T;
        using pointer = T*;
        using reference = T&;

        Iterator(T* ptr){
            this->ptr = ptr;
        }

        reference operator*() const { 
            return *ptr;
        }

        pointer operator->() { 
            return ptr; 
        }

        // Pre-increment
        Iterator& operator++() {
            ++ptr;
            return *this;
        }

        // Post-increment
        Iterator operator++(int) {
            Iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        // Pre-decrement
        Iterator& operator--() {
            --ptr;
            return *this;
        }

        // Post-decrement
        Iterator operator--(int) {
            Iterator tmp = *this;
            --(*this);
            return tmp;
        }

        Iterator operator+(difference_type offset) const {
            return Iterator(ptr + offset);
        }

        Iterator operator-(difference_type offset) const {
            return Iterator(ptr - offset);
        }

        difference_type operator-(const Iterator& other) const {
            return ptr - other.ptr;
        }

        Iterator& operator+=(difference_type offset) {
            ptr += offset;
            return *this;
        }

        Iterator& operator-=(difference_type offset) {
            ptr -= offset;
            return *this;
        }

        reference operator[](difference_type offset) {
            return *(ptr + offset);
        }

        bool operator==(const Iterator& other) const {
            return ptr == other.ptr;
        }

        bool operator!=(const Iterator& other) const {
            return ptr != other.ptr;
        }

        bool operator<(const Iterator& other) const {
            return ptr < other.ptr;
        }

        bool operator>(const Iterator& other) const {
            return ptr > other.ptr;
        }

        bool operator<=(const Iterator& other) const {
            return ptr <= other.ptr;
        }

        bool operator>=(const Iterator& other) const {
            return ptr >= other.ptr;
        }
    };

    Iterator begin() {
        return Iterator(sharedData->data.get());
    }

    Iterator end() {
        return Iterator(sharedData->data.get() + sharedData->size);
    }
};
