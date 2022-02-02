#include<iostream>
using namespace std;
bool isValid(int A[], int N, int M, int maxNum)
{
    int count=1;
    int sum=0;
    for(int i=0; i<N; i++)
    {
        if(sum+A[i]>maxNum)
        {
            count++;
            sum=A[i];
        }
        else    
            sum+=A[i];
    }
   
    return (count<=M);
}
int findPages(int A[], int N, int M) 
{
    if(N<M)
        return -1;
        
    int result = INT_MAX;
    int low = *max_element(A, A + N);
    int high=0;
    for(int i=0; i<N; i++)
        high+=A[i];
    
    while(low<=high)
    {
        int mid = (high+low)/2;
        cout<<"High: "<<high<<" "<<"Low: "<<low<<" "<<"Mid: "<<mid<<endl;
        if(isValid(A,N,M,mid))
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
    int A[] = {12, 34, 67, 90};
    int N = 4;
    int M = 2;
    cout<<findPages(A,N,M)<<endl;
}