#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> mergeHeaps(vector<int> a, vector<int> b, int n, int m) 
{
    priority_queue<int>m1(a.begin(),a.end());
    priority_queue<int>m2(b.begin(),b.end());
    vector<int>v;
    while(!m2.empty())
    {
        m1.push(m2.top());
        m2.pop();
    }
    while(!m1.empty())
    {
        v.push_back(m1.top());
        m1.pop();
    }
    return v;

}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> a;
    vector<int> b;

    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        a.push_back(x);
    }
        
    for(int j=0; j<m; j++)
    {
        int y;
        cin>>y;
        b.push_back(y);
    }
    
    vector<int> ans = mergeHeaps(a,b,n,m);
    for(int i=0; i<ans.size(); i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}