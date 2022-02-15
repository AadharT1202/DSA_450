#include<iostream>
#include<vector>
using namespace std;

vector<int> singleNumber(vector<int> nums) 
{
    int a=0;
    int b=0;
    int n=nums.size();
    int XOR = 0;
    
    for(int i=0; i<n; i++)
        XOR = XOR ^ nums[i];
        
    int rmsb = XOR & ~(XOR-1);
    for(int i=0; i<n; i++)
    {
        if((rmsb & nums[i]) == 0)
            a = a ^ nums[i];
        else
            b = b ^ nums[i];
    }
    
    vector<int> ans;
    if(a>b)
    {
        ans.push_back(b);
        ans.push_back(a);
    }
    else
    {
        ans.push_back(a);
        ans.push_back(b);
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int> nums;
    for(int i=0; i<n; i++)
    {
        int c;
        cin>>c;
        nums.push_back(c);
    }
    vector<int> ans = singleNumber(nums);
    cout<<ans[0]<<" "<<ans[1]<<endl;
}