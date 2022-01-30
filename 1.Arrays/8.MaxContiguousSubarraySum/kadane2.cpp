//O(n) time complexity and space complexity.
#include<iostream>
using namespace std;

int maxSubArraySum(int *arr, int n)
{
    int maxi = arr[0];
    int max_till_here = arr[0];
    for(int i=1; i<n; i++)
    {
        max_till_here = max(max_till_here + arr[i], arr[i]);
        maxi = max(maxi,max_till_here);
    }
    return maxi;
}

int main()
{
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a)/sizeof(a[0]);
    int max_sum = maxSubArraySum(a, n);
    cout<<"Max Contiguous Subarray Sum is: "<<max_sum<<endl;
    return 0;
}