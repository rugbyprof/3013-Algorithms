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

    node *findNode(node *&root, int key)
    {

        if (!root)
        {
            return NULL;
        }
        else
        {
            if (root->data == key)
            {
                return root;
            }
            else
            {
                if (key < root->data)
                {
                    return findNode(root->left, key);
                }
                else
                {
                    return findNode(root->right, key);
                }
            }
        }
    }

    int countChildren(node *root)
    {
        int children = 0;

        if (!root)
        {
            return 0;
        }

        if (root->left)
        {
            children++;
        }

        if (root->right)
        {
            children++;
        }

        return children;
    }

    node* findMin(node* &root){
        node *temp = root->left;
        while(temp->right){
            temp = temp->right;
        }
        return temp;
    }

    void deleteNode(node *&root, int key)
    {
        if(!root){
            return;
        }
        if(root->data != key){
            if(key < root->data){
                cout<<"going left"<<endl;
                deleteNode(root->left,key);
            }else{
                cout<<"going right"<<endl;
                deleteNode(root->right,key);
            }
        }else{
            cout<<"root->data == "<<key<<endl;
            if (countChildren(root) == 0)
            {
                cout<<"zero children"<<endl;
                root->data = 54;
                delete root;
            }
            else if (countChildren(root) == 1)
            {
                if (root->left)
                {
                    cout<<"left child"<<endl;
                    node *temp = root;
                    root = root->left;
                    delete temp;
                }
                else if (root->right)
                {
                    cout<<"right child"<<endl;
                    node *temp = root;
                    root = root->right;
                    delete temp;
                }
            }
            else
            {
                cout<<"two children"<<endl;
                node *min = findMin(root);
                node *temp = root;
                root = root->right;
                delete temp;
            }

        }
    }

    // node *deleteNode2(node *&root, int key)
    // {
    //     cout << "root->data=" << root->data << endl;
    //     if (!root)
    //     {
    //         return NULL;
    //     }

    //     //If there are no right or left child
    //     if (!root->left)
    //     {
    //         cout << "No left child...\n";
    //         node *temp = root;
    //         root = root->right;
    //         delete temp;
    //         return root;
    //     }
    //     else if (!root->right)
    //     {
    //         cout << "No right child...\n";
    //         node *temp = root;
    //         root = root->left;
    //         delete temp;
    //         return root;
    //     }

    //     if (key < root->data)
    //     {
    //         cout << "going left" << endl;
    //         root->left = deleteNode(root->left, key);
    //     }
    //     else if (key > root->data)
    //     {
    //         cout << "going right" << endl;
    //         root->right = deleteNode(root->right, key);
    //     }
    //     else
    //     {
    //         if (root->left == NULL)
    //         {
    //             node *temp = root->right;
    //             delete root;
    //             return temp;
    //         }
    //         else if (root->right == NULL)
    //         {
    //             node *temp = root->left;
    //             delete root;
    //             return temp;
    //         }

    //         // node with two children: Get the inorder successor (smallest
    //         // in the right subtree)
    //         node *temp = minValueNode(root);

    //         //print_node(temp, "minvaluenode");

    //         // Copy the inorder successor's content to this node
    //         root->data = temp->data;

    //         // Delete the inorder successor
    //         root->right = deleteNode(root->right, temp->data);
    //     }
    //     return root;
    // }

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
    //************************************************************************
    // Method to help create GraphViz code so the expression tree can
    // be visualized. This method prints out all the unique node id's
    // by traversing the tree.
    // Recivies a node pointer to root and performs a simple recursive
    // tree traversal.
    //************************************************************************
    void GraphVizGetIds(node *nodePtr, ofstream &VizOut)
    {
        static int NullCount = 0;
        if (nodePtr)
        {
            GraphVizGetIds(nodePtr->left, VizOut);
            VizOut << "node" << nodePtr->data
                   << "[label=\"" << nodePtr->data << "\\n"
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
    void GraphVizMakeConnections(node *nodePtr, ofstream &VizOut)
    {
        static int NullCount = 0;
        if (nodePtr)
        {
            GraphVizMakeConnections(nodePtr->left, VizOut);
            if (nodePtr->left)
                VizOut << "node" << nodePtr->data << "->"
                       << "node" << nodePtr->left->data << endl;
            else
            {
                NullCount++;
                VizOut << "node" << nodePtr->data << "->"
                       << "nnode" << NullCount << endl;
            }

            if (nodePtr->right)
                VizOut << "node" << nodePtr->data << "->"
                       << "node" << nodePtr->right->data << endl;
            else
            {
                NullCount++;
                VizOut << "node" << nodePtr->data << "->"
                       << "nnode" << NullCount << endl;
            }

            GraphVizMakeConnections(nodePtr->right, VizOut);
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

    void minValue()
    {
        print_node(minValueNode(root), "minVal");
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

    int top()
    {
        if (root)
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
        GraphVizGetIds(root, VizOut);
        GraphVizMakeConnections(root, VizOut);
        VizOut << "}\n";
        VizOut.close();
    }
};

int main(int argc, char **argv)
{
    srand(2342);

    BSTree B;

    B.insert(38);
    B.insert(10);
    B.insert(55);
    B.printLevelOrder();
    //B.GraphVizOut("before.txt");

    // while (B.top())
    // {
    //     cout << "removing: " << B.top() << endl;
    //     B.deleteNode(B.top());
    // }

    // B.printLevelOrder();

    //B.deleteNode(80);
    B.deleteNode(55);

    B.printLevelOrder();

    B.insert(54);

    B.printLevelOrder();

    //B.GraphVizOut("after.txt");
    return 0;
}