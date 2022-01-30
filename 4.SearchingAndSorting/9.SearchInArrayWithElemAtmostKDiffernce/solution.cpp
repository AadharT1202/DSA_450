#include<iostream>
using namespace std;
int search(int arr[], int n, int x, int k)
{
    int i=0;
    while(i<n)
    {
        if(arr[i]==x)
            return i;
        int steps = abs(arr[i]-x)/k;
        i+= max(steps,1);
    }
    return -1;
} 

int main()
{
    int arr[] = {40,50,60};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 70;
    int k=20;
    cout<<search(arr,n,x,k)<<endl;
}