## Assignment 5 - Processing in Linear Time
#### Due: 02-12-2020 (Wednesday @ 3:30 p.m.)

### Json

- Json is a text based storage mechanism that allows us to serialize data and write it to a file which can subsequently be read back into a digital form and get processed. 
- Json is based on key value pairs and has symbols (characters) which represent specific data types.
- For more info look [here](../../Resources/03-Json/README.md)


### Timing

- You need to track the run time of your code. 
- Check [this](../../Resources/05-Timing/README.md) out.

### Getching :)



### Overview

- Write a program that will read in a dictionary file from [here](dict_w_defs.json) and store it in a simple data structure like a vector or array. 
- We will subsequently perform a set of "lookups" and time the performance.
- Use the `Timer.hpp` class I've linked to.
- Also we need to capture keyboard input: 
  - https://stackoverflow.com/questions/421860/capture-characters-from-standard-input-without-waiting-for-enter-to-be-pressed
- I would like to time how long it takes to "find" any particular word.
- I want us to implement some auto suggestion mechanism. 