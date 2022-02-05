#include<iostream>
#include<vector>
using namespace std;
void adjList(int v, int e)
{
    vector<int> graph[v];
    cout<<"Enter the edges as u-v: "<<endl;
    for(int i=0; i<e; i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        //graph[v].push_back(u);
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


void adjMatrix(int v, int e)
{
    int graph[v][v];
    for(int i=0; i<v; i++)
    {
        for(int j=0; j<v; j++)
        {
            graph[i][j]=0;
        }
    }
    cout<<"Enter the edges as u-v: "<<endl;
    for(int i=0; i<e; i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u][v]=1;
        graph[v][u]=1;
    }
    cout<<"Adjacency Matrix is as below: "<<endl;
    for(int i=0; i<v; i++)
    {
        cout<<i<<"--> ";
        for(int j=0; j<v; j++)
        {
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int v,e;
    cout<<"Enter number of vertices and edges: "<<endl;
    cin>>v>>e;
    //adjMatrix(v,e);
    //cout<<endl;
    adjList(v,e);
}