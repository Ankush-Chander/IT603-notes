---
delivery date: 2024-09-11
---
#### Quick recap
1. Binary fraction representation
2. IEEE Floating point representation
3. Normalization
4. Biased exponent representation
---
#### Today
1. Boolean Algebra
2. Bit level operations
---
#### Boolean Algebra
Boolean algebra is a branch of algebra that deals with binary values (0 and 1), typically used in logic circuits, computer science, and digital systems. It involves logical operations on binary variables.

**Boolean Values**
- **0**: Represents `false`
- **1**: Represents `true`
---
#### Basic Boolean Operations

1. **AND (v,  &)**
   - The result is `1` if **both** inputs are `1`, otherwise `0`.
   - **Truth table**:
     | A | B | A & B |
     |---|---|-------|
     | 0 | 0 |   0   |
     | 0 | 1 |   0   |
     | 1 | 0 |   0   |
     | 1 | 1 |   1   |
---

2. **OR (v, |)**
   - The result is `1` if **at least one** input is `1`.
   - **Truth table**:
     | A | B | A \| B |
     |---|---|-------|
     | 0 | 0 |   0   |
     | 0 | 1 |   1   |
     | 1 | 0 |   1   |
     | 1 | 1 |   1   |
---
3. **NOT (¬ or ~)**
   - The result is the **inverse** of the input: `1` becomes `0` and `0` becomes `1`.
   - **Truth table**:
     | A | ¬A |
     |---|----|
     | 0 |  1 |
     | 1 |  0 |
---
2. **XOR (^)**
   - The result is `1` if **only one of the input** is 1 .
   - **Truth table**:
     | A | B | A ^ B |
     |---|---|-------|
     | 0 | 0 |   0   |
     | 0 | 1 |   1   |
     | 1 | 0 |   1   |
     | 1 | 1 |   0   |
---
#### Laws of Boolean Algebra

1. **Identity Law**
   - `A | 0 = A`
   - `A & 1 = A`

2. **Null Law**
   - `A | 1 = 1`
   - `A & 0 = 0`

3. **Idempotent Law**
   - `A | A = A`
   - `A & A = A`
---
4. **Complement Law**
   - `A | ~A = 1`
   - `A & ~A = 0`

5. **Distributive Law**
   - `A & (B | C) = (A & B) | (A & C)`
   - `A | (B & C) = (A | B) & (A | C)`

6. **De Morgan’s Law**
   - `~(A | B) = ~A & ~B`
   - `~(A & B) = ~A | ~B`
---
#### Bit-level Operations in C++

Bit-level operations in C++ allow you to manipulate individual bits within an integer value. These operations are crucial in systems programming, cryptography, and optimizing algorithms.

---
#### Common Bitwise Operators
1. **AND (`&`)**
   - Compares each bit of two numbers. The result is `1` if both corresponding bits are `1`, otherwise `0`.
   - Example:
     ```cpp
     int a = 5;  // 0101 in binary
     int b = 3;  // 0011 in binary
     int result = a & b;  // result is 1 (0001 in binary)
     ```
---
2. **OR (`|`)**
   - Compares each bit of two numbers. The result is `1` if at least one corresponding bit is `1`, otherwise `0`.
   - Example:
     ```cpp
     int a = 5;  // 0101 in binary
     int b = 3;  // 0011 in binary
     int result = a | b;  // result is 7 (0111 in binary)
     ```
---
3. **XOR (`^`)**
   - Compares each bit of two numbers. The result is `1` if the bits are different, otherwise `0`.
   - Example:
     ```cpp
     int a = 5;  // 0101 in binary
     int b = 3;  // 0011 in binary
     int result = a ^ b;  // result is 6 (0110 in binary)
     ```
---

4. **NOT (`~`)**
   - Inverts each bit. `0` becomes `1`, and `1` becomes `0`.
   - Example:
     ```cpp
     int a = 5;  // 0101 in binary
     int result = ~a;  // result is -6 (1111...1010 in two's complement representation)
     ```
---
5. **Left Shift (`<<`)**
   - Shifts bits to the left by a specified number of positions. It multiplies the number by `2^n` where `n` is the number of positions shifted.
   - Example:
     ```cpp
     int a = 5;  // 0101 in binary
     int result = a << 1;  // result is 10 (1010 in binary)
     ```
---
6. **Right Shift (`>>`)**
   - Shifts bits to the right by a specified number of positions. It divides the number by `2^n` where `n` is the number of positions shifted.
   - Example:
     ```cpp
     int a = 5;  // 0101 in binary
     int result = a >> 1;  // result is 2 (0010 in binary)
     ```
---
## Bit Manipulation Techniques

1. **Setting a Bit**
   - To set a specific bit (i.e., change it to `1`), use the OR (`|`) operator with a bitmask.
   - Example:
     ```cpp
     int a = 5;  // 0101 in binary
     int bit_position = 1;  // We want to set the 1st bit (counting from 0)
     int result = a | (1 << bit_position);  // result is 7 (0111 in binary)
     ```
---
2. **Clearing a Bit**
   - To clear a specific bit (i.e., change it to `0`), use the AND (`&`) operator with the negation of a bitmask.
   - Example:
     ```cpp
     int a = 5;  // 0101 in binary
     int bit_position = 2;  // We want to clear the 2nd bit (counting from 0)
     int result = a & ~(1 << bit_position);  // result is 1 (0001 in binary)
     ```
---
3. **Toggling a Bit**
   - To toggle a specific bit (i.e., change `1` to `0` or `0` to `1`), use the XOR (`^`) operator with a bitmask.
   - Example:
     ```cpp
     int a = 5;  // 0101 in binary
     int bit_position = 0;  // We want to toggle the 0th bit
     int result = a ^ (1 << bit_position);  // result is 4 (0100 in binary)
     ```
---
4. **Checking a Bit**
   - To check whether a specific bit is set (`1`), use the AND (`&`) operator with a bitmask.
   - Example:
     ```cpp
     int a = 5;  // 0101 in binary
     int bit_position = 2;  // We want to check the 2nd bit
     bool is_set = a & (1 << bit_position);  // is_set is true (non-zero) if the 2nd bit is 1
     ```
---
#### Examples

**Example 1: Checking if a number is even or odd**
A number is even if its least significant bit is `0`, and odd if it's `1`.
```cpp
int num = 5;
if (num & 1) {
    std::cout << "Odd";
} else {
    std::cout << "Even";
}
```

---
**Example 2: Swapping two numbers without using a temporary variable**

```cpp
int a = 5, b = 3; // 101, 011 
a = a ^ b; // 110, 011
b = a ^ b; // 110, 101
a = a ^ b; // 011, 101
// Now a is 3 and b is 5

```
---
#### References
1. Section 2.1 CSAPP
