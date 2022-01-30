#include<iostream>
using namespace std;
long long countTriplets(long long arr[], int n, long long sum)
{
    sort(arr,arr+n);
    long long count=0;
    for(long long i=0; i<n-2; i++)
    {
        long long start=i+1;
        long long end=n-1;
        while(start<end)
        {
            long long add = arr[i] + arr[start] + arr[end];
            if(add>=sum)
                end--;
            else
            {
                count = count + (end-start);
                start++;
            }
        }
    }
    return count;
}

int main()
{
    long long arr[] = {5, 1, 3, 4, 7};
    int n=sizeof(arr)/sizeof(arr[0]);
    long long sum=12;
    cout<<"Number of triplets: "<<countTriplets(arr,n,sum)<<endl; 
}