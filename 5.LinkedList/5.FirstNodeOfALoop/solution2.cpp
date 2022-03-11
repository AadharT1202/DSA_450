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

Node* firstNodeOfLoop(Node *root)
{
    Node * temp;
    Node * next;
    while(root != NULL)
    {
        // This condition is for the case
        // when there is no loop
        if (root->next == NULL) {
            return NULL;
        }
 
        // Check if next is already
        // pointing to temp
        if (root->next == temp) {
            break;
        }

        next  = root->next;
        root->next = temp;
        root = next;
    }
    return root;
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