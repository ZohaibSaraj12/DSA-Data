#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int data) 
    {
        this->next = NULL;
        this->data = data;
    }
    ~Node()
    {
        this->next = NULL;
    }
};

class Stack
{
    Node *top;

public:
    Stack()
    {
        top = NULL;
    }

    bool isEmpty()
    {
        return (top == NULL);
    }

    void push(int element)
    {
        Node *temp = new Node(element);
        temp->next = top;
        top = temp;
        cout << element << " Pushed onto the stack!!" << endl;
    }
    void pop()
    {
        if (isEmpty())
        {
            cout << "stack is empty!!" << endl;
        }

        Node* currentent = top;
        top  = top->next;
        currentent->next = NULL;
        cout << currentent->data << " popped from stack.\n";
        delete currentent;
        
    }
    int peek()
    {  
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return -1;
        }
        return top->data;
    }
    
    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty.\n";
            return;
        }
        Node *currentent = top;
        cout << "Stack elements: ";
        while (currentent != NULL)
        {
            cout << currentent->data << " ";
            currentent = currentent->next;
        }
        cout << "\n";
    }
};
int main()
{
    Stack s;
    s.push(30);
    s.push(40);
    s.push(50);
    cout << s.peek() << endl;
    s.display();

    s.pop();
    s.display();
}