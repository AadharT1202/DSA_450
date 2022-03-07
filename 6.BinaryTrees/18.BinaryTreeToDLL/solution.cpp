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

void solve(Node *root,Node *&head, Node *&prev, int &f)
{
    if(!root)
        return;
    solve(root->left,head,prev,f);
    if(f==0)
    {
        f=1;
        head=root;
        prev=root;
    }
    else{
        prev->right = root;
        prev->right->left = prev;
        prev = prev->right;
    }
    solve(root->right,head,prev,f);
}

Node * bToDLL(Node *root)
{
    Node *head = NULL;
    Node *prev = NULL;
    int f=0;
    solve(root,head,prev,f);
    return head;
}

void printList(Node *node)
{
    Node *prev = NULL;
    while (node!=NULL)
    {
        cout << node->data << " ";
        prev = node;
        node = node->right;
    }
    cout << endl;
    while (prev!=NULL)
    {
        cout << prev->data << " ";
        prev = prev->left;
    }
    cout << endl;
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
    Node* sol = bToDLL(root);
    printList(sol);
}