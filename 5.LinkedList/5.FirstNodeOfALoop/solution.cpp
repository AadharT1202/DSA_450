#include<iostream>
using namespace std;

struct Node {
    int key;
    struct Node* next;
};

Node* newNode(int key)
{
    Node* temp = new Node;
    temp->key = key;
    temp->next = NULL;
    return temp;
}

Node* firstNodeOfLoop(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;

    Node* slow_ptr = head;
    Node* fast_ptr = head;

    slow_ptr = slow_ptr->next;
    fast_ptr = fast_ptr->next->next;

    while(slow_ptr!=fast_ptr)
    {
        if(slow_ptr==fast_ptr)
            break;
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
    }

    if(slow_ptr!=fast_ptr)
        return NULL;

    slow_ptr = head;
    while(slow_ptr!=fast_ptr)
    {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next;
    }
    return slow_ptr;
}

int main()
{
    Node* head = newNode(50);
    head->next = newNode(20);
    head->next->next = newNode(15);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(10);
 
    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next;
 
    Node* res = firstNodeOfLoop(head);
    if (res == NULL)
        cout << "Loop does not exist"<<endl;
    else
        cout << "Loop starting node is " << res->key<<endl;
 
    return 0;
}