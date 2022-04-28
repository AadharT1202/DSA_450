#include<iostream>
#include<queue>
using namespace std;

vector<int> kLargest(int arr[], int n, int k) 
{
    vector<int> ans;
    priority_queue<int> q;
    for(int i=0; i<n; i++)
    {
        q.push(arr[i]);
    }
    
    for(int i=0; i<k; i++)
    {
        ans.push_back(q.top());
        q.pop();
    }
    
    return ans;
}

int main()
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    vector<int> ans = kLargest(arr,n,k);
    for(int i=0; i<k; i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}
