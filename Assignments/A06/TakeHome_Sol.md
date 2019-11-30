## Test 2 Takehome - Hashing
#### Due: November 11<sup>th</sup>


|      Honor Statement         |
|:------------------|
| <br><br> By signing below I am confirming that I have neither given nor received assistance from anyone. I understand that if my answers come close to resembling that of another student and/or digital source, where this resemblance is based on the judgment of the instructor (and a conference with each participant), I can be given a score of zero. <br><br> |


|  Due      |
|:-------|
| Your completed exam will not have ANY handwritten portions (except your signature) whatsoever and will not be graded if it does. Turn your completed take home exam by Monday, November 11, 2019 by 9 p.m. by uploading a digital copy to slack. You will also bring a printed copy to Dr. Griffin by 11:00 a.m. Tuesday. All work will be completed by 9 p.m. Monday night and the printed copy will not have any revisions from the uploaded copy.

| Warning |
|:--------|
| This is a takehome, so make sure you explain or justify every answer (when appropriate). |
| For example Q1 has an answer of .1, but you may want to add the definition of (&lambda;) to bolster your answer. |


|                           M Number                           | Signature                                                   |
| :----------------------------------------------------------: | :---------------------------------------------------------- |
| <br><br>____________________________________________________ | <br><br> __________________________________________________ |




## Q1

Suppose that an open-address hash table has a capacity of 1000 and it contains 100 elements. What is the table's load factor? 

>**Answer:**
>The ***load factor*** of hash table with ***M*** entries and ***n*** keys or ***&lambda; = n/M***  is therefore:  `100 / 1000 = .10`

-----

## Q2

I plan to put 1000 items in a hash table, and I want the average number of accesses in a successful search to be about 3.0.


- About how big should the array be if I use open addressing with linear probing?
>**Answer:**
> For a successful search to be on average about 3 comparisons, that I need to either find the item, or quit the search after looking at 3 values. To quit the search after 3 comparison I need to find an empty slot, meaning I need on average 1 empty slot per 3 full slots. A lambda; of `.75` would give me on average (for a good hash function) 1 empty slot for every 3 full ones. So, I need a table size the gives me a lambda; wich gives us ***`1000 / `&lambda;` = .75`*** or ***`1333.33333` or `1333`***.


- About how big should the array be if I use chained hashing? 
>**Answer:**
> This is different, because I do not need an empty slot in the array to terminate a search, I can use the end of a list. Therefore every hash key can terminate its own search with at the end of its list. If we are ok with an average of 3 accesses for everysearch, then every list can be 3 in length, making my hash table only need to be about 1/3 or .33 percent of the size of the items I'm loading. This gives me ***`1000 * .33 = 333`***.

-----

## Q3

Define collision in a hash table.

>**Answer:**
>When a hash function maps two different keys to the same table address forcing the hash function to find another location to store the value. 

-----

## Q4

If you're picking a table size for your hash table, which sizes should you stay away from?

>**Answer:**
>
>Assuming we are using the division method of finding a hash key : ***`h(K) = K mod M`***.
>
>You want to stay away from numbers that will undermine your hash functions ability to evenly distribute keys throughout the table with equal probability (assuming the hash function is good). 
>
>For example if I have a table that is an even number in size (***M***), then ***`h(K)`*** will be **even** when ***`K`*** is even and odd when ***`K`*** is **odd**. This will bias the hash function and lead to poor performance. 
>
>Another way to look at it is you don't want your hash function to generate keys that end up becoming multiples `{x , 2x, 3x, 4x, 5x, 6x...}` of the hash value. This causes your keys to be clustered around those multiples. How do we get multiples in the first place? By picking table sizes that are divisible by some number like 3 or 5. How do we stay a way from them? By picking table sizes that are prime and not close to powers of two.

-----

## Q5

What is generally a good choice for a load factor (&lambda;) when using open addressing?

>**Answer:**
>
>The general consensus is `.75` to `.80`. BUT it also depends on what you are trying to do and what your knowledge of the data is. You might opt for a &lambda; of **1**, if you know exactly what values your hashing and are confident in zero collisions. You might opt for a lower &lambda; if search times are paramount and you want make sure there is very low chance for clustering. 

## Q6

Is the choice for load factor (&lambda;) the same when using chaining?

Not really since we can terminate a search easily by reaching the end of a "chain", and not scanning the array for the key we are looking for and hoping we find an open slot quickly if the key is not there. When using chaining (assuming a good hash function with good distribution) we can pick &lambda;'s closer to 1 or even over 1, since we don't care about maintaining a certain amount of empty slots to quickly terminate unsuccessfull searches. We only care about how long we are willing our average chains to get (wich determines number of access before terminating a search).

## Q7

Draw a hash table with open addressing and a size of 9. Use the hash function `k%9`. Insert the keys: 5, 29, 20, 0, 27 and 18 into your table (in that order).

>**Answer:**
>
><img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/test2.1.png">

-----

## Q8

What is the correct formula for the load factor?

