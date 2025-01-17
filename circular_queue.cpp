#include <iostream>
using namespace std;

class CircularQueue {
    int arr[10]; // Array to hold queue elements
    int rear;    // Index for rear of the queue
    int front;   // Index for front of the queue

public:
    CircularQueue() {
        front = -1; // Initialize front to -1
        rear = -1;  // Initialize rear to -1
    }

    // Check if the queue is full
    bool isFull() {
        return ((rear + 1) % 10 == front);
    }

    // Check if the queue is empty
    bool isEmpty() {
        return (front == -1);
    }

    // Add an element to the queue
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is Full " << endl;
            return;
        }
        if (front == -1) {
            front = 0; // Set front to 0 if queue was empty
        }
        rear = (rear + 1) % 10; // Move rear in circular manner
        arr[rear] = value;      // Insert the value at rear
        cout << "Value pushed into circular queue: " << value << endl;
    }
     void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }
        
        int value = arr[front]; // The value to be dequeued
        cout << "Dequeued: " << value << endl;
        
        if (front == rear) {
            front = rear = -1; // Queue is empty after dequeue
        } 
        else{
        front = (front + 1) % 10; // Move front in circular manner
        }
    }

    // Display the elements of the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % 10; // Move to the next element in circular manner
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();
    


    q.dequeue();
    q.dequeue();
    q.dequeue();

    q.display();
    return 0;
}
