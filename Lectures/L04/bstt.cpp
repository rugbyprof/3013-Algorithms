#include <iostream>
#include <fstream>
#include <string>
#include <vector>

//http://www.webgraphviz.com/

using namespace std;

template<typename T>
struct node
{
    T data;
    node *left;
    node *right;
    node()
    {
        data = NULL;
        left = NULL;
        right = NULL;
    }
    node(T x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class BSTree
{
private:
    node<string> *root;

    int count(node<string> *root)
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

    void insert(node<string> *&root, node<string> *&temp)
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

    void print_node(node<string> *n, string label = "")
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
    node<string> *minValueNode(node<string> *root)
    {
        node<string> *current = root;

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

    node<string> *deleteNode(node<string> *&root, string key)
    {
        cout << "root->data=" << root->data << endl;
        if (!root)
        {
            return NULL;
        }

        //If there are no right or left child
        if (!root->left)
        {
            cout << "No left child...\n";
            node<string> *temp = root;
            root = root->right;
            delete temp;
            return root;
        }
        else if (!root->right)
        {
            cout << "No right child...\n";
            node<string> *temp = root;
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
                node<string> *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL)
            {
                node<string> *temp = root->left;
                delete root;
                return temp;
            }

            // node with two children: Get the inorder successor (smallest
            // in the right subtree)
            node<string> *temp = minValueNode(root);

            //print_node(temp, "minvaluenode");

            // Copy the inorder successor's content to this node
            root->data = temp->data;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }

    int height(node<string> *root)
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
    void printGivenLevel(node<string> *root, int level)
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
    void GraphVizGetIds(node<string> *nodePtr, ofstream &VizOut)
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
    void GraphVizMakeConnections(node<string> *nodePtr, ofstream &VizOut)
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

    void insert(string x)
    {
        node<string> *temp = new node<string>(x);
        insert(root, temp);
    }

    void deleteNode(string key)
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

    string top()
    {
        if (root)
            return root->data;
        else
            return 0;
    }

    bool empty(){
        return root == NULL;
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

int main(int argc, char** argv)
{
    string word = "";

    if(argc < 2){
        cout<<"Error: Need an input file!\n";
        exit(0);
    }

    ifstream fin(argv[1]);

    BSTree B;

    while(!fin.eof()){
        fin>>word;
        B.insert(word);
    }


    B.printLevelOrder();
    B.GraphVizOut("before.txt");

    while (!B.empty())
    {
        cout << "removing: " << B.top() << endl;
        B.deleteNode(B.top());
        
    }

    B.printLevelOrder();

    //B.GraphVizOut("after.txt");
    return 0;
}