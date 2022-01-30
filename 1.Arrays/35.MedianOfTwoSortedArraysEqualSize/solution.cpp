#include<iostream>
using namespace std;

int findMedian(int *arr1, int *arr2, int n1, int n2)
{
    int low = 0;
    int high = n1;
    while(low<=high)
    {
        int cut1 = low + (high-low)/2;
        int cut2 = (n1+n2)/2 - cut1;

        int l1 = (cut1==0)?INT_MIN:arr1[cut1-1];
        int l2 = (cut2==0)?INT_MIN:arr2[cut2-1];
        int r1 = (cut1==n1)?INT_MAX:arr1[cut1+1];
        int r2 = (cut2==n2)?INT_MAX:arr2[cut2+1];

        if(l1>r2)
            high = cut1-1;
        else if(l2>l1)
            low = cut1+1;
        else{
            if((n1+n2)%2==0)
            {
                return (max(l1,l2)+min(r1,r2))/2;
            }
            else
                return min(r1,r2);
        }
    }
    return 0;
}

int main()
{
    int ar1[] = {1, 12, 15, 26, 38};
    int ar2[] = {2, 13, 17, 30, 45};
 
    int n1 = sizeof(ar1)/sizeof(ar1[0]);
    int n2 = sizeof(ar2)/sizeof(ar2[0]);
    if (n1 == n2)
        printf("Median is %d", findMedian(ar1, ar2, n1, n2));
    else
        printf("Doesn't work for arrays of unequal size");
    return 0;
}