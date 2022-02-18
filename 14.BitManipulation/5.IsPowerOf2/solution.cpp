#include<iostream>
using namespace std;

bool isPower(int n)
{
    if(n==0)
        return false;

    if((n & (n-1))==0)
        return true;
    else
     return false;
}

int main()
{
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    int ans = isPower(n);
    if(ans==true)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}