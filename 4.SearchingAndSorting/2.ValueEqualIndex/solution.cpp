#include<iostream>
#include<vector>
using namespace std;

vector<int> numEqualIndex(int *arr, int n)
{
    vector<int> sol;
    for(int i=0; i<n; i++)
    {
        if(arr[i]==i+1)
        {
            sol.push_back(arr[i]);
        }
    }
    return sol;
}

int main()
{
    int arr[] = {15, 2, 45, 12, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> ans = numEqualIndex(arr,n);
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
}