#include<iostream>
#include<vector>
using namespace std;

long long max(long long n1, long long n2)
{
    if(n1>=n2)
        return n1;
    else 
        return n2;
}
	
long long min(long long n1, long long n2)
{
    if(n1<=n2)
        return n1;
    else
        return n2;
}
long long maxProduct(int *arr, int n) {
    
    if(n==0)
        return -1;
    
    if(n==1)
        return arr[0];
    
    long long maxi = 1;
    long long mini = 1;
    long long res = 1;
    
    for(int i=0; i<n; i++)
    {
        if(arr[i]==0)
        {
            maxi=1;
            mini=1;
            continue;
        }
        long long temp1 = maxi * arr[i];
        long long temp2 = mini * arr[i];
        maxi = max(temp1,temp2);
        maxi = max(arr[i],maxi);
        mini = min(temp1,temp2);
        mini = min(arr[i],mini);
        res = max(maxi,res);
    }
    return res;
}

int main()
{
    int arr[] = {2, 3, 4, 5, -1, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Maximum Product of SubArray is: "<<maxProduct(arr,n)<<endl;
}