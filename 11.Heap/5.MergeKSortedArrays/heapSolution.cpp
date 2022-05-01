#include<iostream>
#include<queue>
#include<vector>
#define piii pair<int, pair<int,int> >
using namespace std;
vector<int> mergeKArrays(vector<vector<int> > arr, int k)
{
    vector<int> ans;
    priority_queue<piii,vector<piii>, greater<piii> > pq;
    for(int i=0; i<k; i++)
    {
        pq.push(make_pair(arr[i][0], make_pair(i,1)));
    }
    while(!pq.empty())
    {
        piii temp = pq.top();
        pq.pop();
        ans.push_back(temp.first);
        int row = temp.second.first;
        int col = temp.second.second;
        if(col < k)
        {
            pq.push(make_pair(arr[row][col], make_pair(row,col+1)));
        }
    }
    return ans;
}

int main()
{
    vector<vector<int> > arr;
    int k;
    cout<<"Enter the value of k: ";
    cin>>k;
    cout<<"Input the array: "<<endl;
    for(int i=0; i<k; i++)
    {
        vector<int> temp;
        for(int j=0; j<k; j++)
        {
            int x;
            cin>>x;
            temp.push_back(x);
        }
        arr.push_back(temp);
    }
    vector<int> ans = mergeKArrays(arr,k);
    for(int i=0; i<ans.size(); i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}