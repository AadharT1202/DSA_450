#include<iostream>
#include<unordered_set>
using namespace std;

bool sumZero(int *arr, int n)
{
    unordered_set<int> s;
    int sum=0;

    for(int i=0; i<n; i++)
    {
        sum+=arr[i];
        if(sum==0||s.find(sum)!=s.end())
        {
            return true;
        }
        s.insert(sum);
    }
    return false;
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