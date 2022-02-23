#include<iostream>
using namespace std;
int countBitsFlip(int a, int b)
{   
    int XOR = a ^ b;
    int count=0;
    while(XOR>0)
    {
        XOR = XOR & (XOR-1);
        count++;
    }
    return count;
}

int main()
{
    int a,b;
    cout<<"Input the values of a and b: ";
    cin>>a>>b;
    cout<<"Bits to be toggled: "<<countBitsFlip(a,b)<<endl;
}