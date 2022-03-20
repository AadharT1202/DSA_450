#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> NGE(vector<int> v, int n)
{
    vector<int> nge;
    stack<int> st;
    for(int i=0; i<n; i++)
    {
        if(st.empty())
            st.push(i);
        else
        {
            if(v[i] <= v[st.top()])
                st.push(i);
            else
            {
                while(!st.empty() && v[i]>v[st.top()])
                {
                    nge[st.top()] = v[i];
                    st.pop();
                }
                st.push(i);
            }
        }
    }
    while(!st.empty())
    {
        nge[st.top()] = -1;
        st.pop();
    }
    return nge;
}

int main()
{
    vector<int> v;
    int n;
    cout<<"Enter the number of elements";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    vector<int> sol = NGE(v,n);
    for(int i=0; i<n; i++)
    {
        cout<<sol[i]<<" ";
    }
    cout<<endl;
}