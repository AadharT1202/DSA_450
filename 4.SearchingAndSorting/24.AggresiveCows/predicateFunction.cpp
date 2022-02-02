#include<iostream>
using namespace std;
const int N = 10e5+10;
int n,cows;
long long position[N];

bool canPlaceCows(long long dis)
{
    long long last=-1;
    int cow_cnt = cows;
    for(int i=0; i<n; i++)
    {
        if(position[i]-last >= dis || last==-1)
        {
            cow_cnt--;
            last = position[i];
        }
        if(cow_cnt==0)
            break;
    }
    return cow_cnt==0;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>cows;
        for(int i=0; i<n; i++)
        {
            cin>>position[i];
        }
    }
    sort(position,position+n);

    long long low = 0;
    long long high = 10e9;
    while(high-low>1)
    {
        long long mid = (high+low)/2;
        if(canPlaceCows(mid))
            low=mid;
        else
            high=mid-1;
    }
    if(canPlaceCows(high))
        cout<<high<<endl;
    else    
        cout<<low<<endl;
    return 0;
}