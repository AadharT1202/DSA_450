#include<iostream>
#include<vector>
using namespace std;
int rowWithMax1s(vector<vector<int> > arr, int n, int m) 
{
    int indexOfOne = INT_MAX;
    int rowIndex = -1;
    for(int i=0; i<n; i++)
    {
        int ans = INT_MAX;
        int l = 0, h = m-1;
        while(l<=h)
        {
            int mid = (l+h)/2;
            if(arr[i][mid]==1)
            {
                if(mid<ans)
                    ans = mid;
                h = mid-1;
            }
            else
                l = mid+1;
        }
        
        if(ans < indexOfOne)
        {
            indexOfOne = ans;
            rowIndex = i;
        }
    }
    return rowIndex;
}

int main()
{
    int n,m;
    cout<<"Enter the number of rows and cols: ";
    cin>>n>>m;
    vector<vector<int> > arr;
    for(int i=0; i<n; i++)
    {
        vector<int> temp;
        for(int i=0; i<m; i++)
        {
            int x;
            cin>>x;
            temp.push_back(x);
        }
        arr.push_back(temp);
    }

    cout<<"Row index having maximum ones: "<<rowWithMax1s(arr,n,m);
    cout<<endl;
}
