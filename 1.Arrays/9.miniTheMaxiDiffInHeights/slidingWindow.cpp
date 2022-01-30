#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

int getMinDiff(int *arr, int n, int k)
{
    sort(arr,arr+n);
    int ans = arr[n-1] - arr[0];

    for(int i=1; i<n; i++)
    {
        int minEle = min(arr[i]-k,arr[0]+k);
        int maxEle = max(arr[i-1]+k,arr[n-1]-k);

        int diff = maxEle - minEle;
        ans = min(ans,diff); 
    }
    return ans;
}
int main()
{
    int k = 5, n = 10;
    int arr[] = { 8, 1, 5, 4, 7, 5, 7, 9, 4, 6 };
    cout << getMinDiff(arr, n, k) <<endl;
}