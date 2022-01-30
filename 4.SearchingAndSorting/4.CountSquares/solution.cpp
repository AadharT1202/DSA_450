#include<iostream>
#include<cmath>
using namespace std;
int countSquares(int N) 
{
    int count=0;
    for(int i=1; i<sqrt(N); i++)
    {
        if(i*i < N)
            count++;
    }
    return count;
}

int countSquares2(int N)
{
    int a = sqrt(N);
    if(a*a==N)
        return a-1;
    else 
        return a;
}

int main()
{
    int n = 26;
    cout<<countSquares(n)<<endl;
    cout<<countSquares2(n)<<endl;
}