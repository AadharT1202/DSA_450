#include<iostream>
using namespace std;

int positionOfSetBit(int n)
{
    int pos=0;

    if(n==0)
        return -1;
    int x = (n & (n-1));
    if(x!=0)
        return -1;


    else if(x==0)
    {
        while(n >= (1<<pos))
            pos++;
    }
    return pos;
}

int main()
{
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    cout<<"Position of set bit is: "<<positionOfSetBit(n)<<endl;
}