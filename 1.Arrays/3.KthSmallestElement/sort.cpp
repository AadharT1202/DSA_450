#include<iostream>
#include<algorithm>
using namespace std;

int kthsmallest(int *arr, int n, int k)
{
    sort(arr, arr+n);
    return (arr[k-1]);
}

int main()
{
    int arr[] = {12,3,5,7,19};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k;
    cout<<"Enter the value of k: ";
    cin>>k;
    cout<<"The kth smallest element in the array is: "<<kthsmallest(arr,n,k)<<endl;
}