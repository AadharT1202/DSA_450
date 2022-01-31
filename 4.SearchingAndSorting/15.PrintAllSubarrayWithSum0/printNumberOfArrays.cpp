#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
long long findSubarray(long long *arr, int n ) 
{
    unordered_map<long long,int> mp;
    
    long long ans = 0;
    long long sum = 0; 
    mp[0]++;
    for(int i=0; i<n; i++)
    {
        sum += arr[i];
        if(mp.find(sum) != mp.end()) 
            ans += mp[sum];
        mp[sum]++;
    }
    
    return (ans);
}
int main()
{
    long long arr[] = {0,0,5,5,0,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<findSubarray(arr,n)<<endl;
}