#include<iostream>
#include<cmath>
using namespace std;

//we could have applied linear search to get the minimum element but that would be O(n).
//we will use binary search.
int finMinElement(int *arr, int n)
{
    int low =0 , high = n-1;
    while(low<=high)
    {
        int mid = low + (high-low)/2 ;
        int prev = (mid-1 + n)  %n;
        int next = (mid+1)%n;

        if(arr[mid]<=arr[prev] && arr[mid]<=arr[next])
            return mid;

        else if (arr[mid]<=arr[high])
            high = mid-1 ;

        else if (arr[mid]>=arr[low])
            low=mid+1;
    }
    return 0;
}

/*int BS(int *arr, int start, int end, int x)
{
    while(start<=end)
    {
        int mid = (start+end)/2;
        if(arr[mid]==x)
            return mid;
        else if(arr[mid]>x)
            end = mid-1;
        else    
            start = mid+1;
    }
    return -1;
}*/

int main()
{
    int arr[] = {11,12,15,18,2,5,6,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 15;
    int min = finMinElement(arr,n);
    int x1 = arr[min-1];
    int x2 = arr[n-1];
    if(x1>=x2)
        cout<<min-1<<endl;
    else if(x2>x1)
        cout<<n-1<<endl;
}