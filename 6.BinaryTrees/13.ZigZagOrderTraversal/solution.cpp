#include<iostream>
#include<queue>
#include<map>
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

vector <int> zigZagTraversal(Node* root)
{
    vector<int> ans;
    if(!root)
        return ans;
    queue<Node *> q;
    q.push(root);
    int level = 1;
    while(!q.empty())
    {
        vector<int> temp;
        int qsize = q.size();
        while(qsize--)
        {
            Node *t = q.front();
            q.pop();
            temp.push_back(t->data);
            if(t->left)
                q.push(t->left);
            if(t->right)
                q.push(t->right);
        }
        if(level%2==0)
            reverse(temp.begin(),temp.end());
        for(int i=0; i<temp.size(); i++)
            ans.push_back(temp[i]);
        level++;
    }
    return ans;
}

int main()
{
    /*
    zig zag traversal of following tree is 1 3 2 4 5 6 7 8 .

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
    vector<int> sol = zigZagTraversal(root);

    for(int i=0; i<sol.size(); i++)
        cout<<sol[i]<<" ";
    cout<<endl;
}