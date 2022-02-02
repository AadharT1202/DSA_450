#include<iostream>
#include<vector>
using namespace std;

vector<vector<int> > mergedIntervals(vector<vector<int> >arr, int n)
{
    //sort the array on the first element.
    //just add the first element of the arr in the result array.
    //start a for loop from the index 1 and check for the condition.
    /*if(result[j][1]>=interval[i][0]) result[j][1]=max(result[j][1],interval[i][1]);
            //else they are not overlapping
            else
            {
                j++;
                result.push_back(interval[i]);
            }*/
    //return the result array.

}

int main()
{
    int n;
    vector<vector<int> > arr;
    for(int i=0; i<n; i++)
    {
        vector<int> temp;
        for(int j=0; j<2; j++)
        {
            int t;
            cin>>t;
            temp.push_back(t);
        }
        arr.push_back(temp);
    }
    vector<vector<int> > ans = mergedIntervals(arr,n);
}