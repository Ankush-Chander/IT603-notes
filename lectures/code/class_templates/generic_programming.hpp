#include <iostream>
#include <iterator>


template <typename T>
class Array {

private:
    T* data_;
    size_t size_;

public:
    
    // declare iterator
    class Iterator;

    // blank constructor
    Array(size_t size) {
        data_ = new T[size];
        size_ = size;
    }
    
    // destructor
    ~Array() { delete[] data_; }

    // operator overloading of []
    T& operator[](size_t index) { 
        return data_[index];
        }
    // const version
    const T& operator[](size_t index) const {
         return data_[index];
    }

    size_t size() const {
         return size_; 
    }

    // declare sum function
    T sum();
    // declare min function
    T min();
    T max();


    // iterator code 
    Iterator begin() { 
        return Iterator(data_);
    }
    
    Iterator end() { 
        return Iterator(data_ + size_);
    }

    class Iterator {
    private:
        pointer ptr_;

    public:
        using iterator_category = std::random_access_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;

        Iterator(pointer ptr) : ptr_(ptr) {}

        reference operator*() const { return *ptr_; }
        pointer operator->() { return ptr_; }

        // Prefix increment
        Iterator& operator++() {
            ++ptr_;
            return *this;
        }

        // Postfix increment
        Iterator operator++(int) {
            Iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        friend bool operator==(const Iterator& a, const Iterator& b) { return a.ptr_ == b.ptr_; }
        friend bool operator!=(const Iterator& a, const Iterator& b) { return a.ptr_ != b.ptr_; }


    };    
};

// linked list
template <typename T>
class LinkedList {
public:
    struct Node {
        T data;
        Node* next;
    };

    class Iterator;

    // blank constructor
    LinkedList(){
        head_ = nullptr;
    }

    // destructor
    ~LinkedList() {
        Node* current = head_;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    
    void push_back(T value) {
        Node* newNode = new Node{value, nullptr};
        if (!head_) {
            head_ = newNode;
        } else {
            Node* current = head_;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    T sum();
    T min();
    T max();




    // iterator code
    Iterator begin() { return Iterator(head_); }
    Iterator end() { return Iterator(nullptr); }

    class Iterator {
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = Node*;
        using reference = T&;

        
        Iterator(pointer ptr) : ptr_(ptr) {}

        reference operator*() const {
             return ptr_->data; 
        }
        pointer operator->() { 
            return ptr_; 
        }

        // Prefix increment
        Iterator& operator++() {
            ptr_ = ptr_->next;
            return *this;
        }

        // Postfix increment
        Iterator operator++(int) {
            Iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        friend bool operator==(const Iterator& a, const Iterator& b) { return a.ptr_ == b.ptr_; }
        friend bool operator!=(const Iterator& a, const Iterator& b) { return a.ptr_ != b.ptr_; }

    private:
        pointer ptr_;
    };

    T max_element() const {
        T max = head_->data;
        Node* current = head_->next;
        while (current) {
            if (current->data > max) {
                max = current->data;
            }
            current = current->next;
        }
        return max;
    }

private:
    Node* head_;
};