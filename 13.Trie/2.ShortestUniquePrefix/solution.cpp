#include<iostream>
#include<vector>
using namespace std;

vector<string> solution;

struct TrieNode{
    int pc;
    struct TrieNode *children[26];
};

struct rootNode{
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
void search(struct TrieNode *root, string key)
{
    struct TrieNode *temp = root;
    string x = "";
    for(int i=0; i<key.length(); i++)
    {
        int idx = key[i] - 'a';
        if(temp->children[idx]==NULL)
            solution.push_back(" ");
        else
        {
            char toBeCon = char(idx + 'a');
            x = x + toBeCon;
            if(temp->children[idx]->pc == 1)
            {
                solution.push_back(x);
                break;
            }
            temp = temp->children[idx];
        }
        
    }
}

int main()
{
    string arr[] = {"zebra", "dog", "duck", "dove"};
    int n = sizeof(arr)/sizeof(arr[0]);
    struct TrieNode *root = getNode();
    root->pc=0;

    for(int i=0; i<n; i++)
        insert(root,arr[i]);
    
    for(int i=0; i<n; i++)
        search(root, arr[i]);

    for(int i=0; i<solution.size(); i++)
        cout<<solution[i]<<" ";
    cout<<endl;
}