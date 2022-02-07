#include<iostream>
#include<vector>
#include<queue>
#include<util.h>
using namespace std;

struct cell{
    int x,y,dist;
    cell() {}
    cell(int x, int y, int dist) : x(x), y(y), dist(dist){}
};

bool isSafe(int n, int col, int row) 
{
    if (col < 0 || col >= n || row < 0 || row >= n) return false;
    return true;
}
    
int rowMoves[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int colMoves[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int minKnightMoves(vector<int> &knightPos, vector<int> &targetPos, int n)
{
    queue<cell> q;
    vector<vector<bool> >vis(n+1,vector<bool>(n+1,false));
    cell src(knightPos[0]-1,knightPos[1]-1,0);
    q.push(src);
    vis[knightPos[0]-1][knightPos[1]-1] = true;

    while(!q.empty())
    {
        cell c = q.front();
        
        if(c.x==targetPos[0]-1 && c.y==targetPos[1]-1)
            return c.dist;
        q.pop();
        for(int i=0; i<8; i++)
        {
            int new_x = c.x + rowMoves[i];
            int new_y = c.y + colMoves[i];
            if(isSafe(n,new_x,new_y) && vis[new_x][new_y]==0)
            {
                cell temp(new_x,new_y,c.dist+1);
                q.push(temp);
                vis[new_x][new_y]= true;
            }
        }

    }
    return -1;
}

int main()
{
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    
    vector<int> knightPos;
    vector<int> targetPos;
    int x1,y1,x2,y2;
    
    cout<<"Enter the position of knight: ";
    cin>>x1; cin>>y1;
    knightPos.push_back(x1);
    knightPos.push_back(y1);

    cout<<"Enter the position of target: ";
    cin>>x2; cin>>y2;
    targetPos.push_back(x2);
    targetPos.push_back(y2);
    int ans = minKnightMoves(knightPos,targetPos,n);
    cout<<ans<<endl;
}