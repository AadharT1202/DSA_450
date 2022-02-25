#include<iostream>
#include<vector>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    
    void dfs(Node* node, Node* copy, vector<Node*> &visited)
    {
        visited[copy->val] = copy;
        for(int i=0; i<(node->neighbors).size(); i++)
        {
            if(visited[node->neighbors[i]->val]==NULL)
            {
                Node* temp = new Node(node->neighbors[i]->val);
                (copy->neighbors).push_back(temp);
                dfs(node->neighbors[i],temp,visited);
            }
            else
                (copy->neighbors).push_back(visited[node->neighbors[i]->val]);
        }
    }
    
    Node* cloneGraph(Node* node) {
        if(node==NULL)
            return NULL;
        vector<Node* > visited(1000,NULL);
        Node* copy = new Node(node->val);
        dfs(node,copy,visited);
        return copy;
    }
};

int main()
{
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    (node1->neighbors).push_back(node2);
    (node1->neighbors).push_back(node4);
    (node2->neighbors).push_back(node1);
    (node2->neighbors).push_back(node3);
    (node3->neighbors).push_back(node2);
    (node3->neighbors).push_back(node4);
    (node4->neighbors).push_back(node1);
    (node4->neighbors).push_back(node3);

    Solution s;
    Node* copy = s.cloneGraph(node1);
    vector<Node *> n1 = copy->neighbors;
    cout<<copy->val<<"--> ";
    for(int i=0; i<n1.size(); i++)
        cout<<n1[i]->val<<" ";
    cout<<endl;
    //similarly we can check for other nodes as well;

}