#include<iostream>
using namespace std;

struct TrieNode{
    int pc;
    struct TrieNode *children[26];
};

struct TrieNode* getNode()
{
    struct TrieNode* temp = new TrieNode;
    temp->pc = 1;
    for(int i=0; i<26; i++)
        temp->children[i]=NULL;
    return temp;
}

void insert(struct TrieNode* root, string key)
{
    struct TrieNode* temp = root;
    for(int i=0; i<key.length(); i++)
    {
        int idx = key[i] - 'a';
        if(temp->children[idx]==NULL)
            temp->children[idx] = getNode();
        else
            temp->children[idx]->pc++;
        temp = temp->children[idx];
    }
}

int main()
{
    string arr[] = { "i", "like", "sam", "sung", "samsung", "mobile", "ice", 
  "cream", "icecream", "man", "go", "mango"};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<n;
}