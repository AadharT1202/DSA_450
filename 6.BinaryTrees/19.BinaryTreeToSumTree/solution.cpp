#include<iostream>
#include<vector>
using namespace std;

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

Node * getNode(int val)
{
    struct Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int solve(Node *root)
{
    if(!root)
        return 0;
    int a = solve(root->left);
    int b = solve(root->right);
    int x = root->data;
    root->data = a+b;
    return a+b+x;
}

void inorder(Node * node)
{
    if(node==NULL)
        return;
    
    inorder(node->left);
    cout<<node->data<<" ";
    inorder(node->right);
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
    inorder(root);
    cout<<endl;
    solve(root);
    inorder(root);
    cout<<endl;
}