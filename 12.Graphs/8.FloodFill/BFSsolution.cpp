#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

bool isValid(int x, int y, int rows, int cols)
{
    if(x>=0 && y>=0 && x<rows && y<cols)
        return true;
    else
        return false;
}

void floodFill(int sr, int sc, int rows, int cols, int oldColor, int newColor, vector<vector<int> >&image)
{

    if(image[sr][sc]==newColor)
        return;

    vector<vector<bool> >visited(rows, vector<bool>(cols,false));
    queue<pair<int,int> > q;
    q.push(make_pair(sr,sc));
    visited[sr][sc]=true;
    image[sr][sc] = newColor;
    while(!q.empty())
    {
        pair<int,int> p = q.front();
        q.pop();
        int x1 = p.first;
        int y1 = p.second;
        for(int i=0; i<4; i++)
        {
            int new_x = x1 + dx[i];
            int new_y = y1 + dy[i];
            if(isValid(new_x,new_y,rows,cols) && !visited[new_x][new_y] && image[new_x][new_y]==oldColor)
            {
                image[new_x][new_y]=newColor;
                q.push(make_pair(new_x,new_y));
            }
        }

    }
}

int main()
{
    int rows,cols;
    cout<<"Enter number of rows and cols: ";
    cin>>rows>>cols;
    vector<vector<int> >image(rows,vector<int>(cols,0));

    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            cin>>image[i][j];
        }
    }
    
    int sr,sc,newColor;
    cout<<"Enter the position of source: ";
    cin>>sr>>sc;
    cout<<"Enter new color: ";
    cin>>newColor;
    int oldColor = image[sr][sc];
    cout<<oldColor<<endl;

    floodFill(sr,sc,rows,cols,oldColor,newColor,image);

    cout<<"After flood fill algo: "<<endl;;
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            cout<<image[i][j]<<" ";
        }
        cout<<endl;
    }
}