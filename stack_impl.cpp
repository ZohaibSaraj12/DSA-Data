#include <iostream>
using namespace std;
class Stack {
public:
int* arr;
int size;
int top;

// Constructor
Stack(int size) 
{
    arr = new int[size];
    top = -1;
    this->size = size;

}

// Destrcutor 

~Stack() 
{
    delete[] arr;
}
bool isFull() 
{
    return (top == size - 1);
}
bool isEmpty()
{
    return (top == -1);
}
void push(int element) 
{
    if (isFull())
    {
        cout << "Stack overflow!!" << endl;
        return;
    }
    arr[++top] = element;

    cout << element << " Pushed Onto the stack!!" << endl;
}
void pop()
{
    if (isEmpty())
    {
        cout << "Stack UnderFlow!!!" << endl;
        return;
    }
    
    cout << arr[top--] << " Popped Out of the Stack" << endl;

}
int peek() 
{
    if (isEmpty())
    {
        cout << "Stack is empty!!" << endl;
        return -1;
    }
    return arr[top];
}
void display()
{
    if (isEmpty())
    {
        cout << "Stack is Empty!!" << endl;
        return;
    }
    
    cout << "Elements are: " << endl;
    for (int i = top; i >= 0; i--)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
};
int main() 
{
int stackSize;
    cout << "Enter the size of the stack: ";
    cin >> stackSize;

    Stack stack(stackSize);

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.display();

    cout << "Top element: " << stack.peek() << "\n";

    stack.pop();

    stack.display();
}