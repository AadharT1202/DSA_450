#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printArray(vector<int> arr, int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void solve(vector<int> soldiers, vector<int> Bishu, int n, int q)
{
    sort(soldiers.begin(),soldiers.end());
    vector<int> sum;
    sum.push_back(0);
    int s=0;
    for(int i=0; i<n; i++)
    {
        s+=soldiers[i];
        sum.push_back(s);
    }
    for(int i=0; i<q; i++)
    {
        int idx = upper_bound(soldiers.begin(),soldiers.end(),Bishu[i]) - soldiers.begin();
        cout<<idx<<" "<<sum[idx]<<endl;
    }
    
}

int main()
{
    int n,q;
    cout<<"Enter the number of soldiers: "<<endl;
    cin>>n;
    vector<int> soldires;
    cout<<"Enter the powers of soldiers: "<<endl;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        soldires.push_back(x);
    }
    cout<<"Enter the number of queries: "<<endl;
    cin>>q;
    cout<<"Enter bishu power for q rounds: "<<endl;
    vector<int> Bishu;
    for(int i=0; i<q; i++)
    {
        int p;
        cin>>p;
        Bishu.push_back(p);
    }
    solve(soldires,Bishu,n,q);
}