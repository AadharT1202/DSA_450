#include<iostream>
using namespace std;
void sort012(int arr[], int n)
{
    int a=1;
    int b=1;
    int i=0;
    int start=0;
    int end=n-1;
    while(i<=end)
    {
        if(arr[i]<a)
        {
            swap(arr[i],arr[start]);
            i++;
            start++;
        }
        else if(arr[i]>b)
        {
            swap(arr[i],arr[end]);
            end--;
        }
        else
            i++;
    }
}

int main()
{
    int arr[]= {0, 2, 1, 2, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort012(arr,n);
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}