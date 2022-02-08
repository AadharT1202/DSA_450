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

vector<int> solve(int vertices)
{
    vector<int> inDegree(vertices,0);
    for(int i=0; i<vertices; i++)
    {
        for(int j=0; j<graph[i].size(); j++)
        {
            int x = graph[i][j];
            inDegree[x]++;
        }
    }
    vector<int> ans(vertices,0);
    queue<int> q;
    for(int i=0; i<vertices; i++)
        if(inDegree[i]==0)
            q.push(i);
    int t=0;
    while(!q.empty())
    {
        t++;
        int qsize = q.size();
        while(qsize--)
        {
            int x = q.front();
            q.pop();
            ans[x] = t;
            for(int i=0; i<graph[x].size(); i++)
            {
                int cur = graph[x][i];
                inDegree[cur]--;
                if(inDegree[cur]==0)
                    q.push(cur);
            }
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
    vector<int> ans = solve(vertices);
    for(int i=0; i<vertices; i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}