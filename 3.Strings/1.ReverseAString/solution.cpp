#include<iostream>
using namespace std;

int main()
{
    string in;
    cout<<"Enter the string to be reversed: ";
    cin>>in;
    int i=0;
    int j=in.length()-1;
    while(i<=j)
    {
        char temp = in[i];
        in[i] = in[j];
        in[j] = temp;
        i++;
        j--;
    }
    cout<<"String after reversing: "<<in<<endl;
}