#include <iostream>
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

};

int main(int argc, char** argv){

    Bst tree;

    for(int i=1;i<argc;i++){
        cout<<"Inserting: "<<argv[i]<<endl;
        tree.Insert(argv[i]);
    }

    tree.Print();

    return 1;
}