#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int largestAreaInHistogram(vector<int> &heights)
{
    int n = heights.size();
    stack<int> myStack;
    vector<int> left(n),right(n);
    
    //finding the left limits.
    for(int i=0; i<n; i++)
    {
        if(myStack.empty())
        {
            left[i] = 0;
            myStack.push(i);
        }
        else
        {
            while(!myStack.empty() && heights[myStack.top()]>=heights[i])
                myStack.pop();
            left[i] = myStack.empty()? 0 : myStack.top() + 1;
            myStack.push(i);
        }
    }

    //clearing the stack
    while (!myStack.empty())
        myStack.pop();
    
    //filling the right array.
    for(int i=n-1; i>=0; i--)
    {
        if(myStack.empty())
        {
            right[i] = n-1;
            myStack.push(i);
        }
        else{
            while(!myStack.empty() && heights[myStack.top()]>=heights[i])
                myStack.pop();
            right[i] = myStack.empty() ? n-1 : myStack.top() - 1;
            myStack.push(i);
        }
    }

    int maxArea = INT_MIN;
    for(int i=0; i<n; i++)
    {
        maxArea = max(maxArea, (right[i] - left[i] + 1) * heights[i]);
    }
    return maxArea;
}

int maxAreaRectangle(vector<vector<int> > matrix, int n, int m)
{
    vector<int> heights(m,0);
    int ans = INT_MIN;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(matrix[i][j]==0)
                heights[j] = 0;
            else
            {
                heights[j] = matrix[i][j] + heights[j];
            }
        }
        int temp = largestAreaInHistogram(heights);
        if(temp>ans)
            ans = temp;
    }
    return ans;
}

int main()
{
    vector<vector<int> > matrix;
    int n,m;
    cout<<"Enter the rows and cols: ";
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        vector<int> temp;
        for(int j=0; j<m; j++)
        {
            int x;
            cin>>x;
            temp.push_back(x);
        }
        matrix.push_back(temp);
    }
    cout<<"Ans: "<<maxAreaRectangle(matrix, n, m)<<endl;
}