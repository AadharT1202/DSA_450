#include<iostream>
#include<vector>
using namespace std;
vector<long long int> productExceptSelf(long long int *nums, int n) 
{
       
    vector<long long int> v;
    long long int total =1;
    int z =0;
    for(int i=0; i<n; i++)
    {
        if(nums[i] != 0)
            total = total * nums[i];
        else
            z++;
    }        
    if(z ==0)
    {
        for(int i=0; i<n; i++)
        {
            v.push_back(total/nums[i]);
        }
        return v;
    }
    if (z == 1)
    {
        for(int i=0; i<n; i++)
        {
            if(nums[i] == 0)
                v.push_back(total);
            else
                v.push_back(0);
        }
        return v;
    }
    if (z > 1)
    {
        for(int i=0; i<n; i++)
        {
            v.push_back(0);
        }
        return v;
    }
}

int main()
{
    long long int arr[] = {12,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<long long int> ans = productExceptSelf(arr,n);
    for(int i=0; i<n; i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}