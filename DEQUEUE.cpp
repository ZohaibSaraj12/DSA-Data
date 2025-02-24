#include <iostream>
using namespace std;

class Deque {
    int arr[5];  // Array to store deque elements (size 5 for example)
    int front, rear;  // Indices for front and rear of the deque

public:
    Deque() {
        front = -1;  // Initialize front
        rear = -1;   // Initialize rear
    }

    // Check if the deque is full
    bool isFull() {
        return ((rear + 1) % 5 == front);
    }

    // Check if the deque is empty
    bool isEmpty() {
        return front == -1;
    }

    // Insert at the front
    void insertFront(int value) {
        if (isFull()) {
            cout << "Deque is full!" << endl;
            return;
        }
        if (front == -1) {
            front = rear = 0;  // If deque is empty, set both front and rear to 0
        } else {
            front = (front - 1 + 5) % 5;  // Circular decrement of front index
        }
        arr[front] = value;
        cout << "Inserted " << value << " at the front." << endl;
    }

    // Insert at the rear
    void insertRear(int value) {
        if (isFull()) {
            cout << "Deque is full!" << endl;
            return;
        }
        if (front == -1) {
            front = rear = 0;  // If deque is empty, set both front and rear to 0
        } else {
            rear = (rear + 1) % 5;  // Circular increment of rear index
        }
        arr[rear] = value;
        cout << "Inserted " << value << " at the rear." << endl;
    }

    // Delete from the front
    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty!" << endl;
            return;
        }
        
        cout << "Deleted " << arr[front] << " from the front." << endl;

        if (front == rear) {  // If only one element exists
            front = rear = -1;  // Reset deque after deleting the last element
        } else {
            front = (front + 1) % 5;  // Move front to next element in circular manner
        }
    }

    // Delete from the rear
    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty!" << endl;
            return;
        }
        
        cout << "Deleted " << arr[rear] << " from the rear." << endl;

        if (front == rear) {  // If only one element exists
            front = rear = -1;  // Reset deque after deleting the last element
        } else {
            rear = (rear - 1 + 5) % 5;  // Move rear to previous element in circular manner
        }
    }

    // Display elements of the deque
    void display() {
        if (isEmpty()) {
            cout << "Deque is empty!" << endl;
            return;
        }
        cout << "Deque elements: ";
        int i = front;
        while (i != rear) {
            cout << arr[i] << " ";
            i = (i + 1) % 5;  // Circular increment of the index
        }
        cout << arr[rear] << endl;  // Display the rear element
    }
};

int main() {
    Deque dq;

    // Test cases for insertion and deletion
    dq.insertRear(10);
    dq.insertFront(20);
    dq.insertRear(30);
    dq.insertFront(40);
    
    dq.display();

    dq.deleteFront();
    dq.deleteRear();
    
    dq.display();

    return 0;
}
