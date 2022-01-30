#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int kthSmallest(int *arr, int n, int k)
{
    priority_queue<int, vector<int>, greater<int> > minHeap;
    for(int i=0; i<n; i++)
    {
        minHeap.push(arr[i]);
    }
    int x;
    for(int i=0; i<k; i++)
    {
        x = minHeap.top();
        minHeap.pop();
    }
    return x;
}
int main()
{
    
    int arr[] = {2,3,1,5,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 2;
    cout<<kthSmallest(arr,n,k)<<endl;
}