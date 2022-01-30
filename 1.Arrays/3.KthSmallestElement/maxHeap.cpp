#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int kthSmallest(int *arr, int n, int k)
{
    priority_queue<int, vector<int> > maxHeap;
    for(int i=0; i<k; i++)
    {
        maxHeap.push(arr[i]);
    }
    for(int j=k; j<n; j++)
    {
        if(arr[j]<maxHeap.top())
        {
            maxHeap.push(arr[j]);
            maxHeap.pop();
        }
    }
    
    return maxHeap.top();
}
int main()
{
    
    int arr[] = {2,3,1,5,4,0,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 2;
    cout<<kthSmallest(arr,n,k)<<endl;
}