#include<iostream>
#include<vector>
using namespace std;

void dfs(int src, vector<bool> &visited, int &counter, vector<int> graph[])
{
    visited[src]=true;
    counter++;
    for(int i=0; i<graph[src].size(); i++)
    {
        int cur = graph[src][i];
        if(!visited[cur])
            dfs(cur,visited, counter, graph);
    }
}

int main()
{
    int vertices;
    cout<<"Enter the number of astronauts: ";
    cin>>vertices;

    int p;
    cout<<"Enter the number of pairs: ";
    cin>>p;

    vector<int> graph[vertices];
    for(int i=0; i<p; i++)
    {
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    } 

    vector<int> compSize;
    vector<bool> visited(vertices,false);

    for(int i=0; i<vertices; i++)
    {
        if(!visited[i])
        {
            int counter=0;
            dfs(i,visited,counter,graph);
            compSize.push_back(counter);
        }
    }

    int ans = (vertices * (vertices-1))/2;
    for(int i=0; i<compSize.size(); i++)
    {
        int temp = (compSize[i] * (compSize[i]-1))/2;
        ans = ans-temp;
    }
    cout<<"Possible pairs are: "<<ans<<endl;
}