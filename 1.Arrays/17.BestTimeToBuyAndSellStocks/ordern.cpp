#include<iostream>
using namespace std;

int maxProfit(int *prices, int n)
{
    int maxPro = 0;
    int minPrice = INT_MAX;
    for(int i=0; i<n; i++)
    {
        minPrice = min(minPrice, prices[i]);
        maxPro = max(maxPro, prices[i]-minPrice);
    }
    return maxPro;
}

int main()
{
    int prices[] = {7, 1, 5, 3, 6, 4} ;
    int n = sizeof(prices)/sizeof(prices[0]);
    cout<<"Max Profit: "<<maxProfit(prices,n)<<endl;
}