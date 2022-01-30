#include<iostream>
#include<unordered_set>
using namespace std;

string isSubset(int *a1, int *a2, int n1, int n2)
{
    unordered_set<int> s(a1,a1+n1);
    for(int i=0; i<n2; i++)
    {
        if(s.find(a2[i])==s.end())
            return "No";
    }
    return "Yes";
}

int main()
{
    int a1[] = {11, 1, 13, 21, 3, 7};
    int a2[] = {11, 3, 7, 1};
    int n1 = sizeof(a1)/sizeof(a1[0]);
    int n2 = sizeof(a2)/sizeof(a2[0]);

    cout<<isSubset(a1,a2,n1,n2)<<"\n";
}