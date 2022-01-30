#include<iostream>
using namespace std;

int firstOccurance(int *arr, int n, int x)
{
    int start=0;
    int end=n-1;
    int ans = INT_MAX;

    while(start<=end)
    {
        int mid = start - (start-end)/2;
        if(arr[mid]==x)
        {
            if(mid<ans)
                ans=mid;
            end = mid-1;
        }
        else if(arr[mid]>x)
            end = mid-1;
        else
            start = mid+1;

    }
    return ans;
}

int lastOccurance(int *arr, int n, int x)
{
    int start=0;
    int end=n-1;
    int ans = INT_MIN;

    while(start<=end)
    {
        int mid = start - (start-end)/2;
        if(arr[mid]==x)
        {
            if(mid>ans)
                ans=mid;
            start = mid+1;
        }
        else if(arr[mid]>x)
            end = mid-1;
        else
            start = mid+1;

    }
    return ans;
}

int main()
{
    int arr[] = { 1, 3, 5, 5, 5, 5, 7, 123, 125 };
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 7;
    cout<<"First Occurance Index: "<<firstOccurance(arr,n,x)<<endl;
    cout<<"Last Occurance Index: "<<lastOccurance(arr,n,x)<<endl;
}