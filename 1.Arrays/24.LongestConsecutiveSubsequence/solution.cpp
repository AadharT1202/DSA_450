#include<iostream>
#include<unordered_set>
using namespace std;

int longestSubsequence(int *arr, int n)
{
    unordered_set<int> set(arr,arr+n);
    int ans = 0;
    for(int i=0; i<n; i++)
    {
        //here we are finding the start of the sequence so basically if the element previous to current element is not present
        //in the set than it is the starting point of the sequence.
        //then we store the next element in the sequence i.e arr[i]+1 and keep on checking whether next element is present in 
        //the set or not. then we just update the ans variable val - arr[i] gives the number of elements in the sequence.
        if(set.find(arr[i]-1)==set.end())
        {
            int val = arr[i] + 1;
            while(set.find(val)!=set.end())
                val++;
            ans = max(ans,val-arr[i]);
        }
    }
    return ans;
}

int main()
{
    int arr[] = {2,6,1,9,4,5,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int ans = longestSubsequence(arr,n);
    cout<<ans;
}