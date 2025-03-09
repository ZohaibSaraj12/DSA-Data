#include <iostream>
#include <vector>
using namespace std;
class Queue {
vector<int> arr;
int front;
int rear;
public:
Queue() : arr(10, 0) 
{
    front = -1; 
    rear = -1;
}

bool isFull()
{
    return rear == (arr.size() - 1);
}
bool isEmpty()
{
    return (front == -1);
}
void push(int data)
{
    if (isFull())
    {
        cout << "queue Full, overflow" << endl;
        return;
    }
    
    if (front == -1)
    {
        front = 0;
    }

    rear++;
    arr[rear] = data;
    cout << "\nValue with " << data << " pushed" << endl;
}
void pop()
{
    if (isEmpty())
    {
        cout << "queue is empty" << endl;
        return;
    }
    cout << "Value deleted with data " << arr[front] << endl;

    if (front == rear)
    {
        front = rear = -1;
    }

    else
    {
        front++;
    }
    
}
void frontElement()
{
    cout << "Front is " << arr[front] << endl;
}
void rearElement()
{
    cout << "Rear is " << arr[rear] << endl;
}
};
int main()
{
    Queue q;
    q.push(20);
    q.push(30);
    q.push(40);

    q.frontElement();
    q.rearElement();

}