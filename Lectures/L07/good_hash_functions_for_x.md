## Good Hash Functions for Chaining

**Intuition:** Hash function should spread out the data
evenly among the ***M*** entries in the table.
More formally: any key should be equally likely to
hash to any of the M locations.
Impractical to check in practice since the probability
distribution on the keys is usually not known.
For example: Suppose the symbol table in a compiler
is implemented with a hash table. The compiler writer
cannot know in advance which variable names will appear
in each program to be compiled.
Heuristics are used to approximate this condition: try
something that seems reasonable, and run some experiments
to see how it works.

Good Hash Functions for Chaining (cont’d)
Some issues to consider in choosing a hash function:
 Exploit application-specific information. For symbol
table example, take into account the kinds of
variables names that people often choose (e.g., x1).
Try to avoid collisions on these names.
 Hash function should depend on all the information
in the keys. For example: if the keys are English
words, it is not a good idea to hash on the first letter,
since many words begin with S and few with X.
CPSC 211 Data Structures & Implementations (c) Texas A&M University [ 272]
Average Case Analysis of Chaining
Define load factor of hash table with M entries and n
keys to be  = n=M. (How full the table is.)
Assume a hash function that is ideal for chaining (any
key is equally likely to hash to any of the M locations).
Fact: Average length of each linked list is n=M = .
The average running time for chaining:
 Insert: O(1) (same as worst case).
 Unsuccessful Search: O(1 + ). O(1) time to compute
h(k);  items, on average, in the linked list are
checked until discovering that k is not present.
 Successful Search: O(1 + =2). O(1) time to compute
h(k); on average, key being sought is in middle
of linked list, so =2 comparisons needed to find k.  Delete: Essentially the same as search.
For these times to be O(1),  must be O(1), so n cannot
be too much larger than M.
CPSC 211 Data Structures & Implementations (c) Texas A&M University [ 273]
Open Addressing
With this scheme, there are no linked lists. Instead, all
elements are stored in the table proper.
If there is a collision, you have to probe the table –
check whether a slot (table entry) is empty – repeatedly
until finding an empty slot.
You must pick a pattern that you will use to probe the
table.
The simplest pattern is to start at h(k) and then check
h(k)+1, h(k)+2, h(k)+3, :::, wrapping around to
check 0, 1, 2, etc. if necessary, until finding an empty
slot. This is called linear probing.
0 1 8 2 3 4 5 6 7
F FF F F F F
If h(k)=7, the probe sequence will be 7, 8, 0, 1, 2, 3.
(F means full.)
CPSC 211 Data Structures & Implementations (c) Texas A&M University [ 274]
Clustering
A problem with linear probing: clusters can build up.
A cluster is a contiguous group of full slots.
If an insert probe sequence begins in a cluster,
 it takes a while to get out of the cluster to find an
empty slot,
 then inserting the new element just makes the cluster
even bigger.
To reduce clustering, change the probe increment to
skip over some locations, so locations are not checked
in linear order.
There are various schemes for how to choose the increments;
in fact, the increment to use can be a function
of how many probes you have already done.
CPSC 211 Data Structures & Implementations (c) Texas A&M University [ 275]
Clustering (cont’d)
0 1 8 2 3 4 5 6 7
F FF F F F F
If the probe sequence starts at 7 and the probe increment
is 4, then the probe sequence will be 7, 2, 6.
Warning! The probe increment must be relatively prime
to the table size (meaning that they have no common
factors): otherwise you will not search all locations.
For example, suppose you have table size 9 and increment
3. You will only search 1/3 of the table locations.
CPSC 211 Data Structures & Implementations (c) Texas A&M University [ 276]
Double Hashing
Even when “non-linear” probing is used, it is still true
that two keys that hash to the same location will follow
the same probe sequence.
To get around this problem, use double hashing:
1. One hash function, h1, is used to determine where
to start probing.
2. A second hash function, h2, is used to determine the
probe sequence.
If the hash functions are chosen properly, different keys
that have the same starting place will have different
probe increments.
CPSC 211 Data Structures & Implementations (c) Texas A&M University [ 277]
Double Hashing Example
Let h1(k) = k mod 13 and h2(k)=1+(k mod 11).
0 9 10 11 12 1 8 2 3 4 5 6 7
79 69 98 72 15 50
 To insert 14: start probing at 14 mod 13 = 1. Probe
increment is 1 + (14 mod 11) = 4. Probe sequence
is 1, 5, 9, 0.
 To insert 27: start probing at 27 mod 13 = 1. Probe
increment is 1 + (27 mod 11) = 6. Probe sequence
is 1, 7, 0, 6.
 To search for 18: start probing at 18 mod 13 = 5.
Probe increment is 1 + (18 mod 11) = 8. Probe
sequence is 5, 0 – not in table.
CPSC 211 Data Structures & Implementations (c) Texas A&M University [ 278]
Deleting with Open Addressing
Open addressing has another complication:
 to insert: probe until finding an empty slot.
 to search: probe until finding the key being sought
or an empty slot (which means not there)
Suppose we use linear probing. Consider this sequence:
 Insert k1, where h(k1)=3, at location 3.
 Insert k2, where h(k2)=3, at location 4.
 Insert k3, where h(k3)=3, at location 5.
 Delete k2 from location 4 by setting location 4 to
empty.
 Search for k3. Incorrectly stops searching at location
4 and declares k3 not in the table!
Solution: when an element is deleted, instead of marking
the slot as empty, it should be marked in a special
way to indicate that an element used to be there but was
deleted. Then the search algorithm needs to continue
searching if it finds one of those slots.
CPSC 211 Data Structures & Implementations (c) Texas A&M University [ 279]
Good Hash Functions for Open Addressing
An ideal hash function for open addressing would satisfy
an even stronger property than that for chaining,
namely:
Each key should be equally likely to have each permutation
of f0; 1;:::;M 1g
as its probe sequence.
This is even harder to achieve in practice than the ideal
property for chaining.
A good approximation is double hashing with this scheme:
 Let M be prime, then let h1(k) = k mod M and let
h2(k)=1+ k mod (M
2).
Generalizes the earlier exampl
CPSC 211 Data Structures & Implementations (c) Texas A&M University [ 280]
Average Case Analysis of Open Addressing
In this situation, the load factor  = n=M is always
less than 1: there cannot be more keys in the table than
there are table entries, since keys are stored directly in
the table.
Assume that there is always at least one empty slot.
Assume that the hash function ensures that each key is
equally likely to have each permutation of
f0; 1;:::;M
1g as its probe sequence.
Average case running times:
 Unsuccessful Search: O( 1
1
).  Insert: Essentially same as unsuccessful search.
 Successful Search: O( 1
  ln 1
1),
where ln is the
natural log (base e = 2:7:::).
 Delete: Essentially same as search.
The reasoning behind these formulas requires more sophisticated
probability than for chaini
CPSC 211 Data Structures & Implementations (c) Texas A&M University [ 281]
Sanity Check for Open Addressing Analysis
The time for searches should increase as the load factor
increases.
The formula for unsuccessful search is O( 1
1).
 As n gets closer to M,  gets closer to 1,
 so 1
 gets closer to 0,
 so 1
1
gets larger.
At the extreme, when n = M
1, the formula 1
1
=
M, meaning that you will search the entire table before
discovering that the key is not t
