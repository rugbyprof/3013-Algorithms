#include <iostream>
#include <fstream>
#include <string>

using namespace std;


/**
 * TreeNode
 * 
 * Description:
 *      Used to hold data and child pointers 
 *      in our Binary Search Tree
 */
struct TreeNode{
    string word;
    TreeNode* left;
    TreeNode* right;

    TreeNode(){
        word = "";
        left = NULL;
        right = NULL;
    }

    TreeNode(string s){
        word = s;
        left = NULL;
        right = NULL;
    }
};

class Bst{
//////////////////////////////////////////////////////////////////////////
private:
//////////////////////////////////////////////////////////////////////////
    TreeNode* Root;
    int counter;

    /**
     * private _Insert
     * 
     * Description:
     *      Recursive method that traverses left and right depending 
     *      on inserted value eventually finding a NULL pointer and 
     *      inserting the new node there.
     * 
     * Params:
     *      TreeNode* &nptr     : A reference pointer so we can update actuall tree
     *      TreeNode* temp      : The new node to be linked in
     * 
     * Returns:
     *      void 
     */
    void _Insert(TreeNode* &nptr,TreeNode* temp){
        if(!nptr){
            nptr = temp;
            return;
        }

        if(temp->word < nptr->word){
            _Insert(nptr->left,temp);
        }else{
            _Insert(nptr->right,temp);
        }
    }


    /**
     * private _Print
     * 
     * Description:
     *      Recursive method that traverses left and right printing 
     *      values at each node.
     * 
     * Params:
     *      TreeNode* nptr     : A copy of the root pointer to get started
     * 
     * Returns:
     *      void 
     */
    void _Print(TreeNode* nptr){
        counter++;
        if(!nptr){
            return;
        }

        //preorder
        _Print(nptr->left);
        cout<<nptr->word<<" "; //inorder
        if(counter % 10 == 0){
            cout<<endl;
        }
        _Print(nptr->right);
        //postorder
    }

    /*
    * Compute the "maxDepth" of a tree -- the number of nodes along
    * the longest path from the root node down to the farthest leaf node.
    */
    int _maxDepth(TreeNode* node)
    {
        if (node == NULL)
        {
            return (0);
        }
        else
        {
            // compute the depth of each subtree
            int lDepth = _maxDepth(node->left);
            int rDepth = _maxDepth(node->right);
            // use the larger one
            if (lDepth > rDepth)
                return (lDepth + 1);
            else
                return (rDepth + 1);
        }
    }

    /**
     * _Delete
     * 
     * Params:
     * 
     *      TreeNode *nptr   : pointer to a TreeNode
     *      string   key     : value to find and delete
     * 
     * Returns:
     * 
     *      a pointer to a node
     */
    TreeNode* _Delete(TreeNode *&nptr, string key)
    {
        TreeNode* temp;
        if (nptr == NULL)
            return NULL;
        else if (key < nptr->word)
            nptr->left = _Delete(nptr->left,key);
        else if (key > nptr->word)
            nptr->right = _Delete(nptr->right,key);
        else if (nptr->left && nptr->right)
        {
            temp = _FindPredecessor(nptr);
            nptr->word = temp->word;
            nptr->right = _Delete(nptr->right,nptr->word);
        }
        else
        {
            temp = nptr;
            if (nptr->left == NULL)
                nptr = nptr->right;
            else if (nptr->right == NULL)
                nptr = nptr->left;
            delete temp;
        }

        return nptr;
    }

    /**
     * _Height
     * 
     * Params:
     * 
     *      TreeNode *nptr   : pointer to a TreeNode
     * 
     * Returns:
     * 
     *      The height of the tree
     */
    int _Height(TreeNode* nptr)
    {
        if (!nptr)
        {
            return 0;
        }
        else
        {
            int left = _Height(nptr->left);
            int right = _Height(nptr->right);
            if (left > right)
            {
                return left + 1;
            }
            else
            {
                return right + 1;
            }
        }
    }

    /**
     * _FindMin
     * 
     * Params:
     * 
     *      TreeNode *nptr   : pointer to a TreeNode
     * 
     * Returns:
     * 
     *      Pointer to min value 
     */
    TreeNode* _FindMin(TreeNode* nptr)
    {
        if (nptr == NULL)
            return NULL;
        else if (nptr->left == NULL)
            return nptr;
        else
            return _FindMin(nptr->left);
    }


