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

void removeDuplicate(Node *head)
{
    Node * curr = head;
    Node * temp;
    if(curr == NULL)
        return;
    while(curr->next != NULL)
    {
        if(curr->key == curr->next->key)
        {
            temp = curr->next->next;
            free(curr->next);
            curr->next = temp;
        }
        else    
            curr = curr->next;
    }
}

void printList(struct Node* node)
{
	// Print the list after loop removal
	while (node != NULL) {
		cout << node->key << " ";
		node = node->next;
	}
}

int main()
{
    Node* head = newNode(20);
    head->next = newNode(13);
    head->next->next = newNode(13);
    head->next->next->next = newNode(11);
    head->next->next->next->next = newNode(11);
    cout<<"Before removal: "<<endl;
    printList(head);
    removeDuplicate(head);
    cout<<"After removal: "<<endl;
    printList(head);
    cout<<endl;
}