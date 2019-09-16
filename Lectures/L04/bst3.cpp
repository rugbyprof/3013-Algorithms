#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

class BST
{

    Node* root;

    Node* makeEmpty(Node* t)
    {
        if (t == NULL)
            return NULL;
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        return NULL;
    }

    Node* insert(int x, Node* t)
    {
        if (t == NULL)
        {
            t = new Node(x);
            t->data = x;
            t->left = t->right = NULL;
        }
        else if (x < t->data)
            t->left = insert(x, t->left);
        else if (x > t->data)
            t->right = insert(x, t->right);
        return t;
    }

    Node* findMin(Node* t)
    {
        if (t == NULL)
            return NULL;
        else if (t->left == NULL)
            return t;
        else
            return findMin(t->left);
    }

    Node* findMax(Node* t)
    {
        if (t == NULL)
            return NULL;
        else if (t->right == NULL)
            return t;
        else
            return findMax(t->right);
    }

    Node* remove(int x, Node* t)
    {
        Node* temp;
        if (t == NULL)
            return NULL;
        else if (x < t->data)
            t->left = remove(x, t->left);
        else if (x > t->data)
            t->right = remove(x, t->right);
        else if (t->left && t->right)
        {
            temp = findMin(t->right);
            t->data = temp->data;
            t->right = remove(t->data, t->right);
        }
        else
        {
            temp = t;
            if (t->left == NULL)
                t = t->right;
            else if (t->right == NULL)
                t = t->left;
            delete temp;
        }

        return t;
    }

    void inorder(Node* t)
    {
        if (t == NULL)
            return;
        inorder(t->left);
        cout << t->data << " ";
        inorder(t->right);
    }

    Node* find(Node* t, int x)
    {
        if (t == NULL)
            return NULL;
        else if (x < t->data)
            return find(t->left, x);
        else if (x > t->data)
            return find(t->right, x);
        else
            return t;
    }

    int height(Node* root)
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

    void print_node(Node* n, string label = "")
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

    /* Print nodes at a given level */
    void printGivenLevel(Node* root, int level)
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
    BST()
    {
        root = NULL;
    }

    ~BST()
    {
        root = makeEmpty(root);
    }

    void insert(int x)
    {
        root = insert(x, root);
    }

    void remove(int x)
    {
        root = remove(x, root);
    }

    void display()
    {
        inorder(root);
        cout << endl;
    }

    void search(int x)
    {
        root = find(root, x);
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

int main(int argc, char **argv)
{
    BST B;

    B.insert(38);
    B.insert(10);
    B.insert(55);
    B.printLevelOrder();
    B.insert(34);
    B.remove(10);
    B.printLevelOrder();
    B.remove(38);
    B.printLevelOrder();
    return 0;
}