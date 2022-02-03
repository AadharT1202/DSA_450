#include<iostream>
using namespace std;
bool isValid(int x, int prata, int cooks, int *rank)
{
    int count=0;
    for(int i=0;i<cooks; i++)
    {
        int mul = 2;
        int tempSum=rank[i];
        while(tempSum<=x)
        {
            tempSum = tempSum + (mul * rank[i]);
            count++;
            mul++;
        }
    }
    return (count>=prata);
}
int minTime(int prata,int cooks, int *rank)
{
    int ans=-1;
    int maxi = *max_element(rank, rank + cooks);
    int low=0;
    int high=10e8;
    
    
    while(low<=high)
    {
        int mid = (high+low)/2;

        if(isValid(mid,prata,cooks,rank))
        {
            ans=mid;
            high=mid-1;
        }
        else
            low = mid+1;
    }
    return ans;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int prata;
        int cooks;
        cin>>prata>>cooks;
        int rank[cooks];
        for(int i=0; i<cooks; i++)
        {
            cin>>rank[i];
        }

        cout<<minTime(prata,cooks,rank)<<endl;
    }
}