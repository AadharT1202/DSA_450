#include<iostream>
using namespace std;
int PalinArray(int a[], int n)
{ 
    for(int i=0;i<n;i++){
        int temp=a[i];
        int sum=0;
        int flag;
        while(temp!=0){
            int rev=temp%10;
            sum=10*sum+rev;
            temp=temp/10;
        }
        if(sum!=a[i]){
            return false;
        }
    }
    return true;
}

int main()
{
    int arr[] = {111, 222, 333, 444, 555};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<PalinArray(arr,n)<<"\n";
}