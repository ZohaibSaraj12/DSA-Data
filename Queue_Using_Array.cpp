#include <iostream>
using namespace std;
class Queue {
int arr[10];
int front;
int rear;

public:
Queue()
{
    front = -1;
    rear = -1;
}

bool isFull()
{
    return (rear == 9);
}

bool isEmpty()
{
    return (front == -1);
}

void push(int data)
{
    if (isFull())
    {
        cout << "Full Queue can't Push AnyMore" << endl;
        return;

    }
    if (front == -1)
    {
        front = 0;
    }
    else 
    {
        rear++;
        arr[rear] = data;
        cout << "Element Pushed with value " << data << endl;
    }
}
void pop()
{
    if (isEmpty())
    {
        cout << "Queue is Empty" << endl;
        return; 
    }

    cout << "Value deleted" << arr[front] << endl;

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }

    else 
    {
        front++;
    }
}
void frontElement()
{
    if (isEmpty())
    {
        cout << "Stack Empty no front Element, Push onto the Queue " << endl;
        return;
    }
    else 
    {
        cout << "front Element is: " << arr[front] << endl;
    }
}
void backElement()
{
    if (isEmpty())
    {
        cout << "Stack Empty no back Element, Push onto the Queue" << endl;
        return;
    }
    else 
    {
        cout << "front Element is: " << arr[rear] << endl;
    }
}

void display()
{
    if (isEmpty())
    {
        cout << "Empty can't print" << endl;
        return;
    }

    else 
    {
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}
};
int main()
{

}