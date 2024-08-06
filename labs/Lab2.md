---
date: 2024-08-07
---

# Lab2
## Things to be practiced
1. command line argument
2. std input, std output
3. arithmetic expressions
4. conditional operators
5. relational operators
5. references/pointers
6. functions
## Exercises

1. Write a C++ program(`echo.cpp|echo.out`) that works like echo command in linux.

*Hint: use `argv`, `std::out`*
Desired behaviour:
```bash
./echo.out "hello world"
hello world
```

2. Write a c++ program that takes 2 numbers from command line and returns their sum, difference, product and division
*Hint: use command line arguments from `argv` and `arithmetic expressions` and `std::cout`*

```bash
./arithmetic.out 23 10
sum of 23 and 10: 33
difference of 23 and 10: 13
product of 23 and 10: 230
division of 23 and 10: 2
```

  

2. Write a C++ program (`cat.cpp|cat.out`) that takes input from standard input and output same via standard output
```bash
./cat.out
hello world
hello world
[CTRL-D]
```

3. Write a c++ program(`even_odd.cpp|even_odd.out`) to test whether a number is even or odd
Hint: use arithmetic operator as well as conditional operators
```bash
./even_odd.out 23
23 is odd
```

4. Write a C++ program (max_min.cpp|max_min.out) that takes three numbers as input and prints the maximum and minimum of the three.
```bash
./max_min.out 3 5 1
Maximum: 5
Minimum: 1
```
5. Write a C++ program (power.cpp|power.out) that calculates the power of a number. Take the base and exponent as command line arguments.

hint: use iteration and arithmetic operators

```bash
./power.out 2 3
2 raised to the power of 3 is 8
```

6. Write a C++ program (triangle_type.cpp|triangle_type.out) that determines the type of triangle (equilateral, isosceles, or scalene) given the lengths of its sides.

```bash
./triangle_type.out 3 3 3
Equilateral triangle
```
7. Write a C++ program (prime_check.cpp|prime_check.out) that checks if a number is prime using a function.

```bash
./prime_check.out 17
17 is a prime number
```
8. Write a C++ program (fibonacci.cpp|fibonacci.out) that generates the Fibonacci sequence up to a given number of terms using a recursive function.

```bash
./fibonacci.out 10
Fibonacci sequence: 0 1 1 2 3 5 8 13 21 34
```