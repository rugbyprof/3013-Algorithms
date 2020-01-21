## Hash Functions

- The hash functions are typically designed to return a value in the full unsigned range of an integer.
- For a 32-bit integer, this means that the hash functions will return a value in the range `[0..4,294,967,296)`

#### Simple hash functions

The following functions map a single integer key `(k)` to a small integer bucket value `h(k)`. `m` is the size of the hash table (number of buckets).

***Division method (Cormen)***

- Choose a prime that isn't close to a power of 2.
- `h(k) = k mod m`. Works badly for many types of patterns in the input data.

***Knuth Variant on Division***
- `h(k) = k(k+3) mod m`.
- Supposedly works much better than the raw division method.

***Multiplication Method (Cormen)***
- Choose `m` to be a power of 2. Let `A` be some random-looking real number.
- Knuth suggests `M = 0.5*(sqrt(5) - 1)`. Then do the following:

~~~cpp
     s = k*A
     x = fractional part of s
     h(k) = floor(m*x)
~~~

This seems to be the method that the theoreticians like.

To do this quickly with integer arithmetic, let `w` be the number of bits in a word (e.g. 32) and suppose `m` is `2^p`. Then compute:

~~~cpp
     s = floor(A * 2^w)
     x = k*s
     h(k) = x >> (w-p)      // i.e. right shift x by (w-p) bits
                            // i.e. extract the p most significant
                            // bits from x
~~~

### Hashing sequences of characters

The hash functions in this section take a sequence of integers k=k<sub>1</sub>,...,k<sub>n</sub> and produce a small integer bucket value **h(k)**. **m** is the size of the hash table (number of buckets), which should be a prime number. The sequence of integers might be a list of integers or it might be an array of characters (a string).

The specific tuning of the following algorithms assumes that the integers are all, in fact, character codes.

- In C++, a character is a char variable which is an 8-bit integer.
- ASCII uses only 7 of these 8 bits. Of those 7, the common characters (alphabetic and number) use only the low-order 6 bits. And the first of those 6 bits primarily indicates the case of characters, which is relatively insignificant.
- So the following algorithms concentrate on preserving as much information as possible from the last 5 bits of each number, and make less use of the first 3 bits.

When using the following algorithms, the inputs k<sub>i</sub> must be unsigned integers. Feeding them signed integers may result in odd behavior.

For each of these algorithms, let h be the output value. Set h to 0. Walk down the sequence of integers, adding the integers one by one to h. The algorithms differ in exactly how to combine an integer ki with h. The final return value is h mod m.

#### CRC variant:

Do a 5-bit left circular shift of h. Then XOR in k<sub>i</sub>. Specifically:
~~~cpp
     highorder = h & 0xf8000000    // extract high-order 5 bits from h
                                   // 0xf8000000 is the hexadecimal representation
                                   //   for the 32-bit number with the first five
                                   //   bits = 1 and the other bits = 0
     h = h << 5                    // shift h left by 5 bits
     h = h ^ (highorder >> 27)     // move the highorder 5 bits to the low-order
                                   //   end and XOR into h
     h = h ^ ki                    // XOR h and ki
~~~

#### PJW hash:

Left shift h by 4 bits. Add in k<sub>i</sub>. Move the top 4 bits of h to the bottom. Specifically:
~~~cpp
     // The top 4 bits of h are all zero
     h = (h << 4) + ki               // shift h 4 bits left, add in ki
     g = h & 0xf0000000              // get the top 4 bits of h
     if (g != 0)                     // if the top 4 bits aren't zero,
        h = h ^ (g >> 24)            //   move them to the low end of h
        h = h ^ g
     // The top 4 bits of h are again all zero
~~~

PJW and the CRC variant both work well and there's not much difference between them. We believe that the CRC variant is probably slightly better because
- It uses all 32 bits. PJW uses only 24 bits. This is probably not a major issue since the final value m will be much smaller than either.
- 5 bits is probably a better shift value than 4. Shifts of 3, 4, and 5 bits are all supposed to work OK.
- Combining values with XOR is probably slightly better than adding them. However, again, the difference is slight.

#### BUZ hash:

Set up a function ***R*** that takes 8-bit character values and returns random numbers. This function can be precomputed and stored in an array. Then, to add each character ***k<sub>i</sub>*** to ***h***, do a 1-bit left circular shift of ***h*** and then `XOR` in the random value for ***k<sub>i</sub>***. That is:

