/**
 * This program uses a "getch" function which means "get character".
 * However, getch does not print the character to the terminal, it 
 * lets you decide what to do based on what character you are pressing.
 * 
 * You can test which characters are being pressed using thier ascii values. 
 * 
 * An ascii table here should be helpful 
 *      http://www.asciitable.com/
 * 
 * Some integer values for some keys:
 *      LowerCase Letters   = 97(a) -> 122(z)
 *      UpperCase Letters   = 65(A) -> 90(Z)
 *      Enter Key           = 10
 *      Space Bar           = 32
 *      
 *      Arrow Keys          = Have same values as some letters
 *                            so we can't distinguish between 
 *                            the two (in this context).
 * 
 * Code below is a basic example of using a "getch" function along with
 * searching an array of words for partial matches. 
 * 
 * https://repl.it/@rugbyprof/getchexample#main.cpp
 */

#include "mygetch.hpp"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

/**
 * Description:
 *      Originally wrote this to count size of input file so
 *      I could allocate enough memory for an array of strings
 *      but I went with a vector below. But I'm keeping it and
 *      using it anyway!
 * Params:
 *      string file_name - file to get the line count
 * 
 * Returns:
 *      int - line count
 */
int CountLines(string file_name) {
    ifstream inFile(file_name);
    return count(istreambuf_iterator<char>(inFile), istreambuf_iterator<char>(), '\n');
}

/**
 * Description:
 *      Loads a file of strings (words, names, whatever) reading them in
 *      with one word per line. So words must be delimited by newlines '\n'
 * Params:
 *      string file_name - file to get the line count
 * 
 * Returns:
 *      int - line count
 */
vector<string> LoadAnimals(string file_name) {
    ifstream fin;                            // file to get animal names
    int count = (CountLines(file_name) + 1); // get size of input file
    vector<string> array(count);             // allocate vector of correct size

    fin.open("animal_names.txt"); // open file for reading

    // knowing the size of the file lets us treat
    // it like an array without using .push_back(value)
    for (int i = 0; i < count; i++) {
        fin >> array[i];           // read in animals
        for (auto &c : array[i]) { // c++ 11 style loop
            c = tolower(c);        // lowercase the animal name
        }
    }
    return array;
}

/**
 * Description:
 *      Finds partial matches in an array of strings and returns them. It
 *      doesn't matter where in the string the match is.
 * Params:
 *      vector<string>  array       - array to search
 *      string          substring   - substring to search for in each word
 * 
 * Returns:
 *      vector<string> - holding all the matches to substring
 */
vector<string> FindAnimals(vector<string> array, string substring) {
    vector<string> matches;     // to hold any matches
    size_t found;               // size_t is an integer position of 
                                // found item. -1 if its not found.

    for (int i = 0; i < array.size(); i++) {    // loop through array
        found = array[i].find(substring);       // check for substr match
        if (found != string::npos) {            // if found >= 0 (its found then)
            matches.push_back(array[i]);        // add to matches
        }
    }

    return matches;
}

int main() {
    char k;                 // holder for character being typed
    string word = "";       // var to concatenate letters to
    vector<string> animals; // array of animal names
    vector<string> matches; // any matches found in vector of animals

    ofstream fout("temp.txt");

    animals = LoadAnimals("animal_names.txt");

    cout << "Type keys and watch what happens. Type capital Z to quit." << endl;

    // While capital Z is not typed keep looping
    while ((k = getch()) != 'Z') {

        // Tests for a backspace and if pressed deletes 
        // last letter from "word".
        if ((int)k == 127) {
            if (word.size() > 0) {
                word = word.substr(0, word.size() - 1);
            }
        } else {
            // Make sure a letter was pressed and only letter
            if (!isalpha(k)) {
                cout << "Letters only!" << endl;
                continue;
            }

            // We know its a letter, lets make sure its lowercase.
            // Any letter with ascii value < 97 is capital so we
            // lower it.
            if ((int)k < 97) {
                k += 32;
            }
            word += k; // append char to word
        }


        // Find any animals in the array that partially match
        // our substr word
        matches = FindAnimals(animals, word);


        if ((int)k != 32) { // if k is not a space print it
            cout << "Keypressed: " << k << " = " << (int)k << endl;
            cout << "Current Substr: " << word << endl;
            cout << "Animals Found: ";

            // This prints out all found matches
            for (int i = 0; i < matches.size(); i++) {
                cout << matches[i] << " ";
            }
            cout << endl
                 << endl;
        }
    }
    return 0;
}
