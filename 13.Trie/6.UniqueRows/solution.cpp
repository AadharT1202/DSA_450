// { Driver Code Starts
#include<iostream>
#include<vector>
using namespace std;
#define MAX 1000


struct TrieNode{
  struct TrieNode *child[2];
  bool flag;
};

struct TrieNode* getNode()
{
    struct TrieNode *temp = new TrieNode;
    for(int i=0; i<2; i++)
        temp->child[i] = NULL;
    temp->flag = false;
    return temp;
}

bool isPresent(TrieNode *root, int arr[], int n)
{
    TrieNode *temp = root;
    for(int i=0; i<n; i++)
    {
        int idx = arr[i];
        if(temp->child[idx]==NULL)
            return false;
        temp = temp->child[idx];
    }
    return temp->flag;
}

void insert(TrieNode *root, int arr[], int n)
{
    TrieNode *temp = root;
    for(int i=0; i<n; i++)
    {
        int idx = arr[i];
        if(temp->child[idx]==NULL)
            temp->child[idx] = getNode();
        temp = temp->child[idx];
    }
    temp->flag = true;
}
vector<vector<int> > uniqueRow(int M[MAX][MAX],int row,int col)
{
    struct TrieNode *root = getNode();
    vector<vector<int> >res;
    for(int i=0; i<row; i++)
    {
        if(!isPresent(root,M[i],col))
        {
            vector<int> inner;
            insert(root,M[i],col);
            for(int j=0; j<col; j++)
            {
                inner.push_back(M[i][j]);
            }
            
            res.push_back(inner);
        }
    }
    return res;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int n,m;
    	cin>>n>>m;
    	int a[MAX][MAX];
    	for(int i=0;i<n;i++)
    	    for(int j=0;j<m;j++)
    	        cin>>a[i][j];
    	vector<vector<int> > vec = uniqueRow(a,n,m);
    	for(int i = 0;i<vec.size();i++){
    	    for(int j=0; j<vec[i].size(); j++){
    	        cout<<vec[i][j]<<" ";
    	    }
    	    cout<<"$";
    	}
    	cout<<endl;
    }
}
