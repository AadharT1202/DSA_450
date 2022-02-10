#include<iostream>
#include<vector>
#include<queue>

using namespace std;
vector<int> graph[30];

int graphColor(int v, int e)
{
    vector<int> color(v,-1);
    color[0]=0;

    for(int i=1; i<v; i++)
    {
        vector<bool> availableColor(v,true);
        for(int j=0; j<graph[i].size(); j++)
        {
            int node = graph[i][j];
            int col = color[node];
            if(col!=-1)
                availableColor[col]=false;
        }

        int colorThisNode;
        for(int k=0; k<v; k++)
        {
            if(availableColor[k]==true)
            {
                colorThisNode=k;
                break;
            }
        }
        color[i]=colorThisNode;

    }
    
    int num = INT_MIN;
    cout<<"Color Array: ";
    for(int i=0; i<color.size(); i++)
    {
        cout<<color[i]<<" ";
        if(color[i]>num)
            num=color[i];
    }
    cout<<endl;
    return num+1;
}

int main()
{
    int v,e;
    cout<<"Enter vertices and edges: ";
    cin>>v>>e;
    cout<<"Enter the edges as u-v: "<<endl;
    for(int i=0; i<e; i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int i=0; i<v; i++)
    {
        cout<<i<<"--> ";
        for(int j=0; j<graph[i].size(); j++)
        {
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }

    int x = graphColor(v,e);
    cout<<"Number of colors needed: "<<x<<endl;

}