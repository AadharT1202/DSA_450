#include<iostream>
#include<vector>
using namespace std;

void heapify(vector<int> &heap, int curr, int n)
{
    int largest = curr;
    int lChild = 2*curr + 1;
    int rChild = 2*curr + 2;

    if(lChild<n && heap[lChild]>heap[curr])
        largest = lChild;
    if(rChild<n && heap[rChild]>heap[largest])
        largest = rChild;
    if(largest != curr)
    {
        swap(heap[largest],heap[curr]);
        heapify(heap,largest,n);
    }
}

void heapSort(vector<int> &heap, int n)
{
    //Build heap
    int startIndex = (n/2) - 1;
    for(int i=startIndex; i>=0; i--)
        heapify(heap,i,n);

    //heapSort
    for(int i=heap.size()-1; i>=0; i--)
    {
        int max = heap[0];
        heap[0] = heap[i];
        heap[i] = max;
        heapify(heap,0,i);
    }
}

void printHeap(vector<int> &heap, int n)
{
    cout << "Heap in ASC order is:\n";
 
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
    heapSort(heap, heapSize);
    printHeap(heap,heapSize);
}