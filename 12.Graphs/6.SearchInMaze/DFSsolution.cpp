#include<iostream>
#include<vector>
using namespace std;


//Finding all the possible paths.....


vector<string> result;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
char ch[4] = {'D','U','R','L'};

void solve(int x , int y , int n ,vector<vector<int> >&m ,string s ,vector<vector<int> >& visited)
{
    if(x<0 || y<0 || x>=n || y>=n)
        return;
    if(m[x][y]==0 || visited[x][y]==1)
        return;
    
    visited[x][y]=1;
    if(x==n-1 && y==n-1)
        result.push_back(s);
    for(int i=0; i<4; i++)
    {
        int x_new = x + dx[i];
        int y_new = y + dy[i];
        solve(x_new,y_new,n,m,s+ch[i],visited);
    }
    visited[x][y]=0;
}

vector<string> findPath(vector<vector<int> > &m, int n) {
    result.clear();
    vector<vector<int> >visited( n , vector<int>(n,0)) ;
    solve(0,0,n,m,"",visited);
    sort(result.begin(),result.end());
    return result;;
}

int main()
{
    cout<<"Enter the value of n: ";
    int n;
    cin>>n;
    vector<vector<int> >m(n, vector<int>(n,0));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            int x;
            cin>>x;
            m[i][j]=x;
        }
    }
    vector<string> ans = findPath(m,n);
    if(ans.size()==0)
        cout<<"-1"<<endl;
    else{
        for(int i=0; i<ans.size(); i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    
}