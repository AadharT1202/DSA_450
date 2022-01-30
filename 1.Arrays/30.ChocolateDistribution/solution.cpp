#include<iostream>
using namespace std;

int diff(int *arr, int n, int m)
{
    sort(arr, arr+n);
    int left=0;
    int right=m-1;
    int minDiff = INT_MAX;
    while (left<n && right<n)
    {
        int diff = arr[right]-arr[left];
        if(diff<minDiff)
            minDiff=diff;
        left++;
        right++;
    }
    return minDiff;
    
}

int main()
{
    int N = 8;
    int M = 5;
    int A[] = {3, 4, 1, 9, 56, 7, 9, 12};
    cout<<diff(A,N,M)<<endl;
}