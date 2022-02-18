#include<iostream>
using namespace std;
int highestPowerOf2(int n)
{
    int x=0;
    while(n >= (1<<x))
        x++;
    return x-1;
}

int countSetBits(int n)
{
    if(n==0)
        return 0;
        
    int x = highestPowerOf2(n);
    int bitsTill2powX = x * (1<<(x-1));
    int msb = n-(1<<x)+1;
    int rest = n - (1<<x);
    int ans = bitsTill2powX + msb + countSetBits(rest);
    return ans;
}

int main()
{
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    cout<<"Number of set bits from 1 to n: "<<countSetBits(n)<<endl;
}