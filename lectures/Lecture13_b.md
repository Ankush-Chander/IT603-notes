---
delivery date: []
---
# Agenda
1. Dynamic arrays
2. Refer [code](code/lecture_13b)
---
#### Vectors
`std::vector` is a class that provides a **dynamic array** functionality. Unlike static arrays, where the size is fixed at compile-time, vectors can **dynamically resize themselves** as elements are added or removed.

`std::vector` is defined within the `std` namespace and is included via the `<vector>` header file. It encapsulates data and methods that allow for the storage, manipulation, and management of a sequence of elements.

---
##### Initialization
```c++
// Default constructor, empty vector
std::vector<int> vec;

// Explicit assignment
std::vector<int> vec1 = {1, 2, 3, 4};

// Initializes a vector with 10 elements (default-initialized)
std::vector<int> vec2(10);

// Initializes a vector with 10 elements, all set to 5
std::vector<int> vec3(10, 5);
```
---
##### Capacity Functions
Functions like `size()`, `capacity()`, and `empty()` help manage and understand the vector's size and capacity.

- `size()` returns the number of elements currently in the vector.
- `capacity()` returns the number of elements the vector can hold before needing to allocate more memory.
- `empty()` returns whether the vector is empty.
---

#####  Element Access 

Vectors provide several ways to access elements:
- `operator[]`: Provides direct access using the subscript operator.
- `at()`: Provides bounds-checked access.
- `front()` and `back()`: Access the first and last elements.
- `data()`: Returns a pointer to the underlying array.

---
```c++
std::vector<int> vec = {1, 2, 3, 4};
int x = vec[2];    // Access using operator[]
int y = vec.at(2); // Access using at(), throws an exception if out of bounds
int first = vec.front();
int last = vec.back();

```
---
##### Modifiers 
Vectors provide functions to modify their contents:
- `push_back()`: Adds an element to the end of the vector.
- `pop_back()`: Removes the last element.
- `insert()`: Inserts elements at a specific position.
- `erase()`: Removes elements from a specific position or range.
- `clear()`: Removes all elements from the vector.
---
```c++
vec.push_back(5);  // Adds 5 to the end
vec.pop_back();    // Removes the last element
vec.insert(vec.begin() + 1, 10);  // Inserts 10 at the second position
vec.erase(vec.begin() + 2);       // Removes the element at the third position
```
---
##### **Memory Management in Vectors**

- **Dynamic Allocation:** Vectors dynamically allocate memory on the heap. The vector manages this memory, ensuring that elements are stored contiguously.
- **Capacity and Reallocation:** When a vector's capacity is exceeded (e.g., when `push_back()` is called), the vector allocates more memory (usually doubling its capacity) and copies the existing elements to the new memory location.
- **Memory Efficiency:** While vectors handle memory management automatically, understanding the concept of capacity helps you optimize performance.

---
##### Reservation Vs Allocation
```c++
// reservation
std::vector<int> vec;
const int N = std::stoi(argv[1]);
vec.reserve(N); // Reserve capacity for N elements
for (int i = 0; i < N; ++i) {
	vec.push_back(i); // No dynamic resizing needed
}
std::cout << "Final vector capacity: " << vec.capacity() << std::endl;
std::cout << "Final vector size: " << vec.size() << std::endl;
return 0;
```

---
```c++
// reallocation
std::vector<int> vec;
std::cout << "Initial vector size: " << vec.size() << std::endl;
const int N = std::stoi(argv[1]);
for (int i = 0; i < N; ++i) {
	vec.push_back(i); // Vector resizes dynamically as needed
}
std::cout << "Final vector capacity: " << vec.capacity() << std::endl;
std::cout << "Final vector size: " << vec.size() << std::endl;
return 0;
```

---
#### Comparison
```bash
time ./vector_reservation.out 100000000
#Final vector capacity: 100000000
#Final vector size: 100000000

#real	0m0.888s
#user	0m0.700s
#sys	0m0.188s
```
```bash
time ./vector_relocation.out 100000000
#Final vector capacity: 134217728
#Final vector size: 100000000

#real	0m1.190s
#user	0m0.789s
#sys	0m0.401s
```

---
### IntVector class implementation
Refer code here[]()

---
#### References
1. [3.5. Arrays | C++ Primer, Fifth Edition](https://cpp-primer.pages.dev/book/034-3.5._arrays.html)
2. [3.6. Multidimensional Arrays | C++ Primer, Fifth Edition](https://cpp-primer.pages.dev/book/035-3.6._multidimensional_arrays.html)
---