    /**
     * _FindPredecessor
     * 
     * 
     * 
     */
    TreeNode* _FindPredecessor(TreeNode* nptr,bool beenLeft=false)
    {
        if (nptr == NULL){
            return NULL;
        }
        if(beenLeft == false){
            if (nptr->left == NULL)
                return nptr;
            else
                return _FindPredecessor(nptr->left,true);
        }else{
            if (nptr->right == NULL)
                return nptr;
            else
                return _FindPredecessor(nptr->right,true);
        }

    }

    /**
     * _Find
     * 
     * Params:
     * 
     *      TreeNode *nptr   : pointer to a TreeNode
     *      string   key     : key to be found
     * 
     * Returns:
     * 
     *      Pointer to a TreeNode
     */
    TreeNode* _Find(TreeNode *&nptr, string key){
        if(!nptr){
            return NULL;
        }

        if(key == nptr->word){
            return nptr;
        }else{
            if(key<nptr->word){
                return _Find(nptr->left,key);
            }else{
                return _Find(nptr->right,key);
            }
        }
    }

    int _NumChildren(TreeNode* node){
        int children = 0;

        if(node->left){
            children++;
        }
        if(node->right){
            children++;
        }
        return children;
    }

        /* Print nodes at a given level */
    void _printGivenLevel(TreeNode* nptr, int level)
    {
        if (nptr == NULL)
            return;
        if (level == 1)
        {
            _printNode(nptr);
        }
        else if (level > 1)
        {
            _printGivenLevel(nptr->left, level - 1);
            _printGivenLevel(nptr->right, level - 1);
        }
    }
    
   /* Function to line by line print level order traversal a tree*/
    void _printLevelOrder(TreeNode* nptr)
    {
        cout << "Begin Level Order===================\n";
        int h = _Height(nptr);
        int i;
        for (i = 1; i <= h; i++)
        {
            cout << "Begin Level "<<i<<"<<===================\n";
            _printGivenLevel(nptr, i);
            cout << "End Level "<<i<<"<<===================\n";
        }
        cout << "End Level Order===================\n";
    }

    void _printNode(TreeNode *n, string label = "")
    {
        if (label != "")
        {
            cout << "[" << label << "]";
        }
        cout << "[[" << n << "][" << n->word << "]]\n";
        if (n->left)
        {
            cout << "\t|-->[L][[" << n->left << "][" << n->left->word << "]]\n";
        }
        else
        {
            cout << "\t\\-->[L][null]\n";
        }
        if (n->right)
        {
            cout << "\t\\-->[R][[" << n->right << "][" << n->right->word << "]]\n";
        }
        else
        {
            cout << "\t\\-->[R][null]\n";
        }
    }

//////////////////////////////////////////////////////////////////////////
public:
//////////////////////////////////////////////////////////////////////////
    /**
     * private Bst
     * 
     * Description:
     *      Class constructor inits tree to empty
     * 
     * Params:
     *      void
     * 
     * Returns:
     *      void 
     */
    Bst(){
        Root = NULL;
    } 

    /**
     * public Insert
     * 
     * Description:
     *      Calls private insert with the new node and root of the tree.
     *      We need to private method because caller does not now about 
     *      the "root" of our tree.
     * 
     * Params:
     *      string s : a word to insert
     * 
     * Returns:
     *      void 
     */
    void Insert(string s){
        TreeNode* temp = new TreeNode(s);

        if(!Root){
            Root = temp;
        }else{
            _Insert(Root,temp);
        }
    }

    /**
     * public Print
     * 
     * Description:
     *      Calls private print with the root of the tree.
     *      We need to private method because caller does not now about 
     *      the "root" of our tree.
     * 
     * Params:
     *      void
     * 
     * Returns:
     *      void 
     */
    void Print(){
        _Print(Root);
    }

    /**
     * public PrintTree
     * 
     * Description:
     *      Prints a "level order" output of the tree with pointers to children
     * 
     * Params:
     *      void
     * 
     * Returns:
     *      void 
     */
    void PrintTree(){
        _printLevelOrder(Root);
    }

    /**
     * public Find
     * 
     * Description:
     *      Checks if a node exists with a specific key. Should probably return a pointer.
     * 
     * Params:
     *      void
     * 
     * Returns:
     *      void 
     */
    bool Find(string key){
        return _Find(Root,key);
    }

