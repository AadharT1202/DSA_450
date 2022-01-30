//Thus, the approach does 3n/2 -2 comparisons if n is a power of 2. 
// And it does more than 3n/2 -2 comparisons if n is not a power of 2.

#include<iostream>
using namespace std;

struct Pair
{
	int min;
	int max;
};

struct Pair getMinMax(int arr[], int low, int high)
{
    struct Pair maxmin, left, right;
	if(low==high)
    {
        maxmin.max = arr[low];
        maxmin.min = arr[low];
        return maxmin;
    }

    if(high == low+1)
    {
        if(arr[low]>arr[high])
        {
            maxmin.max = arr[low];
            maxmin.min = arr[high];
        }
        else
        {
            maxmin.max = arr[high];
            maxmin.min = arr[low];
        }
        return maxmin;
    }

    int mid = (high+low)/2;
    left = getMinMax(arr,low,mid);
    right = getMinMax(arr,mid+1,high);

    if(left.max > right.max)
        maxmin.max = left.max;
    else
        maxmin.max = right.max;
    
    if(left.min < right.min)
        maxmin.min = left.min;
    else
        maxmin.min = right.min;
    return maxmin;
}

// Driver code
int main()
{
	int arr[] = { 1000, 11, 445, 1, 330, 3000 };
	int arr_size = 6;
	
	struct Pair minmax = getMinMax(arr, 0, arr_size-1);
	
	cout << "Minimum element is " << minmax.min << endl;
	cout << "Maximum element is " << minmax.max << endl;
		
	return 0;
}


