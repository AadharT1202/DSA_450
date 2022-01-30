#include<iostream>
using namespace std;

bool find3Numbers(int A[], int n, int X)
{
    sort(A,A+n);
    for(int i=0; i<n-2; i++)
    {
        int sum = X - A[i];
        int left = i+1;
        int right = n-1;
        while(left<right)
        {
            if(A[left]+A[right]==sum)
                return true;
            else if(A[left]+A[right]>sum)
                right--;
            else
                left++;
        }
    }
    return false;
}

int main()
{
    int n = 6;
    int X = 13;
    int arr[] = {1,4,45,6,10,8};
    cout<<find3Numbers(arr,n,X)<<endl;
}