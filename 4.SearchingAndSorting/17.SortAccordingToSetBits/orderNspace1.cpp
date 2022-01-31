#include<iostream>
#include<vector>
using namespace std;

void sortBySetBitCount(int arr[], int n)
{
    vector<vector<int> > count(32);
    for(int i=0; i<n; i++)
    {
        int temp=arr[i];
        int c=0;
        while(temp>0)
        {
            temp=temp & (temp-1);
            c++;
        }
        count[c].push_back(arr[i]);
    }
    
    int k=0;
    for(int i=31; i>=0; i--)
    {
        vector<int> temp = count[i];
        if(temp.size()!=0)
        {
            for(int j=0; j<temp.size(); j++)
            {
                arr[k] = temp[j];
                k++;
            }
        }
    }


}
int main()
{
    int arr[] = {5, 2, 3, 9, 4, 6, 7, 15, 32};
    int n = sizeof(arr)/sizeof(arr[0]);
    sortBySetBitCount(arr,n);
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}