## Knuth-Morris-Pratt - Overview
#### Due: None

The Knuth-Morris-Pratt (KMP) algorithm is a string-matching algorithm that searches for occurrences of a pattern string within a larger text string. It was proposed by Donald Knuth, Vaughan Pratt, and James Morris in 1977, and is considered to be one of the most efficient and elegant algorithms for string matching.

The KMP algorithm works by pre-processing the pattern string to generate a "failure function" that encodes information about the structure of the pattern. This function is then used to guide the search through the text string, allowing the algorithm to skip over sections of the text that cannot match the pattern based on the information in the failure function.

Here is a high-level overview of the steps involved in the KMP algorithm:

1. Generate the failure function for the pattern string.
2.Initialize two indices, `i` and `j`, to `0` and begin scanning the text string.
3. At each index `i` of the text string, compare the character at that index to the character at index `j` of the pattern string.
4. If the characters match, increment both `i` and `j` and continue scanning the text string.
5. If the characters do not match, use the failure function to determine the next value of `j` to use in the comparison.
6. If `j` is equal to the length of the pattern string, a match has been found.
7. Repeat steps 3-6 until the end of the text string is reached.
   
The failure function for the pattern string is generated using a dynamic programming algorithm that iteratively computes the length of the longest proper prefix of the pattern string that is also a suffix of the substring ending at the current position. This information is used to determine the next value of `j` to use in the comparison if a mismatch is found.

The **KMP** algorithm has a worst-case time complexity of `O(m + n)`, where m is the length of the pattern string and `n` is the length of the text string. This makes it a highly efficient algorithm for string matching, and it has been widely adopted in software libraries and applications that require fast and reliable string matching capabilities.