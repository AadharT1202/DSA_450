#include<iostream>
#include<vector>
using namespace std;


struct node{
    int parent;
    int rank;
};

struct edge{
    int to;
    int from;
    int weight;
};
vector<node> dsuf;
vector<edge> edge_list;
vector<edge> mst;

int find(int v)
{
    if(dsuf[v].parent==-1)
        return v;
    return (dsuf[v].parent = find(dsuf[v].parent));
}

void union_op(int fromP, int toP)
{
    if(dsuf[fromP].rank > dsuf[toP].rank)
        dsuf[toP].parent = fromP;
    else if(dsuf[fromP].rank < dsuf[toP].rank)
        dsuf[fromP].parent = toP;
    else{
        dsuf[fromP].parent = toP;
        dsuf[toP].rank++;
    }
}

bool comparator(edge e1, edge e2)
{
    if(e1.weight<=e2.weight)
        return true;
    else 
        return false;
}

void krushkals(int vertices, int edges)
{
    sort(edge_list.begin(),edge_list.end(),comparator);
 
    int i=0; int j=0;
    while(i<vertices-1 && j<edges)
    {
        int fromP = find(edge_list[j].from);
        int toP = find(edge_list[j].to);
        
        if(fromP == toP)
        {
            j++;
            continue;
        }

        union_op(fromP,toP);
        mst.push_back(edge_list[j]);
        i++;
    }
}

int main()
{
    int edges,vertices;
    cout<<"Enter number of vertices and edges: ";
    cin>>vertices>>edges;

    //initializing the parent and rank array;
    dsuf.resize(vertices);
    for(int i=0; i<vertices; i++)
    {
        dsuf[i].parent = -1;
        dsuf[i].rank = 0;
    }

    //taking edges input;
    cout<<"Enter the edges as u->v and then the weight despite having the undirected graph: "<<endl;
    edge_list.resize(edges);
    for(int i=0; i<edges; i++)
    {
        int to,from,weight;
        cin>>from>>to>>weight;
        edge_list[i].to = to;
        edge_list[i].from = from;
        edge_list[i].weight = weight;
    }

    krushkals(vertices,edges);

    cout<<"MST formed is: "<<endl;
    for(int i=0; i<mst.size(); i++)
    {
        edge e = mst[i];
        cout<<e.from<<" "<<e.to<<" "<<e.weight<<endl;
    }
}