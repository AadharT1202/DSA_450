//taking two pointers pointing to first element of both the arrays.
//swap the element from the first array if they are greater than the smallest element of the second array.
//sort the second array again
//increment the pointer pointing to the element in the first array.
//O(m*nlogn) Time Complexity

#include<iostream>
#include<algorithm>
using namespace std;

void merger(int *arr1, int *arr2, int m, int n)
{
    for(int i=0; i<m; i++)
    {
        if(arr1[i]>arr2[0])
        {
            swap(arr1[i],arr2[0]);
            sort(arr2, arr2+n);
        }
    }
}

int main()
{
    int arr1[] = { 1, 5, 9, 10, 15, 20 };
    int arr2[] = { 2, 3, 8, 13 };
    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);
    merger(arr1, arr2, m, n);
 
    cout << "After Merging"<<"\n"<< "First Array: ";
    for (int i = 0; i < m; i++)
        cout << arr1[i] << " ";
    cout<<"\n";
    cout << "Second Array: ";
    for (int i = 0; i < n; i++)
        cout << arr2[i] << " ";
    return 0;
}