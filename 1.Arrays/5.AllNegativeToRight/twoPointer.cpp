#include<iostream>
using namespace std;
void printArray(int *arr, int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void twoPointer(int *arr, int n)
{
    int left = 0;
    int right = n-1;
    while(left<=right)
    {
        if(arr[left]<0 && arr[right]<0)
            left++;
        else if(arr[left]>=0 && arr[right]<0)
        {
            swap(arr[left],arr[right]);
            left++;
            right--;
        }
        else if(arr[left]>=0 && arr[right]>=0)
            right--;
        else
        {
            left++;
            right--;
        }
    }
    
}

int main()
{
    int arr[] = { -1, 2, -3, 4, 5, 6, -7, 8, 9 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"Intial Array: ";
    printArray(arr,n);
    twoPointer(arr, n);
    cout<<"Final Array: ";
    printArray(arr, n);
    return 0;
}