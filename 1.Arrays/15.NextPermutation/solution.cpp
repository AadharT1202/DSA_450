#include<iostream>
using namespace std;

void nextPer(int *arr, int n)
{
    int index=-1;
    for(int i=n-1; i>=0; i--)
    {
        if(arr[i]>arr[i-1])
        {
            index = i-1;
            break;
        }
    }
    if(index==-1)
    {
        //reverse the array and return.
        int start=0;
        int end=n-1;
        while(start<=end)
        {
            swap(arr[start],arr[end]);
            start++;
            end--;
        }
    }

    else{
        int val = arr[index];
        for(int i=n-1; i>=index+1; i--)
        {
            if(arr[i]>=val)
            {
                swap(arr[i],arr[index]);
                break;
            }
        }
        int start = index+1;
        int end = n-1;
        while(start<=end)
        {
            swap(arr[start],arr[end]);
            start++;
            end--;
        }
    }
}

int main()
{
    int arr[] = {4,1,7,5,3,2,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    nextPer(arr,n);
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}