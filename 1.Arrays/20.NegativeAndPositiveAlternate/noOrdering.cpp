#include<iostream>
using namespace std;

void printArray(int *arr, int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

int partitionAlgo(int *arr, int n)
{
    int pivot = 0;
    int tail = 0;
    for(int i=0; i<n; i++)
    {
        if(arr[i]<pivot)
        {
            swap(arr[i],arr[tail]);
            tail++;
        }
    }
    return tail;
}

int main()
{
    int arr[] = {-1, 2, -3, 4,
                  5, 6, -7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int firstPositive = partitionAlgo(arr,n);
    int neg = 1;
    while (firstPositive < n && neg < firstPositive &&
                     arr[neg] < 0)
    {
        swap(arr[neg], arr[firstPositive]);
        firstPositive++;
        neg += 2;
    }
    printArray(arr,n);
    return 0;
}