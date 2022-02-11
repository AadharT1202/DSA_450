#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> graph[20];

bool bfs(int vertices)
{
    vector<int> color(vertices,-1);
    queue<int> q;

    for(int i=0; i<vertices; i++)
    {
        if(color[i]==-1)
        {
            color[i]=0;
            q.push(i);
            while (!q.empty())
            {
                int temp = q.front();
                q.pop();
                for(int i=0; i<graph[temp].size(); i++)
                {
                    int cur = graph[temp][i];
                    if(color[cur]==-1)
                    {
                        color[cur] = 1-color[temp];
                        q.push(cur);
                    }
                    else if(color[cur]==color[temp])
                        return false;
                }
            }
        
        }
        
    }
    
    return true;
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
        graph[u].push_back(v);
        graph[v].push_back(u);
    }


    bool ans = bfs(vertices);
    if(ans==true)
        cout<<"Bipartite graph"<<endl;
    else    
        cout<<"Not Bipartite graph"<<endl;
}