//swapping first and last recursively.
//O(n) approach.
#include<iostream>
using namespace std;

void revArray(int *arr, int start, int end)
{
    if(start>end)
        return;

    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    revArray(arr, start+1, end-1);
}

int main()
{
    int arr[] = {1,2,3,4,5};
    int n =  sizeof(arr)/sizeof(arr[0]);
    revArray(arr,0,n-1);
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
}