#include<iostream>
using namespace std;

void rotate(int *arr, int n)
{
    for(int i=0; i<n; i++)
        swap(arr[i],arr[n-1]);
    
}

int main() 
{
    int arr[] = {1, 2, 3, 4, 5}, i;
    int n = sizeof(arr) / 
            sizeof(arr[0]);

    cout << "Given array is \n";
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";

    rotate(arr, n);

    cout << "\nRotated array is\n";
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout<<"\n";
    return 0;
}