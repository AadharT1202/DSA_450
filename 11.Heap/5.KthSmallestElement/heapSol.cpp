#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int kthSmallest(int arr[], int l, int r, int k) 
{
    //code here
    priority_queue<int> q;
    for(int i = l; i<=r; i++)
        q.push(arr[i]);
    for(int i = 0; i<=r-k; i++)
        q.pop();
    return q.top();
}

int main()
{
    int n,k;
    cin>>n>>k;
    int arr[n];

    for(int i=0; i<n; i++)
        cin>>arr[i];

    cout<<kthSmallest(arr,0,n-1,k)<<endl;    

}