//O(n) time complexity and space complexity.
#include<iostream>
using namespace std;

int maxSubArraySum(int *arr, int n)
{
    int dp[n];
    dp[0] = arr[0];
    for(int i=1; i<n; i++)
    {
        dp[i] = max(dp[i-1]+arr[i], arr[i]);
    }
    int result = INT_MIN;
    for(int i=0; i<n; i++)
    {
        if(dp[i]>result)
            result = dp[i];
    }
    return result;
}

int main()
{
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a)/sizeof(a[0]);
    int max_sum = maxSubArraySum(a, n);
    cout<<"Max Contiguous Subarray Sum is: "<<max_sum<<endl;
    return 0;
}