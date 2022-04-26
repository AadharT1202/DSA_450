#include<iostream>
#include<vector>
using namespace std;

void heapify(vector<int> &heap, int curr, int n)
{
    int smallest = curr;
    int lChild = 2*curr + 1;
    int rChild = 2*curr + 2;

    if(lChild<n && heap[lChild]<heap[curr])
        smallest = lChild;
    if(rChild<n && heap[rChild]<heap[smallest])
        smallest = rChild;
    if(smallest != curr)
    {
        swap(heap[smallest],heap[curr]);
        heapify(heap,smallest,n);
    }
}

void buildHeap(vector<int> &heap, int n)
{
    int startIndex = (n/2) - 1;
    for(int i=startIndex; i>=0; i--)
    {
        heapify(heap,i,n);
    }
}

void printHeap(vector<int> &heap, int n)
{
    cout << "Array representation of Heap is:\n";
 
    for (int i = 0; i < n; ++i)
        cout << heap[i] << " ";
    cout << "\n";
}
int main()
{
    vector<int> heap;
    int heapSize;
    cout<<"Enter the number of elements in the array: ";
    cin>>heapSize;
    for(int i=0; i<heapSize; i++)
    {
        int x;
        cin>>x;
        heap.push_back(x);
    }
    buildHeap(heap,heapSize);
    printHeap(heap,heapSize);
}