## Assignment 6 - Spanning Trees 
### Due: Tuesday April 17th by Classtime.

#### Part 1

### Overview



Create a graph structure with cities as __Vertices__ and no __Edges__ initially. Fully connect your cities by adding edges between cities that are close together. Basically create a connected graph of all the cities so that every city is reachable by ensuring that each vertex has a max degree of 3, where each edge represents one of three closest cities to that vertex.

You should make sure that you can adjust the max degree using a parameter and not hard coding that solution. Next program we will use Dijkstras shortest path on the graphs created by this program.

I also included an adjacency list of US states. If you build your graphs by only looking at adjacent states, you will reduce the number of comparisons down by quite a lot. 

The input file of cities has the following format.

- zip, lat, lon , city , state , county
- 3301,30.326374,-97.771258,Austin,TX,Travis

Start your connecting process using `Lebanon, Kansas` as it is the center most city in the USA (to start with). The filtered file has one instance of each city so no need for filtering. Be able to change the starting city, becuase we will look at resulting graph stats by starting in:

- Lebanon, Kansas
- Miami, Florida
- Dallas, Texas
- Boston, Massachusetts
- San Juan, Puerto Rico (and staying in Puerto Rico)
- Portland, Oregon

### Deliverables

- You will turn in a printed file with the total distance and number of edges added for each of the starting points:

```
- Lebanon, Kansas 
    XXXX miles XXXX edges
- Miami, Florida
    XXXX miles XXXX edges
- Dallas, Texas
    XXXX miles XXXX edges
- Boston, Massachusetts
    XXXX miles XXXX edges
- San Juan, Puerto Rico (and staying in Puerto Rico)
    XXXX miles XXXX edges
```

- The above file will also be present in your repo.
- You will also turn in a graphviz picture of your Puerto Rico graph including edges and weights. http://www.webgraphviz.com/ should be able to handle it.
- Graphviz has a feature that allows you to somewhat dictate the position of a vertex. If we convert our lat/lon's to x/y's you might get better looking graphs.
    - https://stackoverflow.com/questions/5343899/how-to-force-node-position-x-and-y-in-graphviz
- All code will go in a folder on github as per previous assignments. This is `program_4`!
- Place the graph code I give you into a header file. 
- A README.md describing your project will also be present linking to each file.

```
.
|__assignments
| |__program_4
| | |__README.md
| | |__csv.h
| | |__main.cpp       // your graph code
| | |__distance.h
| | |__graph.h
| | |__filtered_cities.csv
```

