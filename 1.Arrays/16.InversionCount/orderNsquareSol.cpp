#include<iostream>
using namespace std;

int inversionCount(int *arr, int n)
{
    int count = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(arr[i]>arr[j])
                count++;
        }
    }
    return count;
}

int main()
{
    int arr[] = { 1, 20, 6, 4, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int ans = inversionCount(arr, n);
    cout << " Number of inversions are " << ans<<endl;
    return 0;
}