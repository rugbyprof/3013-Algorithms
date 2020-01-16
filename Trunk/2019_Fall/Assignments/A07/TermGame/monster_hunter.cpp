#include "TermGame.h"
#include <iostream>
#include <string>
using namespace std;
namespace TG = TermGame;
namespace TP = TermPrint;

int rows = 30;
int cols = 50;

struct Point {
    int x;
    int y;
    Point(){
        x=0;
        y=0;
    }
    Point(int _x, int _y) {
        x = _x;
        y = _y;
    }
};

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

    void MakeWall() {
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

bool OnBoard(Point p) {
    return p.x >= 0 && p.x < cols && p.y >= 0 && p.y < rows;
}


void Move(Point &p) {
    if (rand() % 2 == 0) {
        if (rand() % 2 == 0) {
            ++p.x;
        } else {
            --p.x;
        }

    } else {
        if (rand() % 2 == 1) {
            ++p.y;
        } else {
            --p.y;
        }
    }

    if (!OnBoard(p)) {
        p.y = rand() % rows;
        p.x = rand() % cols;
    }

}

double Distance(Point p1, Point p2) {
    int dx{p1.x - p2.x};
    int dy{p1.y - p2.y};
    return dx * dx + dy * dy;
}

//🧞 🧞‍♀️ 🧞‍♂️🔥

int main() {

    int r1 = rand() % rows;
    int c1 = rand() % cols;
    int r2 = rand() % rows;
    int c2 = rand() % cols;

    Point p1(rand()%cols,rand()%rows);
    Point p2(rand()%cols,rand()%rows);
    Point tp;

    Player *temp1;
    Player *temp2;

    double dist_prev = 0.0;
    double dist_next = 0.0;

    Cell ***GameBoard = BuildBoard(rows, cols);

    for (int i = 5; i < 15; i++) {
        GameBoard[10][i]->MakeWall();
    }

    GameBoard[p1.y][p1.x]->SetPlayer(new Player("🤺", 2, 1));

    GameBoard[p2.y][p2.x]->SetPlayer(new Player("🦖", 2, 1));

    dist_prev = Distance(p1,p2);

    while (true) {
        TP::clear();

        temp1 = GameBoard[p1.y][p1.x]->GetPlayer();

        dist_next = Distance(p1,p2);
        while(dist_next >= dist_prev){
            Move(p1);
            dist_next = Distance(p1,p2);
        }
        dist_prev = dist_next;

        GameBoard[p1.y][p1.x]->SetPlayer(temp1);


        if(p1.x==p2.x && p1.y==p2.y){
            temp2 = GameBoard[p2.y][p2.x]->GetPlayer();
            temp2->ch = "🦖";
            p2.x = rand()%cols;
            p2.y = rand()%rows;
            GameBoard[p2.y][p2.x]->SetPlayer(temp2);
            temp1->ch = "🤺";
            dist_next = dist_prev =0;
        }

        printBoard(GameBoard, rows, cols);
        TG::sleep(100);
    }
    return 0;
}