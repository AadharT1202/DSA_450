#include<iostream>
#include<vector>
using namespace std;
vector<string> AllPossibleStrings(string s)
{
    int len = s.length();
    int n = (1<<len);
    vector<string> ans;
    
    for(int i=1; i<n; i++)
    {
        int x=i;
        int j=0;
        string c="";
        while(x)
        {
            if(x&1)
            {
                c = c + s[j];
            }
            j++;
            x = x>>1;
        }
        ans.push_back(c);
    }
    sort(ans.begin(),ans.end());
    return ans;
}
int main()
{
    string x;
    cout<<"Enter the string: ";
    cin>>x;
    vector<string> sol = AllPossibleStrings(x);
    for(int i=0; i<sol.size(); i++)
    {
        cout<<sol[i]<<" ";
    }
    cout<<endl;
}