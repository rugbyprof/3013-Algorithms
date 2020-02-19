# ON HOLD
## Assignment 6 - Processing in Log time (or are we?)
#### Due: 02-26-2020 (Wednesday @ 3:30 p.m.)

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
- The list of keys you will lookup is in [lookups.txt](lookups.txt)
- You will read one of the keys, then search for all matching words in your list, and in your array (or vector).
- You need to time how long it takes to find all matches separately between each list and the array. 
- Write your output to the screen and to a file (`output.dat`)


#### Output Example

```
Joe Smith
Program 3

Key         List        Array
=============================
steel       0.013       0.013
cur         0.013       0.013 
...
...
AVERAGE     0.000       0.00      
```


### Deliverables

- Create a folder called **P04** in your assignments folder. 
- **ALL** files used in this project should be in that folder.
- The only documents you need to print and turn in are:
  - Banner
  - Any source code YOU wrote (commented as directed [here](../../Resources/01-Comments/README.md))
  - Your `output.dat` file



#### Banner

```
P04
3013
LASTNAME
```