~~~cpp
     highorder = h & 0x80000000    // extract high-order bit from h
     h = h << 1                    // shift h left by 1 bit
     h = h ^ (highorder >> 31)     // move them to the low-order end and
                                   // XOR into h
     h = h ^ R[ki]                 // XOR h and the random value for ki
~~~

Rumor has it that you may have to run a second hash function on the output to make it random enough. Experimentally, this function produces good results, but is a bit slower than the CRC variant and PJW.

#### Additive Hash

~~~cpp
//-----------------------------------------------------------------
// Additive Hash
// Adds all of the characters together using ascii values.
// @Param: string val - word to be hashed
// @Returns: unsigned int - hash key value
//----------------------------------------------------------------
unsigned int hash_functions::add_hash (string val)
{
  unsigned int h = 0;

  for (unsigned int  i = 0; i < val.length(); i++ )
    h += val[i];

  return h;
}
~~~

#### XOR hash

~~~cpp
//-----------------------------------------------------------------
// XOR hash
// Repeatedly folds the bytes together using the XOR operation to
// produce a seemingly random hash value.
// @Param: string val - word to be hashed
// @Returns: unsigned int - hash key value
//----------------------------------------------------------------
unsigned int hash_functions::xor_hash (string val)
{
  unsigned h = 0;

  for (unsigned i = 0; i < val.length(); i++ )
    h ^= val[i];

  return h;
}
~~~

#### Rotating hash

~~~cpp
//-----------------------------------------------------------------
// Rotating hash
// The rotating hash is identical to the XOR hash except instead of simply
// folding each byte of the input into the internal state, it also performs
// a fold of the internal state before combining it with the each byte of
// the input
// @Param: string val - word to be hashed
// @Returns: unsigned int - hash key value
//----------------------------------------------------------------
unsigned int hash_functions::rot_hash (string val)
{
  unsigned h = 0;

   for (unsigned i = 0; i < val.length(); i++ )
      h = ( h << 4 ) ^ ( h >> 28 ) ^ val[i];

  return h;
}
~~~

#### Bernstein hash

~~~cpp
//-----------------------------------------------------------------
// Bernstein hash
// Dan Bernstein created this algorithm and posted it in a newsgroup.
// It is known by many as the Chris Torek hash because Chris went a
// long way toward popularizing it. Since then it has been used
// successfully by many, but despite that the algorithm itself is not
// very sound when it comes to avalanche and permutation of the internal
// state. It has proven very good for small character keys, where it
// can outperform algorithms that result in a more random distribution.
// @Param: string val - word to be hashed
// @Returns: unsigned int - hash key value
//----------------------------------------------------------------
unsigned int hash_functions::bernstein_hash (string val)
{
  unsigned h = 0;

	for (unsigned i = 0; i < val.length(); i++ )
      h = 33 * h + val[i];

  return h;
}
~~~

#### Modified Bernstein hash

~~~cpp
//-----------------------------------------------------------------
// Modified Bernstein hash
// A minor update to Bernstein's hash replaces addition with XOR for
// the combining step. This change does not appear to be well known
// or often used, the original algorithm is still recommended by
// nearly everyone, but the new algorithm typically results in a
// better distribution.
// @Param: string val - word to be hashed
// @Returns: unsigned int - hash key value
//----------------------------------------------------------------
unsigned int hash_functions::mod_bernstein_hash (string val)
{
  unsigned h = 0;

	for (unsigned i = 0; i < val.length(); i++ )
      h = 33 * h ^ val[i];

  return h;
}
~~~

#### Shift-Add-XOR hash

~~~cpp
//-----------------------------------------------------------------
// Shift-Add-XOR hash
// The shift-add-XOR hash was designed as a string hashing function,
// but because it is so effective, it works for any data as well with
// similar efficiency. The algorithm is surprisingly similar to the
// rotating hash except a different choice of constants for the rotation
// is used, and addition is a preferred operation for mixing. All in
// all, this is a surprisingly powerful and flexible hash. Like many
// effective hashes, it will fail tests for avalanche, but that does
// not seem to affect its performance in practice.
// @Param: string val - word to be hashed
// @Returns: unsigned int - hash key value
//----------------------------------------------------------------
unsigned int hash_functions::shift_add_xor_hash (string val)
{
  unsigned h = 0;

   for (unsigned i = 0; i < val.length(); i++ )
      h ^= ( h << 5 ) + ( h >> 2 ) + val[i];

  return h;
}
~~~

