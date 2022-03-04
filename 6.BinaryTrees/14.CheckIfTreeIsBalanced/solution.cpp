#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *left;
    Node *right;
};

Node * getNode(int val)
{
    struct Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int height(Node *root)
{
    if(root==NULL)
        return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    
    return 1+max(lh,rh);
}

bool isBalanced(Node *root)
{
    if(root==NULL)
        return true;
        
    int lh = height(root->left);
    int rh = height(root->right);
    
    if(abs(lh-rh)<=1 && isBalanced(root->left) && isBalanced(root->right))
        return true;
    return false;
}

int main()
{
    /*

          1
       /     \
     2        3
   /   \      /    \
  4     5   6    7
    \
     8 
     */

    Node* root = getNode(1);
    root->left = getNode(2);
    root->right = getNode(3);
    root->left->left = getNode(4);
    root->left->right = getNode(5);
    root->left->left->right = getNode(8);
    root->right->left = getNode(6);
    root->right->right = getNode(7);
    bool sol = isBalanced(root);

    if(sol)
        cout<<"Tree is Balanced."<<endl;
    else
        cout<<"Tree is not balanced."<<endl;
}