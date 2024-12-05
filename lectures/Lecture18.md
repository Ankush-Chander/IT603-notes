---
delivery date: 2024-09-18
---
#### Quick recap
1. Dynamic memory allocation
	1. Stack vs Heap
	2. new and delete operators
	3. Smart pointers
---
#### Agenda
1. Iterators

---
#### What are containers?
A container is a holder object that stores a collection of other objects (its elements).
The container 
- *manages the storage space* for its elements
- *provides member functions to access them*, either directly or through **iterators** (reference objects with similar properties to pointers).

---
#### Sequential containers

The **[sequential containers](https://cpp-primer.pages.dev/book/096-defined_terms.html#filepos2453431)** let the programmer **control the order in which the elements are stored and accessed**. That order does not depend on the values of the elements. Instead, the order corresponds to the position at which elements are put into the container.

---

| Container      | Function                                                                                                                    |
| -------------- | --------------------------------------------------------------------------------------------------------------------------- |
| `vector`       | Flexible-size array. Supports fast random access. Inserting or deleting elements other than at the back may be slow.        |
| `deque`        | Double-ended queue. Supports fast random access. Fast insert/delete at front or back.                                       |
| `list`         | Doubly linked list. Supports only bidirectional sequential access. Fast insert/delete at any point in the `list`.           |
| `forward_list` | Singly linked list. Supports only sequential access in one direction. Fast insert/delete at any point in the list.          |
| `array`        | Fixed-size array. Supports fast random access. Cannot add or remove elements.                                               |
| `string`       | A specialized container, similar to `vector`, that contains characters. Fast random access. Fast insert/delete at the back. |

---
#### What are iterators?
An **iterator** is an object (like a pointer) that points to an element inside the container. We can use iterators to move through the contents of the container. They can be visualized as something similar to a pointer pointing to some location and we can access the content at that particular location using them.

---
![](https://raw.githubusercontent.com/Ankush-Chander/IT603-notes/49069a8e06c8f58a3d52751935d3a05188df5abe/lectures/images/iterator_types.png)

---
#### Powers of iterators

![](https://media.geeksforgeeks.org/wp-content/uploads/C_Iterator.jpg)

Pic credit: [Geeks for Geeks](https://www.geeksforgeeks.org/introduction-iterators-c)

---
#### Why do we need iterators?
-  **Generic Access Across All Containers**
	Not all containers in C++ support index-based access (like arrays or vectors). For example, `std::list`, `std::set`, and `std::map` are **non-indexed containers**,
- **Abstraction and Decoupling from Data Structures**
	Iterators abstract away the internal representation of the container. You can work with elements without worrying about how they are stored.
-  **Const Iterators**
	Iterators allow for read-only access via **const iterators**, which prevent modification of the elements during traversal. This is more expressive and safer compared to index-based access.
---

#### Standard Container Iterator Operations

| Code                              | Description                                                                                                                                                               |
| --------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| `*iter`                           | Returns a reference to the element denoted by the iterator `iter`.                                                                                                        |
| `iter->mem`                       | Dereferences `iter` and fetches the member named `mem` from the underlying element. Equivalent to `(*iter).mem`.                                                          |
| `++iter`                          | Increments `iter` to refer to the next element in the container.                                                                                                          |
| `--iter`                          | Decrements `iter` to refer to the previous element in the container.                                                                                                      |
| `iter1 == iter2` `iter1 != iter2` | Compares two iterators for equality (inequality). Two iterators are equal if they denote the same element or if they are the off-the-end iterator for the same container. |

---
#### How to declare iterators
```c++
// :: is a scope resolution operator
// read and write iterator over vector<int> elements
vector<int>::iterator it; 

// read and write iterator over characters in a string
string::iterator it2;

// read only iterator over vector<int> elements
vector<int>::const_iterator it3; 

// read only iterator over characters in a string
string::const_iterator it4;      
```

---
#### The begin and end Operations
- **`begin()`**: Returns an iterator pointing to the first element of the container.
- **`end()`**: Returns an iterator pointing just past the last element (not a valid element, but a sentinel).

```c++
vector<int> v;
const vector<int> cv;
auto it1 = v.begin();  
// it1 has type vector<int>::iterator
auto it2 = cv.begin(); 
// it2 has type vector<int>::const_iterator
// return type of `begin()` is const based on type of container

```


---
#### References
1. [3.4. Introducing Iterators | C++ Primer, Fifth Edition](https://cpp-primer.pages.dev/book/033-3.4._introducing_iterators.html)
2. [Introduction to Iterators in C++ - GeeksforGeeks](https://www.geeksforgeeks.org/introduction-iterators-c)
3. [Back to basic- STL(*imp: refer iterator slides)](https://github.com/CppCon/CppCon2021/blob/main/Presentations/back_to_basics_classic_stl__bob_steagall__cppcon_2021_1.pdf)
