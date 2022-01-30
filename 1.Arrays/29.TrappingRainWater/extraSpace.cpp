#include<iostream>
using namespace std;

long long trappingWater(int arr[], int n)
{
    long long int  res=0;
    int lmax[n];
    int rmax[n];
    //finding lmax by comparing element
    lmax[0]=arr[0];
    for(int i=1;i<n;i++)
    {
        lmax[i]=max(arr[i],lmax[i-1]);
    }
    //finding rmax by comparing element 
    rmax[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--)
    {
        rmax[i]=max(arr[i],rmax[i+1]);
    
    }
    //now min of lmax and rmax and then subtract to original array
    for(int i=1;i<n-1;i++)
    {
        res=res+(min( lmax[i],rmax[i])-arr[i]);
    }
    return res;
}

int main()
{
    int arr[] = {3,0,0,2,0,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<trappingWater(arr,n);
}