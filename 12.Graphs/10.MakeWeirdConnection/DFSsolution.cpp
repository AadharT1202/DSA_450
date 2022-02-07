#include<iostream>
#include<vector>
using namespace std;
void dfs(int src,vector<bool> &visited,vector<int> graph[])
{
    visited[src]=true;
    for(int i=0; i<graph[src].size(); i++)
    {
        int x = graph[src][i];
        if(!visited[x])
            dfs(x,visited,graph);
    }
}

int makeConnected(int n, vector<vector<int> >& connections) {
    int edges = connections.size();
    if(edges<n-1)
        return -1;
    vector<int> graph[n];
    for(int i=0; i<edges; i++)
    {
        graph[connections[i][0]].push_back(connections[i][1]);
        graph[connections[i][1]].push_back(connections[i][0]);
    }
    vector<bool> visited(n,false);
    int component=0;
    for(int i=0; i<n; i++)
    {
        if(!visited[i])
        {
            component++;
            dfs(i,visited,graph);
        }
    }
    return component-1;
}

int main()
{
    int n;
    cout<<"Enter number of nodes: ";
    cin>>n;
    int edges;
    cout<<"Enter number of wires: ";
    cin>>edges;
    vector<vector<int> > connections(edges,vector<int>(2,0));
    for(int i=0; i<edges; i++)
    {
        int x,y;
        cin>>x>>y;
        connections[i][0]=x;
        connections[i][1]=y;
    }
    cout<<"Number of connections to be made: ";
    cout<<makeConnected(n,connections)<<endl;

}