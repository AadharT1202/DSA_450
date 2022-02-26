#include<iostream>
#include<vector>
using namespace std;
struct TrieNode{
    bool isEnd;
    TrieNode* children[26];
    TrieNode(){
        isEnd = false;
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
    }
};
TrieNode* head = new TrieNode();
void insert(string s){
    TrieNode* temp = head;
    for(int i=0;i<s.size();i++){
        int idx = s[i]-'a';
        if(!temp->children[idx]){
            temp->children[idx] = new TrieNode();
        }
        temp = temp->children[idx];
    }
    temp->isEnd = true;
}
void findContactUtil(TrieNode* root,vector<string> &res,string s){
    if(!root)return;
    TrieNode* temp = root;
    if(temp->isEnd){
        res.push_back(s);
    }
    for(int i=0;i<26;i++){
        char ch = char(i+'a');
        findContactUtil(temp->children[i],res,s+ch);
    }
}
void findContact(string s,vector<string> &res){
    TrieNode* temp = head;
    for(int i=0;i<s.size();i++){
        int idx = s[i]-'a';
        if(!temp->children[idx]){
            return ;
        }
        temp = temp->children[idx];
    }
    findContactUtil(temp,res,s);
}
vector<vector<string> > displayContacts(int n, string contact[], string s)
{
    for(int i=0;i<n;i++){
        insert(contact[i]);
    }
    vector<vector<string> > res;
    for(int i=1;i<=s.size();i++){
        vector<string> temp;
        findContact(s.substr(0,i),temp);
        if(temp.size()==0){
            temp.push_back(to_string(0));
        }else{
            sort(temp.begin(),temp.end());    
        }
        res.push_back(temp);
    }
    return res;
}

int main()
{
    int n;
    cout<<"Enter the number of contacts: ";
    cin>>n;
    string contacts[n];
    for(int i=0; i<n; i++)
    {
        cin>>contacts[i];
    }
    cout<<"Enter query string: ";
    string q;
    cin>>q;
    vector<vector<string> > ans = displayContacts(n,contacts,q);
    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
