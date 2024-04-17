## Linear Search - Using Json and Getch
#### Due: 03-06-2024 (Wed @ 2:00 p.m.)

### Get Running

Get a combination of [main.cpp](./main.cpp) running but with it using a json object that loads all the dictionary words from [dictionary.json](./data/dictionary.json). Currently [main.cpp](./main.cpp) loads [animals_small.txt](./data/animals_small.txt) as an example on how the program works. It will show suggested words after you type a character into the terminal. It matches to any location within the word: from, middle, end. 

The program [loadJsonEx.cpp](./loadJsonEx.cpp) does load the [dictionary.json](./data/dictionary.json) into a searchable data structure, and searches for the word `axal` by default. 

This assignment will be a simple example of doing a linear search in a json object, but when it finds partial matches of a substring in a word, it prints it out (with color!).


### Files

| File               | Description                                        | Location                                       |
| :----------------- | :------------------------------------------------- | :--------------------------------------------- |
| `animal_names.txt` | Small list of animals (good test file)             | [data/animals.txt](./data/animals.txt)         |
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
- Write a program that will combine the two files: `main.cpp` and `loadJsonEx.cpp` so that `main.cpp` uses the dictionary to look for partial matches in. 
- Time how long it takes to load the data into the json object initially. 
- After your dictionary is loaded, we are going to perform "autosuggestions" when a user types characters at the console.
- Suggestions will start after 1 character is typed, however only the top 10 suggestions will be printed along with the total number of matching words (example output below).
- Matching suggestions will ONLY be words that match the substring starting from position zero. For example: `cat` would match `cat`, `caterpillar`, and `cattle`. But **NOT** `wildcat`.
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
- Any source code YOU wrote (commented as directed [here](../../Resources/01-Comments/README.md))
- 4 screen shots showing your program searching for words (example output above)
