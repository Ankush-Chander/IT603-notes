#ifndef INTARRAY_H
#define INTARRAY_H

#include <cassert>
#include <iostream>
using namespace std;
class IntArray
{

// fixed memory allotment
// indexing
// length
private:
    int m_length{}; // curly brace initialization; equivalent to m_length = 0
    int* m_data{};

public:
    // initialization
    IntArray(int length)
    {
        assert(length > 0);
        m_data = new int[length]{};
        m_length = length;
    }

     
    // destructor for deallocating the memory occupied by the m_data member variable
    // Why do we need a destructor?
    ~IntArray()
    {
        // cout << "destructing IntArray" << endl;
        delete[] m_data;
        // cout << "destructed IntArray" << endl;
        
    }


    void erase()
    {
        delete[] m_data;
        // We need to make sure we set m_data to 0 here, otherwise it will
        // be left pointing at deallocated memory!
        m_data = nullptr;
        m_length = 0;
    }

    int& operator[](int index)
    {
        // allow indexing operator
        // assert is C++11 syntax that checks a condition.
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    int getLength() const { 
        return m_length; 
    }


    // We don't want to allow copies of IntArray to be created.
    // = delete is a C++11 syntax that explicitly deletes a function, making it inaccessible and causing a compiler error if it's used.
    IntArray(const IntArray&) = delete; // disable intArray `intArray b(a);`
    IntArray& operator=(const IntArray&) = delete; // disable `intArray b = a;`

};

#endif