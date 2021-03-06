#include<iostream>
#include<vector>
using namespace std;

vector<int> inTime;
vector<int> outTime;
int timer=1;
void resize(int n)
{
    inTime.resize(n+1);
    outTime.resize(n+1);
}

void dfs(int src, vector<int>&visited, vector<int> g[])
{
    visited[src]=1;
    inTime[src] = timer++;
    for(int i=0; i<g[src].size(); i++)
    {
        int cur = g[src][i];
        if(!visited[cur])
            dfs(cur,visited,g);
    }
    outTime[src] = timer++;
}

bool check(int x, int y)
{
    if(inTime[x]>inTime[y] && outTime[x]<outTime[y])
        return true;
    return false;
}

int main()
{
    int n;
    cin>>n;
    timer=1;
    resize(n);
    vector<int> g[n+1];
    for(int i=1; i<n; i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for(int i=1; i<n; i++)
    {
        cout<<i<<"--> ";
        for(int j=0; j<g[i].size(); j++)
        {
            cout<<g[i][j]<<" ";
        }
        cout<<"\n";
    }
    vector<int> visited(n+1,0);

    dfs(1,visited,g);
    int q;
    cin>>q;
    for(int i=0; i<q; i++)
    {
        int type,x,y;
        cin>>type>>x>>y;
        if(!check(x,y) && !check(y,x))
        {
            cout<<"No\n";
            continue;
        }

        if(type==1)
        {
            if(check(x,y))
                cout<<"Yes\n";
            else
                cout<<"No\n";
        }

        else if(type==0)
        {
            if(check(y,x))
                cout<<"Yes\n";
            else        
                cout<<"No\n";
        }

    }
}

