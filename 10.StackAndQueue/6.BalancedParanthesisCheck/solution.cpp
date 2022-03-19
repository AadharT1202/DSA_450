#include<iostream>
#include<stack>
using namespace std;
bool ispar(string str)
{
    bool flag=true;
    stack<char>st;
    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='(' || str[i]=='[' || str[i]=='{') st.push(str[i]);
        
        else
        {
            if(st.empty()) flag=false;
            else
            {
                if(str[i]==')'&&st.top()=='(' ||
                str[i]==']'&&st.top()=='[' ||
                str[i]=='}'&&st.top()=='{') st.pop();
                
                else flag=false;
                
            }
        }
    }
    
    if(flag&&st.empty()) return true;
    else return false;
}
int main()
{
    string a;
    cin>>a;
    if(ispar(a))
        cout<<"Balanced"<<endl;
    else    
        cout<<"Unbalanced"<<endl;   
}