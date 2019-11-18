///////////////////////////////////////////////////////////////////////////////
// Title:            Huffman.hpp
// Semester:         Fall 2019
// Course:           CMPS 3013
//
// Author:           Terry Griffin
// Email:            terry.griffin@msutexas.edu
// Description:
//       Lightweight implementation of huffman coding.
//       (where lightweight = no bit level storage, just
//        bit string enocoding for demonstration purposes)
/////////////////////////////////////////////////////////////////////////////////
#pragma once
#include "Heap.hpp"
#include "Node.hpp"
#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <iomanip> 

using namespace std;

/**
 * Huffman
 * 
 * Description:
 *      This class implements a compressions algorithm called Huffman Coding.
 *      Huffman coding assigns codes to characters such that the length of the 
 *      code depends on the relative frequency or weight of the corresponding 
 *      character. Huffman codes are of variable-length, and prefix-free
 * 
 * Public Methods:
 *                          Huffman()                               
 *      void                BuildFrequencyTable(string filename)
 *      string              LookupCode(char key)
 *      void                Analyze()
 *      map<char, string>   GetCodes()
 * 
 * Usage: 
 * 
 *      Huffman H(filename):                        // Create Instance of Huffman
 *                                                  // and build freq table. 
 *      H.GetCodes();                               // get map <char,string> of codes
 * 
 *                                                  // or
 *      
 *      Huffman H;                                  // do seperately
 *      H.BuildFrequencyTable(filename);            // or use to re-build another file
 *      H.LookupCode('s')                           // get code for 's' 
 *      
 */
class Huffman {
private:
    Heap<Node> *H; // Priority Heap of character nodes (with frequencies)
    Node **Freq;   // Table of frequencies after reading file
    Node *Tree;    // Huffman tree after combining nodes
    string bits;   // temp string for calculating each encoding string

    map<char, string> LookupTable; // What our Huffman table gets stored in

    /**
     * Private : _BuildLookupTable
     * 
     * Description:
     *      Recursively traverses the tree creating the binary "010101" strings
     *      used to represent each character.
     * 
     * Params:
     *      Node*  Tree  : Root of huffman tree
     *      string bits  : string to store binary in for subsequent recursive calls
     * 
     * Returns:
     *      void (stores codes in a class var)
     */
    void _BuildLookupTable(Node *Tree, string &bits) {
        if (!Tree) {
            return;
        } else {
            string leftbits = bits + "0";
            _BuildLookupTable(Tree->Left, leftbits);
            if (Tree->letter != NULL) {
                LookupTable.insert(pair<char, string>(*Tree->letter, bits));
            }
            string rightbits = bits + "1";
            _BuildLookupTable(Tree->Right, rightbits);
        }
    }

    /**
     * Private : BuildTree
     * 
     * Description:
     *      Uses the frequency table, and a priority heap to build the huffman tree.
     * 
     * Params:
     *      Void  : all local class vars
     * 
     * Returns:
     *      Void  : stores results in class var
     */
    void BuildTree() {
        Node *Temp; // Temp node used to combine two letters
        Node *Sub1; // Huffman says pop top 2 nodes to combine
        Node *Sub2; //     these vars represent those 2 popped nodes

        // While our priority heap has more than one item in it
        while (H->Size() > 1) {

            // Create a new "sub" tree node used to link trees together
            Temp = new Node;

            // Pull two smallest values from heap
            Sub1 = H->Extract();
            Sub2 = H->Extract();

            // Update the priority / freq of our new inner huffman node
            Temp->SetPriority(Sub1->priority + Sub2->priority);
            Temp->innerNode = true;

            // Decide who is left and right child
            if (Sub1->priority <= Sub2->priority) {
                Temp->Left = Sub1;
                Temp->Right = Sub2;
            } else {
                Temp->Left = Sub2;
                Temp->Right = Sub1;
            }

            // Put back onto heap
            H->Insert(Temp);
        }

        // Heap is down to 1 OR 2, so decide how
        // to finish off our tree.
        if (H->Size() == 1) {
            Tree = H->Extract();
        } else {
            // Pull two smallest values from heap
            Sub1 = H->Extract();
            Sub2 = H->Extract();

            // Update the priority / freq of our new inner huffman node
            Temp->SetPriority(Sub1->priority + Sub2->priority);

            // Decide who is left and right child
            if (Sub1->priority < Sub2->priority) {
                Temp->Left = Sub1;
                Temp->Right = Sub2;
            } else {
                Temp->Left = Sub2;
                Temp->Right = Sub1;
            }

            // Final assignment to our Huffman tree
            // resulting in a bunch of inner nodes with only
            // frequency counts, and all the leaves have
            // our letters in them.
            Tree = Temp;
        }
    }

    /**
     * Public : LookupCode
     * Source : https://www.geeksforgeeks.org/write-a-c-program-to-find-the-maximum-depth-or-height-of-a-tree/
     * Description:
     *      Get depth of a binary tree
     * 
     * Params:
     *      Node*  : root of tree
     * 
     * Returns:
     *      int : max depth
     */
    int maxDepth(Node* node)  
    {  
        if (node == NULL)  
            return 0;  
        else
        {  
            /* compute the depth of each subtree */
            int lDepth = maxDepth(node->Left);  
            int rDepth = maxDepth(node->Right);  
        
            /* use the larger one */
            if (lDepth > rDepth)  
                return(lDepth + 1);  
            else return(rDepth + 1);  
        }  
    } 

public:
    /**
     * Public : Huffman
     * 
     * Description:
     *      Constructs our huffman class
     * 
     * Params:
     *      string : filename (optional)
     * 
     * Returns:
     *      Void 
     */
    Huffman(string filename = "") {
        H = new Heap<Node>(false);
        Freq = new Node *[128];
        Tree = NULL;
        bits = ""; // used to build lookup table
        if (filename.length() > 0) {
            BuildFrequencyTable(filename);
        }
    }

