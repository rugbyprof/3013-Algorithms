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
     *      TreeNode* &root     : A reference pointer so we can update actuall tree
     *      TreeNode* temp      : The new node to be linked in
     * 
     * Returns:
     *      void 
     */
    void _Insert(TreeNode* &root,TreeNode* temp){
        if(!root){
            root = temp;
            return;
        }

        if(temp->word < root->word){
            _Insert(root->left,temp);
        }else{
            _Insert(root->right,temp);
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
     *      TreeNode* root     : A copy of the root pointer to get started
     * 
     * Returns:
     *      void 
     */
    void _Print(TreeNode* root){
        counter++;
        if(!root){
            return;
        }

        //preorder
        _Print(root->left);
        cout<<root->word<<" "; //inorder
        if(counter % 10 == 0){
            cout<<endl;
        }
        _Print(root->right);
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
     *      TreeNode *root   : pointer to a TreeNode
     *      string   key     : value to find and delete
     * 
     * Returns:
     * 
     *      a pointer to a node
     */
    TreeNode* _Delete(TreeNode *root, string key)
    {
        TreeNode* temp;
        if (root == NULL)
            return NULL;
        else if (key < root->word)
            root->left = _Delete(root->left,key);
        else if (key > root->word)
            root->right = _Delete(root->right,key);
        else if (root->left && root->right)
        {
            temp = _FindPredecessor(root);
            root->word = temp->word;
            root->right = _Delete(root->right,root->word);
        }
        else
        {
            temp = root;
            if (root->left == NULL)
                root = root->right;
            else if (root->right == NULL)
                root = root->left;
            delete temp;
        }

        return root;
    }

    /**
     * _Height
     * 
     * Params:
     * 
     *      TreeNode *root   : pointer to a TreeNode
     * 
     * Returns:
     * 
     *      The height of the tree
     */
    int _Height(TreeNode* root)
    {
        if (!root)
        {
            return 0;
        }
        else
        {
            int left = _Height(root->left);
            int right = _Height(root->right);
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
     *      TreeNode *root   : pointer to a TreeNode
     * 
     * Returns:
     * 
     *      Pointer to min value 
     */
    TreeNode* _FindMin(TreeNode* root)
    {
        if (root == NULL)
            return NULL;
        else if (root->left == NULL)
            return root;
        else
            return _FindMin(root->left);
    }

    TreeNode* _FindPredecessor(TreeNode* root,bool beenLeft=false)
    {
        if (root == NULL){
            return NULL;
        }
        if(beenLeft == false){
            if (root->left == NULL)
                return root;
            else
                return _FindPredecessor(root->left,true);
        }else{
            if (root->right == NULL)
                return root;
            else
                return _FindPredecessor(root->right,true);
        }

    }

    /**
     * _Find
     * 
     * Params:
     * 
     *      TreeNode *root   : pointer to a TreeNode
     *      string   key     : key to be found
     * 
     * Returns:
     * 
     *      Pointer to a TreeNode
     */
    TreeNode* _Find(TreeNode *&root, string key){
        if(!root){
            return NULL;
        }

        if(key == root->word){
            return root;
        }else{
            if(key<root->word){
                return _Find(root->left,key);
            }else{
                return _Find(root->right,key);
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
    void _printGivenLevel(TreeNode* root, int level)
    {
        if (root == NULL)
            return;
        if (level == 1)
        {
            _printNode(root);
        }
        else if (level > 1)
        {
            _printGivenLevel(root->left, level - 1);
            _printGivenLevel(root->right, level - 1);
        }
    }
    
   /* Function to line by line print level order traversal a tree*/
    void _printLevelOrder(TreeNode* root)
    {
        cout << "Begin Level Order===================\n";
        int h = _Height(root);
        int i;
        for (i = 1; i <= h; i++)
        {
            cout << "Begin Level "<<i<<"<<===================\n";
            _printGivenLevel(root, i);
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


    void PrintTree(){
        _printLevelOrder(Root);
    }


    bool Find(string key){
        return _Find(Root,key);
    }

    int Height(){
        return _Height(Root);
    }

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

    cout<<tree.Delete("bungler")<<endl;

    tree.Delete("ancestry");

    cout<<tree.maxDepth()<<endl;

    tree.PrintTree();

    tree.GraphVizOut("graph.out");

    return 1;
}