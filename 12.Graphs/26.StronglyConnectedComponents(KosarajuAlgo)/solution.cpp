#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> adj[20];
void dfs1(int src, vector<int> adj[], stack<int> &st, vector<bool> &visited)
{
    visited[src]=true;
    for(int i=0; i<adj[src].size(); i++)
    {
        int cur = adj[src][i];
        if(!visited[cur])
            dfs1(cur,adj,st,visited);
    }
    st.push(src);
}

void dfs2(int src, vector<int> reverse[], vector<bool> &visited1)
{
    visited1[src]=true;
    for(int i=0; i<reverse[src].size(); i++)
    {
        int cur = reverse[src][i];
        if(!visited1[cur])
            dfs2(cur, reverse, visited1);
    }
}

int kosaraju(int V)
{
    vector<int> reverse[V];
    for(int i=0; i<V; i++)
    {
        for(int x=0; x<adj[i].size(); x++)
            reverse[adj[i][x]].push_back(i);
    }
    
    stack<int> st;
    vector<bool> visited(V,false);
    for(int i=0; i<V; i++)
    {
        if(!visited[i])
            dfs1(i, adj, st, visited);
    }
    
    int ans=0;
    vector<bool> visited1(V,false);
    while(st.size()>0)
    {
        int src = st.top();
        st.pop();
        if(!visited1[src])
        {
            dfs2(src,reverse,visited1);
            ans++;
        }
    }
    return ans;
}

int main()
{
    int vertices,edges;
    cout<<"Enter the number of vertices and edges: ";
    cin>>vertices>>edges;

    cout<<"Enter the edges as u->v "<<endl;
    for(int i=0; i<edges; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    cout<<"Number of strongly connected components: "<<kosaraju(vertices)<<endl;

}