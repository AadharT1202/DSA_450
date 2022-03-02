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

vector<int> topView(Node *root)
{
    vector<int> ans;
    if(!root)
        return ans;
    map<int,int> mp;
    queue<pair<Node*, int> > q;
    q.push(make_pair(root,0));
    while(!q.empty())
    {
        Node *temp = q.front().first;
        int h = q.front().second;
        q.pop();
        if(!mp[h])
            mp[h] = temp->data;
        if(temp->left)
            q.push(make_pair(temp->left,h-1));
        if(temp->right)
            q.push(make_pair(temp->right,h+1));
    }

    map<int,int>::iterator x = mp.begin();
    while (x != mp.end()) {
        ans.push_back(x->second);
        ++x;
    }
    return ans;
}
int main()
{
    /*
    Top view of following tree is 4 2 1 3 7.

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
    vector<int> sol = topView(root);

    for(int i=0; i<sol.size(); i++)
        cout<<sol[i]<<" ";
    cout<<endl;
}