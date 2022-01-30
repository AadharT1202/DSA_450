//Approach is whether we take an element or not take it so naieve approach will be exponential
//doing it recursively we will encounter repeating cases so we will be using dp
#include<iostream>
using namespace std;

int thief(int *arr, int n)
{
    //base cases
    //only 1 house to steal from.
    if(n==1)
        return arr[0];
    //if 2 houses only return the max of two
    if(n==2)
        return max(arr[0],arr[1]);
    int dp[n];
    //Now lets initialize the dp array.
    dp[0] = arr[0]; //max(0,arr[0]) basically max of either taking it or leaving it.
    dp[1] = max(arr[0],arr[1]); //either we will take first element or second element.

    for(int i=2; i<n; i++)
    {
        dp[i] = max(arr[i]+dp[i-2],dp[i-1]);
    }
    return dp[n-1];
}

int main()
{
    int arr[] = {5,5,10,100,10,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Maximum loot: "<<thief(arr,n)<<endl;
}