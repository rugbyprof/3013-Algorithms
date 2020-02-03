#include <iostream>
#include "input.hpp"



using namespace std;


int main(){

    char letter;

    std::cout << "enter a letter -->\n\n";
    while(letter != 'x'){

    
      letter = getch();
    
      std::cout << letter;
    }
    cout<<"done!"<<endl;
    return 0;
}