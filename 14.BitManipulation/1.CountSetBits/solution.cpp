#include<iostream>
using namespace std;
int setBits(int N) 
{
    int count=0;
    while(N>0)
    {
        if(N&1)
            count++;
        N = N>>1;

    }
    return count;
}
int main()
{
    int n;
    cout<<"Enter the number: ";
    cin>>n;

    cout<<"Number of set bits are: "<<setBits(n)<<endl;
}