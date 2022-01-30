#include<iostream>
#define MAX 500
using namespace std;

int mul(int *res, int res_size, int x)
{
    int carry = 0;
    for(int i=0; i<res_size; i++)
    {
        int prod = res[i] * x + carry;
        res[i] = prod%10;
        carry = prod/10;
    }

    while(carry)
    {
        res[res_size] = carry%10;
        carry = carry/10;
        res_size++;
    }
    return res_size;
}

void factorial(int n)
{
    int res[MAX];
    res[0]=1;
    int res_size = 1;

    for(int x=2; x<=n; x++)
    {
        res_size = mul(res,res_size,x);
    }

    cout << "Factorial of given number is \n";
    for (int i=res_size-1; i>=0; i--)
        cout << res[i];
    cout<<"\n";
}

int main()
{
    factorial(50);
    return 0;
}