#### FNV hash

~~~cpp
//-----------------------------------------------------------------
// FNV hash
// The FNV hash, short for Fowler/Noll/Vo in honor of the creators,
// is a very powerful algorithm that, not surprisingly, follows the
// same lines as Bernstein's modified hash with carefully chosen
// constants. This algorithm has been used in many applications with
// wonderful results, and for its simplicity, the FNV hash should be
// one of the first hashes tried in an application. It is also
// recommended that the FNV website be visited for useful descriptions
// of how to modify the algorithm for various uses.
// @Param: string val - word to be hashed
// @Returns: unsigned int - hash key value
//----------------------------------------------------------------
unsigned int hash_functions::fnv_hash (string val)
{
  unsigned int h = 2166136261;

   for (unsigned i = 0; i < val.length(); i++ )
      h = ( h * 16777619 ) ^ val[i];

  return h;
}
~~~

#### One-at-a-Time hash

~~~cpp
//-----------------------------------------------------------------
// One-at-a-Time hash
// @Param: string val - word to be hashed
// @Returns: unsigned int - hash key value
//----------------------------------------------------------------
unsigned int hash_functions::one_at_a_time_hash (string val)
{
  unsigned int h = 0;

  for (unsigned i = 0; i < val.length(); i++ ) {
    h += val[i];
    h += ( h << 10 );
    h ^= ( h >> 6 );
  }

  h += ( h << 3 );
  h ^= ( h >> 11 );
  h += ( h << 15 );

  return h;
}
~~~

#### Jsw hash

~~~cpp
//-----------------------------------------------------------------
// Jsw hash
// This is a hash of my own devising that combines a rotating hash
// with a table of randomly generated numbers. The algorithm walks
// through each byte of the input, and uses it as an index into a
// table of random integers generated by a good random number
// generator. The internal state is rotated to mix it up a bit, then
// XORed with the random number from the table. The result is a
// uniform distribution if the random numbers are uniform. The size
// of the table should match the values in a byte. For example, if a
// byte is eight bits then the table would hold 256 random numbers.
// @Param: string val - word to be hashed
// @Returns: unsigned int - hash key value
//----------------------------------------------------------------
unsigned int hash_functions::jsw_hash (string val)
{
  unsigned h = 16777551;

  for (unsigned i = 0; i < val.length(); i++ )
    h = ( h << 1 | h >> 31 ) ^ rand_vals[val[i]];

  return h;
}
~~~

#### Elf Hash

~~~cpp

//-----------------------------------------------------------------
// Elf hash
// The ELF hash function has been around for a while, and it is believed
// to be one of the better algorithms out there. Though ELF hash does not
// perform sufficiently better than most of the other algorithms
// in this collection to justify its slightly more complicated implementation.
// @Param: string val - word to be hashed
// @Returns: unsigned int - hash key value
//----------------------------------------------------------------
unsigned int hash_functions::elf_hash (string val)
{
  unsigned h = 0 , g;

	for (unsigned i = 0; i < val.length(); i++ ) {
	  h = ( h << 4 ) + val[i];
	  g = h & 0xf0000000L;

	  if ( g != 0 )
		h ^= g >> 24;

	  h &= ~g;
	}

  return h;
}
~~~

#### My Hash

~~~cpp
//-----------------------------------------------------------------
// My hash
// I basically took ideas from above hash functions and others found
// on the internet to create my own. this function uses the rotative
// and additive priniciple to create a unique hash key for every input
// @Param: string val - word to be hashed
// @Returns: unsigned int - hash key value
//----------------------------------------------------------------
unsigned int hash_functions::my_hash (string val)
{
	unsigned int hash = 0xAAAAAAAA;

	for(unsigned i = 0; i < val.length(); i++)
   {
      hash ^= ((i & 1) == 0) ? (  (hash <<  11) ^ val[i] * (hash >> 7)) :
                               (~((hash << 19) + (val[i] ^ (hash >> 11))));
   }

   return hash;
}
~~~
