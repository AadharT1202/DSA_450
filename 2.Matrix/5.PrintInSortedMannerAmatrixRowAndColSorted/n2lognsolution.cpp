#include<iostream>
#include<vector>
using namespace std;
vector<vector<int> > sortedMatrix(int N, vector<vector<int> > Mat) 
{
    vector<int> v;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            v.push_back(Mat[i][j]);
        }
    }
    int k=0;
    sort(v.begin(),v.end());
    vector<vector<int> > ans(N,vector<int>(N));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            ans[i][j]=v[k];
            k++;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int> > matrix,ans;
    for(int i=0; i<n; i++)
    {
        vector<int> temp;
        for(int j=0; j<n; j++)
        {
            int x;
            cin>>x;
            temp.push_back(x);
        }
        matrix.push_back(temp);
    }

    ans = sortedMatrix(n, matrix);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

}