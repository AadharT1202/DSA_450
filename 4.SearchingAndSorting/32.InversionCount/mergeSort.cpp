//A naieve solution will be using nested loop to find elements such that a[i]>a[j] when i<j
//It will be O(n2)
//Better approach is done below
#include<iostream>
using namespace std;


long long merge(long long arr[], long long l, long long m, long long r)
{
    long long n1 = m-l+1;
    long long n2 = r-m;
    long long *left = new long long[n1];
    long long *right = new long long[n2];
    
    for(long long i=0; i<n1; i++)
        left[i] = arr[l+i];
    for(long long j=0; j<n2; j++)
        right[j] = arr[m+1+j];
        
    long long i=0,j=0,k=l;
    long long count=0;
    while(i<n1 && j<n2)
    {
        if(left[i]<=right[j])
            arr[k++] = left[i++];
        else{
            arr[k++] = right[j++];
            count+=n1-i;
        }
    }
    while(i<n1)
        arr[k++] = left[i++];
    while(j<n2)
        arr[k++] = right[j++];
        
    return count;
    
}
long long sortFunction(long long arr[], long long l, long long r)
{
    long long count=0;
    if(l<r)
    {
        int m = l + (r-l)/2;
        count+=sortFunction(arr,l,m);
        count+=sortFunction(arr,m+1,r);
        count+=merge(arr,l,m,r);
    }
    return count;
}

long long int inversionCount(long long arr[], long long N)
{
    long long ans = sortFunction(arr,0,N-1);
    return ans;
}


int main()
{
    long long N = 5;
    long long arr[] = {2, 4, 1, 3, 5};
    cout<<inversionCount(arr,N)<<endl;
}