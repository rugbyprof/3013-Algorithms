## Assignment 6 - Processing in Log time (or are we?)
#### Due: 02-24-2020 (Monday @ 3:30 p.m.)

### Necessary Files

| File               | Description                                                        | Location            |
| :----------------- | :----------------------------------------------------------------- | :------------------ |
| `dict_w_defs.json` | Json input file                                                    | Resources/04-Data   |
| `json.hpp`         | Json class written by [nlohmann](https://github.com/nlohmann/json) | Resources/03-Json   |
| `JsonFacade.hpp`   | Json helper class I wrote to assist with the `json.hpp` class      | Resources/03-Json   |
| `Timer.hpp`        | Timer helper class                                                 | Resources/05-Timing |
| `read_dict.cpp`    | Example json reader with some timing.                              | This folder         |

## Background

- Look [HERE](../05-P02/README.md) for background

## Assignment

### Requirements
- We are building on your linked list program from last time. 
- In this installation I want you to also read the [dict_w_defs.json](../../Resources/04-Data/dictionary_files/dict_w_defs.json) into an array (or vector) of `wordNodes`.
- Time how long it takes to load the data into your array (or vector) list.
- Time how long it takes to load the data into your linked list.
- Last program we searched a list linearly for each matching substring. This time I want you to also perform a **binary search** on your container array (or vector).
- Instead of printing out suggestions, I want you to compare the search times for each container. Does the linked list perform slower like you might think? 
- A binary search should be `O(lg n)` on a sorted list right?
- Look up the following substrings:

```
cur
col
she
hol
```


#### Output Example

- User types the word `ste` 
- Below the word the number of words found and the amount of time in seconds will be printed
- Only print out the first 10 words of the matching words
```
```



### Deliverables

- Create a folder called **P03** in your assignments folder. 
- **ALL** files used in this project should be in that folder.
- The only documents you need to print and turn in are:
  - Banner
  - Any source code YOU wrote (commented as directed [here](../../Resources/01-Comments/README.md))
  - 4 screen shots (fitted to one page)



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