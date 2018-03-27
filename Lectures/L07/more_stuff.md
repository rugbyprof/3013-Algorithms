## Hashing Problems

- Consider a hash table where collisions are resolved with chaining. Under what conditions do the operations of insert, search and delete take constant expected time? 
- Consider a hash table using `chaining` where `M = 5`, `h(k) = k mod 5`, and the keys `1, 5, 11, 15` are inserted, in that order, into an initially empty hash table. Draw the result. 
- Consider a hash table using `open addressing` with `linear probing` where `M = 5`, `h(k) = k mod 5` and the keys `1, 5, 11, 15` are inserted, in that order, into an initially empty hash table. Draw the result. 

- What is double hashing?
- What is the load factor of a hash table? 

- What is a collision, in the context of a hash table? 
- Informally, what is the behavior of a hash function that is ideal for chaining? 
- Informally, what is the behavior of a hash function that is ideal for open addressing?
- Explain how to design an experiment that would evaluate the success of a given hash function whether it was for chaining or open addressing.


Find polynomial hashing in Wikipedia
•  Why does using polynomial hash code on string preferable to a hash code that
simply sums up the ASCII representation of each character on the string? (2 points)
•  Write a pseudo-C++ code for computing the polynomial hash code of a string
that doesn’t involve the use of exponentiation. (3 points)

Suppose integers are being inserted into a hash table of 11 elements. The integers are hashed using the hash function below. 

    int Hash(int n)
    {
        return (n*2) + n/2;
    }
 The values returned by Hash are converted to indices in the hash table by using %11 (the remainder after dividing by 11). Hash collisions are resolved using chaining and new elements are inserted at the front of each linked list. 
Draw a diagram of the hash table that results from inserting 
5, 22, 17, 18, 35, 101, 16, 0, 8
into the hash table in the order shown (5 first, 8 last)






You are given: a hash table with TableSize = 11 and the hash function 
	Key MOD TableSize
Consider the following Keys in the given order: 
	36    85   53   113   123   23   62   134   142   47
2a) What is the result of inserting the given values into an open hash table with arbitrarily large buckets? 
   [0]   [1]   [2]   [3]   [4]   [5]   [6]   [7]   [8]   [9]  [10]
 +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
 |     |     |     |     |     |     |     |     |     |     |     |
 |     |     |     |     |     |     |     |     |     |     |     |
 |     |     |     |     |     |     |     |     |     |     |     |
 |     |     |     |     |     |     |     |     |     |     |     |
 +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
2b) What is the result of inserting the given values into a closed hash table with linear probing? 
   [0]   [1]   [2]   [3]   [4]   [5]   [6]   [7]   [8]   [9]  [10]
 +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
 |     |     |     |     |     |     |     |     |     |     |     |
 |     |     |     |     |     |     |     |     |     |     |     |
 |     |     |     |     |     |     |     |     |     |     |     |
 |     |     |     |     |     |     |     |     |     |     |     |
 +-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+



•  How does a hash table allow for O(1) searching? What is the worst case efficiency of a look up in a hash table using separate chaining?
•  The bigger the ratio between the size of the hash table and the number of data elements, the less chance there is for collision. What is a drawback to making the hash table big enough so the chances of collision is ignorable?
•  How could a linked list and a hash table be combined to allow someone to run through the list from item to item while still maintaining the ability to access an individual element in O(1) time?
•  How could a hash table be used to implement a spell checker? 
•  How long would a deletion operation take from hash table implemented using separate chaining? 


•  Explain the advantages and disadvantages of using linked storage for hash tables.

•  Linear probing is another method for collision avoidance. With linear probing, if a collision occurs, you sequentially look from the current place in the hash table for the next open spot, and store the string there. What disadvantage does this method have for an insertion in terms of efficiency?


