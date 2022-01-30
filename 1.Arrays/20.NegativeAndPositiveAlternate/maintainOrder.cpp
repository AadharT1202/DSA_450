#include<iostream>
using namespace std;

void rotate(int start, int end, int *arr)
{
    int temp = arr[end];
    for(int i=end-1;i>=start;i--)
    {
        arr[i+1]=arr[i];
    }
	arr[start]=temp;
}

void printArray(int *arr, int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

void solution(int *arr, int n)
{
    int pos,neg,k=0;
    while(k<n)
    {
        //even position must have negative numbers.
        if(k%2==0)
        {
            if(arr[k]>=0)
            {
                pos = k;
                neg = k;
                while(neg<n && arr[neg]>=0)
                    neg++;
                if(neg>=n)
                    break;
                
                rotate(pos,neg,arr);
            }
        }

        else
        {
            //odd position must have positive numbers.
            if(arr[k]<0)
            {
                pos = k;
                neg = k;
                while(pos<n && arr[pos]<0)
                    pos++;
                if(pos>=n)
                    break;
                rotate(neg,pos,arr);
            }
        }
        k++;
    }
}

int main()
{
    int arr[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
    int n = sizeof(arr) / sizeof(arr[0]);
    solution(arr,n);
    printArray(arr,n);
    return 0;
}