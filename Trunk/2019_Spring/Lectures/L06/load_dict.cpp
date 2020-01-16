#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

// word node for tree
// not used in this sample
struct word
{
    string data;
    string type;
    // constructor 1, no inputs
    word()
    {
        data = "";
        type = "";
    }
    // constructor 2, word and type
    word(string w, string t)
    {
        data = w;
        type = t;
    }
};

// main driver to read in values
int main(int argc, char **argv)
{
    // declare stl map
    map<string, string> wl;

    // create an iterator to loop over your <string:string> container
    map<string, string>::iterator it;

    // vars to hold words
    string key;
    string word;
    string value;

    // file pointer
    ifstream fin;

    // count command line args and make sure 
    // a file name is on the line to run this file
    if(argc<2){
        cout<<"You need an input file!\n";
        cout<<"Usage: stlmap filename.txt";
        exit(0);
    }

    // open file from command line
    fin.open(argv[1]);

    // read words into stlmap ensuring there are no dups
    while (!fin.eof())
    {
        fin >> word;
        if (wl.find(word) == wl.end())
        {
            wl[word] = "animal";
        }
    }

    // loop over stl map and print out key value
    for (it = wl.begin(); it != wl.end(); it++)
    {
        key = it->first;        // first = array index 
        value = it->second;     // second = array value pointed to by index
        cout << key << "->" << value << endl;
    }

    return 0;
}
