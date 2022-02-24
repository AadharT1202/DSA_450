#include<iostream>
#include<vector>
using namespace std;
const int Alphabet_Size = 26;

struct TrieNode{
    struct TrieNode *children[Alphabet_Size];
    int wordEndCount;
};

//Returns a new TrieNode initialized to Null.
struct TrieNode* getNode()
{
    struct TrieNode *temp =  new TrieNode;
    temp->wordEndCount = 0;
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
    temp->wordEndCount++;
}

bool search(struct TrieNode *root, string key)
{
    struct TrieNode *temp = root;
    for(int i=0; i<key.length(); i++)
    {
        int idx = key[i] - 'a';
        if(temp->children[idx]==NULL)
            return false;
        temp = temp->children[idx];
    }
    if(temp->wordEndCount>0)
        return true;
    return false;
}

int main()
{

    string keys[] = {"the", "a", "there",
                    "answer", "any", "by",
                     "bye", "their", "aadhar" };

    int n = sizeof(keys)/sizeof(keys[0]);
 
    struct TrieNode *root = getNode();
 
    // Construct trie
    for (int i = 0; i < n; i++)
        insert(root, keys[i]);
 
    // Search for different keys
    search(root, "the")? cout << "Yes\n" : cout << "No\n";
    search(root, "aadhar")? cout << "Yes\n" : cout << "No\n";
    return 0;
}