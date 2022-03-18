#include<iostream>
using namespace std;
#define n 20
class queue{
    int *arr;
    int front;
    int back;

    public:
        queue()
        {
            arr = new int[n];
            front = -1;
            back = -1;
        }
        void enqueue(int x);
        void dequeue();
        int peek();
        bool isEmpty();
};

void queue::enqueue(int x)
{
    if(back == n-1)
    {
        cout<<"Queue overflow";
        return;
    }
    back++;
    arr[back] = x;
    if(front==-1)
        front++;
}

void queue::dequeue()
{
    if(front==-1 || front>back)
    {
        cout<<"Queue is empty";
        return;
    }
    front++;
}

int queue::peek()
{
    if(front==-1 || front>back)
    {
        cout<<"Queue is empty";
        return -1;
    }
    return arr[front];
}

bool queue::isEmpty()
{
    return (front==-1 || front>back);
}

int main()
{
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    cout<<q.peek()<<endl;
    q.dequeue();
    cout<<q.peek()<<endl;
    q.dequeue();
    
    cout<<q.isEmpty()<<endl;
}