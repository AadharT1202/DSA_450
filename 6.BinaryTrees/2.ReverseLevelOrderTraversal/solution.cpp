#include<iostream>
#include<vector>
#include<queue>
#include<stack>
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
//https://practice.geeksforgeeks.org/problems/reverse-level-order-traversal/1
//link to the probelem.
vector<int> reverseLevelOrder(Node *root)
{
    vector<int> ans;
    if(!root)
        return ans;
        
    queue<Node*>q;
    stack<int>s;
    q.push(root);
    while(!q.empty())
    {
        Node *temp = q.front();
        s.push(temp->data);
        q.pop();
        if(temp->right)
            q.push(temp->right);
        if(temp->left)
            q.push(temp->left);
        
    }
    
    while(!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

//Not writing the main function to implement the whole tree.