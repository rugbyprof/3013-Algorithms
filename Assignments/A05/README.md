## Assignment 5 - Crazy Word Creator
Due: Mar 1<sup>st</sup> by Classtime

### Overview

***Fun Part:*** <br>
>Were going to create crazy names similar to what github and repl.it do when suggesting names for repls or repos. Github suggests things like: `musical-journey` or `cautious-waffle` or `bug-free-succotash`. Whereas repl.it suggests things like:  `LikelyTatteredGreatwhiteshark` or `PepperySunnyMaggot` or `ClearcutLongtermCrocodile` or `RowdyWorthwhileBird`. I'm not sure what thier algorithm is, but I'm sure we can come up with something better (or at least similar). 

***Data Structures Part:*** <br>
>After we generate about 10000 names, we are going to compare the performance of a Binary Search Tree vs an AVL tree when it comes to finding those named components in each tree.

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
    - Come up with some heuristic that will create a crazy name using your word lists. If we look at some of the examples from above: 
        - ***RowdyWorthwhileBird*** = ***adjective adjective noun*** 
        - ***bug-free-succotash*** = ***noun adjective noun***
        - ***PepperySunnyMaggot*** = ***adjective adjective noun***
        - ***cautious-waffle*** = ***adjective noun*** 
    - There are no verbs or adverbs! I want you to find a way to incorporate all the word groups into your crazy word generator. 
    - You don't have to have every group in every crazy word, but try to randomly cycle through all the groups. 
    - How you do this is up to you, however you need to generate at least ***10000*** crazy words that are made up with 3-5 word parts. 
    - Just for your information, animals make words funnier. Totally my opinion, but I'm grading your programs so ...
    - Your 10000 words will be stored in a file, one crazy word per line, with spaces between each word component. 
    - No repeat words!

`crazywords.txt`
```
rowdy worthwhile bird
bug free succotash
peppery sunny maggot
cautious waffle
```
    
- Part 2
    - Assuming you have loaded all of your words into an AVL tree and a Binary Search Tree (BST).
    - Read in all of your 10000 crazy words and lookup each portion of the word in the AVL and BST data structures.
    - Compare the performance of the BST and AVL trees by adding up the number of comparisons necessary to lookup each word component.
    - Load both data structures with the same order that the files are listed above.
    - Output will look like: 
        - BST Comparisons       = xxx
        - AVL Comparisons       = xxx
        - Number of Adjectives  = xxx 
        - Number of Adverbs     = xxx 
        - Number of Nouns       = xxx 
        - Number of Verbs       = xxx 

### Big Picture

1. Read each of the word files into some structure (possibly an array).
2. Build your crazy random words (with no repeats) and save them into `tenthousandwords.txt`
3. Load all of the word files into your `BSTree` and `AVLtree` in this order:
    - adjectives
    - adverbs
    - animals
    - nouns
    - animals
4. Make sure you don't load duplicates into either of your trees!!
4. The `adjectives` file should start with an `M` word. 
4. Open your `tenthousandwords.txt` and as you read in each crazy word:
    - look up each word component in the `BSTree` and `AVLtree` to count comparisons.
5. Output your results to screen and file.

### Deliverables

- Create a folder called `program_3` in your `assignments` folder.
- You will have an `AVLtree.h` and a `BSTree.h` in this folder as well (which I will provide and you will alter).
- Have a copy of the word files in here as well.
- Place part one of your solution in `generate_words.cpp`. 
- Place part ones output in a file called `tenthousandwords.txt` one crazy word per line with one space between words (like the above example).
- Place part two of your solution in `analyze_trees.cpp`. And a compiled version in `analyze_trees.exe`. If I run `analyze_trees.exe` from the command line I should be able to run it like: `analyze_trees.exe myinput.txt` and have it analyze my crazy words input file. 
- You should have the output for the analysis of your crazy words file in `analysis.out`
- The directory structure (not the order) of this project should mimic the following;

```
.
|__program_3
| |__generate_words.cpp
| |__BSTree.h
| |__tenthousandwords.txt
| |__word_files
| | |__nouns.txt
| | |__adverbs.txt
| | |__animals.txt
| | |__adjectives.txt
| | |__verbs.txt
| |__README.md
| |__analysis.out
| |__analyze_trees.exe
| |__analyze_trees.cpp
| |__AVLtree.h
```


