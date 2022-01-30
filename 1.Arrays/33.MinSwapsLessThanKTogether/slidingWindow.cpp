#include<iostream>
using namespace std;
int minSwaps(int *arr, int n, int k)
{
    int good=0;
    int bad=0;

    for(int i=0; i<n; i++)
    {
        if(arr[i]<=k)
            good++;
    }

    for(int i=0; i<good; i++)
    {
        if(arr[i]>k)
            bad++;
    }
    
    int left=0;
    int right=good;
    int ans = bad;
    while(right<n)
    {
        if(arr[left]>k)
            bad--;
        if(arr[right]>k)
            bad++;
        ans = min(ans,bad);
        right++;
        left++;
    }
    return ans;

}

int main()
{
    int arr[] = {2,7,9,5,8,7,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k=6;
    cout<<minSwaps(arr,n,k)<<endl;
}