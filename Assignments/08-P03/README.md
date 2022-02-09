## Program 3 - Processing in Trie Tree Time
#### Due: 03-03-2022 (Thursday @ 12:30 p.m.)

### Trie Time Lookup

- https://www.techiedelight.com/cpp-implementation-trie-data-structure/
  

### Necessary Files

- Same as [P02](../06-P02/README.md).

## Background

- Same as [P02](../06-P02/README.md).

## Assignment

Using a Trie (implementation of one is given [here](https://www.techiedelight.com/cpp-implementation-trie-data-structure/)) perform the same "auto suggestions" we did with the linked list data structure in P02. The goal of this project is to show the speed up that should be gained by choosing a proper data structure to solve the problem.  We used a linked list for the previous implementation, and now we are choosing to use a Trie which is designed for just the type of searching we are performing. 

### Requirements
- Write a program that will read in a dictionary file from [dict_w_defs.json](../../Resources/04-Data/dictionary_files/dict_w_defs.json) and store it in a **Trie Tree**.
- Trie's are implemented somewhat differently than our previous data structures. 
- Time how long it takes to load the data into your Trie tree.
- After your dictionary (Trie) is loaded, we are going to perform "autosuggestions" when a user types characters at the console.
- Suggestions will start after 1 character is typed, however only the top 10 suggestions will be printed along with the total number of matching words (example output below).
- The time it takes to find each suggestion will be displayed in seconds.


#### Output Example

- User types the word `ste` 
- Below the word the number of words found and the amount of time in seconds will be printed
- Only print out the first 10 words of the matching words


```
ste

62 words found in 0.013 seconds

stead steadfast steadfastly steadfastness steadied steadier steadies steadiest steadily steadiness

```


- User types the word `steel` 

```
steel

18 words found in 0.003 seconds

steel steele steeled steelers steeles steelhead steelie steelier steelies steeliness 

```

### Deliverables

- Create a folder called **P03** in your assignments folder. 
- **ALL** files used in this project should be in that folder.
- The only documents you need to print and turn in are:
  - Banner
  - Any source code YOU wrote (commented as directed [here](../../Resources/01-Comments/README.md))
  - 4 screen shots (fitted to one page)
  - If your banner is wrong: -1 letter grade. The banner is to keep your programs organized. Or I can stop taking late work ... 



#### Banner

```
P04
3013
LASTNAME
```

#### Example Screen Shot

- Of course your screens will differ slightly, however they should fit on one page
- Be readable and have four examples
- Also the text in my screenshots is small, try and make yours larger even if the words wrap

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/screen.png" width="500">