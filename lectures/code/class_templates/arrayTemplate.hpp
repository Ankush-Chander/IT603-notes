#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <cassert>

template <typename T>
class Array
{
private:
    int m_length{};
    T* m_data{};

public:
    // Constructor    
    Array(int length)
    {
        assert(length > 0);
        m_data = new T[length]{}; // Allocate an array of objects of type T
        m_length = length;
    }

    // Copy constructor for deep copying
    Array(const Array& other)
    {
        m_length = other.m_length;
        // 
        m_data = new T[m_length];
        for (int i = 0; i < m_length; ++i)
        {
            m_data[i] = other.m_data[i];
        }
    }

    // Copy assignment operator for deep copying
    Array& operator=(const Array& other)
    {
        if (this == &other)
            return *this; // handle self-assignment

        // Clean up existing resource
        delete[] m_data;

        // Copy data from the source object
        m_length = other.m_length;
        m_data = new T[m_length];
        for (int i = 0; i < m_length; ++i)
        {
            m_data[i] = other.m_data[i];
        }

        return *this;
    }

    // Destructor
    ~Array()
    {
        delete[] m_data;
    }

    void erase()
    {
        delete[] m_data;
        m_data = nullptr;
        m_length = 0;
    }

    // Templated operator[] function
    T& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    int getLength() const { return m_length; }

    // Print all elements of the array
    void print() const
    {
        for (int i = 0; i < m_length; i++)
        {
            std::cout << m_data[i] << " ";
        }
        std::cout << std::endl;
    }


    // define iterator class
    class Iterator {
    private:
        T* ptr_;
    public:
        using iterator_category = std::random_access_iterator_tag;

        using value_type = T;
        using pointer = T*;
        using reference = T&;
        
        // signed integer type used to represent the difference between two pointers.
        using difference_type = std::ptrdiff_t;
        
        Iterator(pointer ptr) : ptr_(ptr) {}

        // access operators
        // deference operator
        reference operator*() const { return *ptr_; }
        
        // arrow operator
        pointer operator->() { return ptr_; }
        

        // prefix increment
        Iterator& operator++() { 
            ++ptr_;
            return *this; }
        // // postfix increment
        Iterator operator++(int) { Iterator temp = *this; ++(*this); return temp; }
        
        // // // prefix decrement
        Iterator& operator--() { 
            --ptr_; 
            return *this; }
        // postfix decrement
        Iterator operator--(int) { 
            Iterator temp = *this;
            --(*this); return temp; 
        }
        
        // addition and subtraction operators
        Iterator operator+(difference_type offset) const { return Iterator(ptr_ + offset); }
        Iterator operator-(difference_type offset) const { return Iterator(ptr_ - offset); }
        
        // difference operator
        difference_type operator-(const Iterator& other) const { return ptr_ - other.ptr_; }

        Iterator& operator+=(difference_type offset) { ptr_ += offset; return *this; }
        Iterator& operator-=(difference_type offset) { ptr_ -= offset; return *this; }

        // comparison operators
        bool operator==(const Iterator& other) const { return ptr_ == other.ptr_; }
        bool operator!=(const Iterator& other) const { return !(*this == other); }
        
        bool operator<(const Iterator& other) const { return ptr_ < other.ptr_; }
        bool operator>(const Iterator& other) const { return ptr_ > other.ptr_; }
        bool operator<=(const Iterator& other) const { return ptr_ <= other.ptr_; }
        bool operator>=(const Iterator& other) const { return ptr_ >= other.ptr_; }
    };

    Iterator begin() { 
        return Iterator(m_data);
         }
    Iterator end(){ 
        return Iterator(m_data + m_length);
    }

    };


#endif
