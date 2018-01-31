#include <iostream>
#include <fstream>
#include <time.h>

//https://visualgo.net/en/bst

using namespace std;

struct TreeNode{
    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    int AvlValue;
};

class BSTree{
    
private:
    TreeNode *root;
    void insert(TreeNode *&, TreeNode *&);
    void inorder(TreeNode *nodePtr);
    void preorder(TreeNode *nodePtr);
    void postorder(TreeNode *nodePtr);
    void deleteNode(int ,TreeNode *&);
    void makeDeletion(TreeNode *&nodePtr);
    int  Height(TreeNode *nodePtr);
    
public:
    BSTree();
    ~BSTree();
    void DoDumpTree(TreeNode *nodePtr);
    void DumpTree(){cout<<"---------------------------------"<<endl;
        cout<<"Root:   "<<root<<"\n";
        DoDumpTree(root);
    };
    void insertNode(int);
    void ShowInorder(){inorder(root);};
    void ShowPreorder(){preorder(root);};
    void ShowPostorder(){postorder(root);};
    bool SearchNode(int);
    void remove(int num){deleteNode(num,root);};
    int  TreeHeight();
    void GraphVizGetIds(TreeNode *nodePtr,ofstream &VizOut);
    void GraphVizMakeConnections(TreeNode *nodePtr,ofstream &VizOut);
    void GraphVizOut(string filename);
};


BSTree::BSTree(){
    root=NULL;
}

BSTree::~BSTree(){
    
}

//************************************************************************
// Method Name: insert
//
// Private
//
// Purpose: Inserts a node into a binary tree
//
// Arguments: reference to the root, and a reference to the new node
//
// Returns: Nothing.
//*************************************************************************
void BSTree::insert(TreeNode *&nodePtr, TreeNode *&newNode){
    
    if (nodePtr == NULL){
        nodePtr = newNode;
    }else if (newNode->value <= nodePtr->value){
        newNode->parent = nodePtr;
        insert(nodePtr->left,newNode);
        
    }else{
        newNode->parent = nodePtr;
        insert(nodePtr->right,newNode);
    }
    
}

//************************************************************************
// Method Name: insertNode
//
// Public
//
// Purpose: Creates a new node and assigns the passed in value to it. Subsequently
//          calls insert to actually travers the binary tree and link the node in
//          proper location.
//
// Arguments: integer to be placed in binary tree.
//
// Returns: Nothing.
//*************************************************************************
void BSTree::insertNode(int num){
    TreeNode *newNode;
    
    newNode = new TreeNode;
    newNode->value = num;
    newNode->AvlValue = 0;
    newNode->left = newNode->right = NULL;
    newNode->parent = NULL;
    insert(root,newNode);
}

//************************************************************************
// Method Name: inorder,postorder,preorder (all the same)
//
// Public
//
// Purpose: Traverses a binary tree
//
// Arguments: integer to be placed in binary tree.
//
// Returns: Nothing.
//*************************************************************************
void BSTree::inorder(TreeNode *nodePtr){
    if(nodePtr){
        inorder(nodePtr->left);
        cout<<nodePtr->value<<" "<<"("<<nodePtr->AvlValue<<") ";
        inorder(nodePtr->right);
    }
}

void BSTree::postorder(TreeNode *nodePtr){
    if(nodePtr){
        inorder(nodePtr->left);
        inorder(nodePtr->right);
        cout<<nodePtr->value<<" "<<"("<<nodePtr->AvlValue<<") ";
    }
}

void BSTree::preorder(TreeNode *nodePtr){
    if(nodePtr){
        cout<<nodePtr->value<<" "<<"("<<nodePtr->AvlValue<<") ";
        inorder(nodePtr->left);
        inorder(nodePtr->right);
    }
}

//************************************************************************
// Method Name: searchNode
//
// Public
//
// Purpose: Traverses a binary tree looking for a key value
//
// Arguments: integer to look for
//
// Returns: true if found, false otherwise
//*************************************************************************
bool BSTree::SearchNode(int num){
    TreeNode *nodePtr = root;
    
    while (nodePtr){
        if(nodePtr->value==num)
            return true;
        else if (num < nodePtr->value)
            nodePtr = nodePtr->left;
        else
            nodePtr = nodePtr->right;
    }
    return false;
}

//************************************************************************
// Method Name: deleteNode
//
// Private
//
// Purpose: Traverses a binary tree looking for a key value to mark for
//          deletion (could be merged with searchNode).
//
// Arguments: key to delete, nodePtr of the start of the tree (root , subroot, etc.)
//
// Returns: void
//*************************************************************************
void BSTree::deleteNode(int num,TreeNode *&nodePtr){
    if(nodePtr){
        if(num<nodePtr->value)
            deleteNode(num,nodePtr->left);
        else if (num > nodePtr->value)
            deleteNode(num,nodePtr->right);
        else if(nodePtr->value == num)
            makeDeletion(nodePtr);
    }else{
        cout<<"Value does not exist!"<<endl;
    }
}

