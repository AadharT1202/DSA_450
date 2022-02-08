#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> graph[20];

void adjList(int v, int e)
{
    cout<<"Enter the edges as u->v: "<<endl;
    for(int i=0; i<e; i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
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

vector<int> topoSort(int V, vector<int> adj[]) 
{
    vector<int> indegree(V,0);
    vector<int> ans;
    queue<int> q;
    for(int i=0; i<V; i++)
    {
        for(int j=0; j<adj[i].size(); j++)
        {
            int x = adj[i][j];
            indegree[x]++;
        }
    }
    
    for(int i=0; i<V; i++)
    {
        if(indegree[i]==0)
            q.push(i);
    }
    
    while(!q.empty())
    {
        int td = q.front();
        q.pop();
        ans.push_back(td);
        for(int j=0; j<adj[td].size(); j++)
        {
            int x = adj[td][j];
            indegree[x]--;
            if(indegree[x]==0)
                q.push(x);
        }
            
    }
    return ans;
}

int main()
{
    int edges, vertices;
    cout<<"Enter the number of vertices and edges: ";
    cin>>vertices>>edges;
    adjList(vertices,edges);
    vector<int> ans = topoSort(vertices,graph);
    for(int i=0; i<ans.size(); i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}