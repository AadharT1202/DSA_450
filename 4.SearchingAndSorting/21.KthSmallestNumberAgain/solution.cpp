#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int t;
    cout<<"Enter number of test cases: "<<endl;
    cin>>t;
    while(t--)
    {
        cout<<"Enter the number of ranges: "<<endl;
        int n;
        cin>>n;
        cout<<"Enter number of queries: "<<endl;
        int q;
        cin>>q;

        vector<pair<int,int> > v;
        for(int i=0; i<n; i++)
        {
            int x,y;
            cin>>x>>y;
            v.push_back(make_pair(x,y));
        }

        sort(v.begin(),v.end());
        vector<pair<int,int> > uniqueIntervals;
        int idx=0;
        for(int j=1; j<n; j++)
        {
            if(v[idx].second >= v[j].first)
            {
                v[idx].second = max(v[idx].second,v[j].second);
            }
            else
            {
                idx++;
                v[idx] = v[j];
            }

        }
        while(q--)
        {
            int k;
            cin>>k;
            int ans = -1;
            for(int i=0; i<=idx; i++)
            {
                if(v[i].second - v[i].first + 1 >=k)
                {
                    ans = v[i].first + k -1;
                    break;
                }
                else
                    k = k - (v[i].second - v[i].first + 1);
            }
            cout<<ans<<endl;
        }

    }
}