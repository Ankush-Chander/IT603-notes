## Lecture 7

## Quick Recap
1. Primitive Variable types(bool, char, short, int, long, float, double)
2. Memory management (stack, heap, program data, initialization behaviour)
3. Type conversions

## Agenda: 
1. Expressions/Statements
2. Control flow

## Expressions vs statements

| Aspect             | Expression                                  | Statement                                   |
|--------------------|---------------------------------------------|---------------------------------------------|
| **Definition**     | Produces a value.                           | Performs an action.                         |
| **Components**     | Can be a variable, constant, or a combination using operators. | Can include expressions, but also control structures like loops, conditionals, and declarations. |
| **Result**         | Evaluates to a value.                       | Does not necessarily produce a value, but can affect the flow of control. |
| **Example**        | `5 + 3`, `x * y`, `42`                      | `int x = 10;`, `if (x > 5) { ... }`, `return 0;` |
| **Use in Code**    | Typically used within statements.           | Forms the structure of the program's logic. |
| **Side Effects**   | May or may not have side effects.           | Typically used to perform actions or change state. |
| **Terminating Character** | Generally doesn't end with a semicolon (except in certain contexts like function calls). | Ends with a semicolon or a block (`{}`) in most cases. |



## Examples

```c++
    int x; // a declaration statement, no return value
    int a, b=1, c=2;

    a = b+c; // assignment expression, return value = left-hand-operand
    std::cout << "value stored in a => " << a << std::endl; 
    std::cout << (a=b+c) << std::endl; // prints 3

    
    int result = 5 + 3; // declaration statement, no return value only side effect

    
    std::cout << x; // expression with return value left-hand-operand
    
    if (x > 5) {          // Conditional statement
        x = x * 2;        
    }
```

## Different kinds of operators
**Arithmetic operators**

|Operator|Function|Use|
|---|---|---|
|`+`|Unary plus|`+expr`|
|`-`|Unary minus|`-expr`|
|`+`|Addition|`expr + expr`|
|`-`|Subtraction|`expr - expr`|
|`*`|Multiplication|`expr * expr`|
|`/`|Division|`expr / expr`|
|`%`|Remainder|`expr % expr`|


**Relational and logical operators**
Logical and Relational Operators

| Associativity | Operator | Function              | Use           |
| ------------- | -------- | --------------------- | ------------- |
| Left          | `<`      | Less than             | `-expr`       |
| Left          | `<=`     | Less than or equal    | `expr <= expr` |
| Left          | `>`      | Greater than          | `expr > expr` |
| Left          | `>=`     | Greater than or equal | `expr >= expr` |
| Left          | `==`     | Equality              | `expr == expr` |
| Left          | `!=`     | Inequality            | `expr != expr` |
| Right         | `!`      | Logical _NOT_         | `!expr`       |
| Left          | `&&`     | Logical _AND_         | `expr && expr` |
| Left          | `\|\|`     | Logical _OR_          | `expr \|\| expr` |


```c++
#include <iostream>

int main() {
    // Arithmetic Operators
    int num1 = 10;
    int num2 = 5;

    std::cout << "Arithmetic Operations:\n";
    std::cout << "Addition: " << num1 + num2 << "\n";
    std::cout << "Subtraction: " << num1 - num2 << "\n";
    std::cout << "Multiplication: " << num1 * num2 << "\n";
    std::cout << "Division: " << static_cast<float>(num1) / num2 << "\n"; // Using float to avoid integer division

    // Logical Operators
    bool condition1 = true;
    bool condition2 = false;

    std::cout << "\nLogical Operations:\n";
    std::cout << "AND Operation: " << (condition1 && condition2) << "\n";
    std::cout << "OR Operation: " << (condition1 || condition2) << "\n";
    std::cout << "NOT Operation: " << !condition1 << "\n";

    return 0;
}
```

### Logical operators and short circuiting

The right side of an && is evaluated if and only if the left side is true.
```
Eg: If you have 70+ attendance **and** you get Grade above 3,  you pass.
If first statement evaluates to False, the second  one does not need to be evaluated and final result will be False.
```

The right side of an || is evaluated if and only if the left side is false.  
```
Eg: if its sunny **or** I have an umbrella, I will be dry.
If first statement is true, it wont matter whether I have umbrella or not. 
```

### Conditional operator
The conditional operator (the ?:operator) lets us embed simple if-else logic inside an expression. The conditional operator has the following form:

```c++
cond  ? expr1  : expr2;
```

Example usage:

```c++
string finalgrade = (grade < 60) ? "fail" : "pass";
```

Note: There are some other operators like bitwise operator, comma operator, etc. which  will be covered eventually with  relate topics.

## Control Flow in C++
- Control flow determines the order in which statements and instructions are executed.
- Types of control flow:
  - Sequential Execution
  - Conditional statements
  - Iterative statements
  - Jump statements



### Sequential execution
- The default mode of execution in C++.
- Statements are executed one after another in the order they appear.
- Example:

  ```c++
  int a = 5;
  int b = 10;
  int sum = a + b;
  ```

### Conditional statements
- Allow execution of code based on conditions.
- Types:
  - `if` statement
  - `if-else` statement
  - `else if` ladder
  - `switch` statement

**if statement**
```c++
if (condition) {
    // Code to execute if condition is true
}
```
**if-else statement**
```c++
if (condition) {
    // Code to execute if condition is true
} else {
    // Code to execute if condition is false
}
```

**else if ladder**
```c++
if (condition1) {
    // Code to execute if condition1 is true
} else if (condition2) {
    // Code to execute if condition2 is true
} else {
    // Code to execute if all conditions are false
}
```
**switch statement**
```c++
switch (expression) {
    case constant1:
        // Code to execute if expression == constant1
        break;
    case constant2:
        // Code to execute if expression == constant2
        break;
    default:
        // Code to execute if no case matches
}
```

### Iterative statements
- Allow execution of code multiple times.
- Types:
  - `for` loop
  - `while` loop
  - `do-while` loop  

**for loop**
```c++
for (initialization; condition; increment) {
    // Code to execute
}
```
**while loop**
```c++
while (condition) {
    // Code to execute
}
```

### Jump statements
- Alter the flow of control unconditionally.
- Types:
  - `break`
  - `continue`
  - `goto`
  - `return`

**break statement**
```c++
for (int i = 0; i < 10; i++) {
    if (i == 5) {
        break; // Exit the loop
    }
}
```
**continue statement**
```c++
for (int i = 0; i < 10; i++) {
    if (i % 2 == 0) {
        continue; // Skip the current iteration
    }
}
```

### Jump statements (Continued)
**goto statement**
```c++
goto label;
...
label:
    // Code to execute
```
**return statement**
```c++
int sum(int a, int b) {
    return a + b; // Exit the function and return a value
}
```

## References
1. [C++ primer: Expressions](https://cpp-primer.pages.dev/book/038-chapter_4._expressions.html)
2. [C++ primer: Statements](https://cpp-primer.pages.dev/book/053-chapter_5._statements.html)
