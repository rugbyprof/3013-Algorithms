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


	for(int i=0;i<150;i++){
	  MyTree.insert(rand()%5000);
	}
	
	//MyTree.remove(7);
	//\MyTree.ShowPostorder();
	MyTree.graphVizOut("viz.txt");

    return 0;
}