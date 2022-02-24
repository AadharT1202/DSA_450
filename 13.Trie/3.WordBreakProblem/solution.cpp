#include<iostream>
using namespace std;
const int Alphabet_Size = 26;

struct TrieNode{
    struct TrieNode *children[Alphabet_Size];
    bool iswordEnd;
};

//Returns a new TrieNode initialized to Null.
struct TrieNode* getNode()
{
    struct TrieNode *temp =  new TrieNode;
    temp->iswordEnd = false;
    for(int i=0; i<Alphabet_Size; i++)
    {
        temp->children[i] = NULL;
    }
    return temp;
}

void insert(struct TrieNode *root, string key)
{
    struct TrieNode *temp = root;
    for(int i=0; i<key.length(); i++)
    {
        int idx = key[i] - 'a';
        if(temp->children[idx]==NULL)
            temp->children[idx] = getNode();
        temp = temp->children[idx];
    }
    temp->iswordEnd = true;
}

bool check(struct TrieNode *root, string inp)
{
    struct TrieNode* temp = root;
    if(inp.size()==0)
        return true;

    for(int i=0; i<inp.length(); i++)
    {
        int idx = inp[i]-'a';
        if(temp->children[idx]==NULL)
        {
            return false;
        }
        
        else if(temp->children[idx]->iswordEnd == true){
                temp = root;
        }

        else
            temp = temp->children[idx];

    }
    return true;
}

int main()
{
    string arr[] = {"mobile","samsung","sam",
                           "sung","ma\n","mango",
                           "icecream","and","go","i",
                           "like","ice","cream"};
    int n = sizeof(arr)/sizeof(arr[0]); 
    struct TrieNode *root = getNode();
    for(int i=0; i<n; i++)
        insert(root,arr[i]);
    
    string inp;
    cout<<"Enter the string: ";
    cin>>inp;
    cout<<check(root,inp)<<endl;
}