//************************************************************************
// Method Name: makeDeletion
//
// Private
//
// Purpose: Actually removes a node from a tree by pointer manipulation and
//          frees the memory
//
// Arguments: address of node to be deleted
//
// Returns: void
//*************************************************************************
void BSTree::makeDeletion(TreeNode *&nodePtr){
    TreeNode *tempNodePtr;
    
    if(nodePtr ==NULL)
        cout<<"Cannot delete empty node.\n";
    else if (nodePtr->right==NULL){
        
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->left;
        delete tempNodePtr;
        
    }else if (nodePtr->left==NULL){
        
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->right;
        delete tempNodePtr;
        
    }else{
        tempNodePtr = nodePtr->right;
        while(tempNodePtr->left)
            tempNodePtr = tempNodePtr->left;
        tempNodePtr->left = nodePtr->left;
        tempNodePtr = nodePtr;
        nodePtr=nodePtr->right;
        delete tempNodePtr;
    }
}

//************************************************************************
// Method Name: Height
//
// Private
//
// Purpose: Actually removes a node from a tree by pointer manipulation and
//          frees the memory
//
// Arguments: address of the root of the tree (or subtree)
//
// Returns: void
//*************************************************************************
int BSTree::Height(TreeNode *nodePtr){
    int left_height=0;
    int right_height=0;
    if(nodePtr==NULL)
        return 0;
    else{
        left_height = Height(nodePtr->left);
        right_height = Height(nodePtr->right);
    }
    if(left_height>right_height)
        return 1+left_height;
    else
        return 1+right_height;
}

//************************************************************************
// Method Name: TreeHeight
//
// Public
//
// Purpose: Public method to call the private height method
//
// Arguments: none
//
// Returns: void
//*************************************************************************
int BSTree::TreeHeight(){
    return Height(root);
}

//************************************************************************
// Method to help create GraphViz code so the expression tree can
// be visualized. This method prints out all the unique node id's
// by traversing the tree.
// Recivies a node pointer to root and performs a simple recursive
// tree traversal.
//************************************************************************
void BSTree::GraphVizGetIds(TreeNode *nodePtr,ofstream &VizOut){
    static int NullCount=0;
    if(nodePtr){
        GraphVizGetIds(nodePtr->left,VizOut);
        VizOut<<"node"<<nodePtr->value
        <<"[label=\""<<nodePtr->value<<"\\n"
        <<"Avl:"<<nodePtr->AvlValue<<"\\n"
        //<<"Add:"<<nodePtr<<"\\n"
        //<<"Par:"<<nodePtr->parent<<"\\n"
        //<<"Rt:"<<nodePtr->right<<"\\n"
        //<<"Lt:"<<nodePtr->left<<"\\n"
        <<"\"]"<<endl;
        if(!nodePtr->left){
            NullCount++;
            VizOut<<"nnode"<<NullCount<<"[label=\"X\",shape=point,width=.15]"<<endl;
        }
        GraphVizGetIds(nodePtr->right,VizOut);
        if(!nodePtr->right){
            NullCount++;
            VizOut<<"nnode"<<NullCount<<"[label=\"X\",shape=point,width=.15]"<<endl;
            
        }
    }
}

//************************************************************************
// This method is partnered with the above method, but on this pass it
// writes out the actual data from each node.
// Don't worry about what this method and the above method do, just
// use the output as your told:)
//************************************************************************
void BSTree::GraphVizMakeConnections(TreeNode *nodePtr,ofstream &VizOut){
    static int NullCount=0;
    if(nodePtr){
        GraphVizMakeConnections(nodePtr->left,VizOut);
        if(nodePtr->left)
            VizOut<<"node"<<nodePtr->value<<"->"<<"node"<<nodePtr->left->value<<endl;
        else{
            NullCount++;
            VizOut<<"node"<<nodePtr->value<<"->"<<"nnode"<<NullCount<<endl;
        }
        
        if(nodePtr->right)
            VizOut<<"node"<<nodePtr->value<<"->"<<"node"<<nodePtr->right->value<<endl;
        else{
            NullCount++;
            VizOut<<"node"<<nodePtr->value<<"->"<<"nnode"<<NullCount<<endl;
        }
        
        GraphVizMakeConnections(nodePtr->right,VizOut);
        
    }
}

//************************************************************************
// Recieves a filename to place the GraphViz data into.
// It then calls the above two graphviz methods to create a data file
// that can be used to visualize your expression tree.
//************************************************************************
void BSTree::GraphVizOut(string filename)
{
    ofstream VizOut;
    VizOut.open(filename);
    GraphVizGetIds(root,VizOut);
    GraphVizMakeConnections(root,VizOut);
    VizOut.close();
    
}

//************************************************************************
// Method Name: DoDumpTree
//
// Private
//
// Purpose: Private method to show the basic pointer structure of the tree.
//          Initially written to help with debugging.
//
// Arguments: address of a node
//
// Returns: void
// Outputs: tree information
//*************************************************************************
void BSTree::DoDumpTree(TreeNode *nodePtr)
{
    if(nodePtr){
        cout<<"Add:    "<<nodePtr<<"\n"
        <<"Parent->"<<nodePtr->parent<<"\n"
        <<"Val:    "<<nodePtr->value<<"\n"
        <<"Left->  "<<nodePtr->left<<"\n"
        <<"Right-> "<<nodePtr->right<<"\n\n";
        
        DoDumpTree(nodePtr->left);
        DoDumpTree(nodePtr->right);
    }
}

int main(){
    srand(23232);
    
    BSTree Tree;
    
    for(int i = 0 ; i < 15 ; i++){
        Tree.insertNode(rand()%1000);
    }
    
    Tree.GraphVizOut("viz.out");
   
    return 0;
}
