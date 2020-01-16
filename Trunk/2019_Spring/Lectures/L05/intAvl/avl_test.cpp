#include <iostream>
#include "avlTree.h"
#include <string>
#include <time.h>
#include <map>

using namespace std;

int main(){
    srand(time(0));
	avlTree MyTree;

    map <string, int> word_list;

    word_list["word"] = 0;

// 	MyTree.insertNode(10);
// 	MyTree.insertNode(11);
// 	MyTree.insertNode(23);
// 	MyTree.insertNode(34);
// 	MyTree.insertNode(36);
// 	MyTree.insertNode(8);
// 	MyTree.insertNode(4);
// 	MyTree.ShowInorder();
	for(int i=0;i<150;i++){
	  MyTree.insert(rand()%5000);
	}
	
	//MyTree.remove(7);
	//\MyTree.ShowPostorder();
	MyTree.graphVizOut("viz.txt");

    return 0;
}