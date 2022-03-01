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

void postorder(Node* node)
{
    if(!node)
        return;
    
    postorder(node->left);
    postorder(node->right);
    cout<<node->data<<" ";
}

int main()
{
    /* Construct the following tree
               1
             /   \
            /     \
           2       3
          /      /   \
         /      /     \
        4      5       6
              / \
             /   \
            7     8
    */
 
    Node* root = getNode(1);
    root->left = getNode(2);
    root->right = getNode(3);
    root->left->left = getNode(4);
    root->right->left = getNode(5);
    root->right->right = getNode(6);
    root->right->left->left = getNode(7);
    root->right->left->right = getNode(8);
 
    postorder(root);
    cout<<endl;
    return 0;
}