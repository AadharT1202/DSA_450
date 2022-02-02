#include<iostream>
#include<utility>
#include<unordered_map>
#include<vector>
using namespace std;

vector<pair<int, int> > subArray(int *arr, int n)
{
    unordered_map<int, vector<int> > mp;
    vector<pair<int,int> > result;
    int sum=0;
    for(int i=0; i<n; i++)
    {
        sum+=arr[i];
        if(sum==0)
            result.push_back(make_pair(0,i));
        
        if(mp.find(sum)!=mp.end())
        {
            vector<int> temp = mp[sum];
            for(int j=0; j<temp.size(); j++)
            {
                result.push_back(make_pair(temp[j]+1,i));
            }
        }

        mp[sum].push_back(i);
    }
    return result;
}

int main()
{
    int arr[] = {0,0,5,5,0,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<pair<int, int> > ans = subArray(arr,n);
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i].first<<" "<<ans[i].second <<endl;
    }
}