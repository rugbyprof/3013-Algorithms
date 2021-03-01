## Program 2 - Processing in Linear Time
#### Due: 03-04-2021 (Thursday @ 12:30 p.m.)


### Linear Time Lookup

This project is about loading a singly linked list with dictionary words, then timing how it takes to look them up. We are doing this with the knowledge that this is slow, and we plan on applying our "lookup" code to other backend data structures with better performance. So, keep this in mind when designing your program. 

### Necessary Files

| File             | Description                                        | Location    |
| :--------------- | :------------------------------------------------- | :---------- |
| `dictionary.txt` | Words ... lots of words.                           | This Folder |
| `main.cpp`       | Example driver that reads in words and uses getch. | This Folder |
| `my_getch.cpp`   | Get character, without printing it .               | This folder |
| `timer.hpp`      | Timer helper class                                 | This Folder |
| `termcolor.hpp`  | Class to color text                                | This Folder |

## Background

### ~~Json~~

- ~~For this project,  we are going to use `Javascript Object Notation` or **JSON** as our input data format.~~
- ~~JSON is probably an expected line on your resume, and used everywhere in industry as a platform independent data exchange format.~~  
- ~~For a quick intro look [here](../../Resources/03-Json/README.md)~~
- ~~I will also provide some example code that reads in a json file with this assignment.~~
- ~~I wrote my JsonFacade class (which is a wrapper around `json.hpp`) to simplify the functionality of [nlohmann](https://github.com/nlohmann/json)s class. He did a great job and I'm trying to filter only what we need. Therefore I would appreciate lots of feedback on how to make it better and or simpler.~~  

### Timing

- Timing becomes important when you want to benchmark how fast code is running.
- There are many things that effect run times, so you should try to run your code with the same conditions (like the same machine) as much as possible.
- The library here will give us milli-second granularity. So go look at the example code.
- Check [timer.hpp](timer.hpp) out in this folder. 
- The example program[main.cpp](main.cpp) shows some usage.

### Getching :)

- Getch: a word that implies the capture of keyboard input, with hitting the enter key and optionally not even reflecting on the console that anything happened.
- This is obvious with games, since not all key strokes imply an attempt to type, they may be trying to control movement or communication in other ways.
- The function here provides a `getch` function for both windows or linux / osx.  
- See example [main.cpp](main.cpp) here in this folder. It just needs a little tweaking.

## Assignment

### Requirements
- Write a program that will read in a dictionary file from [dictionary.txt](dictionary.txt) and store it in a **linked list**.
- Define a `wordNode` to be a struct or a class to hold a `word`. Definitions might come later. Then the `json` library will be very handy!
- The linked list should hold `wordNodes`.
- Time how long it takes to load the data into your linked list (we will use that later as well).
- After your dictionary (linked list) is loaded, we are going to perform "autosuggestions" when a user types characters at the console.
- Suggestions will start after 1 character is typed, however only the top 10 suggestions will be printed along with the total number of matching words (example output below).
- Matching suggestions will ONLY be words that match the substring starting from position zero. For example: `cat` would match `cat`, `caterpillar`, and `cattle`. But NOT `wildcat`.
- As typing, the time it takes to find suggestions will be displayed in seconds.
- In addition I have included a file to help color text. Docs are here: https://termcolor.readthedocs.io/ but I included some examples in [main.cpp](main.cpp).


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

- Create a folder called **P02** in your assignments folder. 
- **ALL** files used in this project should be in that folder.
- The only documents you need to print and turn in are:
  - Banner
  - Any source code YOU wrote (commented as directed [here](../../Resources/01-Comments/README.md))
  - 4 screen shots (fitted to one page)
  - If your banner is wrong: -1 letter grade. The banner is to keep your programs organized. Or I can stop taking late work ...


#### Banner

```
P02
3013
LASTNAME
```

#### Example Screen Shot

- Of course your screens will differ slightly, however they should fit on one page
- Be readable and have four examples
- Also the text in my screenshots is small, try and make yours larger even if the words wrap

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/screen.png" width="500">