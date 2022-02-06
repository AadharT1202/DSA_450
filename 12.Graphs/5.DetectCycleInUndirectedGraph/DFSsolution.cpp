#include<iostream>
#include<vector>
using namespace std;
vector<int> adj[20];

void adjList(int v, int e)
{
    cout<<"Enter the edges as u-v: "<<endl;
    for(int i=0; i<e; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout<<"Adjacency List is as below: "<<endl;
    for(int i=0; i<v; i++)
    {
        cout<<i<<"--> ";
        for(int j=0; j<adj[i].size(); j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool solve(int src, int par, vector<bool> &visited, vector<int> adj[])
{
    visited[src]=true;
    for(int i=0; i<adj[src].size(); i++)
    {
        int node = adj[src][i];
        if(!visited[node])
        {
            bool x = solve(node, src, visited, adj);
            if(x)
                return true;
        }
        else
        {
            if(node!=par)
                return true;
        }
    }
    return false;
}

bool isCycle(int V, vector<int> adj[]) {
    vector<bool> visited(V,false);
    for(int i=0; i<V; i++)
    {
        if(!visited[i])
        {
            bool res = solve(i,-1,visited,adj);
            if(res)
                return true;
        }
            
    }
    return false;
    
}
int main()
{
    int v,e;
    cout<<"Enter number of vertices and edges: "<<endl;
    cin>>v>>e;
    adjList(v,e);
    bool result = isCycle(v,adj);
    if(result==false)
        cout<<"No cycle found"<<endl;
    else   
        cout<<"Cycle found"<<endl;
}