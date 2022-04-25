#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

void commonElements(vector<vector<int> > matrix, int row, int col)
{
    unordered_map<int, int> mp;
    for(int i=0; i<col; i++)
        mp[matrix[0][i]] = 1;

    for(int i=1; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            if(mp[matrix[i][j]]==i)
            {
                mp[matrix[i][j]]++;

                if(i==row-1 && mp[matrix[i][j]]==row)
                    cout<<matrix[i][j]<<" ";
            }
        }
    }
}

int main()
{
    int row,col;
    cout<<"Enter the number of rows and cols: ";
    cin>>row>>col;

    vector<vector<int> > matrix;
    for(int i=0; i<row; i++)
    {
        vector<int> temp;
        for(int j=0; j<col; j++)
        {
            int x;
            cin>>x;
            temp.push_back(x);
        }
        matrix.push_back(temp);
    }
    commonElements(matrix,row,col);
    cout<<endl;
}