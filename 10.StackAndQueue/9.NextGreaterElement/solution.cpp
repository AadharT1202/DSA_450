#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<long long> nextLargerElement(vector<long long> arr, int n)
{
    stack<long long>s;
    vector<long long>v;
    for(long long i=n-1;i>=0;i--)
    {
        while(!s.empty() && s.top()<=arr[i])
        {
            s.pop();
        }
        if(s.empty())
        {
            v.push_back(-1);
        }
        else
        {
            v.push_back(s.top());
        }
        s.push(arr[i]);
    }
    reverse(v.begin(),v.end());
    return v;
}

int main()
{
    vector<long long> v;
    int n;
    cout<<"Enter the number of elements";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    vector<long long> sol = nextLargerElement(v,n);
    for(int i=0; i<n; i++)
    {
        cout<<sol[i]<<" ";
    }
    cout<<endl;
}