/**
 * This program reads dictionary_clean.txt into an array, then traverses it
 * as if its doing binary search so that it can create an output file that 
 * loads into a binary tree perfectly balanced.
 * 
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void binsearchTraversal(const vector<string> words,int left,int right,string direction=" "){
     
    int middle = (left+right) / 2;
    int lmiddle = middle-1;
    int rmiddle = middle+1;

    //cout<<left<<","<<middle<<","<<right<<","<<direction<<" :";
    cout<<words[middle]<<endl;

    // weird edge case
    if(left == middle && left == (right-1)){
        //cout<<right<<","<<right<<","<<right<<","<<direction<<" :";
        cout<<words[right]<<endl;
    }

    if(left == middle  || middle == right){
        return;
    }


    binsearchTraversal(words,left,lmiddle,"left"); 
    binsearchTraversal(words,rmiddle,right,"right");
}

void binsearchTraversalIterative(const vector<string> words){
    
}

int main(){

    ifstream fin("dictionary_clean.txt");
    //ifstream fin("animal_names_small.txt");
    vector <string> words;
    string word;

    ofstream fout("balanced_dict.txt");

    while(!fin.eof()){
        fin>>word;
        words.push_back(word);
    }

    // for(int i=0;i<words.size();i++){
    //     cout<<words[i]<<endl;
    // }

    binsearchTraversal(words,0,words.size()-1);
    return 0;
}
