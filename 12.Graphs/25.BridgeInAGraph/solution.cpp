#include<iostream>
#include<vector>
using namespace std;

struct edge{
    int u,v;
    edge(int _u, int _v)
    {
        u=_u;
        v=_v;
    }
    edge(){}
};

vector<int> graph[20];

void dfs(int src,vector<int> temp[], vector<bool> &visited)
{
    visited[src]=true;
    for(int i=0; i<temp[src].size(); i++)
    {
        int cur = temp[src][i];
        if(!visited[cur])
            dfs(cur,temp,visited);
    }
}

int main()
{
    int vertices,edges;
    cout<<"Enter number of vertices and edges: ";
    cin>>vertices>>edges;

    vector<edge> edge_list(edges);
    vector<pair<int, int> > ans;
    int x=0;

    cout<<"Enter the edges as u-v: "<<endl;


    for(int i=0; i<edges; i++)
    {
        int u,v;
        cin>>u>>v;
        edge_list[i].u = u;
        edge_list[i].v = v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }


    for(int i=0; i<edges; i++)
    {
        vector<int> temp[vertices];

        int u = edge_list[i].u;
        int v = edge_list[i].v;
        cout<<"u: "<<u<<" v: "<<v<<endl;

        for(int j=0; j<vertices; j++)
        {
            for(int k=0; k<graph[j].size(); k++)
            {
                if((j==u && graph[j][k]==v) || (j==v && graph[j][k]==u))
                    continue;
                else
                    temp[j].push_back(graph[j][k]);
            }
        }

        for(int i=0; i<vertices; i++)
        {
            cout<<i<<"--> ";
            for(int j=0; j<temp[i].size(); j++)
            {
                cout<<temp[i][j]<<" ";
            }
            cout<<endl;
        }
        int components=0;

        vector<bool>visited(vertices,false);
        for(int i=0; i<vertices; i++)
        {
            if(!visited[i])
            {
                dfs(i,temp,visited);
                components++;

            }
        }
        cout<<"Components: "<<components<<endl;

        if(components>1)
        {
            ans.push_back(make_pair(u,v));
        }

        cout<<"---------------"<<endl;

        for(int m=0; m<ans.size(); m++)
        {
            cout<<ans[m].first<<"--"<<ans[m].second<<endl;
        }
    }
}