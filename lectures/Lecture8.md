### Quick recap
1. Expressions are evaluated, yields values
2. Statements are executed, leads to side effect, sometimes generate values
3. Operators (Arithmetic, Logical/Relational operators, Conditional operators)
4. Control flow (Sequential, Conditional, Iterative, Jumps)
---
### Agenda:
1. Compound datatypes (references, pointers)
2. Functions

---
## Compound datatypes

| Feature        | References                                                    | Pointers                                                      |
| -------------- | ------------------------------------------------------------- | ------------------------------------------------------------- |
| Definition     | An alias for another variable.                                | A variable that holds the memory address of another variable. |
| Syntax         | `int &ref = var;`                                             | `int *ptr;`                                                   |
| Initialization | Must be initialized when declared.                            | Can be initialized to `NULL`, `nullptr`, or an address.       |
| Dereferencing  | Automatically dereferenced.                                   | Use `*` operator to access the value at the address.          |
| Reassignment   | Cannot be reassigned after initialization.                    | Can be reassigned to point to different addresses.            |
| Nullability    | Cannot be null. Must always refer to a valid object/variable. | Can be null (i.e., point to no address).                      |
| Memory Address | Does not store an address but refers to an existing variable. | Can store the address of a variable.                          |
| Arithmetic     | Does not support arithmetic.                                  | Supports pointer arithmetic (e.g., `ptr++`, `ptr+1`).         |


---
```c++
#include <iostream>

int main(int argc, char const *argv[])
{
    /* code */
    int i = 10;
    // create a reference for an existing variable
    int &j = i;
    std::cout << "i=" << i << std::endl << "j=" << j << std::endl;
    std::cout << "&i=" << &i << std::endl << "&j=" << &j << std::endl;
    
    // change the reference
    j=20;
    std::cout << "i=" << i << std::endl << "j=" << j << std::endl;
    std::cout << "&i=" << &i << std::endl << "&j=" << &j << std::endl;

    // declare a reference without initializing it. ???  
    // int &k;
    

    return 0;
}

```

---
```c++
#include <iostream>

int main(int argc, char const *argv[])
{
    /* code */
    // create a char variable
    char a  = 'x';
    
    // & is the addressof operator
    // Note that same operator when used in left hand side,
    // it"s used as reference operator
    
    // * is the pointer notation which signifies ptr stores the address of an int variable
    
    char *ptr = &a;
    std::cout << "char a=" << a << std::endl; // value of variable
    std::cout << "&a=" << &a << std::endl; // address of variable
    std::cout << "ptr=" << ptr << std::endl; // address of variable stored in a pointer


    std::cout << "*ptr=" << *ptr << std::endl;
    std::cout << "ptr=" << long(ptr) << std::endl;
    std::cout << "ptr+1=" << long(ptr+1) << std::endl;
    std::cout << "char: long(ptr+1) - long(ptr) =" << long(ptr+1) - long(ptr) << std::endl;


    // create an int pointer
    int x  = 10;
    int *ptr2 = &x;
    std::cout << "int x=" << x << std::endl; // value of variable
    std::cout << "&x=" << &x << std::endl; // address of variable
    std::cout << "ptr2=" << ptr2 << std::endl; // address of variable stored in a pointer


    std::cout << "*ptr2=" << *ptr2 << std::endl;
    std::cout << "ptr2=" << long(ptr2) << std::endl;
    std::cout << "ptr2+1=" << long(ptr2+1) << std::endl;
    std::cout << "int: long(ptr2+1) - long(ptr2) =" << long(ptr2+1) - long(ptr2) << std::endl;
    
    return 0;
}
```
---

## Functions
Functions are blocks of code that perform a specific task, encapsulated so they can be reused throughout a program. Functions help in organizing code, improving readability, and reducing redundancy.

---
### Signature
```c++
return_type function_name(parameter_list) {
    // body of the function
    // code to be executed
}
```

---
### Return type
The type of the value that a function returns need to be specified in function"s definition.
Most of the datatypes can be used as return types:
Eg: void, int, float etc. 

But not Arrays or function types.

---
### Parameters vs Arguments:

**Parameters** are the input that a function accepts. Anybody using the function needs to abid by the types of parameter. They should either be of same type or they should be convertible to the parameter type.

**Arguments** are the initializers for a function’s parameters. The first argument initializes the first parameter, the second argument initializes the second parameter, and so on.

