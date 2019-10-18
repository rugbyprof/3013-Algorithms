## Program 3 - Graphs
### Due: 28<sup>th</sup> of October

### Overview

Remember: https://repl.it/@rugbyprof/graphroads2019 (Almost a complete solution to this program).

Create a graph structure with cities as __Vertices__ and roads as __Edges__. We are creating a connected graph of cities so that every city is reachable. We are not following an existing road network, we are magically flying between cities. Make it so that every city will have a degree of ***D*** (*in/out degree*), where each edge connects one of ***D*** closest cities to that vertex.

You should make sure that you can adjust the degree using a command line parameter and not hard coding it. 

Included in the folder is a [cities.json](./cities.json) file with 1000 cities along with some data about each city. Your `Vertex` data type should hold all the information below.

```json
{
	"city": "Wichita Falls",
	"growth_from_2000_to_2013": 0.7,
	"latitude": 33.9137085,
	"longitude": -98.4933873,
	"population": 104898,
	"rank": 271,
	"state": "Texas"
}
```

Also included are the [JsonFacade.hpp](./JsonFacade.hpp) and [json.hpp](json.hpp) files. Using the json helper, you can read in the [cities.json](./cities.json) file just like our last project. 

Starting with the first city in the file ***C***<sub>*0*</sub>, find the ***D*** closest cities to ***C***<sub>*0*</sub> and create undirected edges between them: ***C***<sub>*0*</sub> => ***C***<sub>*i*</sub> and ***C***<sub>*i*</sub> => ***C***<sub>*0*</sub>.  Your edge type should store the `distance` (as well as  other pertinent information). Continue processing the rest of the cities ***C***<sub>*1*</sub> , ***C***<sub>*2*</sub>, ... ,***C***<sub>*n*</sub> adding edges until each city as ***D*** edges. 

Look out for pitfalls, like just because a city is close to another, you may not be able to connect them if it already has ***D*** edges. 

#### Finding Closest

You must use a Heap to find the closest cities. I've included a heap implementation thats templated and only requires you to push on a `struct*` that includes a `Priority` data member. You can calculate the distance using the `Haversine` formula in [Geo.hpp](Geo.hpp). 

### Deliverables

- Turn in a printed file with the first 10 and last 10 cities and who they are connected to. The order is based on where they are in the input file. 

```
0001 : New York 
    1) City A (distance)
	1) City B (distance)
	2) City C (distance)
0002 : Los Angeles
    1) City A (distance)
	2) City B (distance)
	3) City C (distance)
0003 : Chicago
    1) City A (distance)
	2) City B (distance)
	3) City C (distance)

	...

0997 : Beloit
    1) City A (distance)
	2) City B (distance)
	3) City C (distance)

0998 : Panama City
    1) City A (distance)
	2) City B (distance)
	3) City C (distance)
```

### Comments

**Example Top Comment Block for every file you wrote code in ...**

```cpp
///////////////////////////////////////////////////////////////////////////////
//
// Date:             28 October 2019
// Title:            Program 3 - Graphs
// Semester:         Spring 2018
// Course:           CMPS 3013 
// Assignment:       A05
// Author:           (your name)
// Email:            (your email address)
// Files:            (list of source files)
// Description:
//       describe program here thoroughly
//
/////////////////////////////////////////////////////////////////////////////////
```

**Example Function Comment Block**

```cpp
/**
 * Swap
 * 
 * Description:
 *      Swaps to values in thier original memory locations
 * 
 * Params:
 *      int *a : location 1 (the '*' accesses the location to get the value)
 *      int *b : locatoin 2
 * 
 * Returns:
 *      void
 */
void swap(int *a, int *b) {
    int temp = *a; // put first value in temp location
    *a = *b;       // overwrite location1 with value at location2
    *b = temp;     // overwrite location2 with value from temp
}
```

### Deliverables

- In `assignments` create a folder called `A05`
- In `A05` place your code in a file called `graph_builder.cpp`
- Any and ALL files used to run your code MUST be in your repo.
- Include any files that you wrote code in.
- Comment your code. 
- Turn in a printed copy of your source code (DO NOT PRINT FROM GITHUB!!). 
  - There IS a way to print source code from github, its a pain, but ask me in class to show you if your desperate.
- Staple your pages together at the top left (very close to the corner).
- No hand writing on your pages at all! 
- Top page should be your first source code page with a BIG comment block that explains the program and tells me who you are with date etc.

