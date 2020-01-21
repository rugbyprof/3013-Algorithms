## Hashing - Not the cryptographic kind

### Capacity
The **`capacity`** is the number of buckets in the hash table, and the initial capacity is simply the capacity at the time the hash table is created. 

### Load Factor

- The load factor `α` of a hash table with *`n`* elements is given by the following formula:
    - *`α` = `n` / array_size*
- Thus, *`0 < α < 1`* for linear probing. (`α` can be greater than 1 for other collision resolution methods)
- For linear probing, as *`α`* approaches 1, the number of collisions increases.

### Avalanche

A hash function is said to achieve `avalanche` if the resulting hash value is wildly different if even a single bit is different in the key. (Remember the example of the one way hash we did in class using **`MD5`**. By changing a letter **`L`** to **`l`**, the entire hash changed.) This effect aids distribution because similar keys will not have similar hash values. A hash function that distributes the hash values in a uniform manner will minimize collisions and fill the array more evenly. `Avalanche` is a concept derived from `cryptographic hashing`, and it offers a way to ensure that a hash function is good when used for table lookup.

## Open Addressing

### Linear Probing

Linear probing looks at contiguous memory locations, until one is open.

**Example:**
- Want to insert key (element) j 
- Compute h(j) = k
- If `H[k]` is empty store in `H[k]`, otherwise try `H[k+1]`, `H[k+2]`, etc.

**Advantages**:
 - Easy to implement

**DisAdvantages**:
- Can cause clustering


### Quadratic Probing

Quadratic probing operates by taking the original hash value and adding successive values of an arbitrary quadratic polynomial to the starting value. 
>**Example:** If ***h(k,i) = h(k) + i + i<sup>2</sup>(mod m)*** , then the probe sequence will be ***h(k),h(k) + 2,h(k) + 6,...***

**Advantages**:
 - Reduced primary clustering
 
**DisAdvantages**:
 - Can cause secondary clustering


## Chaining

### Additive Hash

```cpp
unsigned addHash(void *key, int len)
{
    unsigned char *p = key;
    unsigned h = 0;
    int i;

    for (i = 0; i < len; i++)
    {
        h += p[i];
    }

    return h;
}
```

- Generally, any hash algorithm that relies primarily on a commutitive operation will have an exceptionally bad distribution. 
- This hash fails to treat permutations differently, so “abc”, “cba”, and “cab” will all result in the same hash value.
- However, it is easy to implement and may work in a pinch.

### XOR Hash

```cpp
unsigned xorHash(void *key, int len)
{
    unsigned char *p = key;
    unsigned h = 0;
    int i;

    for (i = 0; i < len; i++)
    {
        h ^= p[i];
    }

    return h;
}
```

- The internal state, the variable h, is not mixed nearly enough to come close to achieving `avalanche`.
- A single XOR effective at permuting the internal state, so the resulting distribution, while better than the `additive` and `multiplicative` hashes, is still not very good.

### Rotating Hash

```
unsigned rotHash(void *key, int len)
{
    unsigned char *p = key;
    unsigned h = 0;
    int i;

    for (i = 0; i < len; i++)
    {
        h = (h << 4) ^ (h >> 28) ^ p[i];
    }

    return h;
}
```

- The rotating hash is identical to the XOR hash except instead of simply folding each byte of the input into the internal state, it also performs a fold of the internal state before combining it with the each byte of the input. 
- This extra mixing step is enough to give the rotating hash a much better distribution. 

### Bernstein Hash

```cpp
unsigned bernsteinHash(void *key, int len)
{
    unsigned char *p = key;
    unsigned h = 0;
    int i;

    for (i = 0; i < len; i++)
    {
        h = 33 * h + p[i];
    }

    return h;
}
```

- Bernstein's hash should be used with caution. It performs very well in practice, for no apparently known reasons (much like how the constant 33 does better than more logical constants for no apparent reason), but in theory it is not up to snuff.
- Always test this function with sample data for every application to ensure that it does not encounter a degenerate case and cause excessive collisions.

### Modified Bernstein

```cpp
unsigned modBernsteinHash(void *key, int len)
{
    unsigned char *p = key;
    unsigned h = 0;
    int i;

    for (i = 0; i < len; i++)
    {
        h = 33 * h ^ p[i];
    }

    return h;
}
```

- A minor update to Bernstein's hash replaces addition with XOR for the combining step. 
- The updated algorithm typically results in a better distribution.

### Shift-Add-XOR hash

```cpp
unsigned shiftAddXor_hash(void *key, int len)
{
    unsigned char *p = key;
    unsigned h = 0;
    int i;

    for (i = 0; i < len; i++)
    {
        h ^= (h << 5) + (h >> 2) + p[i];
    }

    return h;
}
```

- The shift-add-XOR hash was designed as a string hashing function, but because it is so effective, it works for any data as well with similar efficiency. 
- The algorithm is surprisingly similar to the rotating hash except a different choice of constants for the rotation is used, and addition is a preferred operation for mixing.

### FNV hash

```cpp
unsigned fnvHash(void *key, int len)
{
    unsigned char *p = key;
    unsigned h = 2166136261;
    int i;

    for (i = 0; i < len; i++)
    {
        h = (h * 16777619) ^ p[i];
    }

    return h;
}
```

- The FNV hash, short for Fowler/Noll/Vo in honor of the creators, is a very powerful algorithm that, not surprisingly, follows the same lines as Bernstein's modified hash with carefully chosen constants. 
- This algorithm has been used in many applications with wonderful results, and for its simplicity, the FNV hash should be one of the first hashes tried in an application. 
- https://en.wikipedia.org/wiki/Fowler%E2%80%93Noll%E2%80%93Vo_hash_function




#### Why Prime Array Size?
Consider the set of keys K={0,1,...,100} and a hash table where the number of buckets is m=12. Since 3 is a factor of 12, the keys that are multiples of 3 will be hashed to buckets that are multiples of 3:

Keys {0,12,24,36,...} will be hashed to bucket 0.
Keys {3,15,27,39,...} will be hashed to bucket 3.
Keys {6,18,30,42,...} will be hashed to bucket 6.
Keys {9,21,33,45,...} will be hashed to bucket 9.
If K is uniformly distributed (i.e., every key in K is equally likely to occur), then the choice of m is not so critical. But, what happens if K is not uniformly distributed? Imagine that the keys that are most likely to occur are the multiples of 3. In this case, all of the buckets that are not multiples of 3 will be empty with high probability (which is really bad in terms of hash table performance).

This situation is more common that it may seem. Imagine, for instance, that you are keeping track of objects based on where they are stored in memory. If your computer's word size is four bytes, then you will be hashing keys that are multiples of 4. Needless to say that choosing m to be a multiple of 4 would be a terrible choice: you would have 3m/4 buckets completely empty, and all of your keys colliding in the remaining m/4 buckets.

In general:

>Every key in K that shares a common factor with the number of buckets m will be hashed to a bucket that is a multiple of this factor.

Therefore, to minimize collisions, it is important to reduce the number of common factors between m and the elements of K. How can this be achieved? By choosing m to be a number that has very few factors: a prime number.


- Sources:
    - <sub>Eternally Confuzzled: http://www.eternallyconfuzzled.com/tuts/algorithms/jsw_tut_hashing.aspx</sub>
    - <sub>Mario Cervera: https://cs.stackexchange.com/users/57681/mario-cervera</sub>
    - <sub>https://en.wikipedia.org/wiki/Fowler%E2%80%93Noll%E2%80%93Vo_hash_function</sub>
    - <sub>https://www.cs.cmu.edu/~tcortina/15-121sp10/Unit08B.pdf</sub>
