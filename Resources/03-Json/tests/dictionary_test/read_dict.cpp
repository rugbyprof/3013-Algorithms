/**
 * This file reads in a json array, times it, and prints it out. 
 */

#include <iostream>
#include "JsonFacade.hpp"
#include <time.h>
#include <chrono> 
#include "Timer.hpp"      

using namespace std;

int main(){
    Timer T;
    T.Start();                   // Start timer
    JsonFacade J("dict.json");   // create instance of json class
    T.End();                     // End Timer
    double s = T.Seconds();      // get seconds from timer
    long m = T.MilliSeconds();   // get milliseconds

    cout <<s << " seconds to read in json" <<endl;
    cout <<m << " milli to read in json" <<endl;

    // loop through json array 
    for(int i=0;i<J.getSize();i++){
        // everything is a "json" object that you pull out of JsonFacade
        json word = J.getIth(i);

        // so we convert it to a real string to print it out
        std::cout<< word.get<std::string>()<<std::endl;
    }

    // call timer end again to get another length of run time.
    T.End(); 
    cout <<T.Seconds() << " seconds to read in and print json" <<endl;
    cout <<T.MilliSeconds() << " milli to read in and print json" <<endl;

}