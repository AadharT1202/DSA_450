#include<iostream>
#include<unordered_map>
using namespace std;

int getPairsCount(int *arr, int n, int sum)
{
    unordered_map<int,int> mp;
    int ans=0;
    for(int i=0; i<n; i++)
    {
        int val = sum-arr[i];
        if(mp[val])
            ans+=mp[val];
        mp[arr[i]]++;
    }
    return ans;
}

int main()
{
    int arr[] = {1,1,1,1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 2;
    cout << "Count of pairs is "
         << getPairsCount(arr, n, sum)<<endl;
    return 0;
}