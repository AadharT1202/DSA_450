#include<iostream>
using namespace std;
bool isValid(int x, int k, int arr[], int n)
{
    int count=1;
    int sum=0;
    for(int i=0; i<n; i++)
    {
        if(sum+arr[i]>x)
        {
            sum=arr[i];
            count++;
        }
        else
            sum+=arr[i];
    }
    cout<<"Count: "<<count<<endl;
    return (count<=k);
}

long long minTime(int arr[], int n, int k)
{
    long long result = INT_MAX;
    long long low = *max_element(arr, arr + n);
    long long high=0;
    for(int i=0; i<n; i++)
        high+=arr[i];
        
    while(low<=high)
    {
        long long mid=(low+high)/2;
        cout<<"Low: "<<low<<" "<<"Mid: "<<mid<<" "<<"High: "<<high<<endl; 
        if(isValid(mid,k,arr,n))
        {
            result=mid;
            high=mid-1;
        }
        else
            low=mid+1;
    }
    return result;
    
}
int main()
{
    int n=4;
    int k=2;
    int arr[] = {10,20,30,40};
    cout<<minTime(arr,n,k)<<endl;
}