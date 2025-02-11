///////////////////////////////////////////////////////////////////////////////
// Title:            Huffman Driver
// Semester:         Fall 2019
// Course:           CMPS 3013
//
// Author:           Terry Griffin
// Email:            terry.griffin@msutexas.edu
// Description:
//       Small driver for the Huffman coding class
/////////////////////////////////////////////////////////////////////////////////
#include "Heap.hpp"
#include "Huffman.hpp"
#include "Node.hpp"
#include <fstream>
#include <iostream>
#include <time.h>
#include <vector>

using namespace std;

int main() {
    srand(time(0));
    Huffman H;
    H.BuildFrequencyTable("data.txt");
    
    cout<<H.LookupCode('s')<<endl;
    H.Analyze(1240037);
}