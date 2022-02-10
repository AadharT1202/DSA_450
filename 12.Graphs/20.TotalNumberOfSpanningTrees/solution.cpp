#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int determinant( int matrix[3][3], int n) 
{
    int det = 0;
    int submatrix[3][3];
    if (n == 2)
    return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
    else {
        for (int x = 0; x < n; x++) {
            int subi = 0;
            for (int i = 1; i < n; i++) {
            int subj = 0;
            for (int j = 0; j < n; j++) {
                if (j == x)
                continue;
                submatrix[subi][subj] = matrix[i][j];
                subj++;
            }
            subi++;
            }
            det = det + (pow(-1, x) * matrix[0][x] * determinant( submatrix, n - 1 ));
        }
    }
    return det;
}


int main()
{
    int vertices,edges;
    cout<<"Enter number of vertices and edges: ";
    cin>>vertices>>edges;

    vector<vector<int> > adjMatrix (vertices,vector<int>(vertices,0));
    vector<vector<int> > degreeMatrix (vertices,vector<int>(vertices,0));
    vector<vector<int> > laplacianMatrix (vertices,vector<int>(vertices,0));

    cout<<"Enter the edges as u-v: ";
    for(int i=0; i<edges; i++)
    {
        int u,v;
        cin>>u>>v;
        adjMatrix[u][v]=1;
        adjMatrix[v][u]=1;
        degreeMatrix[v][v]++;
        degreeMatrix[u][u]++;
    }

    for(int i=0; i<vertices; i++)
    {
        for(int j=0;j<vertices; j++)
        {
            laplacianMatrix[i][j] = degreeMatrix[i][j] - adjMatrix[i][j];
            cout<<laplacianMatrix[i][j]<<" ";
        }
        cout<<endl;
    }

    int mat[3][3];
    for(int i=1; i<vertices; i++)
    {
        for(int j=1; j<vertices; j++)
        {
            mat[i-1][j-1] = laplacianMatrix[i][j];
        }
    }

    cout<<determinant(mat,3)<<endl;
}