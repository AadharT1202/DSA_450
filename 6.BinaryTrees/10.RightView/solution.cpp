#include<iostream>
#include<queue>
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

vector<int> rightView(Node *root)
{
    vector<int> ans;
    if(!root)
    return ans;
    
    queue<Node *> q;
    q.push(root);
    while(!q.empty())
    {
        int qsize = q.size();
        ans.push_back(q.back()->data);
        while(qsize--)
        {
            Node *temp = q.front();
            q.pop();
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
    return ans;
}

int main()
{
    /*
    Right view of following tree is 1 3 7 8.

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
    vector<int> sol = rightView(root);

    for(int i=0; i<sol.size(); i++)
        cout<<sol[i]<<" ";
    cout<<endl;
}