## Program 2 - Processing in Log Time
#### Due: 03-02-2020 (Tuesday @ 12:30 p.m.)


### Log Time Lookup

This project is about loading a Binary Search Tree with dictionary words, then timing how it takes to look them up. We want to compare this with how long it took to look items up in the linked list from last program. For now we will keep the same interface for the previous program. But again, keep in mind that eventually we will need each of your working backends to write a program that compares all the lookup times. But this installment will use a Binary Search Tree.

### Necessary Files

- Same as [P02](../06-P02/README.md).

## Background

- Same as [P02](../06-P02/README.md).

## Assignment

### Requirements
- Write a program that will read in a dictionary file from [dict_w_defs.json](../../Resources/04-Data/dictionary_files/dict_w_defs.json) and store it in a **Binary Search Tree**.
- Define a `wordNode` to be a struct or a class to hold a `word` and `definition`.
- The binary tree should hold `wordNodes`.
- Time how long it takes to load the data into your binary search tree (we will use that later as well).
- After your dictionary (tree) is loaded, we are going to perform "autosuggestions" when a user types characters at the console.
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
P03
3013
LASTNAME
```

#### Example Screen Shot

- Of course your screens will differ slightly, however they should fit on one page
- Be readable and have four examples
- Also the text in my screenshots is small, try and make yours larger even if the words wrap

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/screen.png" width="500">