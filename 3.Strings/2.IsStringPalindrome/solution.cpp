#include<iostream>
using namespace std;

bool isPlaindrome(string in)
{
    int i=0;
    int j=in.length()-1;
    while(i<=j)
    {
        if(in[i]!=in[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int main()
{
    string in;
    cout<<"Enter a string to be checked: ";
    cin>>in;
    bool ans = isPlaindrome(in);
    if(ans==true)
        cout<<"Palindrome"<<endl;
    else    
        cout<<"Not Palindrome"<<endl;
}