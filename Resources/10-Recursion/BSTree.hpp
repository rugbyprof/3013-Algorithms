#include <iostream>
#include <fstream>
#include <string>
#include <vector>

//http://www.webgraphviz.com/

using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
    node()
    {
        data = -1;
        left = NULL;
        right = NULL;
    }
    node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class BSTree
{
  private:
    node *root;

    int count(node *root)
    {
        if (!root)
        {
            return 0;
        }
        else
        {
            return 1 + count(root->left) + count(root->right);
        }
    }

    void insert(node *&root, node *&temp)
    {
        if (!root)
        {
            root = temp;
        }
        else
        {
            if (temp->data < root->data)
            {
                insert(root->left, temp);
            }
            else
            {
                insert(root->right, temp);
            }
        }
    }

    void print_node(node *n, string label = "")
    {
        if (label != "")
        {
            cout << "[" << label << "]";
        }
        cout << "[[" << n << "][" << n->data << "]]\n";
        if (n->left)
        {
            cout << "\t|-->[L][[" << n->left << "][" << n->left->data << "]]\n";
        }
        else
        {
            cout << "\t\\-->[L][null]\n";
        }
        if (n->right)
        {
            cout << "\t\\-->[R][[" << n->right << "][" << n->right->data << "]]\n";
        }
        else
        {
            cout << "\t\\-->[R][null]\n";
        }
    }

    /**
     * type = ['predecessor','successor']
     */
    node *minValueNode(node *root)
    {
        node *current = root;

        if (root->right)
        {
            current = root->right;
            while (current->left != NULL)
            {
                current = current->left;
            }
        }
        else if (root->left)
        {
            current = root->left;
            while (current->right != NULL)
            {
                current = current->right;
            }
        }

        return current;
    }

    node *deleteNode(node *&root, int key)
    {
        cout<<"root->data="<<root->data<<endl;
        if (!root)
        {
            return NULL;
        }
        
        //If there are no right or left child
        if(!root->left){
          cout<<"No left child...\n";
          node* temp = root;
          root = root->right;
          delete temp;
          return root;
        }else if(!root->right){
          cout<<"No right child...\n";
          node* temp = root;
          root = root->left;
          delete temp;
          return root;
        }
        
        if (key < root->data)
        {
            cout << "going left" << endl;
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->data)
        {
            cout << "going right" << endl;
            root->right = deleteNode(root->right, key);
        }
        else
        {
            if (root->left == NULL)
            {
                node *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL)
            {
                node *temp = root->left;
                delete root;
                return temp;
            }

            // node with two children: Get the inorder successor (smallest
            // in the right subtree)
            node *temp = minValueNode(root);

            //print_node(temp, "minvaluenode");

            // Copy the inorder successor's content to this node
            root->data = temp->data;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }

    // Added for rcursion lesson by Griffin
    int treeSum(node*);
    void treeTraversal(node*,string);
    int height(node*);

  public:
    BSTree()
    {
        root = NULL;
    }
    ~BSTree()
    {
    }

    // Added for rcursion lesson by Griffin
    int height();
    void treeTraversal(string);
    int treeSum();


    int count()
    {
        return count(root);
    }

    void insert(int x)
    {
        node *temp = new node(x);
        insert(root, temp);
    }

    void deleteNode(int key)
    {
        deleteNode(root, key);
    }

    void minValue()
    {
        print_node(minValueNode(root), "minVal");
    }


    int top()
    {
        if (root)
            return root->data;
        else
            return 0;
    }


};

// int main()
// {
//     srand(2342);

//     BSTree B;

//     B.insert(38);
//     B.insert(10);
//     B.insert(29);
//     B.insert(27);
//     B.insert(5);
//     B.insert(43);
//     B.insert(36);
//     B.insert(3);
//     B.printLevelOrder();
//     B.GraphVizOut("before.txt");

//     while(B.top()){
//         cout<<"removing: "<<B.top()<<endl;
//         B.deleteNode(B.top());
//     }

//     B.printLevelOrder();

//     //B.GraphVizOut("after.txt");
//     return 0;
// }