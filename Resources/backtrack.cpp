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
bool PlaceQueens(int**A,int col,int n){
    if(col >= n){
        return true;
    }
    for(int i=0;i<n;i++){
        
        if(isSafe(A,i,col,n)){
            A[i][col] = 1;
    
            if(PlaceQueens(A,col+1,n)){
                return true;
            }
            A[i][col] = 0;
        }
    }
    return false;
}

int main(int argc, char** argv){
    int n = 4;


    int** A = Make2DArray(n,n,0);

    Print2DArray(A,n,n);
    

    if(PlaceQueens(A,0,n)){
        Print2DArray(A,n,n);
    }


    return 0;
}

