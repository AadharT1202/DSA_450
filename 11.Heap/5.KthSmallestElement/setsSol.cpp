/* the following code demonstrates how to find kth smallest
element using set from C++ STL 
Sets are implemented using BST and set stores the elements in sorted order
searching time is O(logn) in worst case O(n).*/
#include<iostream>
#include<set>
using namespace std;

int main()
{

	int n,k;
    cin>>n>>k;
    int arr[n];

    for(int i=0; i<n; i++)
        cin>>arr[i];

	set<int> s(arr, arr + n);
	set<int>::iterator itr
		= s.begin(); // s.begin() returns a pointer to first
					// element in the set
	advance(itr, k - 1); // itr points to kth element in set

	cout << *itr << "\n";

	return 0;
}

