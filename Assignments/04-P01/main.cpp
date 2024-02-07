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

#include "./headers/json.hpp"
#include "./headers/mygetch.hpp"
#include "./headers/termcolor.hpp"
#include "./headers/timer.hpp"
#include "./headers/ioctl.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <time.h>
#include <termios.h>

using namespace std;

#define BLINK             termcolor::blink
#define BLUE              termcolor::blue
#define BOLD              termcolor::bold
#define BRIGHT_BLUE       termcolor::bright_blue
#define BRIGHT_CYAN       termcolor::bright_cyan
#define BRIGHT_GREEN      termcolor::bright_green
#define BRIGHT_GREY       termcolor::bright_grey
#define BRIGHT_MAGENTA    termcolor::bright_magenta
#define BRIGHT_RED        termcolor::bright_red
#define BRIGHT_WHITE      termcolor::bright_white
#define BRIGHT_YELLOW     termcolor::bright_yellow
#define COLOR             termcolor::color
#define COLOR             termcolor::color
#define COLORIZE          termcolor::colorize
#define CONCEALED         termcolor::concealed
#define CROSSED           termcolor::crossed
#define CYAN              termcolor::cyan
#define DARK              termcolor::dark
#define GREEN             termcolor::green
#define GREY              termcolor::grey
#define IS_ATTY           termcolor::is_atty
#define IS_COLORIZED      termcolor::is_colorized
#define ITALIC            termcolor::italic
#define MAGENTA           termcolor::magenta
#define NOCOLORIZE        termcolor::nocolorize
#define ON_BLUE           termcolor::on_blue
#define ON_BRIGHT_BLUE    termcolor::on_bright_blue
#define ON_BRIGHT_CYAN    termcolor::on_bright_cyan
#define ON_BRIGHT_GREEN   termcolor::on_bright_green
#define ON_BRIGHT_GREY    termcolor::on_bright_grey
#define ON_BRIGHT_MAGENTA termcolor::on_bright_magenta
#define ON_BRIGHT_RED     termcolor::on_bright_red
#define ON_BRIGHT_WHITE   termcolor::on_bright_white
#define ON_BRIGHT_YELLOW  termcolor::on_bright_yellow
#define ON_COLOR          termcolor::on_color
#define ON_COLOR          termcolor::on_color
#define ON_CYAN           termcolor::on_cyan
#define ON_GREEN          termcolor::on_green
#define ON_GREY           termcolor::on_grey
#define ON_MAGENTA        termcolor::on_magenta
#define ON_RED            termcolor::on_red
#define ON_WHITE          termcolor::on_white
#define ON_YELLOW         termcolor::on_yellow
#define RED               termcolor::red
#define RESET             termcolor::reset
#define REVERSE           termcolor::reverse
#define UNDERLINE         termcolor::underline
#define WHITE             termcolor::white
#define YELLOW            termcolor::yellow
#define IS_ATTY           termcolor::is_atty
#define IS_COLORIZED      termcolor::is_colorized


/**
 * screenWidth
 *
 * Description:
 *      returns the number of columns in the terminal. Probably won't work for windows
 * Params:
 *      None
 *
 * Returns:
 *      int - column count
 */
int screenWidth(string subtract="") {
  // Get the terminal size
  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

  if(subtract.size() > 0){
      return w.ws_col-subtract.size();
  }

  return w.ws_col;
}



/**
 * countLines
 *
 * Description:
 *      Originally wrote this to count size of input file so
 *      I could allocate enough memory for an array of strings.
 *      Even though I went with a vector below, this isn't totally
 *      useless.
 * Params:
 *      string file_name - file to get the line count
 *
 * Returns:
 *      int - line count
 */
int countLines(string file_name) {
    ifstream inFile(file_name);
    return count(istreambuf_iterator<char>(inFile), istreambuf_iterator<char>(), '\n');
}

/**
 * loadData
 *
 * Description:
 *      Loads a file of strings (words, names, whatever) reading them in
 *      with one word per line. So words must be delimited by newlines '\n'
 * Params:
 *      string file_name - file to get the line count
 *
 * Returns:
 *      int - line count
 */
vector<string> loadData(string file_name) {
    ifstream fin;                            // file to get animal names
    int count = (countLines(file_name) + 1); // get size of input file
    vector<string> array(count);             // allocate vector of correct size

    fin.open("./data/animal_names.txt"); // open file for reading

    // knowing the size of the file lets us treat
    // it like an array without using .push_back(value)
    for (int i = 0; i < count; i++) {
        fin >> array[i];  
                 // read in animals
        for (auto &c : array[i]) { // c++ 11 style loop
            c = tolower(c);        // lowercase the animal name

        }
    }

    return array;
}

