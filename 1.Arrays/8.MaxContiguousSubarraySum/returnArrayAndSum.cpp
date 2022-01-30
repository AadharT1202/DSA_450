#include<iostream>
using namespace std;

void maxSubArraySum(int *arr, int n)
{
    int max_so_far = INT_MIN;
    int max_here = 0;
    int start = 0;
    int end = 0;
    int s = 0;

    for(int i=0; i<n; i++)
    {
        max_here = max_here + arr[i];
        if(max_here>max_so_far)
        {
            max_so_far = max_here;
            start = s;
            end = i;
        }
        if(max_here<0)
        {
            max_here=0;
            s=i+1;
        }
    }
    cout << "Maximum contiguous sum is "
        << max_so_far << endl;
    cout << "Starting index "<< start
        << endl << "Ending index "<< end << endl;
    cout<<"Sub Array is: ";
    for(int i=start; i<=end; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

int main()
{
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a)/sizeof(a[0]);
    maxSubArraySum(a, n);
    //cout<<"Max Contiguous Subarray Sum is: "<<max_sum<<endl;
    return 0;
}