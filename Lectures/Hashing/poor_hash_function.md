# Example of a Poor Hash Function Favoring Certain Table Slots

In this example, we'll illustrate how a poorly chosen hash function can lead to many keys landing in the same buckets. A common pitfall is using a table size that is a power of 2 and relying solely on the low-order bits of the key.

---

## What Happens with Low-Order Bit Hashing

When the table size is a power of 2, e.g., 16, using a hash function like:

```cpp
int poorHash(int key, int tableSize) {
    return key & (tableSize - 1);
}
```

### Explanation:

- The expression key & (tableSize - 1) effectively computes key mod tableSize by only using the lower-order bits of the key.
- If many keys have the same low-order bits, they will all hash to the same bucket(s), leading to clustering.

### Code Example:

Below is a simple C++ program demonstrating this effect:

```cpp
#include <iostream>
using namespace std;

int poorHash(int key, int tableSize) {
    // Using bitwise AND when tableSize is a power of 2 uses only low-order bits.
    return key & (tableSize - 1);
}

int main() {
    int tableSize = 16;  // Table size is a power of 2 (poor choice in this context)
    // A set of keys with patterns that share similar low-order bits
    int keys[] = {18, 34, 50, 66, 82};

    cout << "Using table size = " << tableSize << " (power of 2):" << endl;
    for (int key : keys) {
        cout << "Key " << key << " -> Bucket " << poorHash(key, tableSize) << endl;
    }
    return 0;
}
```

### Expected Output

For keys that are spaced by 16 (or share similar low-order bits), the output might look like:

```
Using table size = 16 (power of 2):
Key 18 -> Bucket 2
Key 34 -> Bucket 2
Key 50 -> Bucket 2
Key 66 -> Bucket 2
Key 82 -> Bucket 2
```

### Observation:

- All keys hash to bucket 2 because the poor hash function only considers the low-order bits.
- This leads to severe clustering, making the hash table inefficient for search and insertion.

## Key Points

- Poor Table Size & Low-Order Bit Usage:
Using a table size that is a power of 2 with a hash function based on bitwise AND (&) can result in many keys being mapped to the same bucket if they share similar low-order bits.
- Better Approaches:
  - Use a prime number for the table size.
  - Design hash functions that mix both high- and low-order bits (e.g., the multiplication method).


# Example of a Poor Hash Function Using Modulo Arithmetic

In this example, we illustrate how a poorly chosen table size, combined with a simple modulo hash function, can lead to severe clustering. Unlike using bitwise AND, this example uses the modulo operator directly.

---

## Code Example

```cpp
#include <iostream>
using namespace std;

// A simple poor hash function using modulo arithmetic.
int poorModuloHash(int key, int tableSize) {
    // This function returns the remainder when key is divided by tableSize.
    return key % tableSize;
}

int main() {
    // A poor choice: table size is 10, a round number that can lead to clustering.
    int tableSize = 10;
    // Keys chosen such that they share a common factor with 10
    int keys[] = {5, 15, 25, 35, 45, 55, 65, 75};

    cout << "Using table size = " << tableSize << " with modulo hash:" << endl;
    for (int key : keys) {
        cout << "Key " << key << " -> Bucket " << poorModuloHash(key, tableSize) << endl;
    }
    return 0;
}
```

### Expected Output

For the given keys:

```
Using table size = 10 with modulo hash:
Key 5 -> Bucket 5
Key 15 -> Bucket 5
Key 25 -> Bucket 5
Key 35 -> Bucket 5
Key 45 -> Bucket 5
Key 55 -> Bucket 5
Key 65 -> Bucket 5
Key 75 -> Bucket 5
```

 ### Observation:

- All keys are multiples of 5, so when taken modulo 10, they all produce a remainder of 5.
- This results in all keys landing in the same bucket, demonstrating a poor distribution due to an inappropriate choice of table size.

## Key Points

- Poor Table Size:
  - Using a table size like 10 (a round number) can cause clustering when keys have common factors.
- Modulo Operation:
  - The modulo operator % calculates the remainder, and if many keys share similar low-order values relative to the table size, they will hash to the same bucket.
- Better Practices:
  - Choose a prime number for the table size to reduce the chance of keys clustering.
  - Design hash functions that mix input bits well to achieve a more uniform distribution.


