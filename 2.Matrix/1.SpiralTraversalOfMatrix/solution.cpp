#include<iostream>
#include<vector>
using namespace std;
vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
{
    vector<int> ans;
    int startRow = 0;
    int endRow = r-1;
    int startCol = 0;
    int endCol = c-1;
    
    while(startRow<=endRow && startCol<=endCol)
    {
        for(int i=startCol; i<=endCol; i++)
        {
            ans.push_back(matrix[startRow][i]);
        }
        startRow++;
        
        for(int i=startRow; i<=endRow; i++)
        {
            ans.push_back(matrix[i][endCol]);
        }
        endCol--;
        
        if(startRow<=endRow)
        {
            for(int i=endCol; i>=startCol; i--)
            {
                ans.push_back(matrix[endRow][i]);
            }
            endRow--;
        }
        
        if(startCol<=endCol)
        {
            for(int i=endRow; i>=startRow; i--)
            {
                ans.push_back(matrix[i][startCol]);
            }                
            startCol++;
        }
    }
    return ans;
}

int main()
{
    int r,c;
    cout<<"Enter the number of rows and cols: ";
    cin>>r>>c;
    vector<vector<int> > matrix;
    cout<<"Enter the elements of matrix: "<<endl;
    for(int i=0; i<r; i++)
    {
        vector<int> temp;
        for(int j=0; j<c; j++)
        {
            int x;
            cin>>x;
            temp.push_back(x);
        }
        matrix.push_back(temp);
    }
    vector<int> ans = spirallyTraverse(matrix,r,c);
    for(int i=0; i<r*c; i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}