//Naieve sol is traverse the whole matrix in O(n2)
//this solution works in lesser time complexity.

#include<iostream>
#include<vector>
using namespace std;
bool search(vector<vector<int> > matrix, int n, int m, int x) 
{
    int row = 0;
    int col = m-1;
    while(row<n && col>=0)
    {
        if(matrix[row][col]==x)
            return true;
        
        else if(matrix[row][col]<x)
            row++;
        
        else if(matrix[row][col]>x)
            col--;
    }
    return false;
}
int main()
{
    cout<<"Enter rows and cols: ";
    int n,m;
    cin>>n>>m;
    vector<vector<int> >matrix;
    for(int i=0; i<n; i++)
    {
        vector<int> temp;
        for(int j=0; j<m; j++)
        {
            int x;
            cin>>x;
            temp.push_back(x);
        }
        matrix.push_back(temp);
    }
    int x;
    cout<<"Enter the target element: ";
    cin>>x;

    bool ans = search(matrix, n,m,x);
    if(ans)
        cout<<"Element Found";
    else    
        cout<<"Element not found";
    cout<<endl;
}