---
### Example
Without function:

```c++
#include <iostream>

int main(int argc, char const *argv[])
{
    /* code */
    int n = std::stoi(argv[1]);
    int r = std::stoi(argv[2]);
    //nPr = n!/(n-r)!

    // calculate factorial of n
    int n_factorial = 1;
    for (int i = 1; i <= n; i++)
    {
        n_factorial *= i;
    } 

    // calculate factorial of n-r
    int n_r_factorial = 1;
    for (int i = 1; i <= n-r; i++){
        n_r_factorial *= i;
    }


    int n_cr = n_factorial / (n_r_factorial);
    std::cout <<"nCr(" << n << "," << r << ")== " << n_cr << std::endl;
    return 0;
}
```
---
With function
```c++
#include <iostream>

// return_type func_name(parameter_list)
int factorial(int n)
{
    int fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}

int factorial_recursive(int n){
    if (n == 0){
        return 1;
    }
    else{
        return n * factorial_recursive(n-1);
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    int n = std::stoi(argv[1]);
    int r = std::stoi(argv[2]);

    // function call: func_name(argument_list)
    // initialization of function parameters
    // int nPr = factorial(n) / factorial(n-r); // return value stored in nPr
    int nPr = factorial_recursive(n) / factorial_recursive(n-r);
    std::cout <<"nPr(" << n << "," << r << ")== " << nPr << std::endl;
    return 0;
}
```
---
Function calling
```c++
factorial("hello");       // error: wrong argument type
factorial();              // error: too few arguments
factorial(42, 10, 0);     // error: too many arguments
factorial(3.14);          // ok: argument is converted to int
```

---
### Different ways to pass arguments

1. Pass by value
```c++
void addTen(int x) {
    x = x + 10;
    std::cout << "Inside function: " << x << "\n";
}

int main() {
    int a = 5;
    addTen(a);
    std::cout << "Outside function: " << a << "\n";
}
```


---

```vb
main():      a = 5
             |
             v
        [copy] -----> addTen(x = 5)
                        x += 10 → x = 15
        <---- returns, original a remains unchanged

Output:
Inside function: 15
Outside function: 5

```
---
2. Pass by reference
```c++
void addTen(const int& x) {
    x = x + 10;
    std::cout << "Inside function: " << x << "\n";
}

int main() {
    int a = 5;
    addTen(a);
    std::cout << "Outside function: " << a << "\n";
}

```
---
```vb
main():      a = 5
             |
             v
        [reference] ---> addTen(x refers to a)
                          x += 10 → a = 15

Output:
Inside function: 15
Outside function: 15

```
---
3. Pass by address

```cpp
void addTen(int* x) {
    if (x) *x = *x + 10;
    std::cout << "Inside function: " << *x << "\n";
}

int main() {
    int a = 5;
    addTen(&a);
    std::cout << "Outside function: " << a << "\n";
}

```
---
```vb
main():      a = 5
             |
             v
        [address] ---> addTen(x = pointer to a)
                        *x += 10 → a = 15

Output:
Inside function: 15
Outside function: 15

``` 
---

### Scope and lifetime
In C++, names have scope , and objects have lifetimes.

- The scope of a name is the part of the program’s text in which that name is visible.
- The lifetime of an object is the time during the program’s execution that the object exists.

Parameters and variables defined inside a function body are referred to as local variables. There visibility is within the function body, and lifetime is while the function is executing. They are called **automatic objects**  

---
### Static objects
Sometimes we want objects to retain their value between function calls. In that case we define those variables as **static objects**


```c++
size_t count_calls()
{
    static size_t ctr = 0;  // value will persist across calls
    return ++ctr;
}
int main()
{
    for (size_t i = 0; i != 10; ++i)
        cout << count_calls() << endl;
    return 0;
}
```

---

### Function overloading
Function overloading allows multiple functions with the same name but different parameter lists. The correct function is chosen based on the arguments passed.
```c++
int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}

int main() {
    std::cout << add(2, 3) << std::endl;     // calls int add(int, int)
    std::cout << add(2.5, 3.5) << std::endl; // calls double add(double, double)
    return 0;
}

```

---
## References
1. [Compound types](https://cpp-primer.pages.dev/book/023-2.3._compound_types.html)
2. [Functions](https://cpp-primer.pages.dev/book/062-chapter_6._functions.html)
