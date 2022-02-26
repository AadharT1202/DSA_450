#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

struct TrieNode{
    bool isWordEnd;
    TrieNode *children[26];
    vector<int> indexes;
};

//Returns a new TrieNode initialized to Null.
struct TrieNode* getNode()
{
    struct TrieNode *temp =  new TrieNode;
    temp->isWordEnd = false;
    for(int i=0; i<26; i++)
    {
        temp->children[i] = NULL;
    }
    return temp;
}

void insert(struct TrieNode* root, string key, int index)
{
    struct TrieNode *temp = root;
    for(int i=0; i<key.length(); i++)
    {
        int idx = key[i]-'a';
        if(temp->children[idx]==NULL)
            temp->children[idx] = getNode();
        temp = temp->children[idx];
    }
    temp->isWordEnd = true;
    temp->indexes.push_back(index);
}

void search(struct TrieNode* root, string key, vector<string> &dict)
{
    struct TrieNode *temp = root;
    for(int i=0; i<key.length(); i++)
    {
        int idx = key[i] - 'a';
        if(temp->children[idx]==NULL)
            return;
        temp = temp->children[idx];
    }
    if(temp->isWordEnd>0)
    {
        for(int i=0; i<temp->indexes.size(); i++)
            cout<<dict[temp->indexes[i]]<<" ";
    }
    cout<<endl;
}

int main()
{
    int n;
    cin>>n;
    vector<string> dict;
    unordered_set<string> uniques;

    for(int i=0; i<n; i++)
    {
        string x;
        cin>>x;
        dict.push_back(x);
    }

    struct TrieNode *root = getNode();

    for(int i=0; i<n; i++)
    {
        string s = dict[i];
        sort(s.begin(),s.end());
        insert(root,s,i);
        uniques.insert(s);
    }

    unordered_set<string> :: iterator itr;
 
    // iterator itr loops from begin() till end()
    for (itr = uniques.begin(); itr != uniques.end(); itr++)
    {
        search(root, *itr, dict);
    }
        

}