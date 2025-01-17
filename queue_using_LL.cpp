#include <iostream>
using namespace std;
class Node
{

public:
    int data;
    Node *next;
    Node(int value)
    {
        data = value;
        next = NULL;
    }
    ~Node()
    {
        this->next = NULL;
    }
};
class Queue
{

    Node *front;
    Node *rear;

public:
    Queue()
    {
        front = rear = NULL;
    }

    bool isEmpty()
    {
        return (front == NULL || rear == NULL);
    }

    void push(int data)
    {
        Node *temp = new Node(data);

        if (front == NULL || rear == NULL)
        {
            front = rear = temp;
        }

        rear->next = temp;
        rear = temp;
    }
    void pop()
    {
        if (front == NULL || rear == NULL)
        {
            cout << "Empty";
            return;
        }
        Node *temp = front;
        cout << "Deleted value " << temp->data << endl;
        front = front->next;
        temp->next = NULL;
        delete temp;
    }
    void frontElement()
    {
        if (front == NULL || rear == NULL)
        {
            cout << "Empty cannot display the front element" << endl;
            return;
        }

        else
        {
            cout << "Data of Front is: " << front->data << endl;
        }
    }
    void backElement()
    {
        if (front == NULL || rear == NULL)
        {
            cout << "Empty cannot display the rear element" << endl;
            return;
        }
        else
        {
            cout << "rear data is: " << rear->data << " " << endl;
        }
    }
    void display()
    {
        if (front == NULL || rear == NULL)
        {
            cout << "Empty is the Queue" << endl;
            return;
        }
        Node *temp = front;

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.frontElement();
    q.backElement();
    q.display();
    q.pop();
    q.display();
    q.pop();
    q.display();
}