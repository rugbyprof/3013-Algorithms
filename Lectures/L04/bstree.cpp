#include <iostream>

using namespace std;

struct Node
{
  int data;
  Node *Left;
  Node *Right;
  Node(int x)
  {
    data = x;
    Left = NULL;
    Right = NULL;
  }
};

class Bstree
{
private:
  Node *root;
  bool real_Search(Node *Temp, int key)
  {
    if (Temp)
    {
      if (Temp->data == key)
      {
        return true;
      }
      else
      {
        if (Temp->data > key)
          return real_Search(Temp->Left, key);
        else
        {
          return real_Search(Temp->Right, key);
        }
      }
    }
    else
    {
      return false;
    }
  }

  void real_PrintTree(Node *Temp)
  {
    if (Temp)
    {
      real_PrintTree(Temp->Left);
      cout << Temp->data << " ";
      real_PrintTree(Temp->Right);
    }
  }

  void real_insert(Node *&nodePtr, Node *&newTreeVal)
  {
    if (nodePtr == NULL)
    {
      nodePtr = newTreeVal;
    }
    else if (newTreeVal->data <= nodePtr->data)
    {
      real_insert(nodePtr->Left, newTreeVal);
    }
    else
    {
      real_insert(nodePtr->Right, newTreeVal);
    }
  }

public:
  Bstree()
  {
    root = NULL;
  }

  void Insert(int x)
  {
    //Empty Bstree
    if (!root)
    {
      root = new Node(x);
    }
    else
    {
      Node *newTreeVal = new Node(x);
      real_insert(root, newTreeVal);
    }
  }

  bool Search(int key)
  {
    Node *Temp = root;
    return real_Search(Temp, key);
  }

  int Delete(int key)
  {
    return 0;
  }

  void PrintTree()
  {
    Node *Temp = root;
    real_PrintTree(Temp);
  }
};

int main()
{
  Bstree T;

  srand(3433);

  for (int i = 0; i < 10; i++)
  {
    T.Insert(rand() % 100);
  }
  T.PrintTree();
  cout << endl;
  cout << T.Search(70) << endl;
}