#include<iostream>
using namespace std;

int merge(int *arr, int *temp, int left, int mid, int right)
{
    int i,j,k, inv=0;
    i=left;
    j=mid;
    k=left;
    while(i<=mid-1 && j<=right)
    {
        if(arr[i]<=arr[j])
            temp[k++] = arr[i++];
        else{
            temp[k++] = arr[j++];
            inv += mid-i;
        }
    }

    while(i<=mid-1)
        temp[k++] = arr[i++];
    
    while(j<=right)
        temp[k++] = arr[j++];

    return inv;
}

int mergeSort(int *arr, int *temp, int left, int right)
{
    int count=0;
    if(left<right)
    {
        int mid = (left+right)/2;

        count += mergeSort(arr,temp,left,mid);
        count += mergeSort(arr,temp,mid+1,right);
        count += merge(arr,temp,left,mid+1,right);
    }
    return count;
}

int main()
{
    int arr[] = { 1, 20, 6, 4, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int temp[n];
    int ans = mergeSort(arr, temp, 0, n-1);
    cout << " Number of inversions are " << ans<<"\n";
    return 0;
}