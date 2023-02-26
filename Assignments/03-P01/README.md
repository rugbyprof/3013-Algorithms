## Assignment 1 - Database Indexes ... What?!?
#### Due: 02-24-2023 (Friday @ 10:00 a.m.)

### Overview

- Using `random_person_data` we created using `Mockaroo`, build 1 or more data structure(s) that can be searched using specified keys in the random data. 
- Your search should happen in `O(lg n)` time. 
- Since we really only discussed binary trees, I'm providing you with an [AVL](avlTree.hpp) implementation to help. 
- As we discussed, comparing the speed of each algorithm matters, so here is a linked list class that loads a `csv` file into the list. This should be helpful.
- Since we want to time our querys, there is a timing lib in resources [here](../../Resources/05-Timing/Timer.hpp)
- I took the data out of our repo as it got very big, but I have linked to all the data files at the bottom of this doc.  
  

### Main Idea

The main idea is to be able to search for values in `O(lg n)` time regardless of which key we are comparing the search key to. This means we need to implement "indexes" (search trees) based on each key. You don't have to do all the keys, but at least 8 of them. Below is the code we discussed in class to help you create and manage more than a single bst. 

```cpp
/**
 * Fake BST implementation so code will compile.
 * There is an avlTree.hpp in this folder for you to use
 */
class BST{
public:
  BST(){}
  BST(string key){}
};


/**
 * A Bst or Avl tree manager class that will let you create 
 * and use multiple binary trees.
 */
class TreeManager{

    map <string,Avl*> manager;  // stl map of binary trees accessed by the 
                                // key the tree is sorted by
    /**
     * Add a binary tree and sort it based on key passed in.
     */
    void addTree(string key){
        manager[key] = new Avl(key);
    }
public:
    /**
     * A search method would need the key to access the map of trees
     * in order to search the correct tree, and a key to actually search for.
     */
    string search(string treeKey,string searchKey){
        //stuff
    }
    
};

int main() {
  vector<Avl*> treeManager;                     // make a tree manager
  string searchKey = "fname";                   // which key to order on
  treeManager.push_back(new Avl(searchKey));    // make the tree and push it on the treeManager

  // obviously lots of stuff will be going on in these methds! But this is just an idea of 
  // how to organize.
}
```

### Sample Searches


https://replit.com/@rugbyprof/3013P01Something#main.cpp

```
Searching for "Park" in Avl tree by key: `address` ...
Compared "Park" to 235 nodes ... 
Found in 0.023 seconds

Searching for "Park" in Linked List by key: `address` ...
Compared "Park" to 566 nodes ... 
Found in 2.023 seconds


Plus at least one search per additional key in an Avl tree and Linked List...


```

### Data Definition:

The data is stored as json (key value pairs) in the following format and is available on the cs server here: https://cs.msutexas.edu/~griffin/data/ in the `3013_random_data` folder


#### Json Example: 

```json
"id": 18,
"first_name": "Coop",
"last_name": "Harby",
"email": "charbyh@blogs.com",
"address": "81274 Dennis Center",
"city": "Birmingham",
"state": "AL",
"latitude": 33.5225,
"longitude": -86.8094,
"car": "Mercury",
"car_model": "Milan",
"car_color": "Pink",
"favorite_movie": "Crazies, The",
"pet": "Peccary, collared",
"job_title": "Staff Accountant I",
"phone_number": "(205) 1085531",
"stocks": {
    "stock1": "GILT",
    "stock2": "CLNE",
    "stock3": "AB",
    "stock4": "PNQI",
    "stock5": "BSE",
    "stock6": "SJW",
    "stock7": "ALL"
}
```

When storing the data, mostly they are be strings, but there are a few that are integers or doubles: 

```cpp
int id
string first_name
string last_name
string email
string address
string city
string state
double latitude
double longitude
string car
string car_model
string car_color
string pet
string job_title
string phone_number
vector <string> stocks
```


### Downloads

- To obtain the data, I have placed multiple files on the CS server so you can download files 1 at a time, or all at once.
- Remember, to test your code, you do not need ALL the data. You only need enough to ensure your code is running correctly.


#### Data File Descriptions

- There is a small data file that has 1000 rows of data originally created in class.
- There are 10 more files with 100,000 records each totalling 1 million
records. You can download 1 at a time or all of them using the zip file.
- The zip file has all files from 01-10 (1 million records) for download as well.

|       | File                                                                                                             | Size |
| :---: | :--------------------------------------------------------------------------------------------------------------- | ---: |
| Small | [random_person_data_small](https://cs.msutexas.edu/~griffin/data/3013_random_data/random_person_data_small.json) | 492K |
|  01   | [random_person_data_01](https://cs.msutexas.edu/~griffin/data/3013_random_data/random_person_data_01.json)       |  45M |
|  02   | [random_person_data_02](https://cs.msutexas.edu/~griffin/data/3013_random_data/random_person_data_02.json)       |  45M |
|  03   | [random_person_data_03](https://cs.msutexas.edu/~griffin/data/3013_random_data/random_person_data_03.json)       |  45M |
|  04   | [random_person_data_04](https://cs.msutexas.edu/~griffin/data/3013_random_data/random_person_data_04.json)       |  45M |
|  05   | [random_person_data_05](https://cs.msutexas.edu/~griffin/data/3013_random_data/random_person_data_05.json)       |  45M |
|  06   | [random_person_data_06](https://cs.msutexas.edu/~griffin/data/3013_random_data/random_person_data_06.json)       |  45M |
|  07   | [random_person_data_07](https://cs.msutexas.edu/~griffin/data/3013_random_data/random_person_data_07.json)       |  45M |
|  08   | [random_person_data_08](https://cs.msutexas.edu/~griffin/data/3013_random_data/random_person_data_08.json)       |  45M |
|  09   | [random_person_data_09](https://cs.msutexas.edu/~griffin/data/3013_random_data/random_person_data_09.json)       |  45M |
|  10   | [random_person_data_10](https://cs.msutexas.edu/~griffin/data/3013_random_data/random_person_data_10.json)       |  45M |
|  All  | [random_person_data_all](https://cs.msutexas.edu/~griffin/data/3013_random_data/random_person_data.zip)          | 138M |


### Note: 
Most of these data elements are easily sorted and made searchable. The one pair of values that would give us trouble knowing what we know up to now are the two doubles representing latitude and longitude. Think for a minute how you would try to search using a pair of GPS coordinates :) I added a paper to this folder if your interested in reading about the [first data structure](R-Tree-Guttman.pdf) created for spatial values (points, lines, polygons)!



## Deliverables

- Make a folder called P01 in your assignments folder.
- Add all of your source code to this folder. 
- Output file or screen dump.
- Don't forget your banner.
- README.md with an explanation of your approach to the problem
