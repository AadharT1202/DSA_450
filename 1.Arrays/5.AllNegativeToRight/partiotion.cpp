#include<iostream>
using namespace std;

void partitionAlgo(int *arr, int n)
{
    int pivot = INT_MAX;
    int index = -1;
    for(int i=0; i<n; i++)
    {
        if(arr[i]>0)
        {
            if(arr[i]<pivot)
            {
                pivot = arr[i];
                index = i;
            }
                
        }
    }
    swap(arr[index],arr[n-1]);
    int tail=0;
    for(int i=0; i<n-1; i++)
    {
        if(arr[i]<pivot)
        {
            swap(arr[i],arr[tail]);
            tail++;
        }
    }
    swap(arr[tail],arr[n-1]);
}
void printArray(int *arr, int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int arr[] = { -1, 2, -3, 4, 5, 6, -7, 8, 9 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"Intial Array: ";
    printArray(arr,n);
    partitionAlgo(arr, n);
    cout<<"Final Array: ";
    printArray(arr, n);
    return 0;
}