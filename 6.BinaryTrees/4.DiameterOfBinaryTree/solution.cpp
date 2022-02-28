#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

Node * newNode(int val)
{
    struct Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int height(Node *root, int &ans)
{
    if(root==NULL)
        return 0;
    int lh = height(root->left,ans);
    int rh = height(root->right,ans);
    ans = max(ans, lh+rh+1);
    return 1+max(lh,rh);
}

int diameter(Node* root) {
    if(root == NULL)
        return 0;
    int ans = INT_MIN;
    height(root,ans);
    return ans;
}

// Driver code
int main()
{
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
 
    printf("Diameter is %d\n", diameter(root));
 
    return 0;
}