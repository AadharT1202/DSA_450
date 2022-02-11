//Bellmanford Algorithm
#include<iostream>
#include<vector>
using namespace std;
vector<vector<int> >edgeList;

bool isNegativeCycle(int vertices, int edges)
{
    vector<int> value(vertices,INT_MAX);
    value[0]=0;
    bool isUpdated;
    for(int i=0; i<vertices-1; i++)
    {
        isUpdated=false;
        for(int j=0; j<edges; j++)
        {
            int u = edgeList[j][0];
            int v = edgeList[j][1];
            int w = edgeList[j][2];

            if(value[u]!=INT_MAX && value[v] > value[u] + w)
            {
                value[v] = value[u] + w;
                isUpdated=true;
            }
        }
        if(isUpdated==false)
            return false;
    }

    for(int j=0; j<edges; j++)
    {
        int u = edgeList[j][0];
        int v = edgeList[j][1];
        int w = edgeList[j][2];

        if(value[u]!=INT_MAX && value[v] > value[u] + w)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int vertices,edges;
    cout<<"Enter the number of vertices and edges: ";
    cin>>vertices>>edges;
    cout<<"Enter the edges as src dst weight: "<<endl;
    for(int i=0; i<edges; i++)
    {
        int s,d,w;
        cin>>s>>d>>w;
        vector<int> temp;
        temp.push_back(s);
        temp.push_back(d);
        temp.push_back(w);
        edgeList.push_back(temp);
    }

    bool ans = isNegativeCycle(vertices,edges);
    if(ans)
        cout<<"Negative Edge Cycle Exist"<<endl;
    else    
        cout<<"Negative Edge Cycle Does not Exist"<<endl;
}