---
delivery date: 2024-08-13
---
#### Quick recap

1. Datatypes
2. Variables
	1. Primitive
	2. Compound
3. Functions
4. Multi-file compilation
	1. Preprocessing directives
	2. Header files
	3. Linker
		1. Symbol resolution
		2. Relocation

---
#### Agenda
1. Arrays (C++)
2. Strings (C++)
---
#### Arrays
Arrays are a  [compound type](https://cpp-primer.pages.dev/book/023-2.3._compound_types.html#filepos394806). 
An array declarator has the form `a[d]`, where 
- `a` is the name being defined 
- `d` is the dimension of the array. The dimension specifies the number of elements and must be greater than zero.    

The number of elements in an array is part of the array’s type. As a result, the dimension must be known at compile time, which means that the **dimension must be a constant expression**

---
#### Array initialization
```c++
unsigned cnt = 42;          // not a constant expression
constexpr unsigned sz = 42; // constant expression
                            // constexpr see § 2.4.4 (p. 66)
int arr[10];             // array of ten ints
int *parr[sz];           // array of 42 pointers to int
string bad[cnt];         // error: cnt is not a constant expression
string strs[get_size()]; // ok if get_size is constexpr, error otherwise
```
---
#### Accessing elements
![](https://media.geeksforgeeks.org/wp-content/uploads/20250310111928472679/traverse-array.webp)

Arrays are accessed using [] operator.
arr[0] refers to first element, arr[1] refers to the second element and so on

---
#### Array indexes and pointer arithmetic
- Name of the array is the address of the first element of the array.
- Applying indexing operation on array is equivalent to dereferencing of the array elements
---
	
```c++
int arr[5];
```

| Notation  | Type |                                                                  |
| --------- | ---- | ---------------------------------------------------------------- |
| arr       | int* | Address of the first element of the array. Equivalent to &arr[0] |
| arr + i   | int* | Address of the ith element of the array                          |
| \*(arr+i) | int  | value of ith element of the array                                |
| arr[i]    | int  | value of ith element of the array                                |

---

#### String literals
A **string literal** is a sequence of characters enclosed in double quotes (`"`). It is a constant array of characters that ends with a null character (`'\0'`), which indicates the end of the string.

```cpp
const char* str = "Hello, World!";
str[0] = "h" // not allowed

"Hello" + "World" // + operator doesnt work!
```
---
#### Char arrays
A **char array** is a basic array of characters that you can use to store a sequence of characters. Unlike string literals, a char array can be modified.
```cpp
char greeting[] = "Hello";
greeting[1] = 'H' // modifiable

```
---
#### std::string
`std::string` is a class provided by the C++ Standard Library that represents a dynamic sequence of characters. It is part of the `<string>` header and is much more flexible and powerful than raw string literals.

```cpp
// initialization
string greeting = "Hello";
greeting += " World!"
cout << greeting << endl; // "Hello World!"
```

---

| **Feature**           | **String Literal** (`"Hello"`)       | **Char Array** (`char greeting[] = "Hello"`) | **std::string** (`std::string greeting = "Hello"`)                           |
| --------------------- | ------------------------------------ | -------------------------------------------- | ------------------------------------------------------------------------------- |
| **Type**              | `const char[]`                       | `char[]`                                     | `std::string`                                                                |
| **Null-Terminated**   | Yes (automatically)                  | Yes (if initialized with a string literal)   | No (internally managed, but compatible with C-style strings using `c_str()`) |
| **Mutable**           | No                                   | Yes                                          | Yes                                                                          |
| **Memory Management** | Fixed at compile-time, read-only     | Fixed at compile-time, but mutable           | Dynamically managed, resizes automatically                                   |
| **Usability**         | Limited                              | Requires careful management                  | High, with many built-in functions                                           |
| **Memory Storage**    | Typically stored in read-only memory | Stack (if local)                             | Heap (dynamic allocation)                                                    |

---
##### Ways to Initialise strings(1)

| Code                 | Description                                                   |
| -------------------- | ------------------------------------------------------------- |
| `string s1`          | Default initialization; `s1` is the empty string.             |
| `string s2(s1)`      | `s2` is a copy of `s1`.                                       |
| `string s2 = s1`     | Equivalent to `s2(s1)`, `s2` is a copy of `s1`.               |
| `string s3("value")` | `s3` is a copy of the string literal, not including the null. |

---
##### WAYS TO INITIALISE STRINGS(2)

| Code                  | Description                                                        |
| --------------------- | ------------------------------------------------------------------ |
| `string s3 = "value"` | Equivalent to `s3("value")`, `s3` is a copy of the string literal. |
| `string s4(n, 'c')`   | Initialize `s4` with `n` copies of the character`'c'`.             |

---
##### String Functions

```c++
#include <iostream>
#include <string>
using namespace std;

int main() {
    // Initializing a string
    string str = "Hello, World!";

    // Length of the string
    cout << "Length of the string: " << str.length() << endl;

    // Accessing characters
    cout << "First character: " << str[0] << endl;
    cout << "Last character: " << str[str.length() - 1] << endl;

    // Substring
    string sub = str.substr(7, 5); // Starting from index 7, length 5
    cout << "Substring: " << sub << endl;

    // Find a substring
    size_t pos = str.find("World");
    if (pos != string::npos) {
        cout << "\"World\" found at index: " << pos << endl;
    } else {
        cout << "\"World\" not found" << endl;
    }

    // Replace a part of the string
    str.replace(7, 5, "Everyone"); // Replacing "World" with "Everyone"
    cout << "After replacement: " << str << endl;

    // Inserting a substring
    str.insert(7, "Beautiful "); // Inserting "Beautiful " at index 7
    cout << "After insertion: " << str << endl;

    // Erasing a part of the string
    str.erase(7, 10); // Erasing "Beautiful "
    cout << "After erasing: " << str << endl;

    // Converting to C-string (const char*)
    const char* cstr = str.c_str();
    cout << "C-string: " << cstr << endl;

    return 0;
}

```
---

#### References
1. [Chapter 3. Strings, Vectors, and Arrays | C++ Primer, Fifth Edition](https://cpp-primer.pages.dev/book/029-chapter_3._strings_vectors_and_arrays.html)
