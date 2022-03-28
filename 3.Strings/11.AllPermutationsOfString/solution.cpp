#include<iostream>
#include<vector>
using namespace std;

void permutation(string s, int i, vector<string>&res)
{
    if(i>=s.size()){
        res.push_back(s);
        return;
    }
    
    for(int j=i; j<s.size(); j++){
        swap(s[i], s[j]);
        permutation(s, i+1, res);
        swap(s[i], s[j]);
    }
}
vector<string>find_permutation(string S)
{
    vector<string>res;
        permutation(S, 0, res);
        sort(res.begin(), res.end());
        return res;		
}

int main()
{
    cout<<"Enter string: ";
    string x;
    cin>>x;
    vector<string> ans = find_permutation(x);
    for(int i=0; i<ans.size(); i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}