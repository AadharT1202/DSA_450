#include<iostream>
using namespace std;

int trappingWater(int *arr, int n)
{
    int left=0;
    int right=n-1;
    int leftMax = 0;
    int rightMax = 0;
    int res =0;

    while(left<right)
    {
        if(arr[left]<=arr[right])
        {
            leftMax = max(leftMax,arr[left]);
            res += leftMax - arr[left++];
        }

        else
        {
            rightMax = max(rightMax,arr[right]);
            res += rightMax - arr[right++];
        }
    }
    return res;
}

int main()
{
    int arr[] = {3,0,0,2,0,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<trappingWater(arr,n)<<endl;;
}