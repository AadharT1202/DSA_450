#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> graph[20];

bool solve(int vertices, vector<vector<int> > &dependencies, int n)
{
    vector<int> inDegree(vertices,0);
    for(int i=0; i<n; i++)
    {
        int u = dependencies[i][1];
        int v = dependencies[i][0];
        graph[u].push_back(v);
    }

    cout<<"Adjacency List is as below: "<<endl;
    for(int i=0; i<vertices; i++)
    {
        cout<<i<<"--> ";
        for(int j=0; j<graph[i].size(); j++)
        {
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i=0; i<vertices; i++)
    {
        for(int j=0; j<graph[i].size(); j++)
        {
            int x = graph[i][j];
            inDegree[x]++;
        }
    }

    cout<<"Indegree Array: "<<endl;
    for(int i=0; i<vertices; i++)
        cout<<inDegree[i]<<" ";
    cout<<endl;

    bool isZero=false;
    queue<int> q;

    for(int i=0; i<inDegree.size(); i++)
    {
        if(inDegree[i]==0)
        {
            isZero=true;
            q.push(i);
        }
    }

    if(isZero==false)
        return false;
    cout<<isZero<<endl;
    
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        for(int i=0; i<graph[x].size(); i++)
        {
            int cur = graph[x][i];
            inDegree[cur]--;
            if(inDegree[cur]==0)
                q.push(cur);
        }
    }
        
    for(int i=0; i<vertices; i++)
    {
        if(inDegree[i]>0)
            return false;
    }

    return true;
}

int main()
{
    int vertices;
    cout<<"Enter the number of vertices: ";
    cin>>vertices;
    int n;
    cout<<"Enter the number of dependencies: ";
    cin>>n;
    vector<vector<int> >dependencies (n,vector<int>(2,0));
    cout<<"Enter the dependencies: "<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>dependencies[i][0];
        cin>>dependencies[i][1];
    }

    bool x = solve(vertices,dependencies,n);
    if(x)
        cout<<"POSSIBLE"<<endl;
    else
        cout<<"IMPOSSIBLE"<<endl;
}   