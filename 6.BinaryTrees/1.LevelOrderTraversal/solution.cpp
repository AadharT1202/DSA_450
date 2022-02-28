#include<iostream>
#include<vector>
#include<queue>
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

//code to do the level order traversal.
//https://practice.geeksforgeeks.org/problems/level-order-traversal/1
//link to the probelem.
vector<int> levelOrder(Node* node)
{
    vector<int> ans;
    if(!node)
    return ans;
    queue<Node *> q;
    q.push(node);
    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        ans.push_back(temp->data);
        
        if(temp->left)
        q.push(temp->left);
        
        if(temp->right)
        q.push(temp->right);
    }
    return ans;
}

//Not writing the main function to implement the whole tree.