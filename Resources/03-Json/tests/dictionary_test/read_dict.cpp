/**
 * Make sure before running, you copy necessary .hpp files
 * into your project folder so they can be found.
 * 
 * Trying to run this code as is will fail since the .hpp
 * files our in the resources folder. 
 * 
 */

#include <iostream>
#include "JsonFacade.hpp"       // need to grab a copy from resources folder
#include <time.h>
#include <chrono> 
#include "Timer.hpp"            // need to grab a copy from resources folder

using namespace std;

int main(){
    Timer T;
    T.Start();
    JsonFacade J("dict.json");   // create instance of json class
    T.End(); 
    double s = T.Seconds();
    long m = T.MilliSeconds();

    for(int i=0;i<J.getSize();i++){
        json word = J.getIth(i);
        std::cout<< word.get<std::string>()<<std::endl;
    }

    T.End(); 
    cout <<s << " seconds" <<endl;
    cout <<m << " milli" <<endl;

}