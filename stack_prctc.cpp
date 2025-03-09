#include <iostream>
#include <vector>
using namespace std;

class Stack {
vector<int>arr;
int top;
public:
Stack() : arr(10, 0)
{
    top = -1;
}

bool isFull()
{
    return (top == arr.size() - 1);
}
bool isEmpty()
{
    return (top == -1);
}
void push(int data)
{
    if (isFull())
    {
        cout << "Stack Full" << endl;
        return;
    }
    
    top++;
    arr[top] = data;
    cout << "Data " << data << " inserted" << endl;
}
void pop()
{
    if (isEmpty())
    {
        cout << "Stack UnderFlow" << endl;
        return;
    }

    cout << "data deleted " << arr[top] << endl;
    top--;
}
void display()
{
    if (isEmpty())
    {
        cout << "stack is empty" << endl;
        return;
    }
    for (int i = top; i >= 0; i--)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
};
int main()
{
    Stack s;
    s.push(20);
    s.push(30);
    s.push(40);
    s.display();
    s.pop();
    s.display();
}