#include "termcolor.h" // color header file
#include <fstream>     // file output
#include <iostream>    // standard output
#include <map>         // stl map
#include <math.h>
#include <stdlib.h> // used for windows system("cls"); // clear screen
#include <string>
#include <unistd.h> // used for Griffins macbook clear screen
#include <vector>   // stl vector

using namespace std;

// Maze Walls
#define NSBARRIER "+--" // north south barrier for maze
#define NSOPEN "+  "    // north south opening
#define EWBARRIER "|  " // east west barrier
#define EWOPEN "   "    // east west opening

/**
 * A data type (struct) that only has arrows right now but 
 * other unicode characters could be added. 
 */
struct shapes {
    map< string, map<string, string> > arrows;
    shapes() {
        // BS = Big Solid Arrow
        arrows["BS"]["N"] = "\u25B2";
        arrows["BS"]["S"] = "\u25BC";
        arrows["BS"]["E"] = "\u25B6";
        arrows["BS"]["W"] = "\u25C0";

        // BH = Big Hollow Arrow
        arrows["BH"]["N"] = "\u21E7";
        arrows["BH"]["S"] = "\u21E9";
        arrows["BH"]["E"] = "\u21E8";
        arrows["BH"]["W"] = "\u21E6";

        // TA = Thin Arrow
        arrows["TA"]["N"] = "\u2191";
        arrows["TA"]["S"] = "\u2193";
        arrows["TA"]["E"] = "\u2192";
        arrows["TA"]["W"] = "\u2190";
    }
};

/**
 * Cell: Data type to represent one maze cell.
 *       In this type of maze representation, each cell contains its left wall and ceiling.
 *       It's neighboring cells will hold the right wall and floor.
 *       It is confusing, but prints out much more compactly on the standard screen.
 */
struct Cell {
    int row;          // what row cell is in
    int col;          // column of cell
    bool visited;     // has cell been visited
    bool north;
    bool south;
    bool east;
    bool west;
    string top;       // ceiling
    string left;      // left wall
    string character; // what (if anything) is in cell
    string color;     // color of cell (not working)
    Cell(int r = 0, int c = 0) {
        row = r;          // cells row
        col = c;          // cells column
        visited = false;  // True if cell marked as visited
        top = NSBARRIER;  // Top wall type
        left = EWBARRIER; // Left wall type
        character = " ";  // Unicode character to print if occupied (in a path)
        color = "green";
        north=false;
        south=false;
        east=false;
        west=false;
    }

    /**
     * Overloaded ostream operator:
     *      Allows for easy printing of cells
     * 
     * Old Way: 
     *     cout << "(" << c.row << "," << c.col << ",v:" << c.visited << ")";
     * New Way:
     *     cout << cellVar <<endl;
     */
    friend ostream &operator<<(ostream &output, const Cell &c) {
        output << "(" << c.row << "," << c.col << ",v:" << c.visited << ")";
        return output;
    }
};

/**
 * Maze:
 *    Represents a maze or 2D array of Cells
 * 
 */
class Maze {
protected:
    int height;                // height in rows
    int width;                 // width in columns
    Cell ***maze;              // 2D array of cell pointers
    vector<Cell *> move_stack; // Vector of cell pointers
    Cell *startCell;           // Entrance of maze
    Cell *exitCell;            // Exit of maze
    shapes S;                  // Shapes instance (arrows and such)

public:
    /**
     * Maze constructor
     * Params:
     *     int rows : height of maze
     *     int cols : width of maze
     */
    Maze(int rows = 16, int cols = 16, bool show_build = false) {
        height = rows; // num rows in maze
        width = cols;  // num cols in maze

        maze = new Cell **[rows]; // 2D list maze container

        // build 2D array to hold Cell pointers
        for (int i = 0; i < rows; i++) {
            maze[i] = new Cell *[width];
        }

        __init_maze();            // Creates new cells in our 2D array
        __build_maze(show_build); // Uses stack to randomly visit cells and knockdown walls
        __reset_maze();           // Mark all cells as not visited

        startCell = maze[0][0];                 // Mark entrance to maze
        exitCell = maze[height - 1][width - 1]; // Mark exit to maze
    }

