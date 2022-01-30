#include<iostream>
using namespace std;

bool sumZero(int *arr, int n)
{
    bool ans = false;
    for(int i=0; i<n; i++)
    {
        int sum=0;
        for(int j=i; j<n; j++)
        {
            sum+=arr[j];
            if(sum==0)
            {
                ans=true;
                break;
            }
        }
        if(ans) break;
    }
    return ans;
}

int main()
{
    int arr[] = {4,2,-1,1,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    bool ans = sumZero(arr,n);
    if(ans==true)
        cout<<"Yes\n";
    else
        cout<<"No\n";
}