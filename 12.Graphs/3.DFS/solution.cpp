#include<iostream>
#include<vector>
using namespace std;
vector<int> v;
vector<int> graph[20];
void adjList(int v, int e)
{
    cout<<"Enter the edges as u-v: "<<endl;
    for(int i=0; i<e; i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    cout<<"Adjacency List is as below: "<<endl;
    for(int i=0; i<v; i++)
    {
        cout<<i<<"--> ";
        for(int j=0; j<graph[i].size(); j++)
        {
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}


void solve(int x, vector<int> &visited, vector<int> adj[])
{
    visited[x]=1;
    v.push_back(x);
    for(int i=0; i<adj[x].size(); i++)
    {
        int temp = adj[x][i];
        if(visited[temp]!=1)
            solve(temp,visited,adj);
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    v.clear();
    vector<int> visited(V,0);
    solve(0,visited,adj);
    return v;
}

int main()
{
    int v,e;
    cout<<"Enter number of vertices and edges: "<<endl;
    cin>>v>>e;
    adjList(v,e);
    vector<int> ans = dfsOfGraph(v,graph);
    for(int i=0; i<v; i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}