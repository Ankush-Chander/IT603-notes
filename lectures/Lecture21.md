---
delivery date: 2024-09-25
---
#### Quick recap
1. Containers(map, unordered_map)
	1. Inner workings

---
#### Agenda
1. Generic Algorithms
---
**[Generic algorithms](https://cpp-primer.pages.dev/book/105-defined_terms.html#filepos2712822)**: 
- “algorithms” because they implement common classical algorithms such as sorting and searching, 
- “generic” because they operate on elements of differing type and across multiple container types—not only library types such as `vector` or `list`, but also the built-in array type

---
#### Sequential container Operations

| **Operation**            | **Command**               | **Description**                                                                                      |
| ------------------------ | ------------------------- | ---------------------------------------------------------------------------------------------------- |
| **Add element**          | `push_back(value)`        | Adds an element to the end of the container.                                                         |
|                          | `emplace_back(arguments)` | Constructs an element at the end of the container.                                                   |
| **Remove element**       | `pop_back()`              | Removes the last element from the container.                                                         |
|                          | `erase(iterator)`         | Removes an element or range of elements.                                                             |
| **Access first element** | `front()`                 | Returns a reference to the first element.                                                            |
| **Access last element**  | `back()`                  | Returns a reference to the last element.                                                             |
| **Check if empty**       | `empty()`                 | Returns `true` if the container has no elements, otherwise `false`.                                  |
| **Access begin**         | `begin()`                 | Returns an iterator to the first element.                                                            |
| **Access end**           | `end()`                   | Returns an iterator to one past the last element.                                                    |
| **Insert element**       | `insert(position, value)` | Inserts an element at the specified position.                                                        |
| **Clear elements**       | `clear()`                 | Removes all elements from the container.                                                             |
| **Size of container**    | `size()`                  | Returns the number of elements in the container.                                                     |
| **Resize container**     | `resize(new_size)`        | Changes the number of elements stored in the container.                                              |
| **Reserve space**        | `reserve(size)`           | Requests that the container capacity be at least enough to hold `size` elements (for `vector` only). |

---
#### Example of generic algorithm

```cpp
int val = 42; // value we'll look for
// result will denote the element we want if it's in vec, or vec.cend() if not
auto result = find(vec.cbegin(), vec.cend(), val);
// report the result
cout << "The value " << val
     << (result == vec.cend()
           ? " is not present" : " is present") << endl;
```
---
1. access the first element in the sequence.
2. compare that element to the value we want.
3. If the element matches the one we want, `find` returns a value that identifies this element.
4. Otherwise, `find` advances to the next element and repeats steps 2 and 3.
5. `find` must stop when it has reached the end of the sequence.
6. If `find` gets to the end of the sequence, it needs to return a value indicating that the element was not found. This value and the one returned from step 3 must have compatible types.
---
#### Note on Generic Algorithms
- Iterators make the algorithms container independent
- Algorithms do depend on element-type operations
- Algorithms never execute container operations
---
#### Read only algorithms
**Read-only algorithms** do not modify the elements of the container but instead perform actions like searching, counting, or summing values.

---
 **`find`**
The `find` algorithm searches for the first occurrence of a specific value in a range of elements.

- **Header**: `<algorithm>`
- **Syntax**:
  ```cpp
  iterator find(iterator first, iterator last, const T& value);
  ```
  - `first`, `last`: The range of elements to search through.
  - `value`: The value to find.

- **Returns**: An iterator pointing to the first element equal to `value`. If not found, it returns `last`.
---
- **Example**:
  ```cpp
  #include <algorithm>
  #include <vector>
  #include <iostream>

  int main() {
      std::vector<int> vec = {1, 2, 3, 4, 5};
      auto it = std::find(vec.begin(), vec.end(), 3);
      
      if (it != vec.end()) {
          std::cout << "Found: " << *it << std::endl;
      } else {
          std::cout << "Not Found" << std::endl;
      }
  }
  ```
---
 **`count`**    
The `count` algorithm counts the number of occurrences of a specific value in a range of elements.
- **Header**: `<algorithm>`
- **Syntax**:
  ```cpp
  int count(iterator first, iterator last, const T& value);
  ```
  - `first`, `last`: The range of elements to search through.
  - `value`: The value to count.

- **Returns**: The number of elements that are equal to `value`.

---
- **Example**:

```cpp
#include <algorithm>
#include <vector>
#include <iostream>
using namespace srd;
  int main(){
      vector<int> vec = {1, 2, 3, 2, 2, 5};
      int countOfTwos = count(vec.begin(), vec.end(), 2);
      cout << "Count of 2s: " << countOfTwos << endl;
}
```

---

 **`accumulate`**  
The `accumulate` algorithm computes the sum (or other binary operation result) of elements in a range.
- **Header**: `<numeric>`
- **Syntax**:
  ```cpp
  T accumulate(iterator first, iterator last, T init);
  
  T accumulate(iterator first, iterator last, T init, BinaryOperation op);
  ```
  - `first`, `last`: The range of elements.
  - `init`: The initial value to start the accumulation.
  - `op`: A binary operation (optional) applied to each element.
- **Returns**: The accumulated result.
---
- **Example (Sum)**:

```cpp
#include <numeric>
#include <vector>
#include <iostream>
using namespace std;

int main() {
      vector<int> vec = {1, 2, 3, 4, 5};
      int sum = accumulate(vec.begin(), vec.end(), 0);
      
      std::cout << "Sum: " << sum << std::endl;
  }
```
---
- **Example (Product)**:
```cpp
#include <numeric>
#include <vector>
#include <iostream>
using namespace std;
int main() {
      vector<int> vec = {1, 2, 3, 4, 5};
      int product = accumulate(vec.begin(), vec.end(), 1, multiplies<int>());
      cout << "Product: " << product << endl;
}
```

---
#### Algorithms That Write Container Elements
Some algorithms assign new values to the elements in a sequence.  
Note : Algorithms do not perform container operations, so they have no way themselves to change the size of a container.

---
**`std::fill`**  
The `fill` algorithm assigns a specific value to all elements in a range.
- **Syntax**:
  ```cpp
  void fill(iterator first, iterator last, const T& value);
  ```
  - `first`, `last`: The range of elements to be filled.
  - `value`: The value to assign to each element in the range.
- **Description**: This algorithm overwrites all elements in the specified range with the given value.
---
- **Example**:
  ```cpp
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int main() {
      vector<int> vec(5);
      fill(vec.begin(), vec.end(), 10);
      
      for (int v : vec) {
          cout << v << " ";  // Output: 10 10 10 10 10
      }
  }
  ```
---
**`std::copy`**  
The `copy` algorithm copies elements from one range to another.
- **Syntax**:
  ```cpp
  iterator copy(iterator first, iterator last, iterator result);
  ```
  - `first`, `last`: The source range of elements to copy.
  - `result`: The beginning of the destination range.
- **Description**: copies elements from the source range `[first, last)` to the range starting at `result`. The destination must be large enough to hold the elements.

---

- **Example**:

```cpp
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main() {
	vector<int> src = {1, 2, 3, 4, 5};
	vector<int> dest(5);
	copy(src.begin(), src.end(), dest.begin());
	// std::copy(src.begin(), src.begin()+2, src.end()-2);
	for (int v : dest) {
		cout << v << " "; // Output: 1 2 3 4 5
	}
}
```
---
**`std::generate`**  
The `generate` algorithm assigns values to elements in a range by calling a function object or lambda expression for each element.

- **Syntax**:
  ```cpp
  void generate(iterator first, iterator last, Generator gen);
  ```
  - `first`, `last`: The range of elements to be assigned.
  - `gen`: A function object or lambda that generates the values.

- **Description**: This algorithm replaces each element in the specified range by invoking the generator function.
---
- **Example**:

```cpp
 #include <algorithm>
 #include <vector>
 #include <iostream>
 #include <cstdlib>  // For std::rand
int random_gen(){
	return std::rand() % 100; 
}
int main() {
      std::vector<int> vec(5);
      
      std::generate(vec.begin%% (), vec.end(), []() { return std::rand() % 100; }); 
      std::generate(vec.begin(), vec.end(), random_gen);
      for (int v : vec) {
          std::cout << v << " ";  // Random output: 42 17 88 59 34 (for example)
      }
  }
  ```
---
 **`std::replace`**  
The `replace` algorithm replaces all occurrences of a specific value in a range with another value.
- **Syntax**:
  ```cpp
  void replace(iterator first, iterator last, const T& old_value, const T& new_value);
  ```
  - `first`, `last`: The range of elements.
  - `old_value`: The value to be replaced.
  - `new_value`: The value to replace `old_value`.

- **Description**: This algorithm replaces all occurrences of `old_value` in the range with `new_value`.
---
- **Example**:
  ```cpp
  #include <algorithm>
  #include <vector>
  #include <iostream>

  int main() {
      std::vector<int> vec = {1, 2, 3, 2, 5};
      std::replace(vec.begin(), vec.end(), 2, 10);
      
      for (int v : vec) {
	          std::cout << v << " ";  // Output: 1 10 3 10 5
      }
  }
  ```
---

**`transform`**

The `transform` algorithm applies a function to each element in a range and stores the result in another range.
- **Syntax**:
  ```cpp
  iterator transform(iterator first, iterator last, iterator result, UnaryOperation op);
  ```
  - `first`, `last`: The source range of elements.
  - `result`: The beginning of the destination range.
  - `op`: A function object or lambda that transforms each element.

---
- **Example**:

 ```cpp
#include <algorithm>
#include <vector>
#include <iostream>

int main() {
	std::vector<int> vec = {1, 2, 3, 4, 5};
    std::vector<int> result(5);
      
    std::transform(vec.begin(), vec.end(), result.begin(), [](int x) { return x * 2; });
      
    for (int v : result) {
        std::cout << v << " ";  // Output: 2 4 6 8 10
    }
}
```

---
#### Lambda expression
A lambda expression represents a callable unit of code. It can be thought of as an unnamed, inline function. 
It has:
- a return type, 
- a parameter list, 
- function body. Unlike a function, lambdas may be defined inside a function. 

---
```c++
[capture list] (parameter list) -> return type  { function body }
```

---
#### References
1. [Chapter 10. Generic Algorithms | C++ Primer, Fifth Edition](https://cpp-primer.pages.dev/book/097-chapter_10._generic_algorithms.html)
