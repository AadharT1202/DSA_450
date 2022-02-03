#include<iostream>
using namespace std;
bool isValid(int n,int k)
{
    int temp=k;
    int count=0;
    int f=5;
    while(f<=k)
    {
        count = count + temp/f;
        f*=5;
    }
    return(count>=n);
}
    
int findNum(int n)
{
    int low=0;
    int high=n*5;
    while(low<high)
    {
        int mid=(high+low)/2;
        if(isValid(n,mid))
        {
            high=mid;
        }
        else
            low=mid+1;
        
    }
    if(high<low)
        return high;
    else
        return low;
}
int main()
{
    int n = 6;
    cout<<findNum(n)<<endl;
}