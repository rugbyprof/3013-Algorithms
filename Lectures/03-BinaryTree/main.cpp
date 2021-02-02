/**
 * Binary Search Tree Example
 * Date: 28 January 2021
 * 
 */
#include "Bst.h" // Bring in our BST
#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief  Shuffles an array to randomize it.
 *  
 * @param  *A: 
 * @param  size: 
 * @param  shuffles: 
 * @retval None
 */
void Shuffle(int *A, int size, int shuffles = 1) {
    int temp;
    int i, j;
    for (int s = 0; s < shuffles; s++) {
        for (int k = 0; k < size; k++) {
            i = rand() % size;
            j = rand() % size;
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
}
int myrandom (int i) { return std::rand()%i;}

int main() {
    Bst Tree;

    std::vector<int> myvector;

    // set some values:
    for (int i = 0; i <= 1000; i+= 10){
        if(i==500){
            continue;
        }
        myvector.push_back(i); 
    }

    // using built-in random generator:
    std::random_shuffle(myvector.begin(), myvector.end());

    std::random_shuffle ( myvector.begin(), myvector.end(), myrandom);

    Tree.Insert(500);

    for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it){
        Tree.Insert(*it);
    }
    
    Tree.Print();

    cout << Tree.Find(81) << endl;
    cout << endl;
    Tree.BuildGraphViz();
    Tree.PrintGraphViz();
}