#include <iostream>
#include <fstream>
#include <time.h>
#include <string>

using namespace std;

struct node{
	int value;
	node *left;
	node *right;
	node *parent;
	int avlValue;
    node(int num){
        value = num;
        left = right = parent = NULL;
        avlValue = 0;
    }
};

class avlTree{

private:
	node *root;
	bool rightHeavy(node *);
	bool leftHeavy(node *);
	void insert(node *&, node *&);
	void inorder(node *);
	void preorder(node *);
	void postorder(node *);
	node* remove(node*& , int );
    node* predSuccessor(node*);
    void printNode(node *, string );
	int  height(node *);
	void computeAvlValues(node *&);
	void rotateLeft(node *&);
	void rotateRight(node *&);
	int  avlValue(node *);

public:
	avlTree();
	~avlTree();
	void doDumpTree(node *);
	void dumpTree(){cout<<"---------------------------------"<<endl;
	                cout<<"Root:   "<<root<<"\n";
					doDumpTree(root);
	};
	void insert(int);
	void showInorder(){inorder(root);};
	void showPreorder(){preorder(root);};
	void showPostorder(){postorder(root);};
	bool search(int);
	void remove(int num){root = remove(root,num);};
	int  treeHeight();
    void graphVizGetIds(node *,ofstream &);
	void graphVizMakeConnections(node *,ofstream &);
	void graphVizOut(string );
};

