#include<iostream>
#include<vector>
using namespace std;
vector<vector<int> > fourSum(int *arr, int n, int k) 
{
    sort(arr,arr+n);
    vector<vector<int> > result;
    for(int i=0; i<n-3; i++)
    {
        /*if(i>0 && arr[i-1]==arr[i])
            continue;*/
        for(int j=i+1; j<n-2; j++)
        {
            /*if(j>i+1 && arr[j]==arr[j-1])
                continue;*/
            int low = j+1;
            int high = n-1;
            while(low<high)
            {
                int sum = arr[i]+arr[j]+arr[low]+arr[high];
                if(sum<k)
                    low++;
                else if(sum>k)
                    high--;
                else
                {
                    vector<int> temp;
                    temp.push_back(arr[i]);
                    temp.push_back(arr[j]);
                    temp.push_back(arr[low]);
                    temp.push_back(arr[high]);
                    result.push_back(temp);
                    low++;
                    high--;
                    /*while(low<high && arr[low]==arr[low-1])
                        low++;
                    while(high>low && arr[high]==arr[high+1])
                        high--;*/
                }
            }
        }
    }
    return result;
}

int main()
{
    int arr[] = {10,2,3,4,5,7,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 23;
    vector<vector<int> > ans = fourSum(arr,n,k);
    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
}