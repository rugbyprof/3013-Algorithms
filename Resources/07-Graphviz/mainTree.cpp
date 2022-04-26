#include <iostream>
#include "bst.hpp"


using namespace std;

int main() {
  Bst tree;
  tree.Insert(105);
  tree.Insert(18);
  tree.Insert(33);
  tree.Insert(41);
  tree.Insert(91);
  tree.Insert(117);
  tree.Insert(113);
    
  for(int i=0;i<33;i++){
      int r = rand()%200;
      if(!tree.Find(r))
        tree.Insert(r);
  }
  tree.Insert(1);

  //tree.Print();
  // int k = 17;
  // cout<<"Looking for "<<k<<":"<<tree.Find(k)<<endl;
  // cout<<"Height: "<<tree.Height()<<endl;

  TreeStats s = tree.treeSize();

  cout<<s<<endl;

  cout<<endl;
  // tree.dumpGraph();
}