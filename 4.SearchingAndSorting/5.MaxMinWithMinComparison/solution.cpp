#include<iostream>
using namespace std;
int middle(int A, int B, int C)
{
    //code here//Position this line where user code will be pasted.
    int mx=max(A,max(B,C));;
    int mn=min(A,min(B,C));
    int z=A+B+C-mx-mn;
    return z;
}

int main()
{
    int a=978, b=518, c=300;
    cout<<middle(a,b,c)<<endl;
}