    /**
     * Function: printMaze 
     *      Prints maze to screen
     * Returns: void 
     */
    void printMaze() {
        system("clear");   // works on my Mac windows is system("cls");
        string tops = "";  // string to hold tops of the cells
        string lefts = ""; // string to hold lefs of the cells

        // These loops build each "row" with the tops and lefts of the cells
        for (int r = 0; r < height; r++) {
            tops = "";
            lefts = "";
            for (int c = 0; c < width; c++) {
                cout << maze[r][c]->top << "-";
            }
            cout << "+" << endl;

            for (int c = 0; c < width; c++) {
                cout << maze[r][c]->left << termcolor::red << maze[r][c]->character << termcolor::green;
            }
            cout << "|" << endl;

            //Prints ONE row
            cout << tops;
            cout << lefts;
        }

        //Prints bottom of maze
        string bottom = "";
        for (int c = 0; c < width; c++) {
            bottom += NSBARRIER;
            bottom += "-";
        }
        cout << bottom << "+" << endl
             << endl;
    }

protected:
    /**
     * Function: __get_direction 
     *      Determines direction moved going from cell (r1,c1) => (r2,c2). Used to determine
     *      which wall to knock down when building the maze.
     * Returns: string 
     */
    string __get_direction(int r1, int c1, int r2, int c2) {

        if (r2 < r1)
            return "North";
        else if (c2 > c1)
            return "East";
        else if (r2 > r1)
            return "South";
        else if (c2 < c1)
            return "West";
        else
            return "";

        return "";
    }

    /**
     * Private Function: __build_maze 
     * 
     * Params: 
     * 
     *     bool pm : true = show building of maze
     *      
     * Returns: void 
     */
    void __build_maze(bool pm = false) {
        bool print_maze = pm;     // print the maze being built?
        Cell *current;            // current cell (top of stack)
        Cell *neighbor;           // neighbor of current (next move)
        vector<Cell *> moves;     // vector of cell pointers holds possible moves
        int neighbor_row;         // row of neighboring cell being looked at
        int neighbor_col;         // column of neighboring cell
        int rand_index;           // random num to pick random direction
        string d;                 // direction
        ofstream fout("log.txt"); // debugging file

        // Prime the move stack with the "first" move.
        move_stack.push_back(maze[rand() % height][rand() % width]);

        // While there are still cells to be visited:
        while (move_stack.size() > 0) {
            //Set current to top of stack (end of list)
            current = move_stack.back();

            //Write to output file (for debugging)
            fout << *current << endl;
            fout << move_stack.size() << endl;

            //Mark current as visited
            current->visited = 1;
            current->character = '.';

            // Get an array of possible moves from our current location.
            // Will hold from 0 - 4 neighbors
            moves = __unvisited_neighbors(current->row, current->col);

            // If there are any moves in our array:
            if (moves.size()) {
                // randomly choose a neighboring cell from moves array.
                rand_index = rand() % moves.size();
                neighbor_row = moves[rand_index]->row;
                neighbor_col = moves[rand_index]->col;

                //pull cell pointer out of array
                neighbor = moves[rand_index];

                // Set the cell to visited and change its color
                neighbor->visited = 1;
                neighbor->color = "red";
                neighbor->character = '.';

                // Determine what direction we moved to get from current => neighbor
                d = __get_direction(current->row, current->col, neighbor_row, neighbor_col);

                // We moved North so open up our ceiling
                if (d == "North") {
                    current->top = NSOPEN;
                    current->north = true;
                    current->character = S.arrows["TA"]["N"];

                    // We moved East so knock down neighbors left wall
                } else if (d == "East") {
                    neighbor->left = EWOPEN;
                    current->east = true;
                    current->character = S.arrows["TA"]["E"];

                    // We moved South so open up the neighbors ceiling
                } else if (d == "South") {
                    neighbor->top = NSOPEN;
                    current->character = S.arrows["TA"]["S"];
                    current->south = true;

                    // We moved West so knock down our own left wall
                } else if (d == "West") {
                    current->left = EWOPEN;
                    current->character = S.arrows["TA"]["W"];
                    current->west = true;
                }

                // Put neighber cell on top of stack
                move_stack.push_back(neighbor);
            } else {
                // No moves ... we need to backtrack!
                move_stack.pop_back();
            }
            if (print_maze) {
                usleep(30000);
                printMaze();
            }
        }
    }

    /**
     * __unvisited_neighbors:
     * 
     *       Creates a Vector of Cells that holds references to unvisited neighbors
     * Params:
     *     int row : target cell row 
     *     int col : target cell col
     * Returns:
     *     vector<Cell *> moves: vector of cell pointers (possible moves)
     */
    vector<Cell *> __unvisited_neighbors(int row, int col) {
        vector<Cell *> moves; // vector to put possible moves in

        if (__in_bounds(row - 1, col) && !maze[row - 1][col]->visited) {
            moves.push_back(maze[row - 1][col]);
        }
        if (__in_bounds(row, col + 1) && !maze[row][col + 1]->visited) {
            moves.push_back(maze[row][col + 1]);
        }
        if (__in_bounds(row + 1, col) && !maze[row + 1][col]->visited) {
            moves.push_back(maze[row + 1][col]);
        }
        if (__in_bounds(row, col - 1) && !maze[row][col - 1]->visited) {
            moves.push_back(maze[row][col - 1]);
        }

        return moves;
    }

