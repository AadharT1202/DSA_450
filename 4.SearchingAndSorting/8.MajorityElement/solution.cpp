#include<iostream>
using namespace std;
int majorityElement(int a[], int size)
{
    
    int maj_index = 0, count = 1;
    for (int i = 1; i < size; i++) {
    if (a[maj_index] == a[i])
        count++;
    else
        count--;
    if (count == 0) {
        maj_index = i;
        count = 1;
    }
}

    int cnt = 0;
    for(int i=0; i<size; i++)
    {
        if(a[i]==a[maj_index])
            cnt++;
    }
    
    if(cnt>size/2)
        return a[maj_index];
    else
        return -1;
    
}
int main()
{
    int a[] = {3,1,3,3,2};
    int n = sizeof(a)/sizeof(a[0]);
    cout<<"Majority Element is: "<<majorityElement(a,n)<<endl;
}