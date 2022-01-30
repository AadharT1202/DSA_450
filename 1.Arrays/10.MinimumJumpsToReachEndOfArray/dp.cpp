#include<iostream>
using namespace std;

int minJumps(int *arr, int n)
{
    int *jumps = new int[n];
    jumps[0] = 0;
    int i,j;

    for(i=1; i<n; i++)
    {
        jumps[i] = INT_MAX;
        for(j=0; j<i; j++)
        {
            if(i<=j+arr[j] && jumps[j]!=INT_MAX)
            {
                jumps[i] = min(jumps[i],jumps[j]+1);
                break;
            }
        }
    }
    return jumps[n-1];
}

int main()
{
    int arr[] = { 1, 3, 6, 1, 0, 9 };
    int size = sizeof(arr) / sizeof(int);
    cout << "Minimum number of jumps to reach end is "
         << minJumps(arr, size)<< endl;
    return 0;
}