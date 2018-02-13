## Assignment 5 - Crazy Word Creator
Due: Mar 1st by Classtime

### Overview

***Fun Part:***<br>
Were going to create crazy names similar to what github and repl.it do when suggesting names for repls or repos. Github suggests things like: `musical-journey` or `cautious-waffle` or `bug-free-succotash`. Whereas repl.it suggests things like:  `LikelyTatteredGreatwhiteshark` or `PepperySunnyMaggot` or `ClearcutLongtermCrocodile` or `RowdyWorthwhileBird`. I'm not sure what thier algorithm is, but I'm sure we can come up with something better (or at least similar). 

***Data Structures Part:***<br>
After we generate about 10000 names, we are going to compare the performance of a Binary Search Tree vs an AVL tree when it comes to finding those named components in each tree.

I think most of us remember what types of words there are:

| ad·jec·tive | noun  | verb | adverb | 
|-------------|--------|----------|---------|
| *ˈajəktiv*    | *noun* | *vərb* | *ˈadˌvərb* |
| a word or phrase naming an attribute, added to or grammatically related to a noun to modify or describe it. | a word (other than a pronoun) used to identify any of a class of people, places, or things common noun, or to name a particular one of these proper noun. | a word used to describe an action, state, or occurrence, and forming the main part of the predicate of a sentence, such as hear, become, happen. | a word or phrase that modifies or qualifies an adjective, verb, or other adverb or a word group, expressing a relation of place, time, circumstance, manner, cause, degree, etc. (e.g., gently, quite, then, there ) |

There are a few more word categories (I think) but we don't really need those to make our crazy words. What we do have are words lists for the above categories + a list of animal names:

- [adjectives](https://github.com/rugbyprof/3013-Algorithms/blob/master/Resources/R01/conv.data.adj)
- [nouns](https://github.com/rugbyprof/3013-Algorithms/blob/master/Resources/R01/conv.data.noun)
- [verbs](https://github.com/rugbyprof/3013-Algorithms/blob/master/Resources/R01/conv.data.verb)
- [adverbs](https://github.com/rugbyprof/3013-Algorithms/blob/master/Resources/R01/conv.data.adv)
- [animals](https://github.com/rugbyprof/3013-Algorithms/blob/master/Resources/R01/animals.words)

#### Motivation

Binary search tree's are only good when they are balanced. So we are going to compare an AVL implementation of a Binary Search Tree to a regular implementation that is not balanced. 

#### Why Crazy Words?

Because there are a lot of words and we need data to load into both of our data structures in order to compare performance. The word lists only number in the thousands, so we won't be bogging down our computers trying to handle the data, but its enough data to motivate us to be efficient. And crazy words are funny.

### Requirements

- Part 1
    - 
- Compare the performance of a Binary Search Tree and an AVL tree by adding up the number of comparisons necessary to find each portion of a crazy word. 



