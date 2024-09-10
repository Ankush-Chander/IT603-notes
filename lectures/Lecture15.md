---
delivery date: 2024-09-04
---
#### Quick recap
1. Numeric representations (Decimal, Binary, Hexadecimal)
2. Data sizes
3. Integer representation (unsigned vs 2"s complement)
4. Integer arithmetic
---
#### Agenda
1. **Fractional binary numbers**
2. IEEE floating point representation
3. Normalization
4. Biased representation

---
#### Fractional binary number representation

$$b = \sum_{i=-n}^{m}2^i*b^i$$

| **Binary Digit** | 1         | 0         | .   | 1       | 1       |        |
| ---------------- | --------- | --------- | --- | ------- | ------- | ------ |
| **Bit Position** | 2         | 1         | .   | -1      | -2      |        |
| **Power of 2**   | 1         | 0         |     | 1/2     | 1/4     |        |
| **Calculation**  | 1*$2^1$=2 | 0*$2^0$=0 |     | 1*(1/2) | 1*(1/4) | =2 3/4 |

---
#### Decimal to binary  conversion(1)
Convert 12.375 to binary  
**Integer part**: Convert 12 to binary.
- $12÷2=6 \text{ remainder 0}$
- $6÷2=3 \text{ remainder 0}$
- $3÷2=1 \text{ remainder 1}$
- $1÷2=0 \text{ remainder 1}$   
 So, 12 in binary is `1100`.

---
#### Decimal to binary  conversion(2)

**Fractional part**: Convert 0.375 to binary.
- $0.375×2=0.75 \text{(0 is the integer part)}$
- $0.75×2=1.50 \text{(1 is the integer part)}$
- $0.50×2=1.0 \text{(1 is the integer part)}$  
`0.375` = `0.011`.  
$12.375_{10}$ => $1100.011_{2}$

---
#### Fixed point notation
Fixed-point notation is a method of representing real numbers in a computer system where **a specific number of digits (or bits) are allocated for the integer part and a specific number for the fractional part**.

Drawbacks:  
1. Limited in range.   
	For example 8 bit(with 4 bit integer and 4 bit fraction) can represent numbers between `-8` to `7.9375` with a precision of `1/16` or `0.0625`.

---
#### Floating point notation
The IEEE ﬂoating-point standard represents a number in a form $$V = (−1)^s × M × 2^E$$
- The **sign** s determines whether the number is negative (s = 1) or positive (s = 0), where the interpretation of the sign bit for numeric value 0 is handled as a special case.
- The **signiﬁcand** M is a fractional binary number that ranges either between 1 and 2 - $\alpha$ or between 0 and 1 
- The **exponent** E weights the value by a (possibly negative) power of 2.
---

|               | Fixed point notation         | Floating point notation    |
| ------------- | ---------------------------- | -------------------------- |
| Notation      | $b = \sum_{i=-n}^{m}2^i*b^i$ | $x × 2^y$                  |
| $$5*2^{100}$$ | 101 followed by 100 zeros.   | stores as  101(5)  and 100 |
|               |                              |                            |

---
#### Standard ﬂoating-point formats

|                      | Sign | Exponent | Mantissa |
| -------------------- | ---- | -------- | -------- |
| Single Precision(32) | 1    | 8        | 23       |
| Double precision(64) | 1    | 11       | 52       |
|                      |      |          |          |
   
---
#### Normalisation

101.11 = 10111 * $2^{-2}$  
101.11 = 101110 * $2^{-3}$  
101.11 = 1011100 * $2^{-4}$  
101.11 = 10111000 * $2^{-5}$  

Same number can be represented by choosing appropriate value of exponent and significand. (Not desirable).  
Hence normalization.

---
##### Explicit normalization vs Implicit normalization
|                | Explicit Normalization                                  | Implicit Normalization                                                  |
| -------------- | ------------------------------------------------------- | ----------------------------------------------------------------------- |
| **Definition** | Move that radix point to LHS of the most significant 1. | Move that radix point to RHS of the most significant 1.   (not stored). |
| **Notation**   | $(-1) * 0.M * 2^{E-bias}$                               | $(-1) * 1.M * 2^{E-bias}$                                               |
| **Example**    | $101.11 = 0.10111 * 2^{3}$                              | $101.11 = 1.0111 * 2^{2}$                                               |

---
#### Biased representation of exponent
Sign of the number is stored in sign bit.
Mantissa is always positive and hence represented as unsigned binary.  
Exponent can be positive as well as negative.
How to store exponent?   
2"s complement???

---


|     | 2"s complement | Biased notation<br>$E - (2^{w-1}-1)$ |     |
| --- | -------------- | ------------------------------------ | --- |
| 000 | 0              | -3                                   |     |
| 001 | 1              | -2                                   |     |
| 010 | 2              | -1                                   |     |
| 011 | 3              | 0                                    |     |
| 100 | -4             | 1                                    |     |
| 101 | -3             | 2                                    |     |
| 110 | -2             | 3                                    |     |
| 111 | -1             | 4                                    |     |

---
#### Why bias
- When exponents are stored using a biased representation, the floating-point numbers can be compared as if they were unsigned integers. This simplifies hardware design because it allows for straightforward magnitude comparisons.
---
#### Decimal to floating point conversion 
Let’s say you want to represent the number **9.75**:

1. Convert 9.75 to binary: $1001.11_2$​ (which is $1.00111×2^3$).
2. The sign bit S=0 (since 9.75 is positive).
3. The exponent is 3. 
4. For single-precision, the bias is 127($2^{8-1}-1$), so the stored exponent is 3+127=130 (or $10000010_2$).
5. The mantissa is the fractional part after the leading 1, i.e., $00111000000000000000000_2$.
---
Thus, the 32-bit IEEE 754 representation of 9.75 is:

| S   | E (exponent) | M (mantissa)            |
| --- | ------------ | ----------------------- |
| 0   | 10000010     | 00111000000000000000000 |

**Memory layout**  

| 01000001 | 00011100 | 00000000 | 00000000 |
| -------- | -------- | -------- | -------- |
| 41       | 1c       | 00       | 00       |

---
#### Implications
1. **What happens when we add signed and unsigned numbers?**  
	When you mix signed and unsigned numbers in an expression, **C/C++ promotes** the signed number to an unsigned type before performing the operation.
	```cpp
	int a = -5; // Signed integer
	unsigned int b = 3; // Unsigned integer
	// This is how `-5` is stored as an unsigned integer
	// -5 + 2**32 = 4294967291 
	// 4294967291 (unsigned) + 3 = 4294967294 (unsigned)	
	```
Avoid using unsigned numbers unless absolutely required.

---
**What happens during casting?**  

*Expansion*
- `float` to `double`: Mantissa is expanded (extra precision), no truncation.
- `int` to `long`: Bit width is expanded (zero or sign extension), no truncation.
*Truncation*
- `double` to `float`: Mantissa is truncated, possible loss of precision.
- `long` to `int`: Higher bits are discarded, possible loss of value if the number exceeds the `int` range. 
---
#### References
1. CSAPP 2.2, 2.3
2. [Computer Organization & Architecture (COA) - YouTube - Number system videos](https://www.youtube.com/playlist?list=PLBlnK6fEyqRgLLlzdgiTUKULKJPYc0A4q)

---
