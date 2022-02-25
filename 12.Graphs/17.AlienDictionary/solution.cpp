#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int>graph[20];

string findOrder(int n, int k, vector<string> &dict)
{
    for(int i=0; i<n-1; i++)
    {
        string w1 = dict[i];
        string w2 = dict[i+1];
        
        for(int i=0; i<min(w1.length(),w2.length()); i++)
        {
            if(w1[i]!=w2[i])
            {
                graph[w1[i]-'a'].push_back(w2[i]-'a');
                break;
            }
        }
    }

    vector<int> inDegree(k,0);
    for(int i=0; i<k; i++)
    {
        for(int j=0; j<graph[i].size(); j++)
        {
            int cur = graph[i][j];
            inDegree[cur]++;
        }
    }
    
    string ans;
    queue<int> q;
    bool isZero = false;
    for(int i=0; i<k; i++)
    {
        if(inDegree[i]==0)
        {
            isZero=true;
            q.push(i);
        }
    }
    if(isZero==false)
        return "";
    
    while(!q.empty())
    {
        int x = q.front();
        char temp = x + 'a';
        q.pop();
        ans += temp;
        for(int i=0; i<graph[x].size(); i++)
        {
            int node = graph[x][i];
            inDegree[node]--;
            if(inDegree[node]==0)
                q.push(node);
        }
    }
    return ans;
}

int main()
{
    int n, k;
    cout<<"Enter the number of words in the dictionary: ";
    cin>>n;
    cout<<"Enter the number of alphabets: ";
    cin>>k;
    vector<string> dict;
    for(int i=0; i<n; i++)
    {
        string x;
        cin >> x;
        dict.push_back(x);
    }
    string ans = findOrder(n,k,dict);
    for(int i=0; i<ans.length(); i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}