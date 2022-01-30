//Naive solution is just sort the array. O(nlogn)
#include<iostream>
using namespace std;

void partition(int *arr, int n, int a, int b)
{
    int start = 0;
    int end = n-1;
    int i=0;
    while(i<=end)
    {
        if(arr[i]<a)
        {
            swap(arr[i],arr[start]);
            start++;
            i++;
        }
        else if (arr[i]>b)
        {
            swap(arr[i],arr[end]);
            end--;
        }
        else
            i++;

    }
}

void printArray(int *arr, int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

int main()
{
    int arr[] = {1,14,5,20,4,2,54,20,87,98,3,1,32,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int a = 10;
    int b = 20;
    partition(arr,n,a,b);
    printArray(arr,n);
}