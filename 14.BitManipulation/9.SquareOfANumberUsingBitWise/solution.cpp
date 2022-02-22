#include<iostream>
using namespace std;

long long square(long long num)
{
    if (num < 0) num = -num;
 
    int result = 0, times = num;
 
    while (times > 0)
    {
        int possibleShifts = 0, currTimes = 1;
 
        while ((currTimes << 1) <= times)
        {
            currTimes = currTimes << 1;
            ++possibleShifts;
        }
 
        result = result + (num << possibleShifts);
        times = times - currTimes;
    }
 
    return result;
}

int main()
{
    long long n;
    cout<<"Enter the number: ";
    cin>>n;
    cout<<square(n)<<endl;
}