/**
 * partialMatch
 *
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
vector<string> partialMatch(vector<string> array, string substring) {
    vector<string> matches; // to hold any matches
    size_t found;           // size_t is an integer position of
                            // found item. -1 if its not found.

    if(substring.size() == 0){
        return matches;
    }


    for (int i = 0; i < array.size(); i++) { // loop through array
        found = array[i].find(substring);    // check for substr match
        if (found != string::npos) {         // if found >= 0 (its found then)
            matches.push_back(array[i]);     // add to matches
        }
    }

    return matches;
}

void titleBar(string title, int length = 0){
    string line = string(length,' ');
    cout<<UNDERLINE<<BRIGHT_CYAN<<title<<RESET<<line<<endl;
}

int main() {
    char k;                 // holder for character being typed
    string key;
    string word = "";       // var to concatenate letters to
    vector<string> animals; // array of animal names
    vector<string> matches; // any matches found in vector of animals
    int loc;                // location of substring to change its color
    string title = "GETCH WORD LOOKUP";
    string resultsLabel = "RESULTS:";
    string *line;
    string *message;
    string pbp;
    bool deleting = false;
    string temp;
    int cols = screenWidth();




    Timer T;   // create a timer
    T.Start(); // start it

    animals = loadData("./data/animal_names.txt");


    T.End(); // end the current timer

    int nanoseconds = (int)T.NanoSeconds();
    int i;
    for(i=0;nanoseconds != 0;i++){
        cout<<nanoseconds<<endl;
        nanoseconds = nanoseconds / 10;
    }




    system("clear");

    // line = new string(screenWidth(title.size()),' ');
    message = new string("These values are showing how long it took to load the data file in three different time granularities.\n");
    cout<<termcolor::underline<<termcolor::bold<<termcolor::bright_cyan<<title<<*line<<termcolor::reset<<endl<<endl;
    // print out how long it took to load the animals file
    cout<<termcolor::bright_magenta<<*message<<termcolor::reset<<endl;
    cout<<termcolor::underline<<termcolor::cyan<<"Load Times:"<< termcolor::reset<<endl;
    cout << termcolor::bold<<termcolor::green <<"   Seconds:      "<< termcolor::yellow <<T.Seconds() << termcolor::reset<< endl;
    cout << termcolor::bold<<termcolor::green <<"   Milliseconds: "<< termcolor::yellow <<T.MilliSeconds() << termcolor::reset<< endl;
    cout << termcolor::bold<<termcolor::green <<"   NanoSeconds:  "<< termcolor::yellow <<T.NanoSeconds() << termcolor::reset<< endl;
    line = new string(cols,' ');
    cout<<termcolor::underline<<termcolor::bold<<termcolor::bright_cyan<<*line<<termcolor::reset<<endl<<endl;

    // While capital Z is not typed keep looping
    while ((k = getch()) != 'Z') {
        
        T.Start(); // start it
        // Tests for a backspace and if pressed deletes
        // last letter from "word".
        if ((int)k == 127) {
            if (word.size() > 0) {
                word = word.substr(0, word.size() - 1);
                deleting = true;
            }
        } else {
            deleting = false;
            // Make sure a letter was pressed and only letter
            if (!isalpha(k)) {
                cout <<termcolor::on_bright_red<< termcolor::bright_white<<"Letters only!" <<termcolor::reset<< endl;
                sleep(1);
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
        matches = partialMatch(animals, word);

        if ((int)k != 32) { // if k is not a space print it
            key = to_string(k);
            T.End();
            // Getting the correct precision to print out in c++ is not
            // straight forward. Strings and precision output are convoluted
            // at best. And drive you crazy at worst





            system("clear");
            pbp = "Play By Play";

            message = new string("User is typing keys, building a search string with every key stroke:" + word);
            line = new string(screenWidth(pbp.size()),' ');


            cout<<termcolor::underline<<termcolor::bold<<termcolor::bright_cyan<<pbp<<*line<<termcolor::reset<<endl<<endl;
            cout<<termcolor::bright_magenta<<*message<<termcolor::reset<<endl;
            // line = new string(screenWidth(),' ');
            cout<<termcolor::underline<<termcolor::bold<<termcolor::bright_cyan<<title<<*line<<termcolor::reset<<endl;
            cout << termcolor::green << termcolor::bold<<"   Seconds:\t\t"<<termcolor::reset<<termcolor::yellow << printf("%.17f", (double)T.NanoSeconds() / 1000000000)
                 << termcolor::reset<< endl;
            cout << termcolor::green<< termcolor::bold<< "   Keypressed: \t\t" << termcolor::yellow;
            if(int(k)==127){
                cout<<"del";
            } else {
                cout << k;
            }
            cout<< " = "<< (int)k << termcolor::reset << endl;
            cout << termcolor::green<< termcolor::bold<<"   Current Substr: \t" << termcolor::reset<<termcolor::red << word << termcolor::reset << endl;
            line = new string(getWidth(resultsLabel.size()),' ');
            cout<<endl;
            cout<<termcolor::underline<<termcolor::bold<<termcolor::bright_cyan<<resultsLabel<<*line<<termcolor::reset<<endl;

            cout << termcolor::green;
            // This prints out all found matches
            for (int i = 0; i < matches.size(); i++) {
                // find the substring in the word
                loc = matches[i].find(word);
                // if its found
                if (loc != string::npos) {
                    // print one letter at a time turning on red or green
                    //  depending on if the matching subtring is being printed
                    cout<<termcolor::bold;
                    for (int j = 0; j < matches[i].size(); j++) {
                        // if we are printing the substring turn it red
                        if (j >= loc && j <= loc + word.size() - 1) {
                            cout << termcolor::red;
                        } else {
                            cout <<termcolor::blue;
                        }
                        cout << matches[i][j];
                    }
                    cout <<termcolor::blue;
                }
                cout << " ";
            }
            cout << termcolor::reset << endl
                 << endl;
        }
    }
    return 0;
}
