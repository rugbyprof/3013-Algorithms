#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

typedef map<string, int> wordmap;
typedef map<string, wordmap> listmap;
typedef wordmap::iterator wit;
typedef listmap::iterator lit;

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

class crazyWords
{
  private:
    char **files; // holds the names of the files
    int numFiles; // number of files read in

    listmap *wordLists; // key = filename -> value = list of words

  public:
    crazyWords(char **in_files, int num_files)
    {
        srand(time(0));
        numFiles = num_files;

        if (numFiles)
        {
            // allocate memory for wordlists
            wordLists = new listmap;

            //
            files = new char *[numFiles];

            for (int i = 1, j = 0; i <= numFiles; i++, j++)
            {
                // create array big enough for filename
                files[j] = new char[strlen(in_files[i]) + 1];

                //assign filename
                files[j] = in_files[i];
            }
        }
        else
        {
            files = NULL;
        }
    }

    void loadWords()
    {
        ifstream fin; // file pointer
        string word;  // holds word from file

        for (int i = 0; i < numFiles; i++)
        {

            fin.open(files[i]);
            while (!fin.eof())
            {
                // read word in
                fin >> word;
                // see if word exists in map yet
                if (wordLists->find(word) == wordLists->end())
                {
                    (*wordLists)[files[i]][word] = 0;
                }
            }
            fin.clear();
            fin.close();
        }
    }

    void printWords(string filename = "")
    {
        if (filename == "")
        {
            for (int i = 0; i < numFiles; i++)
            {
                _printWords(files[i]);
            }
        }
        else
        {
            _printWords(filename);
        }
    }

    void _printWords(string filename)
    {
        string key;   // key value pair from map
        string value; // ditto
        wit it;       // wordMap iterato
        for (it = (*wordLists)[filename].begin(); it != (*wordLists)[filename].end(); it++)
        {
            key = it->first;    // first = array index
            value = it->second; // second = array value pointed to by index
            cout << key << "->" << value << endl;
        }
    }

    void printWordCounts()
    {
        string fileName; // key value pair from map
        int wordCount;   // ditto
        wit wt;          // wordMap iterator
        lit lt;

        for (lt = (*wordLists).begin(); lt != (*wordLists).end(); lt++)
        {
            fileName = lt->first; // first = array index
            wordCount = (*wordLists)[fileName].size();
            cout << fileName << "->" << wordCount << endl;
        }
    }

    string randomWord(int size)
    {
        wit it;
        int i;
        int r;
        string randomWord = "";

        if (size == 3)
        {
            randomWord += _randomWord("words/adjectives.txt");
            randomWord += " ";
            randomWord += _randomWord("words/adjectives.txt");
            randomWord += " ";
            randomWord += _randomWord("words/nouns.txt");
        }
        else if (size == 4)
        {
            randomWord += _randomWord("words/verbs.txt");
            randomWord += "ing ";
            randomWord += _randomWord("words/animals.txt");
            randomWord += " ";
            randomWord += _randomWord("words/adverbs.txt");
            randomWord += " ";
            randomWord += _randomWord("words/nouns.txt");
        }
        else if (size == 5)
        {
            randomWord += _randomWord("words/adjectives.txt");
            randomWord += " ";            
            randomWord += _randomWord("words/animals.txt");
            randomWord += "s ";
            randomWord += _randomWord("words/adjectives.txt");
            randomWord += " ";
            randomWord += _randomWord("words/adverbs.txt");
            randomWord += " ";
            randomWord += _randomWord("words/nouns.txt");           
        }
        return randomWord;
    }

    string _randomWord(string filename)
    {
        wit it;
        int i;
        int r;

        r = rand() % (*wordLists)[filename].size();

        for (it = (*wordLists)[filename].begin(), i = 0; it != (*wordLists)[filename].end(); it++, i++)
        {
            if (i >= r)
            {
                return it->first;
            }
        }
        return "";
    }
};

// main driver to read in values
int main(int argc, char **argv)
{

    ofstream fout;

    // count command line args and make sure
    // a file name is on the line to run this file
    if (argc < 2)
    {
        cout << "You need an input file[s]!\n";
        cout << "Usage: stlmap file1 file2 file3 fileN";
        exit(0);
    }

    crazyWords C(argv, argc - 1);

    C.loadWords();
    C.printWordCounts();

    fout.open("tenthousandwords.txt");
    for (int i = 0; i < 10000; i++)
    {
        fout << C.randomWord(rand()%3+3) << endl;
        if(i%100 == 0){
            cout<<'.';
        }
    }

    return 0;
}
