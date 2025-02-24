#include <iostream>
using namespace std;
class Node {
    public:
int data;
Node* next;

Node(int data)
{
    this->data = data;
    next = NULL;
}
~Node()
{
    this->next = NULL;
}
};

void insertNode(Node*& tail, int element, int data)
{
    if (tail == NULL)
    {
        Node* newNode = new Node(data);
        tail = newNode;
        newNode->next = newNode;
    }
    else 
    {
        Node* current = tail;
        while (current->data != element)
        {
            current = current->next;
        }
        Node* temp = new Node(d);
        temp->next = current->next;
        current->next = temp;
    }
}
int main()
{

}