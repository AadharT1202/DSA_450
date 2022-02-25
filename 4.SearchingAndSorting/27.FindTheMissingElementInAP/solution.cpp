#include<iostream>
using namespace std;
int findMissingUtil(int arr[], int low, int high, int diff)
{   
    int mid;
    while (low <= high)
    {   
        mid = (low + high) / 2;
        if ((arr[mid] - arr[0]) / diff == mid)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return arr[high] + diff;
}

int findMissing(int arr[], int n)
{
    int diff = (arr[n - 1] - arr[0]) / n;
    return findMissingUtil(arr, 0, n - 1, diff);
}
 
int main()
{
    int arr[] = {2, 4, 8, 10, 12, 14};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The missing element is "
         << findMissing(arr, n)<<endl;
    return 0;
}