    /**
     * public Height
     * 
     * Description:
     *      Returns longest path from root to some leaf node
     * 
     * Params:
     *      void
     * 
     * Returns:
     *      void 
     */
    int Height(){
        return _Height(Root);
    }

    /**
     * public Delete
     * 
     * Description:
     *      Deletes a node from the tree.
     * 
     * Params:
     *      void
     * 
     * Returns:
     *      TreeNode* to the deleted  
     */
    TreeNode* Delete(string key){
        return _Delete(Root,key);
    }

    int maxDepth(){
        return _maxDepth(Root);
    }



    //************************************************************************
    // Method to help create GraphViz code so the expression tree can
    // be visualized. This method prints out all the unique node id's
    // by traversing the tree.
    // Recivies a node pointer to root and performs a simple recursive
    // tree traversal.
    //************************************************************************
    void GraphVizGetIds(TreeNode *nodePtr, ofstream &VizOut)
    {
        static int NullCount = 0;
        if (nodePtr)
        {
            GraphVizGetIds(nodePtr->left, VizOut);
            VizOut << "node" << nodePtr->word
                   << "[label=\"" << nodePtr->word << "\\n"
                   //<<"Add:"<<nodePtr<<"\\n"
                   //<<"Par:"<<nodePtr->parent<<"\\n"
                   //<<"Rt:"<<nodePtr->right<<"\\n"
                   //<<"Lt:"<<nodePtr->left<<"\\n"
                   << "\"]" << endl;
            if (!nodePtr->left)
            {
                NullCount++;
                VizOut << "nnode" << NullCount << "[label=\"X\",shape=point,width=.15]" << endl;
            }
            GraphVizGetIds(nodePtr->right, VizOut);
            if (!nodePtr->right)
            {
                NullCount++;
                VizOut << "nnode" << NullCount << "[label=\"X\",shape=point,width=.15]" << endl;
            }
        }
    }

    //************************************************************************
    // This method is partnered with the above method, but on this pass it
    // writes out the actual data from each node.
    // Don't worry about what this method and the above method do, just
    // use the output as your told:)
    //************************************************************************
    void GraphVizMakeConnections(TreeNode *nodePtr, ofstream &VizOut)
    {
        static int NullCount = 0;
        if (nodePtr)
        {
            GraphVizMakeConnections(nodePtr->left, VizOut);
            if (nodePtr->left)
                VizOut << "node" << nodePtr->word << "->"
                       << "node" << nodePtr->left->word << endl;
            else
            {
                NullCount++;
                VizOut << "node" << nodePtr->word << "->"
                       << "nnode" << NullCount << endl;
            }

            if (nodePtr->right)
                VizOut << "node" << nodePtr->word << "->"
                       << "node" << nodePtr->right->word << endl;
            else
            {
                NullCount++;
                VizOut << "node" << nodePtr->word << "->"
                       << "nnode" << NullCount << endl;
            }

            GraphVizMakeConnections(nodePtr->right, VizOut);
        }
    }

    //************************************************************************
    // Recieves a filename to place the GraphViz data into.
    // It then calls the above two graphviz methods to create a data file
    // that can be used to visualize your expression tree.
    //************************************************************************
    void GraphVizOut(string filename)
    {
        ofstream VizOut;
        VizOut.open(filename);
        VizOut << "Digraph G {\n";
        GraphVizGetIds(Root, VizOut);
        GraphVizMakeConnections(Root, VizOut);
        VizOut << "}\n";
        VizOut.close();
    }
};

int main(int argc, char** argv){

    Bst tree;
    string word;


    if(argc < 2){
        cout<<"error: need an input file!\n";
        //exit(0);
    }

    //ifstream fin(argv[1]);

    ifstream fin("/Users/griffin/code/2019_courses/3013-Algorithms/Lectures/L04/words2.dat");

    while(!fin.eof()){
        fin >> word;
        cout<<"Inserting: "<<word<<endl;
        tree.Insert(word);
    }

    tree.PrintTree();

    cout<<tree.Delete("bungler")<<endl;

    cout<<tree.Delete("ancestry")<<endl;

    cout<<tree.maxDepth()<<endl;

    tree.PrintTree();

    tree.GraphVizOut("graph.out");
    

    return 1;
}