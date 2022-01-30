#include<iostream>
#include<vector>
using namespace std;

vector<int> find(int *arr, int n)
{
    int repeat;
    int missing;
    
    for(int i=0; i<n; i++)
    {
        if(arr[abs(arr[i])-1]<0)
            repeat = abs(arr[i]);
        else
            arr[abs(arr[i])-1] = -arr[abs(arr[i])-1];
    }
    
    for(int i=0; i<n; i++)
    {
        if(arr[i]>0)
        {
            missing = i+1;
            break;
        }
            
    }
    vector<int> result;
    result.push_back(repeat);
    result.push_back(missing);
    return result;
}

int main()
{
    int arr[] = {1,3,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> ans = find(arr,n);
    cout<<"Repeating element is: "<<ans[0]<<endl;
    cout<<"Missing element is: "<<ans[1]<<endl;
}