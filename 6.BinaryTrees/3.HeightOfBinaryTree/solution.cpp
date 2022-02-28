#include<iostream>
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

//code to find height of a binary tree.
//https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1
//link to the probelem.
int height(struct Node* node)
{
    if(node==NULL)
        return 0;
    
    int lh = height(node->left);
    int rh = height(node->right);
    
    return 1+max(lh,rh);
}
//Not writing the main function to implement the whole tree.