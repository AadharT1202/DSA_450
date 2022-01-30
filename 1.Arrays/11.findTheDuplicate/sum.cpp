#include<iostream>
using namespace std;
int main()
{
    int arr[] = {1,3,4,2,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum_1_n = (n * (n-1))/2;
    int sum=0;
    for(int i=0; i<n; i++)
        sum+=arr[i];
    cout<<"Repeated Element: "<<sum - sum_1_n<<endl;
}