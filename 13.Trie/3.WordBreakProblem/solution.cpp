//This code passes around 10000 test cases on gfg can't find the problem.

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

//Inserts the strings in the structure.
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
    if(inp.length()==1)
        return root->children[inp[0]-'a']->iswordEnd;

    for(int i=0; i<inp.length(); i++)
    {
        if(temp->iswordEnd==true)
            temp = root;
    
        int idx = inp[i]-'a';
      
        if(temp->children[idx]==NULL)
            return false;
        temp = temp->children[idx];

    }
    return true;
}

int main()
{
    string arr[] = {"b", "bbbbbbb", "baa", "abbaaa", "ababbba", "bbbbaaa", "bbaaab", "aabbaaaa", "aa", "aa", "babbb",
     "aabbaa", "b", "bb", "aba", "bbbbbb", "aba", "bbbabaaa", "baa", "aabb", "aabb", "aaabbb", "baab", "ababa", "bb",
     "babbbabb", "abab", "bbaaa", "ba", "aaa", "bb", "aabbba", "abab", "babaaba", "baaabab", "babba", "babbb", "ababbaa", 
     "baab", "aababbbb", "babbba", "aaaababa", "baaabbb", "abbaaba", "bbaabaaa", "aaabbba", "abbabbaab", "abb", "abbb",
     "baabbbaa", "babbbbbab", "b", "bbb", "bb", "b", "aababab", "abab", "b", "abb", "bbbbb", "bb", "abbb", "abbbbaa", "bbbbb",
      "babb", "bbabaab", "abbbbaa", "bbbbbaa", "abbbab", "aababb", "ba", "bbbbaaabb", "aa", "bbbbaa","babbabbb", "bbbabbbbb",
       "babbb", "bab", "abaaa", "bbaabb", "abbb", "abaabb", "bb", "ba", "aababbaaa", "bbbbba", "abb", "babababab", "aaabbba",
        "abbaabb", "bbbbbabb", "aa", "bbbabbaa", "aaa", "abba", "b", "aba", "b", "bababb", "aabaaaa"};
    int n = sizeof(arr)/sizeof(arr[0]); 
    struct TrieNode *root = getNode();
    for(int i=0; i<n; i++)
        insert(root,arr[i]);
    
    string inp;
    cout<<"Enter the string: ";
    cin>>inp;
    cout<<check(root,inp)<<endl;
}