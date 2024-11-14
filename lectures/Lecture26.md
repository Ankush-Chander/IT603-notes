---
delivery date:
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

usage:
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
