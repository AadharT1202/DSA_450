#include<iostream>
#include<vector>
using namespace std;
int dx[8] = {-1,0,1,-1,1,-1,0,1};
int dy[8] = {1,1,1,0,0,-1,-1,-1};
    
void dfs(vector<vector<char> >& grid, vector<vector<bool> >& visited, int x, int y)
{
    int row = grid.size();
    int col = grid[0].size();
    
    visited[x][y] = true;
    for(int i=0; i<8; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx>=0 && nx<row && ny>=0 && ny<col && !visited[nx][ny] && grid[nx][ny]=='1')
            dfs(grid,visited,nx,ny);
    }
    
}
int numIslands(vector<vector<char> >& grid) {
    int row = grid.size();
    int col = grid[0].size();
    vector<vector<bool> > visited(row,vector<bool>(col,false));
    
    int count=0;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            if(grid[i][j]=='1' && !visited[i][j])
            {
                dfs(grid,visited,i,j);
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int row,col;
    cout<<"Enter rows and cols: "<<endl;
    cin>>row>>col;
    vector<vector<char> > grid;
    for(int i=0; i<row; i++)
    {
        vector<char> temp;
        for(int j=0; j<col; j++)
        {
            char x;
            cin >> x;
            temp.push_back(x);
        }
        grid.push_back(temp);
    }
    cout<<"Number of Islands: "<<numIslands(grid)<<endl;
}