#include<iostream>
using namespace std;

int division(long long divisor, long long divident)
{
    int sign = 1;
    if(divisor<0)
        sign *= -1;
    if(divident<0)
        sign *= -1;
            
    long long n,m;
    n = abs(divident);
    m = abs(divisor);
    long long q = 0;
    long long t = 0;

    for(int i=31; i>=0; i--)
    {
        if(t+(m<<i) <= n)
        {
            t += (m<<i);
            q += (1<<i);
        }
    }

    if(sign==1)
        return q;
    else
        return -1*q;
}

int main()
{
    long long divisor, divident;
    cout<<"Enter the divident: ";
    cin>>divident;
    cout<<"Enter the divisor: ";
    cin>>divisor;
    cout<<"Quotient is: "<<division(divisor,divident)<<endl;

}