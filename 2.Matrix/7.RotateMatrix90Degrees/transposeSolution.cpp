#include<iostream>
#include<vector>
using namespace std;

void rotate(vector<vector<int> > matrix,int rows, int cols)
{
    //taking transpose
    for(int i=0; i<rows; i++)
    {
        for(int j=i; j<cols; j++)
        {
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    //swapping the columns
    for(int i=0; i<rows; i++)
    {
        int l = 0;
        int r = cols-1;
        while(l<r)
        {
            swap(matrix[i][l],matrix[i][r]);
            l++;
            r--;
        }
    }
    cout<<"After Rotation: "<<endl;
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int rows,cols;
    cin>>rows>>cols;
    vector<vector<int> > matrix;
    for(int i=0; i<rows; i++)
    {
        vector<int> temp;
        for(int j=0; j<cols; j++)
        {
            int x;
            cin>>x;
            temp.push_back(x);
        }
        matrix.push_back(temp);
    }
    cout<<"Before Rotation: "<<endl;
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    rotate(matrix,rows,cols);
    
}