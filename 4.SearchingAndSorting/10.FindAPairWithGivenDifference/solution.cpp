#include<iostream>
using namespace std;
bool findPair(int arr[], int size, int n){
    sort(arr,arr+size);
    int start = 0;
    int end = 1;
    while(start<size && end<size)
    {
        int diff = arr[end] - arr[start];
        if(diff == n)
            return true;
        else if(diff<n)
            end++;
        else
            start++;
            
    }
    return false;
}
int main()
{
    int arr[] = {5, 20, 3, 2, 5, 80};
    int size=sizeof(arr)/sizeof(arr[0]);
    int n = 78;
    cout<<findPair(arr,size,n)<<endl;
}