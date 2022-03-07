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

void rightBoundary(Node *root, vector<int>&v)
{
    if(root==NULL)
        return;
    if(root->right)
    {
        rightBoundary(root->right,v);
        v.push_back(root->data);
    }
    
    else if(root->left)
    {
        rightBoundary(root->left,v);
        v.push_back(root->data);
    }
}

void leftBoundary(Node *root, vector<int>&v)
{
    if(root==NULL)
        return;
    if(root->left)
    {           
        v.push_back(root->data);
        leftBoundary(root->left,v);
    }
    
    else if(root->right)
    {
        v.push_back(root->data);
        leftBoundary(root->right,v);
    }
}

void leafNodes(Node *root, vector<int>&v)
{
    if(root==NULL)
        return;
    
    if(root->left)
        leafNodes(root->left,v);
    
    if(root->right)
        leafNodes(root->right,v);
        
    if(root->right==NULL && root->left==NULL)
        v.push_back(root->data);
}
vector <int> boundary(Node *root)
{
    vector<int> v;
    v.push_back(root->data);
    leftBoundary(root->left,v);
    leafNodes(root->left,v);
    leafNodes(root->right,v);
    rightBoundary(root->right,v);
    return v;
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
    vector<int> sol = boundary(root);

    for(int i=0; i<sol.size(); i++)
        cout<<sol[i]<<" ";
    cout<<endl;
}