>**Answer:**
>The ***load factor*** of hash table with ***M*** entries and ***n*** keys is ***&lambda; = n/M***

-----

## Q9

Draw 3 separate hash tables that results from using a given hash function (below) to hash a given set of keys using the following collision resolution techniques:

1. linear probing
2. double hashing
3. chaining

| Ascii Values |       |
| :----------: | :---: |
|      A       |  65   |
|      Z       |  90   |
|      a       |  97   |
|      z       |  122  |

|                                       Hash Function                                       | Description                                              |
| :---------------------------------------------------------------------------------------: | :------------------------------------------------------- |
| <img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/test.2.7.png" width="250"> | The sum of the ascii value of each letter mod table size |
| <img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/test.2.5.png" width="250"> | Where `i` is the `i`<sup>th</sup> collision `+ 1`        |

Strings to hash:

**Epd, DcS, Fcf, Gco, Qzj, Wvc, RUC, ejJ, iwR, zyz**

>**Answer:**
>- We need to choose a table size. With 10 Values to store, so I would choose a hash table of 13 which is **prime** and gets me close to a **.75 load factor**
>- We also need to calculate the hash keys.
>- Here are the hash keys for each string along with its modulo result 
>- <img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/3013.test.3.09a.png" height="250">
> 
>- I used this little python program for correctness: [calc_hash_vals.py](./calc_hash_vals.py)
>- 
>- Here is each hash table:
> <img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/3013.test.3.09b.png">

-----

## Q10

- **Given:** A hash table that uses linear probing to handle collisions.
- **Problem:** Describe a situation in which searching for a value in this hash table you might not find the value, even though it is in the table.

> **Answer:** 
> - If a hash table is allowed to become full (load factor of 1) there will be zero empty slots to terminate a search.
> - In this case you would:
>   - 1) Not let the load factor become 1.
>   - 2) Implement a different method for terminating a search (like counting comparisons).
-----

## Q11

- **Problem:** A hash table is having trouble with clustering.
- **Describe:**
  - What is clustering?
  - What type of collision resolution does this typically occur with?
  - What is the generic solution to the clustering problem? Your answer shouldn’t just be: “use new hash function”. It should be discussed using general terms and definitions.

> **Answer:**
> - **Clustering:** 
>     - The grouping together of hashed values in an **open addressed** hash table. 
> - There are two types of clustering, **primary clustering** and **secondary clustering**.
> - **Primary Clustering** occurs when linear probing is used as the collision resolution technique. Since we simply scan for an open "bucket" and place the value in the first occurence, clusters can start to grow quite large putting a hit on performance.
> - **Secondary Clustering** occurs using quadratic probing as a collision resolution technique. This type of clustering doesn't create large clusters of values like linear probing does, it simply causes the "probe sequence" to get longer and longer since values hashed to the same "bucket" would follow the same sequence. Secondary clustering is considered less severe than primary clustering since the performance of searches tends to be better than linear probing.
> 


-----

## Q12

- **Given:** The formula for unsuccessful search in a hash table is: `O(1/1-`&lambda;`)`
- **Describe:** The time for searches increases as the load factor increases. Explain why this happens as described in our study guide.

> **Answer:**
> - To put it simply the higher the &lambda; the more full the table and the more full the table the less empty slots to terminate a search. 
> - The formula simply results in larger values for larger &lambda;'s
> - To show with values:
>     - When &lambda; = .6 the formula `1+(1/(1-.6)) = 3.5`
>     - When &lambda; = .75 the formula `1+(1/(1-.75)) = 5`
>     - When &lambda; = .9 the formula `1+(1/(1-.9)) = 11`

-----

## Q13

- **Problem:** What decides whether a hash function will perform well or not? In other words, how would you benchmark (***test***) a hash function.
- **Proposed Solution:** Discuss type of `input data`, proposed `load factor`, `collisions` and `collision resolution`.

> **Answer:**
>- **Some Background:**
>- <a href="http://en.wikipedia.org/wiki/Benchmark_%28computing%29" title="Benchmark (computing)">Benchmark (computing)</a>, the result of running a computer program, or a set of programs, in order to assess the relative performance of an object by running a number of standard tests and trials against it.
>
>- **Input data**
>    -   The data being hashed has an impact on the choice of hash function.
>    -   Data that is similar or short in length could create a smaller range of hash keys, increasing collisions.
>- **Load Factor**
>   -   The ratio of the number of records to the number of addresses or indexes within a data structure.
>   -   Effected by choice of table size.
>- **Table Size**
>   -   Poor choice in table size (to small) has a direct effect on load factor.
>   -   A full table is, well…… a huge cost to rehash all those values. There are some alternatives not discussed in class to table resizing
>   -   To large of a table is a simple waste of resources.
>   -   Prime numbers not close to a power of two.
>- **Collision Resolution**
>   -   Chaining vs open addressing (as well as many others)
> - **Actual Answer:**
>Benchmarking a hash function is not very difficult at all. By looking at the factors that determine a hash functions performance (terms above), we could then create a test that would objectively quantify a hash functions performance by cycling through various configurations and simply **counting the number of collisions** (for insertions), and **counting the number of comparisons** (for searches). A "**configuration**" would be various combinations of the items we listed above (table size, load factor, collision resolution).


