#include <iostream>
#include <string> 

using namespace std;

int power(int base, int exponent){
    if (exponent == 0){
        return 1;
    }
    return base * power(base, exponent-1);
}

int fibonnaci(int x) {
   if((x==1)||(x==0)) {
      return(x);
   }else {
      return(fibonnaci(x-1)+fibonnaci(x-2));
   }
}

int factorial(int x){
    if(x == 1){
        return 1;
    }
    return x * factorial(x-1);
}

void message(int x) {
    if (x == 0)
        cout << "Base case \n";
    else {
        cout << "x = " << x << endl;
        message(x - 1);
    }
}

int recursiveArraySum(int *A, int size){
    if(size-1 < 0){
        return 0;
    }
    return A[size-1] + recursiveArraySum(A,size-1);
}


bool palindrome(string p,int i=-1,int j=-1){
    // Initialize i and j assuming they were not passed in
    if(i<0 && j<0){
        i = 0;
        j = p.size()-1;
    }

    // Actual base case
    // If p has ODD length
    if(p.size() % 2 == 1){
        // AND i and j are the same its a palindrome
        if(i == j){
            // r a c e c a r 
            // 0 1 2 3 4 5 6 
            //       ^
            //       |
            return true;
        }
    }else{
        // p is EVEN AND i and j are right next to each other
        if(i == j-1){
            // returns true if they are equal (its a palindrome)
            // false if they arent the same
            // h a n n a h
            // 0 1 2 3 4 5
            //     ^ ^
            //     | |
            return p[i]==p[j];
        }
    }

    // If the two letters at indexes i and j are not 
    // the same it is not a palindrome so return false
    // r a c e c a r s
    // 0 1 2 3 4 5 6 7
    // ^             ^
    // |             |

    if(p[i] != p[j]){
        return false;
    }

    // Move i to the right and j to the left
    return palindrome(p,i+1,j-1);
}

/*
  _____                ____  _          __  __
 |_   _| __ ___  ___  / ___|| |_ _   _ / _|/ _|
   | || '__/ _ \/ _ \ \___ \| __| | | | |_| |_
   | || | |  __/  __/  ___) | |_| |_| |  _|  _|
   |_||_|  \___|\___| |____/ \__|\__,_|_| |_|

*/ 

struct Node{
    Node* left;
    Node* right;
};

int height(Node* root){
    // base case: empty tree has a height of 0
    if (root == nullptr) {
        return 0;
    }
 
    // recur for the left and right subtree and consider maximum depth
    return 1 + max(height(root->left), height(root->right));
}



int treeSum(Node* root){
    if(!root){
        return  0;
    }
    return treeSum(root->left) + treeSum(root->right);
}

void treeTraversal(Node* root){
    if(!root){
        return;
    }
    // pre order
    treeTraversal(root->left);
    // in order
    treeTraversal(root->right);
    // post order
}

void treeTraversal(Node* root,string type="in"){
    if(!root){
        return;
    }
    if(type=="pre"){
        // pre order traversal
    }
    treeTraversal(root->left,type);
    if(type=="in"){
        // in order traversal
    }
    treeTraversal(root->right,type);
    if(type=="post"){
        // post order traversal
    }
}

/*
  _   _                    __        __         _      ____  _          __  __
 | | | | ___  _ __ ___   __\ \      / /__  _ __| | __ / ___|| |_ _   _ / _|/ _|
 | |_| |/ _ \| '_ ` _ \ / _ \ \ /\ / / _ \| '__| |/ / \___ \| __| | | | |_| |_
 |  _  | (_) | | | | | |  __/\ V  V / (_) | |  |   <   ___) | |_| |_| |  _|  _|
 |_| |_|\___/|_| |_| |_|\___| \_/\_/ \___/|_|  |_|\_\ |____/ \__|\__,_|_| |_|

*/

void F(char ch) {
    if ('A' <= ch && ch <= 'H') {
        F(ch - 1);
        cout << ch << endl;
    } else {
        cout << "** \n";
    }
}

int Mystery(int a, int b) {
    int result;
    if (b == 0)
        result = 0;
    else if (b > 0)
        result = a + Mystery(a, b - 1);
    else
        result = Mystery(-a, -b);
    return result;
}

int Mystery2(int x) {
    if (x <= 1)
        return x;
    else
        return Mystery2(x - 1) + Mystery2(x / 2);
}

int main() {
    int A[10] = {5,5,5,5,5,5,5,5,5,5};
    cout<<power(2,10)<<endl;
    int x = 10;
    int i = 0;
    while(i < x) {
      cout << " " << fibonnaci(i)<<" ";
      i++;
   }
   cout<<endl;

   cout<<factorial(5)<<endl;

   cout<<recursiveArraySum(A,10)<<endl;

   cout<<palindrome("racecar")<<endl;
   cout<<palindrome("hannah")<<endl;


    return 0;
}