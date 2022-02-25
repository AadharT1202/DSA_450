#include<iostream>
using namespace std;
int main()
{
    while(true)
    {
        int n;
        cin>>n;
        if(n==0) break;
        else{
            int a[n];
            for(int i=0; i<n; i++)
                cin>>a[i];
            int m;
            cin>>m;
            int b[m];
            for(int i=0; i<m; i++)
                cin>>b[i];
            int s1=0,s2=0;
            int i=0,j=0;
            int ans=0;
            while(i<n && j<m)
            {
                if(a[i]<b[j])
                    s1+=a[i++];
                else if(b[j]<a[i])
                    s2+=b[j++];
                else
                {
                    ans = ans + max(s1,s2) + a[i];
                    s1=0;
                    s2=0;
                    i++;
                    j++;
                }
            }
            while(i<n)
            {
                s1+=a[i++];
            }
            while(j<m)
            {
                s2+=b[j++];
            }
            ans = ans + max(s1,s2);
            cout<<ans<<endl;
        }
    
    }
}
/*
Input:
13 3 5 7 9 20 25 30 40 55 56 57 60 62
11 1 4 7 11 14 25 44 47 55 57 100
4 -5 100 1000 1005
3 -12 1000 1001
0

Output:
450
2100
*/