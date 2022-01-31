#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int minSwaps(int *nums, int n)
{
    int swaps=0;
    vector<pair<int ,int> >v(n);
    for(int i=0;i<n;i++)
        v[i] = make_pair(nums[i] , i);
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        if(i == v[i].second)
        continue;
        else
        {
            swaps++;
            swap(v[i] , v[v[i].second]);
            i--;
        }
    }
    return swaps;
}
int main()
{
    int nums[] = {10, 19, 6, 3, 5};
    int n = sizeof(nums)/sizeof(nums[0]);
    cout<<minSwaps(nums,n)<<endl;
}