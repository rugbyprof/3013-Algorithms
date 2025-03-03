# C++ Bitwise Operations Tutorial

Bitwise operations allow you to manipulate individual bits within an integer. They are especially useful in systems programming, cryptography, and performance-critical code. This tutorial covers the basics of bitwise operators in C++ with input/output examples.

---

## 1. Bitwise AND (`&`)

**Operation:**  
Performs a logical AND on each pair of bits. Only if both bits are 1 will the resulting bit be 1.

**Example:**

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 12;  // Binary: 1100
    int b = 10;  // Binary: 1010

    int result = a & b; // Binary: 1000, which is 8 in decimal

    cout << "12 & 10 = " << result << endl; // Output: 8
    return 0;
}
```

#### Explanation:

- 1100 (12)
- 1010 (10)

- 1000 (8)

## 2. Bitwise OR (|)

Operation:
Performs a logical OR on each pair of bits. If at least one bit is 1, the resulting bit is 1.

#### Example:

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 12;  // Binary: 1100
    int b = 10;  // Binary: 1010

    int result = a | b; // Binary: 1110, which is 14 in decimal

    cout << "12 | 10 = " << result << endl; // Output: 14
    return 0;
}
```

#### Explanation:

- 1100 (12)
- 1010 (10)

- 1110 (14)

## 3. Bitwise XOR (^)

Operation:
Performs a logical XOR on each pair of bits. The result is 1 if the bits are different, and 0 if they are the same.

Example:

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 12;  // Binary: 1100
    int b = 10;  // Binary: 1010

    int result = a ^ b; // Binary: 0110, which is 6 in decimal

    cout << "12 ^ 10 = " << result << endl; // Output: 6
    return 0;
}
```

#### Explanation:

- 1100 (12)
- 1010 (10)

- 0110 (6)

## 4. Bitwise NOT (~)

**Operation:**

- Inverts every bit of the operand (0 becomes 1, and 1 becomes 0).

#### Example:

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 12;  // Binary: 0000 1100 (assuming 8-bit representation for illustration)
    int result = ~a;  // Inverts all bits

    // On an 8-bit system, ~12 becomes 1111 0011, which is -13 in two's complement.
    cout << "~12 = " << result << endl;
    return 0;
}
```

#### Note:

- The actual output depends on the size of the integer (typically 32 or 64 bits) and the system’s representation of negative numbers (two’s complement).

## 5. Left Shift (<<)

Operation:
Shifts the bits of the number to the left by a specified number of positions. Zeros are shifted in on the right.

**Example:**

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 3;  // Binary: 0011
    int result = a << 2; // Shifts bits left by 2 positions: 1100, which is 12 in decimal

    cout << "3 << 2 = " << result << endl; // Output: 12
    return 0;
}
```

#### Explanation:

- 0011 (3) shifted left by 2 becomes 1100 (12).

## 6. Right Shift (>>)

Operation:
Shifts the bits of the number to the right by a specified number of positions. For unsigned integers, zeros are shifted in on the left; for signed integers, the behavior may depend on the compiler (arithmetic vs. logical shift).

#### Example:

```cpp
#include <iostream>
using namespace std;

int main() {
    unsigned int a = 12;  // Binary: 1100
    unsigned int result = a >> 2; // Shifts bits right by 2 positions: 0011, which is 3 in decimal

    cout << "12 >> 2 = " << result << endl; // Output: 3
    return 0;
}
```

Explanation:

- 1100 (12) shifted right by 2 becomes 0011 (3).

### Summary of Operations

- AND (&): Keeps bits that are 1 in both numbers.
- OR (|): Sets bits that are 1 in either number.
- XOR (^): Sets bits that are different between numbers.
- NOT (~): Inverts all bits.
- Left Shift (<<): Multiplies by powers of 2; shifts bits to the left.
- Right Shift (>>): Divides by powers of 2; shifts bits to the right.

### Practice Exercise

1. Write a program that:

- Reads an integer from the user.
- Applies a left shift by 3 and then a bitwise XOR with a fixed number (e.g., 0x55).
- Prints the original, shifted, and final result in both decimal and binary.

2. Experiment with different shift values and observe the effect on the binary output.
