#include<iostream>
using namespace std;
struct Node 
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct Node* reverseList(struct Node *head)
{
    Node* prev = NULL;
    Node* next = NULL;
    Node* curr = head;
    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
//Not writing the code to implement LL.
//question link : https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1/