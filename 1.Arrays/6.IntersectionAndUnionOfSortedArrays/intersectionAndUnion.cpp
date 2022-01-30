#include<iostream>
#include<vector>
using namespace std;
void printArray(vector<int> arr, int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
vector<int> intersection(int *arr1, int n, int *arr2, int m)
{
    int p1=0;
    int p2=0;
    vector<int> result;
    while(p1<n && p2<m)
    {
        if(arr1[p1]<arr2[p2])
            p1++;
        else if(arr1[p1]>arr2[p2])
            p2++;
        else
        {
            result.push_back(arr1[p1]);
            p1++;
            p2++;
        }
    }
    return result;
}
vector<int> unison(int *arr1, int n, int *arr2, int m)
{
    int p1=0;
    int p2=0;
    vector<int> result;
    while(p1<n && p2<m)
    {
        if(arr1[p1]<arr2[p2])
        {
            result.push_back(arr1[p1]);
            p1++;
        }    
        else if(arr1[p1]>arr2[p2])
        {
            result.push_back(arr2[p2]);
            p2++;
        }
        else
        {
            result.push_back(arr1[p1]);
            p1++;
            p2++;
        }
    }
    while(p1<n)
        result.push_back(arr1[p1++]);
    while(p2<m)
        result.push_back(arr2[p2++]);
    
    
    return result;
}
int main()
{
    int arr1[] = { 1, 2, 4, 5, 6 };
    int arr2[] = { 2, 3, 5, 7 };
 
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);
 
    // Function calling
    vector<int> intersect = intersection(arr1, n, arr2, m);
    printArray(intersect,intersect.size());

    vector<int> unionson = unison(arr1, n, arr2, m);
    printArray(unionson,unionson.size());
 
    return 0;
}