    /**
     * __in_bounds
     *     Is a cell in bounds.
     * 
     * Params:
     *    int row : target cell row
     *    int col : target cell col
     * Returns:
     *    bool : true => in the maze / false => off the maze 
     */
    bool __in_bounds(int row, int col) {
        return (row < height && col < width) && (row >= 0 && col >= 0);
    }

    /**
     * __init_maze
     *     Loops height * width times creating new cells
     * 
     * Params:
     *    void
     * Returns:
     *    void
     */
    void __init_maze() {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                maze[i][j] = new Cell(i, j);
            }
        }
    }

    /**
     * __reset_maze
     *     Sets all characters to " " and visited to 0.
     * 
     * Params:
     *    void
     * Returns:
     *    void
     */
    void __reset_maze() {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                maze[i][j]->visited = 0;
                maze[i][j]->character = " ";
            }
        }
    }
};

class RandomSolver : public Maze {
private:
    /**
     * __unvisited_neighbors:
     * 
     *       Creates a Vector of Cells that holds references to unvisited neighbors
     * Params:
     *     int row : target cell row 
     *     int col : target cell col
     * Returns:
     *     vector<Cell *> moves: vector of cell pointers (possible moves)
     */
    vector<Cell *> __possible_moves(int row, int col) {
        vector<Cell *> moves; // vector to put possible moves in

        cout<<maze[row][col]->north<<" "<<maze[row][col]->south<<" "<<maze[row][col]->east<<" "<<maze[row][col]->west<<endl;
        
        if (maze[row][col]->north && __in_bounds(row - 1, col) && !maze[row - 1][col]->visited) {
            moves.push_back(maze[row - 1][col]);
            cout<<"up"<<endl;
        }

        if (maze[row][col]->west && __in_bounds(row, col - 1) && !maze[row][col - 1]->visited) {
            moves.push_back(maze[row][col - 1]);
            cout<<"left"<<endl;
        }

        if (maze[row][col]->south  && __in_bounds(row + 1, col)   && !maze[row + 1][col]->visited) {
            moves.push_back(maze[row + 1][col]);
            cout<<"down"<<endl;
        }

        if (maze[row][col]->east && __in_bounds(row, col + 1) && !maze[row][col + 1]->visited) {
            moves.push_back(maze[row][col + 1]);
            cout<<"up"<<endl;
        }

        return moves;
    }
public:
    RandomSolver(int rows = 16, int cols = 16, bool show = false) : Maze(rows, cols, show) {
    }



    void SolveIt() {
        Cell *current;            // current cell (top of stack)
        Cell *neighbor;           // neighbor of current (next move)
        vector<Cell *> moves;     // vector of cell pointers holds possible moves
        int neighbor_row;         // row of neighboring cell being looked at
        int neighbor_col;         // column of neighboring cell
        int rand_index;           // random num to pick random direction
        string d;                 // direction
        ofstream fout("log.txt"); // debugging file

        // Prime the move stack with the "first" move.
        move_stack.push_back(startCell);


        // While there are still cells to be visited:
        while (move_stack.size() > 0) {
            //Set current to top of stack (end of list)
            current = move_stack.back();

            //Mark current as visited
            current->visited = 1;
            current->character = '.';

            // Get an array of possible moves from our current location.
            // Will hold from 0 - 4 neighbors
            moves = __possible_moves(current->row, current->col);

            for(int i=0;i<moves.size();i++){
                cout<<moves[i]->row<<" "<<moves[i]->col<<endl;
            }

            exit(0);

            // If there are any moves in our array:
            if (moves.size()) {
                // randomly choose a neighboring cell from moves array.
                rand_index = rand() % moves.size();
                neighbor_row = moves[rand_index]->row;
                neighbor_col = moves[rand_index]->col;

                //pull cell pointer out of array
                neighbor = moves[rand_index];

                // Set the cell to visited and change its color
                neighbor->visited = 1;
                neighbor->color = "red";
                neighbor->character = '.';

                // Determine what direction we moved to get from current => neighbor
                d = __get_direction(current->row, current->col, neighbor_row, neighbor_col);

                // We moved North so open up our ceiling
                if (d == "North") {
                    current->top = NSOPEN;
                    current->character = S.arrows["TA"]["N"];

                    // We moved East so knock down neighbors left wall
                } else if (d == "East") {
                    neighbor->left = EWOPEN;
                    current->character = S.arrows["TA"]["E"];

                    // We moved South so open up the neighbors ceiling
                } else if (d == "South") {
                    neighbor->top = NSOPEN;
                    current->character = S.arrows["TA"]["S"];

                    // We moved West so knock down our own left wall
                } else if (d == "West") {
                    current->left = EWOPEN;
                    current->character = S.arrows["TA"]["W"];
                }

                // Put neighber cell on top of stack
                move_stack.push_back(neighbor);
            } else {
                // No moves ... we need to backtrack!
                move_stack.pop_back();
            }

            usleep(30000);
            printMaze();

        }
    }
};
