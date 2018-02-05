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

        if(root->right){
            current = root->right;
            while (current->left != NULL){
                current = current->left;
            }
        }else if(root->left){
            current = root->left;
            while (current->right != NULL){
                current = current->right;
            }
        }

        return current;
    }

    node *deleteNode(node *&root, int key)
    {
        if (!root)
        {
            return NULL;
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

            print_node(temp,"minvaluenode");

            // Copy the inorder successor's content to this node
            root->data = temp->data;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
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

    void deleteNode(int key)
    {
        deleteNode(root, key);
    }

    void minValue(){
        print_node(minValueNode(root),"minVal");
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

    int top(){
        if(root)
            return root->data;
        else
            return 0;
    }

    /* Function to line by line print level order traversal a tree*/
    void printLevelOrder()
    {
        cout << "Begin Level Order===================\n";
        int h = height(root);
        int i;
        for (i = 1; i <= h; i++)
        {
            printGivenLevel(root, i);
            cout << "\n";
        }
        cout << "End Level Order===================\n";
    }
};


int main()
{
    srand(2342);

    BSTree B;

    B.insert(38);
    B.insert(10);
    B.insert(29);
    B.insert(27);
    B.insert(5);
    B.insert(43);
    B.insert(36);
    B.insert(3);
    B.printLevelOrder();
    cout<<endl<<endl;
    B.deleteNode(29);
    B.printLevelOrder();

    cout<<endl<<endl;
    B.deleteNode(36);
    B.printLevelOrder();

    return 0;
}