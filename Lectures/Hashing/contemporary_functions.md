# C++ Hash Function Examples

This document provides code examples for three popular hash functions in C++: **FNV-1a**, **MurmurHash3**, and **CityHash**. These examples demonstrate simple implementations or usage examples that you can discuss or build upon.

---

## 1. FNV-1a Hash

The FNV-1a hash is a non-cryptographic hash function that is simple and fast, making it a popular choice for hash table implementations.

```cpp
#include <cstdint>
#include <string>
#include <iostream>

uint32_t fnv1a_hash(const std::string &s) {
    const uint32_t FNV_offset_basis = 2166136261u;
    const uint32_t FNV_prime = 16777619u;
    uint32_t hash = FNV_offset_basis;
    for (char c : s) {
        hash ^= static_cast<uint32_t>(c);
        hash *= FNV_prime;
    }
    return hash;
}

int main() {
    std::string key = "example";
    std::cout << "FNV-1a hash of \"" << key << "\": " << fnv1a_hash(key) << std::endl;
    return 0;
}
```

## 2. MurmurHash3 (32-bit version)

MurmurHash3 is a non-cryptographic hash function known for its good distribution and speed. Below is a simplified version of the 32-bit variant.

```cpp
#include <cstdint>
#include <cstring>
#include <iostream>

uint32_t murmurhash3(const void* key, int len, uint32_t seed = 0) {
    const uint8_t * data = (const uint8_t*) key;
    const int nblocks = len / 4;
    uint32_t h1 = seed;
    const uint32_t c1 = 0xcc9e2d51;
    const uint32_t c2 = 0x1b873593;

    // Body: process 4-byte blocks
    const uint32_t * blocks = (const uint32_t*) (data);
    for (int i = 0; i < nblocks; i++) {
        uint32_t k1 = blocks[i];
        k1 *= c1;
        k1 = (k1 << 15) | (k1 >> (32 - 15));
        k1 *= c2;

        h1 ^= k1;
        h1 = (h1 << 13) | (h1 >> (32 - 13));
        h1 = h1 * 5 + 0xe6546b64;
    }

    // Tail: process remaining bytes
    const uint8_t * tail = (const uint8_t*) (data + nblocks * 4);
    uint32_t k1 = 0;
    switch (len & 3) {
        case 3: k1 ^= tail[2] << 16;
        case 2: k1 ^= tail[1] << 8;
        case 1: k1 ^= tail[0];
                k1 *= c1;
                k1 = (k1 << 15) | (k1 >> (32 - 15));
                k1 *= c2;
                h1 ^= k1;
    };

    // Finalization
    h1 ^= len;
    h1 ^= h1 >> 16;
    h1 *= 0x85ebca6b;
    h1 ^= h1 >> 13;
    h1 *= 0xc2b2ae35;
    h1 ^= h1 >> 16;

    return h1;
}

int main() {
    std::string key = "example";
    uint32_t hash = murmurhash3(key.data(), key.size(), 42);
    std::cout << "MurmurHash3 of \"" << key << "\": " << hash << std::endl;
    return 0;
}
```

## 3. CityHash

CityHash is a family of hash functions developed by Google that is optimized for speed on short strings. Since CityHash is provided as a library, you typically include its header and use its functions directly.

**Note:**

- You need to download and build CityHash from its repository (CityHash on GitHub).

```
#include "city.h"  // Ensure CityHash is installed and this header is in your include path.
#include <iostream>
#include <string>

int main() {
    std::string key = "example";
    uint64_t hash = CityHash64(key.c_str(), key.size());
    std::cout << "CityHash64 of \"" << key << "\": " << hash << std::endl;
    return 0;
}
```

## Summary

- FNV-1a Hash:
  - Simple, fast, and good for many non-cryptographic applications.
- MurmurHash3:
  - Provides excellent distribution and performance; widely used in hash tables.
- CityHash:
  - Optimized by Google for speed on short strings; useful in performance-critical applications.

These examples demonstrate different approaches to hashing in C++. Depending on your application requirements, you may choose one based on factors such as speed, distribution, and ease of implementation.
