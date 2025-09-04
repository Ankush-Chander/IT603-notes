---
delivery date: 2024-09-06
---
#### Quick recap

1. Introduction to Boolean Algebra
2. Bit level operations
---
#### Agenda
1. Dynamic Memory
---
Program Memory(revision)

![](https://external-content.duckduckgo.com/iu/?u=https%3A%2F%2Fcourses.engr.illinois.edu%2Fcs225%2Ffa2023%2Fassets%2Fnotes%2Fstack_heap_memory%2Fmemory_layout.png&f=1&nofb=1&ipt=3e36e7e095de1d200726bbb8659fbf73397af5ae07c5fb33fb7f814903ce8c2d&ipo=images)
---
### Object Lifetimes and Storage Locations(1)

| **Object Type**    | **Storage Location**        | **Lifetime**                                        | **Example**                                                     |
| ------------------ | --------------------------- | --------------------------------------------------- | --------------------------------------------------------------- |
| **Static Objects** | Data segment (Program Code) | Entire program duration                             | Global variables, static local variables, static class members. |
| **Local Objects**  | Stack                       | Lifetime limited to the scope of the function/block | Local variables declared inside functions or blocks.            |


---
### Object Lifetimes and Storage Locations(2)

| **Object Type**     | **Storage Location**        | **Lifetime**                                                             | **Example**                                              |
| ------------------- | --------------------------- | ------------------------------------------------------------------------ | -------------------------------------------------------- |
| **Global Objects**  | Data segment (Program Code) | Entire program duration                                                  | Variables declared outside any function (global scope).  |
| **Dynamic Objects** | Heap                        | Manually controlled (allocated with `new` and deallocated with `delete`) | Objects allocated using dynamic memory (`new`/`delete`). |

---
#### Related bash commands
```bash
# return the maximum memory available to program stack(in KB)
ulimit -s 

# return the maximim heap memory available to a program
ulimit -v

# set maximum heap memory to 2GB
ulimit -v 2097152
```

---
#### Key operators(1)
1. **`new` Operator**: Allocates memory on the heap.

```c++
// allocating single variable
int* ptr = new int; // Allocates memory for a single int
*ptr = 10; // Assign value to the allocated memory
```

```c++
// allocating an array
int* arr = new int[10];  
// Allocates memory for an array of 10 ints
arr[0] = 1;              // Assign value to the first element
```

**`delete` Operator**: Deallocates memory previously allocated using `new`.
```c++
delete ptr;  // Frees the memory for the single int
delete[] arr;  // Frees the memory for the array

```

---
#### Example : Dynamic array allocation
```c++
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    // Dynamically allocate memory for an array of size 'n'
    int* arr = new int[n];

    // Initialize and display the array
    for (int i = 0; i < n; ++i) {
        arr[i] = i + 1;
        cout << arr[i] << " ";
    }

    // Deallocate the memory
    delete[] arr;

    return 0;
}

```
---
What happens if we do dynamic allocation inside a function?  
Stack or heap!
```c++
#include <iostream>
using namespace std;

int* allocateMemory() {
    // Dynamically allocate an integer
    int* ptr = new int(10);  // Stored in the heap
    return ptr;              // Return the pointer to the allocated memory
}

int main() {
    int* p = allocateMemory();  // Function returns a pointer to heap memory
    cout << *p << endl; // Output: 10

    delete p;// Manually free the memory
    return 0;
}
```

---
#### Why need dynamic memory allocation?

1. **Efficient Use of Memory**: Dynamic memory allocation allows you to request exactly the amount of memory needed when you need it, making your program more flexible and efficient.
```c++
int n;
cout << "Enter size of array: ";
cin >> n;
int* arr = new int[n];  // Allocates 'n' integers dynamically based on user input
```
---

2. **Larger Data Structures:**
   The **stack** has limited space, and large objects (such as large arrays or complex data structures) may exceed the stack size, leading to a **stack overflow**. The **heap** provides a much larger memory pool.
   Stack has a fixed size available beyond which if program try to use, leads to stack overflow error.
```bash
ulimit -s # returns 8192KB 
```
---

3. **Data Persistence Beyond Function Scope**: 
Dynamically allocated memory persists even after a function ends, allowing data to live beyond the local scope of the function. This makes it useful for scenarios where you need objects to survive across function calls.
```c++
int* createInt() {
	int* ptr = new int(100);  
	// Allocated on the heap
	return ptr; 
	// Memory persists after function returns
}
```
---

4. **Complex Data Structures**  
**Dynamic memory allocation** is essential for constructing complex data structures such as:  
- **Linked Lists**: Dynamic nodes that can be inserted and deleted at runtime.
-  **Trees**: Nodes that grow and branch dynamically.
-  **Graphs**: Networks of dynamically allocated nodes.
---
#### Common pitfalls
1. **Memory Leaks**
A memory leak occurs when dynamically allocated memory is not freed after it's no longer needed, causing the program to consume memory without releasing it.

```cpp
int* ptr = new int(10);
// Forgot to free memory with delete
```
---

 2. **Dangling Pointers**
A dangling pointer arises when memory is deallocated, but the pointer still holds the address of the freed memory. Accessing or modifying a dangling pointer can lead to **undefined behavior** or program crashes.

```cpp
int* ptr = new int(10);
delete ptr;  // Memory is freed
*ptr = 20;   // Dangling pointer: accessing freed memory (undefined behavior)
```

Solution:
Set the pointer to `nullptr` after deleting it to prevent accidental access:
```cpp
delete ptr;
ptr = nullptr;
```
---

3. **Improper Use of `new[]` and `delete[]`**
When allocating arrays dynamically, you need to use `new[]` to allocate and `delete[]` to deallocate. Using `delete` instead of `delete[]` can result in undefined behavior.

#### Example:
```cpp
int* arr = new int[10];  // Allocate array
delete arr;              // Incorrect deallocation (undefined behavior)
```

#### Solution:
Always use `delete[]` for arrays:
```cpp
delete[] arr;  // Correct deallocation
```
---

 4. **Mixing `malloc`/`free` with `new`/`delete`**
In C++, `new`/`delete` should be used for dynamic memory allocation and deallocation, whereas `malloc`/`free` come from C. Mixing them can lead to undefined behavior.
#### Example:
```cpp
int* ptr = (int*)malloc(sizeof(int));  // Using malloc
delete ptr;                            // Wrong: should use free
```

#### Solution:
Stick to either `new`/`delete` or `malloc`/`free` within the same program.

---
#### Smart pointers 
Smart pointers reduce the risk of common memory management problems like **memory leaks** and **dangling pointers**. Unlike raw pointers, **smart pointers automatically handle memory deallocation** when an object is no longer in use.

---
#### 1. **`std::unique_ptr`**: Ownership-Based Management

- **Ownership**: `std::unique_ptr` represents **exclusive ownership** of a dynamically allocated object. Only one `unique_ptr` can point to a given object at a time.

```c++
#include <iostream>
#include <memory>

void uniquePtrExample() {
    std::unique_ptr<int> ptr = std::make_unique<int>(10);  
    // Allocates memory for an int
    std::cout << *ptr << std::endl;  
    // Output: 10
}  
// Memory is automatically freed when `ptr` goes out of scope

```

---
#### **`std::shared_ptr`**: Reference Counting

- **Ownership**: `std::shared_ptr` allows **multiple pointers** to share ownership of a dynamically allocated object. It uses **reference counting** to keep track of how many `shared_ptr` instances are pointing to the object.

```c++
#include <iostream>
#include <memory>
void sharedPtrExample() {
    std::shared_ptr<int> ptr1 = std::make_shared<int>(20);  // Allocates memory for an int
    {
        std::shared_ptr<int> ptr2 = ptr1;  // Shared ownership
        std::cout << *ptr2 << std::endl;  // Output: 20
    }  
// ptr2 goes out of scope, but memory is not freed because ptr1 still owns it
    std::cout << *ptr1 << std::endl;  // Output: 20
}
// Memory is freed when the last shared_ptr (ptr1) goes out of scope
```
---
#### **`std::weak_ptr`**: Preventing Cyclic References

- **Ownership**: `std::weak_ptr` is used alongside `std::shared_ptr` to **break circular references**. It does not contribute to the reference count, and therefore does not own the object.
- **Memory Deallocation**: A `weak_ptr` does not prevent the memory from being deallocated. It can safely observe the object without extending its lifetime.
---
```c++
#include <iostream>
#include <memory>

struct Node {
    std::shared_ptr<Node> next;
    std::weak_ptr<Node> prev;  // Weak pointer prevents circular reference
};

void weakPtrExample() {
    std::shared_ptr<Node> node1 = std::make_shared<Node>();
    std::shared_ptr<Node> node2 = std::make_shared<Node>();

    node1->next = node2;  // Shared ownership
    node2->prev = node1;  
    // Weak ownership (avoids circular reference)
}
```
---
#### References
1. [Chapter 12. Dynamic Memory | C++ Primer, Fifth Edition](https://cpp-primer.pages.dev/book/113-chapter_12._dynamic_memory.html)