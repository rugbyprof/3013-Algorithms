/**
 * Binary Search Tree Example
 * Date: 28 January 2021
 * 
 */
#include "Bst.hpp" // Bring in our BST
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

/**
 * @brief  Shuffles an array to randomize it.
 *  
 * @param  *A: 
 * @param  size: 
 * @param  shuffles: 
 * @retval None
 */
void Shuffle(string *A, int size, int shuffles = 1) {
    string temp;
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
    Bst<string> Tree;
    ifstream fin("dictionary_balanced.txt");

    std::vector<string> myvector;
    string word;

    // // set some values:
    // for (int i = 0; i <= 1000; i+= 10){
    //     if(i==500){
    //         continue;
    //     }
    //     myvector.push_back(i); 
    // }

    double i = 0.0;
    while(!fin.eof()){
        fin>>word;
        cout<<word<<" ";
        Tree.Insert(word);
        if((int)i%1000 == 0){
            cout<<(i/128325.0)<<endl;
        }
        i += 1.0;
    }

    // using built-in random generator:
    // std::random_shuffle(myvector.begin(), myvector.end());

    // std::random_shuffle ( myvector.begin(), myvector.end(), myrandom);

    //Tree.Insert(500);

    // for (std::vector<string>::iterator it=myvector.begin(); it!=myvector.end(); ++it){
    //     Tree.Insert(*it);
    // }
    
    // Tree.Print();

    // cout << Tree.Find("duck") << endl;
    // cout << endl;
    Tree.BuildGraphViz();
    Tree.PrintGraphViz();
}