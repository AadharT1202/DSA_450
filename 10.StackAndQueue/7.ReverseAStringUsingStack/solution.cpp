#include<iostream>
#include<stack>
using namespace std;

char* reverse(char *S, int len)
{
    stack<char> s;
    for(int i=0; i<len; i++)
        s.push(S[i]);
        
    int i=0;
    while(!s.empty())
    {
        S[i] = s.top();
        s.pop();
        i++;
    }
    return S;
}

int main()
{
    char str[1000];
    cin>>str;
    int len = strlen(str);
    char *ch = reverse(str,len);
    for(int i=0; i<len; i++)
        cout<<ch[i];
    cout<<endl;
}