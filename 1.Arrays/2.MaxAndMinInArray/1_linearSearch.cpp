// naieve approach O(n).

#include<iostream>
using namespace std;

struct Pair
{
	int min;
	int max;
};

struct Pair getMinMax(int arr[], int n)
{
	struct Pair maxmin;
    int i;
    if(n==1)
    {
        maxmin.min = arr[0];
        maxmin.max = arr[0];
        return maxmin;
    }

    if(arr[0]>arr[1])
    {
        maxmin.min = arr[1];
        maxmin.max = arr[0];
    }
    else{
        maxmin.min = arr[0];
        maxmin.max = arr[1];
    }
    
    for(i=2; i<n; i++)
    {
        if(arr[i]>maxmin.max)
            maxmin.max = arr[i];
        else{
            if(arr[i]<maxmin.min)
                maxmin.min = arr[i];
        }
    }
    return maxmin;
}

// Driver code
int main()
{
	int arr[] = { 1000, 11, 445, 1, 330, 3000 };
	int arr_size = 6;
	
	struct Pair minmax = getMinMax(arr, arr_size);
	
	cout << "Minimum element is " << minmax.min << endl;
	cout << "Maximum element is " << minmax.max << endl;
		
	return 0;
}


