#include <iostream>
#include <string>
#include <vector>

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

    void print_node(node* n,string label=""){
        if(label != ""){
            cout<<"["<<label<<"]";
        }
        cout<<"[["<<n<<"]["<<n->data<<"]]\n";
        if(n->left)
            cout<<"\t|-->[["<<n->left<<"]["<<n->left->data<<"]]\n";
        if(n->right)
            cout<<"\t\\-->[["<<n->right<<"]["<<n->right->data<<"]]\n";
    }

    bool remove(node *&root, int key)
    {
        if (!root)
        {
            return false;
        }
        else
        {
            if (key == root->data)
            {
                cout<<"doing it!"<<endl;
                print_node(root,"root");
                return do_removal(root);
            }
            else if (key < root->data)
            {
                cout<<"going left"<<endl;
                return remove(root->left, key);
            }
            else
            {
                cout<<"going left"<<endl;
                return remove(root->right, key);
            }
        }
    }

    bool do_removal(node *&root)
    {
        if(!root->left && !root->right){
            print_node(root,"root");
            delete root;
            print_node(root,"root");
            return true;
        }
        return false;
    }

    int height(node *root)
    {
        if (!root)
        {
            return 0;
        }
        else
        {
            int left = height(root->left);
            int right = height(root->right);
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

    /* Print nodes at a given level */
    void printGivenLevel(node *root, int level)
    {
        if (root == NULL)
            return;
        if (level == 1)
        {
            print_node(root);
        }
        else if (level > 1)
        {
            printGivenLevel(root->left, level - 1);
            printGivenLevel(root->right, level - 1);
        }
    }

  public:
    BSTree()
    {
        root = NULL;
    }
    ~BSTree()
    {
    }

    int count()
    {
        return count(root);
    }
    void insert(int x)
    {
        node *temp = new node(x);
        insert(root, temp);
    }
    void remove(int key)
    {
        remove(root, key);
    }

    int height(int key = -1)
    {
        if (key > 0)
        {
            //find node
        }
        else
        {
            return height(root);
        }
        return 0;
    }
    /* Function to line by line print level order traversal a tree*/
    void printLevelOrder()
    {
        int h = height(root);
        int i;
        for (i = 1; i <= h; i++)
        {
            printGivenLevel(root, i);
            cout << "\n";
        }
    }
};

int main()
{
    srand(2342);
    vector <int> used;

    BSTree B;

    B.insert(38);
    B.insert(10);
    B.insert(29);
    B.insert(27);
    B.insert(5);
    B.insert(43);
    B.insert(38);
    B.insert(43);
    B.insert(3);


    B.printLevelOrder();

    B.remove(27);
    cout << endl << endl;
    B.printLevelOrder();   
    return 0;
}