-----

## Q14

- **Problem:** Given an example hash function, place it in 1 or more categories
- **Function Names:** Shift, Additive, Rotating ,XOR , or combination
- **Solution**: Look at the different types of [Hash Functions](../../Lectures/L09/hash_functions.md) and be able to categorize them. 

>**Answer:**
> Should at least try to explain what `Shift`, `Additive`, `Rotating` ,`XOR` mean.

-----

## Q15

- **Given:** Suppose you have table size 9 and when you have collisions you increment 3 every time.
- **Problem:** Describe why this is a problem, and how it effects the search space in your table.
- **Proposed Solution:** What could you do the alleviate the problems that occur because of the initial choices made? Describe the relationship between table size and the increment size.

>**Answer:**
>
>With the given table size and increment, you would only use about $\frac{1}{3}$ of the table leaving $\frac{2}{3}$ unused, thereby causing more than necessary collisions and degrading the overall performance of the table. 
>
>One solution is to increase the `probe increment` every time to ensure you don't jump the same increment, thereby increasing your chances of using all slots. Also, make sure your `probe increment` is `relatively prime` to the size of the table. This also helps ensure the hash function doesn't fixate on a subset of table slots.

-----

## Q16

Suppose you wish to make a hash table of all the students at MCSU University using as the key each student's ID number which is an 8 digit number. At MCSU, they give out student ID numbers consecutively. In other words, the first student to enroll gets ID 0000000, the second student gets the number 00000001, and so on. You map IDs to student records so that lookup (and insertion) are by the key of a student ID which is mapped to the value of a student record. In this problem we talk about how hashing the keys works.

You decide to implement the hash-table using an array/vector with 4999 elements, with **quadratic probing** to resolve conflicts. (By the way, both 4999 and 997 are prime numbers.) For each of the following three possible hash functions, say whether it is a good or bad choice, and explain why in one sentence. Note that digit<sub>x</sub> refers to some integer representing one of the eight digits that comprise SIDs at MCSU U (so x takes on values 0 to 7).

>**Answer:**
> 1. `digit`<sub>0</sub>` + digit`<sub>1</sub>` + digit`<sub>2</sub>` + ... + digit`<sub>7</sub>` mod 4999`
>
> This is a horrible solution since it would only create hash keys from 0 - 72. So it wouldn't matter what kind of probing sequence you choose. 


> 2. `SID number mod 4999`
> 
> This is also not a good method for creating a hash key. It would work nicely for the first 4999 students, but then the highorder bits would not be a part of the the hash value. Quadratic probing would help spread the values out over the table, but not using half of the digits in the SID to help determine the hash value would cause a lot of clustering.

> 3. `(digit`<sub>0</sub>` + digit`<sub>1</sub>` * 971`<sup>1</sup> `+ digit`<sub>2</sub>` * 972`<sup>2</sup> `+ ... + digit`<sub>7</sub>` * 997`<sup>7</sup> `) mod 4999`
> 
> This method would work fine. It uses all of the digits in the SID. It multiplies each digit by some large(ish) prime creating hash keys that would be spread out over the entire table. 

-----

## Q17

Given a collision resolution technique (array with linear probing, array with quadratic probing, array with double hashing, and array with chaining), which approach would be most appropriate for an application in which many keys that hash to the same value are likely to be present? Explain why.

> **Answer:**
> - The best answer is to get a better hash function but thats not the case.
> - There are two acceptible answers:
>     - **Chaining** seems to be the obvious choice because of its implementation. We know that we would terminate searches at the end of a chain, and that the performance would be `O(longest_chain.size)`
>    - However, **linear probing** is fast, and with an appropriate table size we would be fairly confident that probing would terminate at the end of each cluster. However if there are many many values that need hashed, we would need a very large table. So, I would still lean towards chaining given the confidence in terminating searches in a well defined time.

-----

## Q18

Explain how deletion is performed in both **probing** and **chaining** hash tables.

> **Answer:**
> - **Probing:**
>     - Deleting from a table that uses probing as its method of searching, we need to be careful when deleting values. If the value were in the middle of a cluster, then other values may not be found since an empty slot would terminate a search. Therefore, we would need to place a special value or a flag in a deleted slot to tell a probe sequence not to terminate here!
> - **Chaining:**
>     - Simply delete the node from the chain.
> 

-----

## Q19

A hash table needs to be resized if load factor of a table exceeds **0.7**. What are the important things to do when resizing a hash table?

>**Answer:**
> The important things to do:
> - Determine of current hash function is appropriate for new table size
> - Allocate the memory necessary for the new table
> - Iterate through the elements of the old table, and inserting them into the new table.
> The load factor is only a threshold to determine "when" to resize, it does not play into how a table gets resized.