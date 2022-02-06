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

bool solve(int src, vector<bool> &visited, vector<bool> &order, vector<int> adj[])
{
    visited[src]=true;
    order[src]=true;
    for(int i=0; i<adj[src].size(); i++)
    {
        int node = adj[src][i];
        if(!visited[node])
        {
            bool x = solve(node,visited,order,adj);
            if(x)
                return true;
        }
        else
        {
            if(order[node])
                return true;
        }
    }
    order[src]=false;
    return false;
}

bool isCyclic(int V, vector<int> adj[]) {
    vector<bool> visited(V,0);
    vector<bool> order(V,0);
    
    for(int i=0; i<V; i++)
    {
        if(!visited[i])
        {
            bool temp = solve(i,visited,order,adj);
            if(temp)
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
    bool result = isCyclic(v,adj);
    if(result==false)
        cout<<"No cycle found"<<endl;
    else   
        cout<<"Cycle found"<<endl;
}