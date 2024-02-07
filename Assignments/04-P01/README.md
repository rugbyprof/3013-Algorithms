## Program 2 - AutoComplete in Linear Time
#### Due: 02-19-2023 (Monday @ 11:00 a.m.)

### Waste Of Time Lookup

I used to start this project with a linear time lookup container like a linked list. This time we will use a Json object and simply search the keys (words) in a websters dictionary data file I found. This project is about 1) learning about Json, and what its good for, and what its bad for. We won't be using it correctly, but we will still use it. 2) Creating our own `Algorithm` to find words in the Json object based on keys typed by a user.

This project is about loading a vector (array) with dictionary words, then timing how long it takes to look them up. We are doing this with the knowledge that this can still be improved upon even though it is O(lg n) search. We will use your code again for a subsequent program, so keep this in mind when designing your project 

### Necessary Files

| File               | Description                                        | Location                                       |
| :----------------- | :------------------------------------------------- | :--------------------------------------------- |
| `animal)names.txt` | Small list of animals (good test file)             | [data/animals.txt](./data/animals.txt)         |
| `dictionary.txt`   | Words only                                         | [data/dictionary.txt](./data/dictionary.txt)   |
| `dictionary.json`  | Words + definitions                                | [data/dictionary.json](./data/dictionary.json) |
| `main.cpp`         | Example driver that reads in words and uses getch. | [./main.cpp](./main.cpp)                       |
| `my_getch.cpp`     | Get character, without printing it .               | [./mygetch.hpp](./mygetch.hpp)                 |
| `timer.hpp`        | Timer helper class                                 | [./timer.hpp](./timer.hpp)                     |
| `termcolor.hpp`    | Class to color text                                | [termcolor.hpp](termcolor.hpp)                 |

## Background

### JSON

Read [this about json](../../Lectures/LectureMaterials/16-Json/README.md) from the [Lecture Materials](../../Lectures/LectureMaterials/README.md) section.

### Timing

- Timing becomes important when you want to benchmark how fast code is running.
- There are many things that effect run times, so you should try to run your code with the same conditions (like the same machine) as much as possible.
- The library here will give us milli-second granularity. So go look at the example code.
- Check [timer.hpp](./heades/timer.hpp) out in the header folder. 
- The example program[main.cpp](main.cpp) shows some usage as well.

### Getching :)

- Getch: a word that implies the capture of keyboard input, with hitting the enter key and optionally not even reflecting on the console that anything happened.
- This is obvious with games, since not all key strokes imply an attempt to type, they may be trying to control movement or communication in other ways.
- The function here provides a `getch` function for both windows or linux / osx.  
- See example [main.cpp](main.cpp) here in this folder. It just needs a little tweaking.

## Assignment

### Requirements
- Write a program that will read in a dictionary file from [dictionary.json](./data/dictionary.json) and store it in a **json object** .
- The loaded json object will work just like a dictionary.
- The linked list should hold `wordNodes`.
- Time how long it takes to load the data into your linked list (we will use that later as well).
- After your dictionary (linked list) is loaded, we are going to perform "autosuggestions" when a user types characters at the console.
- Suggestions will start after 1 character is typed, however only the top 10 suggestions will be printed along with the total number of matching words (example output below).
- Matching suggestions will ONLY be words that match the substring starting from position zero. For example: `cat` would match `cat`, `caterpillar`, and `cattle`. But NOT `wildcat`.
- My example on repl.it matches every word that matches the substring no matter the position.
- As typing, the time it takes to find suggestions will be displayed in seconds. Like: `0.0000554310000000019` seconds.
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