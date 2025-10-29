---
delivery date:
  - "[[2024-11-07]]"
  - "[[2024-11-06]]"
---
#### Quick recap
1. Templates overview
---
#### Agenda
1. Function templates
---
### Function overloading

- **Definition**: Writing multiple functions with the same name but different parameter types or counts.

- **Benefits**:
- Simplifies API design by using the same function name for different types.
- Enables the design of functions that operate seamlessly across different data types.
---
- **Example**:

```cpp

int min(int a, int b){ 
	return (b < a) ? b : a;
}

double min(double a, double b){
	return (b < a) ? b : a;
}

long min(long a, long b){
	return (b < a) ? b : a;
}
```

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
```cpp
//- Definition of function template min

int min(int &a, int &b){ 
	return (b < a) ? b : a;
}



template<class T>
T const& min(T const& a, T const& b)
{
return (b < a) ? b : a;
}

int i = 42, j = 100;
double d = 3.14, e = 4.6;
auto k = min<int>(i, j); // k = 42
auto f = min<double>(d, e); // f = 3.14

```

---
#### Definition vs instantiation
**Definition**: 
- A generic blueprint specifying a function's operations.
- Occurs once, no memory allocated, no function body compiled.
**Instantiation**:   
  - The process where the compiler creates a specific version of the function:
- Occurs when the function is first called with specific type arguments.
- Produces a concrete function handling those types alone.

---
##### Examples
```c++
// File: "add.hpp"
// Function template definition 
template <typename T>
T add(T a, T b) {
	return a + b;
}
```
---
##### Explicit instantiation
```c++
#include "add.hpp"
#include "iostream"
// Explicit instantiation
template int add<int>(int, int);
template double add<double>(double, double);

int main() {
	int resultInt = add<int>(10, 20); 
	// Uses explicitly instantiated function
	double resultDouble = add<double>(5.5, 3.3); 
	// Uses explicitly instantiated function
	cout << "Sum of integers: " << resultInt << endl;
	cout << "Sum of doubles: " << resultDouble << endl;
	return 0;
}

```
---
##### Implicit instantiation

```c++
#include <iostream>
using namespace std;
// Function template definition
template <typename T>
T add(T a, T b) {
	return a + b;
}

int resultInt = add(10, 20); 
// Implicit instantiation with T as int
int resultInt = add(30, 40); 
// Reuse already instantiated function
double resultDouble = add(5.5, 3.3); 
// Implicit instantiation with T as double
```
---
#### Type deduction
```c++
template<typename T>
T max (T const& a, T const& b)
{
	return b < a ? a : b;
}
int i = 10;
int const c = 42;
max(i, c); // OK: T is deduced as int
max(10, c); // OK: T is deduced as int
int& ir = i;
max(i, ir); // OK: T is deduced as int
max(4, 7.2); // ERROR: T can be deduced as int or double
max<float>(4, 7.2) // OK: 4 is type casted to float
```
---
#### Two way compilation
Templates are “compiled” in two phases:
1. Without instantiation at definition time, the template code itself is checked for correctness ignoring the template parameters. 
	- Syntax errors are discovered, such as missing semicolons, unknown names (type names, function names, …) that don’t depend on template parameters are discovered
	- Static assertions that don’t depend on template parameters are checked.
1. At instantiation time, all parts that depend on template parameters are double-checked.
---
#### Compilation step 
When a function template is used in a way that triggers its instantiation, a compiler will (at some point) need to see that template’s definition. This breaks the usual compile and link distinction **for ordinary functions, when the declaration of a function is sufficient to compile its use.**  
**Simplest approach:** Implement each template inside a header file.

---
#### Multiple template parameters
Function templates have two distinct sets of parameters:
1. **Template parameters:** are declared in angle brackets before the function.
2. **Call parameters:**  are declared in parentheses after the function template.
```c++
template<typename T>
// T is template parameter
T max (T a, T b)
// a and b are call parameters
```

---
**Problem statement:** define the max() template for call parameters of two potentially different types
```c++
// Method 1:
template<typename T1, typename T2>
T1 max (T1 a, T2 b){
	return b < a ? a : b; 
}
auto m = ::max(4, 7.2);

// Method 2:
template<typename T1, typename T2, typename RT>
RT max (T1 a, T2 b){
	return b < a ? a : b; 
}
::max<int,double,double>(4, 7.2); // okay but tedious
```
---
```cpp
// Method3
template<typename RT, typename T1, typename T2>
RT max (T1 a, T2 b);
…
::max<double>(4, 7.2) 
//OK: return type is double, T1 and T2 are deduced

// method4: let compiler deduce the return type
template<typename T1, typename T2>
auto max (T1 a, T2 b)
{
return b < a ? a : b;
}
```

```c++
// method 5: choose common type as return type
#include <type_traits>
template<typename T1, typename T2>
std::common_type_t<T1,T2> max (T1 a, T2 b){
	return b < a ? a : b;
}
// Thus, both ::max(4, 7.2) and ::max(7.2, 4) 
//yield the same value 7.2 of type double.
```
---
#### Overloading function templates
- All other factors being equal, the overload resolution process prefers the non-template over one generated from the template.

```cpp
// maximum of two int values:
int max (int a, int b){
return b < a ? a : b;
}
// maximum of two values of any type:
template<typename T>
T max (T a, T b){
	return b < a ? a : b;
}
```


```cpp
int main(){
::max(7, 42); // // calls the nontemplate for two ints
::max(7.0, 42.0);// // calls max<double> (by argument deduction)
::max(’a’, ’b’); //calls max<char> (by argument deduction)
::max<>(7, 42); // calls max<int> (by argument  deduction)
::max<double>(7, 42); // calls max<double>(no argument deduction)
```
---
#### References
1. [How does a C++ compiler choose which overloaded function to use? - Quora](https://www.quora.com/How-does-a-C-compiler-choose-which-overloaded-function-to-use)
2. [Chapter 1 - C++ templates - Complete guide](https://github.com/fusying-hwang/books/blob/main/C%2B%2B%20Templates%20The%20Complete%20Guide(2nd).pdf)
