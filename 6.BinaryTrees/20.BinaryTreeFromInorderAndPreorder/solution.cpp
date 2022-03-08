#include<iostream>
#include<vector>
using namespace std;
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

int preIndex = 0;
Node* solve(int in[],int pre[],int start, int end)
{
    if(start>end)
        return NULL;
    
    Node* root = new Node(pre[preIndex++]);
    int index;
    for(int i=start; i<=end; i++)
    {
        if(in[i]==root->data)
        {
            index = i;
            break;
        }
    }
    
    root->left = solve(in,pre,start,index-1);
    root->right = solve(in,pre,index+1, end);
    
    return root;
}

Node* buildTree(int in[],int pre[], int n)
{
    Node *root = solve(in,pre,0,n-1);
    return root;
}

void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

int main()
{
    cout<<"Enter the number of nodes: ";
    int n;
    cin>>n;
    int inorder[n], preorder[n];
    cout<<"Enter the inorder array: ";
    for(int i=0; i<n; i++)
        cin>> inorder[i];
    cout<<"Enter preorder array: ";
    for(int i=0; i<n; i++)
        cin>> preorder[i];
    Node *root = buildTree(inorder, preorder, n);
    cout<<"Post order traversal of the tree formed: ";
    printPostOrder(root);
    cout<< endl;
}