// Naive solution can be O(n2)
// Then we can sort the array and then count do the traversal and count. O(nlogn + n)
// Final is using maps. time - O(n) space - O(n)

#include<iostream>
#include<map>
using namespace std;

int moreThanNdK(int *arr, int n, int k)
{
    map<int, int>::iterator itr;
    map<int,int> mp;
    for(int i=0; i<n; i++)
    {
        if(mp[arr[i]])
            mp[arr[i]]++;
        else
            mp[arr[i]] = 1;
    }

    int count = 0;
    int ndk = n/k;
    for (itr = mp.begin(); itr != mp.end(); ++itr) {
            if(itr->second > ndk)
                count++;
    }
    return count;
}

int main()
{
    int arr1[] = { 2,3,3,2};
    int size = sizeof(arr1) / sizeof(arr1[0]);
    int k = 3;
    cout<<moreThanNdK(arr1, size, k)<<endl;
}
