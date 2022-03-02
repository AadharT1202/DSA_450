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

vector <int> bottomView(Node *root) 
{
    vector<int> ans;
    if(!root)
        return ans;
    
    queue<pair<Node*, int> > q;
    map<int,vector<int> > m;
    q.push(make_pair(root,0));
    while(!q.empty())
    {
        Node *temp = q.front().first;
        int h = q.front().second;
        q.pop();
        m[h].push_back(temp->data);
        if(temp->left)
            q.push(make_pair(temp->left,h-1));
        if(temp->right)
            q.push(make_pair(temp->right,h+1));
    }

    map<int,vector<int> >::iterator x = m.begin();
    while (x != m.end()) {
        vector<int> temp = x->second;
        ans.push_back(temp[temp.size()-1]);
        ++x;
    }
    return ans;
        
}
int main()
{
    /*
    Top view of following tree is 4 8 6 3 7.

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
    vector<int> sol = bottomView(root);

    for(int i=0; i<sol.size(); i++)
        cout<<sol[i]<<" ";
    cout<<endl;
}