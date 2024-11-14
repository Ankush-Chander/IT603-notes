---
delivery date:
  - 2024-11-13
  - 2024-11-14
---
#### Quick recap
1. Function Templates
---
#### Agenda
1. Class templates
---
#### Declaration of class template
```cpp
template<typename T>
class Box{
private:
	T value; 
public: 
	// constructor
	Box(T val){
		value = val;
	}
	// getter
	T getValue() {
		return value;
	} 
};
```

<<<<<<<< HEAD:lectures/Lecture26.md
usage:
========
---
#### How does function overloading works?
C++ differentiates functions with name and parameter both.  
It generates a new name for each function.  **The new name depends on the original C++ function name and  parameters**.  
Given a function name of a set of parameters, it will always generate a unique name. If parameters (number of params, type of params or order of params) change then it will generate another name even if the original C++ function name is same.  This process of encoding the function name is known as **name mangling**.

---
#### Overload resolution(1)
Overload resolution proceeds through the following steps:
1. Building the set of [candidate functions](https://en.cppreference.com/w/cpp/language/overload_resolution#Candidate_functions).
2. Trimming the set to only [viable functions](https://en.cppreference.com/w/cpp/language/overload_resolution#Viable_functions).
3. Analyzing the set to determine the single [best viable function](https://en.cppreference.com/w/cpp/language/overload_resolution#Best_viable_function) (this may involve [ranking of implicit conversion sequences](https://en.cppreference.com/w/cpp/language/overload_resolution#Ranking_of_implicit_conversion_sequences)).
---
Each [type of standard conversion sequence](https://en.cppreference.com/w/cpp/language/implicit_conversion "cpp/language/implicit conversion") is assigned one of three ranks:

1) **Exact match**: no conversion required, lvalue-to-rvalue conversion, qualification conversion, function pointer conversion,(since C++17) user-defined conversion of class type to the same class  
2) **Promotion**: integral promotion, floating-point promotion   
3) **Conversion**: integral conversion, floating-point conversion, floating-integral conversion, pointer conversion, pointer-to-member conversion, boolean conversion, user-defined conversion of a derived class to its base

---
#### 1) Exact Match
- **No Conversion Required**: 
  ```cpp
  int a = 10;
  int b = a; // Exact match, no conversion
  ```

- **lvalue-to-rvalue Conversion**: 
  ```cpp
  int a = 10;
  int b = a + 5; // `a` is treated as an rvalue in the expression `a + 5`
  ```

- **Qualification Conversion**: 
  ```cpp
  const int a = 10;
  int b = a; // Removing const (qualification) for compatibility
  ```

- **Function Pointer Conversion**: 
  ```cpp
  void func();
  void (*fptr)() = func; // Exact match as function pointer types match
  ```

---
#### 2) Promotion

- **Integral Promotion**: Converts smaller integral types (e.g., `char`, `short`) to `int`. For example:
  
  ```cpp
  char c = 'A';
  int i = c; // `char` is promoted to `int`
  ```

- **Floating-Point Promotion**: Converts `float` to `double`, preserving precision in floating-point arithmetic:
  
  ```cpp
  float f = 3.14f;
  double d = f; // `float` is promoted to `double`
  ```
---
#### 3) Conversion
  ```cpp
// Integral Conversion
int a = 65;
char c = a; // `int` is converted to `char`

// Floating-Point Conversion
double d = 3.14159;
  float f = d; // `double` to `float` conversion

// Floating-Integral Conversion
double d = 3.14;
int i = d; // `double` to `int`, truncates the decimal part

// Pointer Conversion
int* ptr = nullptr; // nullptr can convert to any pointer type

```

---

  ```cpp
// Boolean Conversion
int a = 10;
  bool b = a; // Non-zero integer to `true`

// User-Defined Conversion (Derived to Base)
class Base {};
class Derived : public Base {};

Derived d;
Base* b = &d; // Derived-to-Base conversion
```

---
#### Drawbacks of function overloading
- Increased Maintenance Overhead  
	More challenging to maintain the code. It’s easier to make mistakes or overlook updating all versions when modifications are required.
- Potential for Code Bloat
- Harder to debugging and code analysis
---
#### Comparison with other languages
- C does **not support function overloading** in the way C++ does. Each function must have a unique name, and its parameters must be defined at compile time. 
- JavaScript **doesn't have true function overloading** in the way C++ does. When defining multiple functions with the same name, the last definition will overwrite any previous ones.
- Python **doesn't support function overloading** by default, but you can achieve similar functionality using default arguments, `*args`, and `**kwargs`.

---

#### Function templates 
A function template is a recipe for generating a parametrized family of functions.  
**Example**:
>>>>>>>> 3c6d06157242e0c38974cedb28ab49edeac8c8a1:lectures/Lecture25.md
```cpp
Box<int> intBox(5);
intBox.getValue()// returns 5

Box<std::string> strBox("Hello");
strBox.getValue(); // returns "Hello"
```

---
#### Parameter types
##### Type parameters
```c++
template<typename T> // parameter is of type typename
class Box {
    T value;
public:
    Box(T val) : value(val) {}
    T getValue() { return value; }
};

// Usage:
Box<int> intBox(42);          // T is int
Box<std::string> strBox("Hi"); // T is std::string

```
---

#####  Non type parameters
These allow us to pass constant values (like integers or pointers) as parameters to a template. They can be useful for fixed-size data structures, like arrays.
```c++
template<typename T, int Size> 
class Array{
	T arr[Size]; 
	public: 
	T& operator[](int index) { 
		return arr[index]; 
		} 
}; 

// Usage: 
Array<int, 10> intArray; // Size is set to 10 
Array<double, 5> doubleArray; // Size is set to 5
```
---
#####  Variadic  templates
```c++
// printAll is a funtion template that take 
//variable number of template parameters
template<typename... Args>
void printAll(Args... args) {
	(std::cout << (... + args)) << '\n';

// Fold expression (... + args) equivalent to args[0] + args[1] 
//+ args[2] + ...
}

int main(int argc, char const *argv[]){
	/* code */
	printAll(1, 2.5, "hello"); // Prints: 12.5hello
	printAll(100, 25, "hello", "world!"); // Prints: 10025hello
	return 0;
}
```
---
#### Template specialization
Class template specialization allows us to *create specific versions of a template for particular types or conditions.* This gives us the flexibility to **implement different behaviours or optimizations for particular cases** without needing a new class or function.  
There are two main types of template specialization: 
- **full specialization** 
- **partial specialization**.

---
##### Full specialization(1)
In full specialization, we specify the exact type for a template, creating a unique implementation just for that type.
```c++
// Primary (generic) template
template<typename T>
class Printer {
public:
    void print(T value) {
        std::cout << "Generic Printer: " << value << std::endl;
    }
};
// Full specialization for std::string
template<>
class Printer<std::string> {
public:
    void print(std::string value) {
        std::cout << "String Printer: " << value << std::endl;
    }
};
```
---
##### Full specialization(2)
```c++
// Usage
int main() {
    Printer<int> intPrinter;
    intPrinter.print(42);
    // Uses the generic template

    Printer<std::string> stringPrinter;
    stringPrinter.print("Hello, World"); 
    // Uses the specialized version

    return 0;
}
```

---
##### Partial Specialization(1)
Partial specialization allows us to **specialize a template for a subset of its parameters or when certain conditions are met**. This is often used in more complex templates with multiple parameters or non-type parameters. 

---
##### Partial Specialization(2)
```c++
template<typename T1, typename T2>
class MyClass {
};
template<typename T>
class MyClass<T,T> { // partial: both template parameters have same type
};
template<typename T>
class MyClass<T,int> { // partial: second type is int
};
template<typename T1, typename T2>
class MyClass<T1*,T2*> { // // partial: both template parameters are pointer types
};
```

---
##### Partial Specialization(3)
###### Usage:
```C++
MyClass< int, float> mif; // uses MyClass<T1,T2>
MyClass< float, float> mff; // uses MyClass<T,T>
MyClass< float, int> mfi; // uses MyClass<T,int>
MyClass< int*, float*> mp; // uses MyClass<T1*,T2*>\
```

```c++
MyClass< int, int> m;// ERROR: matches MyClass<T,T> 
// and MyClass<T,int>
MyClass< int*, int*> m;// ERROR: matches MyClass<T,T>
// and MyClass<T1*,T2*>
```
---
##### Type Aliases
1. using `typedef`

```c++
typedef Stack<int> IntStack; // typedef
void foo (IntStack const& s);// s is stack of ints
IntStack istack[10]; // istack is array of 10 stacks of ints
```
2.
By using the keyword `using` (since C++11)

```c++
using IntStack = Stack <int>; // alias declaration
void foo (IntStack const& s); // s is stack of ints
IntStack istack[10];// istack is array of 10 stacks of ints
```
---
#### Iterators, Container algorithms
Refer code examples

---
#### References
1. [Chapter 2 - C++ templates - Complete guide](https://github.com/fusying-hwang/books/blob/main/C%2B%2B%20Templates%20The%20Complete%20Guide(2nd).pdf)
2. [CppCon2021-back_to_basics_templates_part_1__bob_steagall__cppcon_2021.pdf (optional)](https://github.com/CppCon/CppCon2021/blob/main/Presentations/back_to_basics_templates_part_1__bob_steagall__cppcon_2021.pdf)