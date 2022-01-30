#include<iostream>
#include<vector>
using namespace std;

vector<int> commonElements(int *a, int *b, int *c, int n1, int n2, int n3)
{
    int i = 0;
    int j = 0;
    int k = 0;
    vector<int> result;
    while(i<n1 && j<n2 && k<n3)
    {
        if(a[i]==b[j] && b[j]==c[k])
        {
            result.push_back(a[i]);
            i++;
            j++;
            k++;
        }

        else if(a[i] < b[j])
            i++;
        else if(b[j] < c[k])
            j++;
        else
            k++;
    }
    //cout<<result.size();
    return result;
}

int main()
{
    int n1 = 6; 
    int A[] = {1, 5, 10, 20, 40, 80};
    int n2 = 5; 
    int B[] = {6, 7, 20, 80, 100};
    int n3 = 8;
    int C[] = {3, 4, 15, 20, 30, 70, 80, 120};
    vector<int> ans = commonElements(A,B,C,n1,n2,n3);
    //cout<<ans.size();
    cout<<"Common Elements are: ";
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}