#include<iostream>
using namespace std;

bool isWood(int cutHeight, int *arr, int N, int M)
{
    int sum=0;
    for(int i=0; i<N; i++)
    {
        if(arr[i]-cutHeight > 0)
            sum+=arr[i]-cutHeight;
    }
    cout<<"Sum Wood: "<<sum<<endl;
    return sum>=M;
}

int solve(int *arr, int N, int M)
{
    int low=0;
    int ans=-1;
    int high=arr[N-1];
    while(low<high)
    {
        int mid = (high+low)/2;
        cout<<"High: "<<high<<" "<<"Low: "<<low<<" "<<"Mid: "<<mid<<endl;
        if(isWood(mid,arr,N,M))
        {
            ans=mid;
            cout<<ans<<endl;
            low=mid+1;
        }
        else    
            high=mid-1;
    }
    return ans;
}

int main()
{
    int N,M;
    cin>>N>>M;
    int arr[N];
    for(int i=0; i<N; i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+N);
    cout<<solve(arr,N,M)<<endl;
}