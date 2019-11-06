#include <iostream>
#include "maze.hpp"

using namespace std;

int main() {
    srand(time(0));
    // Maze M(10, 40);

    // M.printMaze();

    RandomSolver RS(10,40,false);

    RS.printMaze();
    RS.SolveIt();

}