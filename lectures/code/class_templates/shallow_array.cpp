#include <iostream>
#include <memory>


using namespace std;
template <typename T>
class Array {
private:
    // T* m_data{};
    std::shared_ptr<T[]> m_data;  // Use shared pointer instead for shallow copying
    int m_size;

public:
    // Constructor
    Array(int size) : m_size(size), m_data(new T[size]()) {}

    // Shallow Copy Constructor
    Array(const Array& other){
        m_size = other.m_size;
        m_data = other.m_data; 
    }

    // Shallow Copy Assignment Operator
    Array& operator=(const Array& other) {
        if (this == &other) {
            return *this;  // Self-assignment check
        }

        // Assign size and shared pointer (shallow copy)
        m_size = other.m_size;
        m_data = other.m_data;

        return *this;
    }

    // Destructor
    ~Array() {
        cout << "calling destructor" << endl;
        // no freeing up memory required as it is smart shared pointer     
    }

    // Access elements
    int& operator[](int index) {
        return m_data[index];
    }

    int size() const {
        return m_size;
    }
};

int main() {
    Array<int> arr1(5);
    for (int i = 0; i < arr1.size(); ++i) {
        arr1[i] = i * 2;  // Initialize with some values
    }

    // Use shallow copy constructor
    Array<int> arr2 = arr1;

    // Use shallow copy assignment operator
    Array<int> arr3(5);
    arr3 = arr1;

    // Modify arr1 and see if arr2 and arr3 reflect the changes
    arr1[0] = 100;

    cout << "long(&arr1[0]): " << long(&arr1[0]) << ", long(&arr2[0]): " << long(&arr2[0]) << ", long(&arr3[0]): " << long(&arr3[0])<<endl;
    std::cout << "arr2[0] = " << arr2[0] << "\n";  // Should output 100
    std::cout << "arr3[0] = " << arr3[0] << "\n";  // Should output 100

    return 0;
}
