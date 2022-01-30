//Naive solution will be O(n2). Check all the possible subarray of sum greater than X and select the minimum length subarray.
#include<iostream>
using namespace std;

int minLength(int *arr, int n, int X)
{
    int start=0;
    int end=0;
    int sum=0;
    int ans=n+1;

    while(end<n)
    {
        while(sum<=X && end<n)
        {
            sum+=arr[end];
            end++;
        }
        while(sum>X && start<n)
        {
            ans = min(ans,end-start);
            sum-=arr[start];
            start++;
        }
    }
    return ans;
}

int main()
{
    int arr[] = {2,3,5,1,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int X = 6;
    cout<<minLength(arr,n,X)<<endl;
}