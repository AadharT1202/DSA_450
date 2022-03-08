#include<iostream>
#include<unordered_set>
using namespace std;
struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

bool detectLoop(Node* head)
{
    unordered_set<Node *> m;
    while(head!=NULL)
    {
        if(m.find(head)!=m.end())
            return true;
            
        m.insert(head);
        head = head->next;
    }
    return false;
}
//Not writing the code to implement LL
//Link to question : https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1