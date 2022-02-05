#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int vertArr[20][20];
void displayMatrix(int v) 
{
   int i, j;
   for(i = 0; i < v; i++) {
      for(j = 0; j < v; j++) {
         cout << vertArr[i][j] << " ";
      }
      cout << endl;
   }
}

void add_edge(int u, int v) 
{       
   vertArr[u][v] = 1;
}

vector<int> bfsOfGraph(int v)
{
    vector<int> ans;
    vector<bool> visited(v,false);
    queue<int> q;
    q.push(0);
    visited[0]=true;
    while(!q.empty())
    {
        int temp = q.front();
        q.pop();
        ans.push_back(temp);
        for(int i=0; i<v; i++)
        {
            if(vertArr[temp][i]==1 && visited[i]!=true)
            {
                q.push(i);
                visited[i]=true;
            }
        }
    }
    return ans;
}

int main()
{
    int v;
    cout<<"Enter number of vertices: "<<endl;
    cin>>v;
    add_edge(0,1);
    add_edge(0,2);
    add_edge(0,3);
    add_edge(1,4);
    add_edge(2,4);
    add_edge(2,5);
    add_edge(3,5);
    add_edge(3,6);
    displayMatrix(v);
    vector<int> result = bfsOfGraph(v);
    for(int i=0; i<v; i++)
    {
        cout<<result[i]<<" ";
    }
    cout<<endl;

}