    /**
     * Public : BuildFrequencyTable
     * 
     * Description:
     *      Counts letters in a file and stores the frequencies in an array of nodes
     *      where:
     * 
     *      freq[(int)'a'] => node with info about 'a'
     *      freq[(int)'b'] => node with info about 'b'
     *      etc...
     * 
     * Params:
     *      string : filename to process (no error checking)
     * 
     * Returns:
     *      Void 
     */
    void BuildFrequencyTable(string filename) {
        ifstream fin;
        fin.open(filename);
        char ch;

        // load array with all characters
        for (int i = 0; i < 128; i++) {
            // chars between 32 and 126 inclusive
            // are viewable and printable
            if (i >= 32 && i <= 126) {
                Freq[i] = new Node((char)i);
                Freq[i]->innerNode = false;
            } else {
                // bad char it so make it a dummy node
                // (a little wasted space for convenience
                // of using 32 => 126 as indexes)
                Freq[i] = new Node();
            }
        }

        // process file one character at a time
        while (!fin.eof()) {
            fin.get(ch);
            // if its viewable printable character
            // increment freq and priority
            // they are same in the node, but I wanted
            // them to both have their own var name
            // for readability when programming later
            if ((int)ch >= 32 && (int)ch <= 126) {
                Freq[(int)ch]->freq++;
                Freq[(int)ch]->priority++;
            }
        }

        // If its a viewable / printable character
        // put it's node on the priority heap
        for (int i = 32; i <= 126; i++) {
            if (Freq[i]->freq > 0) {
                H->Insert(Freq[i]);
            }
        }

        // Using our priority heap, build our huffman tree.
        // The tree only stores the letters, and from the tree
        // we need to travers and "build" each letters code.
        // Remember left = 0
        //          right = 1
        BuildTree();

        // Generate the actual "codes" => "010101" for each
        // letter. By traversing and using left / right to
        // make the codes. Again:
        // Remember left = 0
        //          right = 1
        _BuildLookupTable(Tree, bits);
    }

    /**
     * Public : LookupCode
     * 
     * Description:
     *      Pass in a char (e.g 's') and get a string code (e.g. "0011")
     * 
     * Params:
     *      char : key (character) to find
     * 
     * Returns:
     *      string : binary string
     */
    string LookupCode(char key) {
        if (LookupTable.find(key) == LookupTable.end()) {
            return "";
        } else {
            return LookupTable[key];
        }
        return "";
    }

    /**
     * Public : GetCodes
     * 
     * Description:
     *      Get all the codes from the class
     * 
     * Params:
     *      void
     * 
     * Returns:
     *      map<char, string> : where  
     * 
     *          map['a'] => "1001"
     *          map['A'] => "100001100"
     *          etc...
     */
    map<char, string> GetCodes() {
        return LookupTable;
    }

    /**
     * Public : Analyze
     * 
     * Description:
     *      Looks at the frequency table vs the length of each generated code
     *      to determine how much space would be saved if we used this encoding.
     *      Remember to take advantage of huffman coding, we would need to use
     *      bit level storage to actually save space. 
     * 
     *      Remember: 
     *          We can lookup a characters code by simply accessing table with 
     *          a character:
     *                 LookupTable['L'] => "0101010"
     *          Because LookupTable is a map of: <char, string> (e.g. 'x' => "101011")
     *          
     *          To get frequencies we go to the `freq` table:
     *              - char ch = "letter were looking for"
     *              - casting `ch` to `int` gives us an index to lookup frequency
     *              - where: freq[(int)ch] = frequency of letter
     * 
     * Params:
     *      void
     * 
     * Returns:
     *      void : prints everything to the screen
     */
    void Analyze(int filesize_in_bytes = 0) {
        int numbits = 0;
        double ratio = 0.0;
        double avgCodeLength = 0.0;
        int count = 0;
        int min = 999999;
        int max = 0;

        // use iterator to loop over map of codes [key]=>code
        for (auto itr = LookupTable.begin(); itr != LookupTable.end(); ++itr) {

            //
            int freq = Freq[(int)itr->first]->freq;
            string bits = itr->second;
            cout << itr->first << "=" << bits << " x " << freq << " occurences." << endl;
            numbits += bits.length() * freq;
            avgCodeLength += bits.length();
            if(bits.length() > max){
                max = bits.length();
            }
            if(bits.length() < min){
                min = bits.length();
            }
            count++;
        }
        cout<< setprecision(2)<<endl;
        cout << "Huffman code size in characters: " << numbits << endl;
        cout << "Huffman code size in bits:       " << (numbits / 8) << endl;
        cout << "Average Huffman code size:       " << (avgCodeLength/(double)count) <<endl;
        cout << "Longest Huffman code size:       " << max <<endl;
        cout << "Smallest Huffman code size:      " << min <<endl;
        cout << "Depth of the Huffman tree:       " << maxDepth(Tree)<<endl;  
        cout << "Depth of the Left Subtree:       " << maxDepth(Tree->Left)+1<<endl;  
        cout << "Depth of the Right Subtree:      " << maxDepth(Tree->Right)+1<<endl;  
        if (filesize_in_bytes > 0) {
            ratio = (double)(numbits / 8.0)/(double)filesize_in_bytes;
            cout << "Space saved given input size:    " <<(ratio*100) <<"%"<< endl;
        }
    }
};