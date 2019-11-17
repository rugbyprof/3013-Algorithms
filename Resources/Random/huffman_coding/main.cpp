#include <iostream>
#include <fstream>
#include <vector>
#include "Heap.hpp"
#include "Node.hpp"
#include <time.h>

using namespace std;

class Huffman{
private:
  Heap <Node> *H;
  Node** Freq;
  Node* Tree;
  vector  < pair < string , string > > LookupTable;

  
   void _BuildLookupTable(Node* Tree,string &bits){
      if(!Tree){
        return;
      }else{
        string leftbits = bits + "0";
        _BuildLookupTable(Tree->Left,leftbits);
        if(Tree->letter != NULL){
          LookupTable.push_back(std::make_pair(Tree->letter,bits));
        }
        string rightbits = bits + "1";
        _BuildLookupTable(Tree->Right,rightbits);
      }
  }
  
public:

  Huffman(){
    H = new Heap <Node> (false);
    Freq = new Node*[128];
    Tree = NULL;
  }

  void BuildFrequencyTable(string filename){
    ifstream fin;
    fin.open(filename);
    char ch;
 
    // load array with all characters 
    for(int i=0;i<128;i++){
      if(i >=32 && i <=126){
        Freq[i] = new Node((char)i);
        Freq[i]->innerNode = false;
      }else{
        Freq[i] = new Node();
      }
    }

    while(!fin.eof()){
      fin.get(ch);
      if((int)ch >=32 && (int)ch <=126){
        Freq[(int)ch]->freq++;
        Freq[(int)ch]->priority++;
      }
    }

    for(int i=32;i<=126;i++){
      if(Freq[i]->freq > 0){
        H->Insert(Freq[i]);
      }
    }
  }

  void BuildTree(){
    Node* Temp;
    Node* Sub1;
    Node* Sub2;

    while(H->Size() > 1){

      // Create a new "sub" tree node used to link trees together
      Temp = new Node;

      // Pull two smallest values from heap
      Sub1 = H->Extract();
      Sub2 = H->Extract();

      // Update the priority / freq of our new inner huffman node
      Temp->SetPriority(Sub1->priority + Sub2->priority);
      Temp->innerNode = true;
      
      // Decide who is left and right child
      if(Sub1->priority <= Sub2->priority){
        Temp->Left = Sub1;
        Temp->Right = Sub2;
      }else{
        Temp->Left = Sub2;
        Temp->Right = Sub1;
      }

      // Put back onto heap
      H->Insert(Temp);

    }


    if(H->Size() == 1){
      Tree = H->Extract();
    }else{
      // Pull two smallest values from heap
      Sub1 = H->Extract();
      Sub2 = H->Extract();

      // Update the priority / freq of our new inner huffman node
      Temp->SetPriority(Sub1->priority + Sub2->priority);
      
      // Decide who is left and right child
      if(Sub1->priority < Sub2->priority){
        Temp->Left = Sub1;
        Temp->Right = Sub2;
      }else{
        Temp->Left = Sub2;
        Temp->Right = Sub1;
      }
      Tree = Temp;
    }
  }

  void BuildLookupTable(){
    string bits = "";
    _BuildLookupTable(Tree,bits);
  }

  void Analyze(){
    int numbits = 0;
    for(int i=0;i<LookupTable.size();i++){
      char ch = LookupTable[i].first[0];  // because I stored letter as a string in the lookup table
      int freq = Freq[(int)ch]->freq;
      string bits = LookupTable[i].second;
      cout<<ch<<"="<<bits<<" x "<<freq<<" occurences."<<endl;
      numbits += bits.length() * freq;
    }
    cout<<"Size in bits= "<<(numbits/8)<<endl;
  }
  
};



int main() {
  srand(time(0));
  Huffman H;
  H.BuildFrequencyTable("data.txt");
  H.BuildTree();
  H.BuildLookupTable();
  H.Analyze();
}