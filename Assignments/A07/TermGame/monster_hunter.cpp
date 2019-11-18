#include "TermGame.h"
#include <iostream>
#include <string>
using namespace std;
namespace TG = TermGame;
namespace TP = TermPrint;

int rows = 30;
int cols = 50;

struct Player {
    string ch;
    unsigned short foreground;
    unsigned short background;
    Player() {
        foreground = 8;
        background = 1;
        ch = "  ";
    }
    Player(string c) {
        foreground = 8;
        background = 1;
        ch = c;
    }
    Player(string c, unsigned short fore, unsigned short back = 1) {
        foreground = fore;
        background = back;
        ch = c;
    }
    void SetColor(unsigned short fore, unsigned short back = 1) {
        foreground = fore;
        background = back;
    }
    void Print() {
        TP::print(ch, foreground, background);
    }
};

struct Cell {
    int row;
    int col;
    Player *pl;
    bool wall;
    string ch;
    Cell() {
        col = 0;
        row = 0;
        pl = NULL;
        ch = ". ";
        wall = false;
    }
    Cell(int r, int c) {
        col = c;
        row = r;
        pl = NULL;
        ch = ". ";
        wall = false;
    }
    Cell(int r, int c, Player *p) {
        col = c;
        row = r;
        pl = p;
        ch = ". ";
        wall = false;
    }

    void PrintCell() {
        if (pl) {
            pl->Print();
        } else {
            TP::print(ch, 8, 1, false);
        }
    }

    Player *GetPlayer() {
        Player *temp = pl;
        pl = NULL;
        return temp;
    }

    void SetPlayer(Player *p) {
        pl = p;
    }

    void MakeWall(){
        wall = true;
        ch = "🔳";
    }
};

void printBoard(Cell ***gb, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {

            gb[i][j]->PrintCell();
        }
        cout << endl;
    }
}

Cell ***BuildBoard(int rows, int cols) {
    Cell ***GameBoard;
    Player *temp;
    GameBoard = new Cell **[rows];
    for (int i = 0; i < rows; i++) {
        GameBoard[i] = new Cell *[cols];
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            GameBoard[i][j] = new Cell(i, j);
        }
    }
    return GameBoard;
}

bool OnBoard(int x, int y) {
    return x >= 0 && x < cols && y >= 0 && y < rows;
}

//🧞 🧞‍♀️ 🧞‍♂️🔥

int main() {

    int r = rand() % rows;
    int c = rand() % cols;
    Player *temp;

    Cell ***GameBoard = BuildBoard(rows, cols);

    for(int i=5;i<15;i++){
        GameBoard[10][i]->MakeWall();
    }


    GameBoard[r][c]->SetPlayer(new Player("🤺", 2, 1));

    GameBoard[rand()%rows][rand()%cols]->SetPlayer(new Player("🦖", 2, 1));
    

    while (true) {
        TP::clear();

        temp = GameBoard[r][c]->GetPlayer();

        if (rand() % 2 == 0) {
            if (rand() % 2 == 0) {
                ++c;
            } else {
                --c;
            }

        } else {
            if (rand() % 2 == 1) {
                ++r;
            } else {
                --r;
            }
        }
        if(!OnBoard(c,r)){
            r=rand()%rows;
            c=rand()%cols;
        }

        GameBoard[r][c]->SetPlayer(temp);
        printBoard(GameBoard, rows, cols);
        TG::sleep(100);
    }
    return 0;
}