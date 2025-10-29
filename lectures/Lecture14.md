---
delivery date:
  - 2024-09-03
  - "[[2025-09-09]]"
---
# Quick Recap
1. Classes
---
#### Today
1. **Numeric representations (Decimal, Binary, Hexadecimal)**
2. Data sizes
3. Integer representation (unsigned vs 2"s complement)
4. Integer arithmetic

---
#### Numeric representations

| Representation  | Base | Symbols Used                          | Example Conversion |
| --------------- | ---- | ------------------------------------- | ------------------ |
| **Decimal**     | 10   | 0-9                                   | 255 (Decimal)      |
| **Binary**      | 2    | 0, 1                                  | 11111111 (Binary)  |
| **Hexadecimal** | 16   | 0-9, A-F (where A=10, B=11, ... F=15) | FF (Hexadecimal)   |

---
#### Conversion: Decimal to binary
To convert a decimal number to binary:

1. Divide the decimal number by 2.
2. Write down the remainder.
3. Use the quotient for the next division by 2.
4. Repeat until the quotient is 0.
5. The binary equivalent is the remainders read in reverse order.
---
#### Conversion: Decimal to binary(2)
**Example: Decimal 13 to Binary**

| Step | Operation  | Quotient | Remainder |
| ---- | ---------- | -------- | --------- |
| 1    | 13 ÷ 2 = 6 | 6        | 1         |
| 2    | 6 ÷ 2 = 3  | 3        | 0         |
| 3    | 3 ÷ 2 = 1  | 1        | 1         |
| 4    | 1 ÷ 2 = 0  | 0        | 1         |

So, **13 in decimal is `1101` in binary**.

---
#### Conversion: binary to decimal
To convert a binary number to decimal:

1. Write down the binary number.
2. Assign powers of 2 to each bit, starting with 0 on the right.
3. Multiply each bit by 2 raised to the power of its position.
4. Sum all the results to get the decimal equivalent.
---
#### Conversion: binary to decimal(2)

Example: Binary `1011` to Decimal

|                  |       |       |         |     |     |
| ---------------- | ----- | ----- | ------- | --- | --- |
| **Binary Digit** | 1     | 0     | 1       | 1   |     |
| **Bit Position** | 3     | 2     | 1       | 0   |     |
| **Power of 2**   | 8     | 4     | 2       | 1   |     |
| **Calculation**  | 1*8=8 | 0*4=0 | 1*2 = 2 | 0*1 | =11 |

So, **`1011` in binary is `11` in decimal**.


---
#### Conversion: Binary to Hexadecimal
1. **Group the Binary Number:**
   - Starting from the rightmost bit (least significant bit) of the binary number, group the binary digits into sets of four. If the leftmost group has fewer than four digits, pad it with leading zeros.
2. **Convert Each Group to Hexadecimal:**
   - Convert each group of four binary digits into its corresponding hexadecimal
---

#### Example
1. **Group the binary number:**
   - `101101110011` becomes `1011 0111 0011`.

2. **Convert each group to hexadecimal:**
   - `1011` → `B`
   - `0111` → `7`
   - `0011` → `3`

 `101101110011` => `B73` 

---

#### Bash : 
```bash
toBinary(){
    local n bits remainder
    # calculate quotient by bitwise right shift
    # n >> k => n/2^k
    for (( n=$1 ; n>0 ; n >>= 1 ));
	    do
		    # calculate remainder via bitwise and
		    remainder="$(( n&1 ))"  
		    bits="${remainder}${bits}";
		done
    printf "%s\n" "$bits"
}

toHex(){
    printf "%x\n" $1
}
```
---

#### Today: Numeric representations 
1. Numeric representations (Decimal, Binary, hexadecimal)
2. **Data sizes**
3. Integer representation (unsigned vs 2"s complement)
4. Integer arithmetic
---

#### Sizes of C Numeric Data Types (in bytes)

| Data Type | 32-bit Machine | 64-bit Machine |
| --------- | -------------- | -------------- |
| `char`    | 1              | 1              |
| `short`   | 2              | 2              |
| `int`     | 4              | 4              |
| `long`    | 4              | 8              |
| `float`   | 4              | 4              |
| `double`  | 8              | 8              |
| `pointer` | 4              | 8              |

---
#### Signed vs Unsigned
By default all variables are signed i.e. they can be used to store both positive as well as negative values.
In order to store only positive values, we can explicitly use unsigned keyword.

```cpp
# stores positve as well as negative values
long i;
float j;
// will only store positive values
unsigned long x; 
unsigned float y;
```
---
#### Byte ordering

|                   | Little-Endian                                | Big-Endian                                  |
| ----------------- | -------------------------------------------- | ------------------------------------------- |
| **Definition**    | Stores the **least significant byte** first. | Stores the **most significant byte** first. |
| **Memory Layout** | `0x12345`, it is stored as `39 30 00 00`.    | `0x12345` is stored as `00 00 30 39`.       |
```bash
# bash command to check byte ordering
lscpu | grep Endian

```
---
#### Program to find out byte ordering
```c
#include <stdio.h>
#include <stdlib.h>
typedef unsigned char *byte_pointer;
void show_bytes(byte_pointer start, int len) {
	int i;
	for (i = 0; i < len; i++){
		printf(" %.2x", start[i]);
	}
	printf("\n");
}

void show_int(int x) {
	show_bytes((byte_pointer) &x, sizeof(int));
}

int main(int argc, char const *argv[])
{
int x = atoi(argv[1]);
show_int(x);
return 0;
}
```


---
#### Today: Numeric representations 
1. Numeric representations (Decimal, Binary, hexadecimal)
2. Data sizes
3. **Integer representation (unsigned vs 2"s complement)**
4. Integer arithmetic
---
#### Unsigned vs. 2's Complement Notation

| Feature              | Unsigned                               | 2's Complement                                   |
| -------------------- | -------------------------------------- | ------------------------------------------------ |
| **Range of Values**  | Represents only non-negative integers. | Represents both positive and negative integers.  |
| **Bits usage**       | All bits makes positive contribution   | Most significant bit makes negative contribution |
| **min-max (n bits)** | `0` to $2^n$ - 1                       | -$2^{(n-1)}$ to $2^{(n-1)} - 1$                  |
| **Example (4 bits)** | `0000` = 0 to `1111` = 15              | `1000` = -8 to `0111` = 7                        |
|                      |                                        |                                                  |

---
#### Example
Unsigned representation

| **Binary Digit** | 1     | 0     | 1       | 1   |     |
| ---------------- | ----- | ----- | ------- | --- | --- |
| **Bit Position** | 3     | 2     | 1       | 0   |     |
| **Power of 2**   | 8     | 4     | 2       | 1   |     |
| **Calculation**  | 1*8=8 | 0*4=0 | 1*2 = 2 | 0*1 | =11 |

---
#### Example
2"s complement representation

| **Binary Digit** | 1       | 0     | 1       | 1   |     |
| ---------------- | ------- | ----- | ------- | --- | --- |
| **Bit Position** | 3       | 2     | 1       | 0   |     |
| **Power of 2**   | -8      | 4     | 2       | 1   |     |
| **Calculation**  | 1*-8=-8 | 0*4=0 | 1*2 = 2 | 1*1 | =-5 |

---
![image](https://github.com/Ankush-Chander/IT603-notes/blob/main/lectures/images/number_representations.png?raw=true)
Image credits: [Neso Academy - Youtube](https://www.youtube.com/watch?v=-CEJXDeDsAQ&list=PLBlnK6fEyqRgLLlzdgiTUKULKJPYc0A4q&index=64)

---
#### Steps to Calculate Two's Complement in ALU:
1. **Bitwise Inversion (One's Complement):**
    - The first step in computing the two's complement is to invert all the bits of the binary number (i.e., change 0s to 1s and 1s to 0s). (using not gate)
2. **Adding 1 to the Inverted Number:**
    - After inverting the bits, the next step is to add `1` to the least significant bit (LSB) of the inverted number to obtain the two's complement. (using adder circuit)
---
#### Today: Numeric representations 
1. Numeric representations (Decimal, Binary, hexadecimal)
2. Data sizes
3. Integer representation (unsigned vs 2"s complement)
4. **Integer arithmetic**
---
#### Unsigned addition(1)
1. **Align the Binary Numbers**: Ensure both numbers have the same number of bits. 
2. **Perform Binary Addition**: Add the bits starting from the rightmost bit, carrying over to the next bit when the sum exceeds 1. 
3. **Check for Carry-Out**: After the final bit is added, check for a carry-out from the most significant bit (MSB). Carry from the MSB is discarded.
---
#### Unsigned addition(2)
$x+^{u}_{w} y = (x + y)\text{ }mod\text{ }2^{w}$

| x           | y           | x+y           | (x+y) mod 16 |                   |
| ----------- | ----------- | ------------- | ------------ | ----------------- |
| 8<br>[1000] | 7<br>[0111] | 15<br>[1111]  | 15<br>[1111] | Normal            |
| 8<br>[1000] | 9<br>[1001] | 17<br>[10001] | 1<br>[0001]  | Positive overflow |

---
#### 2's Complement Addition(1) 
1. **Align the Binary Numbers**: Ensure both numbers have the same number of bits. 
2. **Perform Binary Addition**: Add the bits starting from the rightmost bit, just like unsigned binary addition.
3. **Check for Carry**: Carry from the MSB is discarded in 2's complement addition.
---

| x            | y            | x+y            | $x+^{t}_{4}y$ |                   |
| ------------ | ------------ | -------------- | ------------- | ----------------- |
| -8<br>[1000] | -5<br>[1011] | -13<br>[10011] | 3<br>[0011]   | Negative overflow |
| -8<br>[1000] | -8<br>[1000] | -16<br>[10000] | 0<br>[0000]   | Negative overflow |
| −8<br>[1000] | 5<br>[0101]  | −3<br>[11101]  | −3<br>[1101]  | Normal            |
| 2<br>[0010]  | 5<br>[0101]  | 7<br>[00111]   | 7<br>[0111]   | Normal            |
| 5<br>[0101]  | 5<br>[0101]  | 10<br>[01010]  | −6<br>[1010]  | Positive overflow |

---
#### Unsigned multiplication

$$
x*^{u}_{w} y = (x * y)\text{ }mod\text{ }2^{w}
$$
$$\text{where w=4 bits,  min=0,  max=15}$$

| x           | y           | x*y           | $x*^{u}_{w} y$           |          |
| ----------- | ----------- | ------------- | ------------------------ | -------- |
| 5<br>[0101] | 4<br>[0100] | 20<br>[10100] | 20 mod 16=4<br>[0100]    | Overflow |
| 5<br>[0101] | 3<br>[0011] | 15<br>[01111] | 15 mod 16 = 15<br>[1111] | Normal   |
|             |             |               |                          |          |

---
#### 2"s complement multiplication
Operands: w bits  
True product: 2*w bits  
Discard w most significant bits.   

---
#### References
1. CSAPP 2.2, 2.3
2. [Computer Organization & Architecture (COA) - YouTube - Number system videos](https://www.youtube.com/playlist?list=PLBlnK6fEyqRgLLlzdgiTUKULKJPYc0A4q)
---


