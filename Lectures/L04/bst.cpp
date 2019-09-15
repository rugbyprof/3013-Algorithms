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
        if(!root){
            return;
        }

        //preorder
        _Print(root->left);
        cout<<root->word<<" "; //inorder
        _Print(root->right);
        //postorder
    }

    bool _Find(TreeNode* root,string key){
        if(!root){
            return false;
        }

        if(key == root->word){
            return true;
        }else{
            if(key<root->word){
                return _Find(root->left,key);
            }else{
                return _Find(root->right,key);
            }
        }
    }

    /*
    Compute the "maxDepth" of a tree -- the number of nodes along
    the longest path from the root node down to the farthest leaf node.
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

    string _Delete(TreeNode* Root,string key){
        TreeNode* DeleteMe = _Locate(Root,key);

        if(!DeleteMe){
            cout<<"I'm not here\n";
        }else{
            cout<<_NumChildren(Root)<<endl;
        }

        return "";
    }

    TreeNode* _Locate(TreeNode* root, string key){
        if(!root){
            return NULL;
        }

        if(key == root->word){
            return root;
        }else{
            if(key<root->word){
                return _Locate(root->left,key);
            }else{
                return _Locate(root->right,key);
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

    bool Find(string key){
        return _Find(Root,key);
    }

    // string Delete(string key){
    //     return _Delete(Root,key);
    // }

    int maxDepth(){
        return _maxDepth(Root);
    }

};

int main(int argc, char** argv){

    Bst tree;
    string word;

    if(argc < 2){
        cout<<"error: need an input file!\n";
        exit(0);
    }

    ifstream fin(argv[1]);

    while(!fin.eof()){
        fin >> word;
        cout<<"Inserting: "<<word<<endl;
        tree.Insert(word);
    }

    cout<<tree.Delete("cheese")<<endl;

    cout<<tree.maxDepth()<<endl;

    return 1;
}