#include<iostream>
using namespace std;

int partition(int *arr, int left, int right, int choosenPivotIndex)
{
    int pivotValue = arr[choosenPivotIndex];
    int lesserItemTail = left;
    swap(arr[right], arr[choosenPivotIndex]);
    for(int i=left; i<right; i++)
    {
        if(arr[i]<pivotValue)
        {
            swap(arr[i],arr[lesserItemTail]);
            lesserItemTail++;
        }
    }
    swap(arr[right],arr[lesserItemTail]);
    return lesserItemTail;
}
int kthSmallest(int *arr, int n, int k)
{
    int left = 0;
    int right = n - 1;
    
    while (left <= right) 
    {
        int choosenPivotIndex = rand()%(right - left + 1) + left;
        int indexOfPivot = partition(arr,left,right,choosenPivotIndex);
        if(indexOfPivot == k-1)
            return arr[indexOfPivot];

        else if(indexOfPivot > k-1)
            right = indexOfPivot - 1;
        else
            left = indexOfPivot + 1;
    }
    return -1;
}

int main()
{
    int arr[] = {2,3,1,5,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 2;
    cout<<kthSmallest(arr,n,k)<<endl;
}