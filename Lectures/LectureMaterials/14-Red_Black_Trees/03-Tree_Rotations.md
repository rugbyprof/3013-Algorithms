## Tree Rotations


### Rotate Left:

```cpp
void RBTree::RotateLeft(Node *&SubRoot){
    Node *Temp;	
    Temp = SubRoot->right;	
    SubRoot->right = Temp->left;	
    Temp->left = SubRoot;	
    SubRoot = Temp;	
}
```

### Rotate Right:

```cpp
void RBTree::RotateRight(Node *&SubRoot){
    Node *Temp;	
    Temp = SubRoot->left;	
    SubRoot->left = Temp->right;	
    Temp->right = SubRoot;	
    SubRoot = Temp; 
}
```