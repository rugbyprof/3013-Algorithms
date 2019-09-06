#include <iostream>

using namespace std;

void genDyn2dArray(int **A,int rows,int cols){
    A = new int*[rows];

    for(int i=0;i<rows;i++){
        A[i] = new int[cols];
    }

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            A[i][j] = rand()%100;
        }
    }
}

void print2DArray(int **A, int rows, int cols){
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(int argc, char** argv){

    cout<<argc<<endl;

    int **Array;

    genDyn2dArray(Array,30,30);
    //print2DArray(Array,30,30);

    return 0;
}