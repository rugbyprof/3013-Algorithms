## Hashing - Not the cryptographic kind

### Avalanche

A hash function is said to achieve `avalanche` if the resulting hash value is wildly different if even a single bit is different in the key. This effect aids distribution because similar keys will not have similar hash values. A hash function that distributes the hash values in a uniform manner will minimize collisions and fill the array more evenly. Avalanche is a concept derived from cryptographic hashing, and it offers a way to ensure that a hash function is good when used for table lookup.

### Additive Hash

```cpp
unsigned add_hash(void *key, int len)
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
unsigned xor_hash(void *key, int len)
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
