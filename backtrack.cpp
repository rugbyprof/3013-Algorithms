#include <iostream>

using namespace std;

int** Make2DArray(int rows,int cols,int init_val=0){
    int** Array;

    Array = new int*[rows];

    for(int i=0;i<rows;i++){
        Array[i] = new int[cols];
        for(int j=0;j<cols;j++){
            Array[i][j] = init_val;
        }
    }
    return Array;
}

void Print2DArray(int** A, int rows,int cols){

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<A[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<endl;
    return;
}

/**
 * 
 * Params:
 *     int** A  : 2d array
 *     int row  : which row
 *     int col  : which rol
 *     int n    : sizeof 2d array (nxn)
 * 
 */
bool isSafe(int** A, int row, int col, int n) 
{ 
    int i, j; 
  
    /* Check this row on left side */
    for (i = 0; i < col; i++) 
        if (A[row][i]) 
            return false; 
  
    /* Check upper diagonal on left side */
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) 
        if (A[i][j]) 
            return false; 
  
    /* Check lower diagonal on left side */
    for (i = row, j = col; j >= 0 && i < n; i++, j--) 
        if (A[i][j]) 
            return false; 
  
    return true; 
}

/**
 * Params:
 *     int** A : 2d array
 *     int r   : row
 *     int n   : nxn size of array
 * 
 */
void PlaceQueens(int**A,int r, int n){
    if(r == (n + 1)){
        Print2DArray(A,n,n);
        return;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<r-1;j++){
            if(isSafe(A,i,j,n)){
                A[i][j] = 1;
            }
        }
        PlaceQueens(A,r+1,n);
    }
}

int main(int argc, char** argv){
    int rows = 4;
    int cols = 4;


    int** A = Make2DArray(rows,cols,0);

    Print2DArray(A,rows,cols);
    

    PlaceQueens(A,0,4);


    return 0;
}

