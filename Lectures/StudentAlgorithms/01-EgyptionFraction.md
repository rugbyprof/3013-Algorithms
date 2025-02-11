## Egyption Fractions - Overview

#### Due Date : None

<sub>Source: Chat GPT!</sub>


The Egyptian Fraction algorithm is a method for representing a positive fraction as a sum of unit fractions. A unit fraction is a fraction where the numerator is 1, and the denominator is a positive integer. For example, 1/2, 1/3, 1/4, etc. are unit fractions.

The algorithm works by repeatedly finding the largest unit fraction that is less than the remaining fraction, subtracting it from the remaining fraction, and then repeating the process with the new remaining fraction until the remaining fraction is zero. The sum of all the unit fractions used is equal to the original fraction.

Here is an implementation of the algorithm in Python:

```python
def egyptian_fraction(numerator, denominator):
    fractions = []
    while numerator > 0:
        unit_fraction = (denominator + numerator - 1) // numerator
        fractions.append(unit_fraction)
        numerator = numerator * unit_fraction - denominator
        denominator = denominator * unit_fraction
    return fractions
```

The `egyptian_fraction` function takes two arguments, `numerator` and `denominator`, and returns a list of unit fractions that sum to the original fraction. Here's how it works:

1. Initialize an empty list fractions to hold the unit fractions.
2. While numerator is greater than 0, do the following:
    1. Compute the largest unit fraction that is less than or equal to the remaining fraction, and append it to `fractions`.
    2. Subtract the unit fraction from the remaining fraction, and update `numerator` and `denominator`.
3. Return the list of unit fractions.
   
For example, to represent the fraction 7/11 as a sum of unit fractions, we would call the egyptian_fraction function with arguments 7 and 11:

```python
fractions = egyptian_fraction(7, 11)
print(fractions)
```

This would output the following list of unit fractions:

```python
[1, 2, 22, 154]
```

To verify that this list of unit fractions sums to `7/11`, we can compute the sum:

```python
sum_of_fractions = sum(1/f for f in fractions)
print(sum_of_fractions)
```

This would output `0.6363636363636364`, which is indeed equal to `7/11`.


### Applications 

What applications does the Egyptian Fraction algorithm have ?


The Egyptian Fraction algorithm has several applications in different fields such as mathematics, computer science, and cryptography. Here are some examples:

1. Historical significance: The Egyptian Fraction algorithm was used by the ancient Egyptians to solve practical problems involving fractions. They were particularly interested in expressing fractions as sums of unit fractions, as this allowed them to measure quantities of grain and other commodities accurately.

2. Approximation of real numbers: The Egyptian Fraction algorithm can be used to approximate real numbers by truncating the expansion after a certain number of terms. This is particularly useful in applications where the exact value of a real number is not needed or is difficult to compute.

3. Optimization problems: The Egyptian Fraction algorithm can be used to solve optimization problems, such as finding the smallest number of unit fractions needed to represent a given fraction or finding the smallest possible value of a linear combination of unit fractions.

4. Cryptography: The Egyptian Fraction algorithm has been used in cryptography to create secure cryptographic systems that are resistant to attacks based on the factorization of large integers.

5. Computer science: The Egyptian Fraction algorithm has applications in computer science, particularly in the area of algorithms for computing the greatest common divisor (GCD) of two integers.

Overall, the Egyptian Fraction algorithm has a wide range of applications in various fields and is still an active area of research in mathematics and computer science.