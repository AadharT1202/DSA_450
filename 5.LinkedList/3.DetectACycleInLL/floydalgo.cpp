#include<iostream>
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
    Node *slow = head;
    Node *fast = head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast)
            return true;
    }
    return false;
}

//Not writing the code to implement LL
//Link to question : https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1