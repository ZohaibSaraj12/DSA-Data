#include <iostream>
using namespace std;
class Node {

public:
int data;
Node* next;
Node(int data)
{
    this->data = data;
    this->next = NULL;
}
~Node()
{
    this->next = NULL;
}
};
void insertAtHead(Node*& head, Node*& tail, int data)
{
    Node* newNode = new Node(data);

    if (head == NULL && tail == NULL)
    {
        head = tail = newNode;
        return;
    }

    newNode->next = head;
    head = newNode;
    

}
void insertAtTail(Node*& head, Node*& tail, int data)
{
    Node* newNode = new Node(data);
    if (head == NULL && tail == NULL)
    {
        tail = head = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;
}
void insertAtPosition(Node*& head, Node*& tail, int data, int position)
{
    Node* temp = head;
    if (position <= 1)
    {
        insertAtHead(head, tail, data);
        return;
    }

    int count = 1;
    while (count < position - 1 && temp != NULL)
    {
        temp = temp->next;
        count++;
    }

    if (temp->next == NULL)
    {
        insertAtTail(head, tail, data);
        return;
    }

    Node* newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;

     
}
void deleteNode(Node*& head, int data)
{
    if (head == NULL)
    {
        cout << "No Node available in the list go forward and insert first!!!!" << endl;
        return;
    }

    if (data == head->data)
    {
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else 
    {
        Node* previous = NULL;
        Node* current = head;

        while (current != NULL)
        {
            if (current->data == data)
            {
                previous->next = current->next;
                current->next = NULL;
                delete current;
                return;
            }
            previous = current;
            current = current->next;
        }
    }

}
void deleteNodeByPosition(Node*& head, Node*& tail, int position)
{
    Node* previous = NULL;
    Node* current = head;
    if (position < 1)
    {
        cout << "No node availabe" << endl;
        return;
    }
    if (position == 1)
    {
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }
    int count = 1;
    while (count < position && current != NULL)
    {
        previous = current;
        current = current->next;
        
        count++;
    }
    
    if(current != NULL) 
    {
    previous->next = current->next;
    current->next = NULL;
    delete current;
    }
}

void print(Node*& head)
{
    Node *temp = head;
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);
    insertAtTail(head, tail, 40);
    insertAtTail(head, tail, 50);
    insertAtTail(head, tail, 60);
    insertAtTail(head, tail, 70);
    insertAtPosition(head, tail, 90, 4);
    deleteNodeByPosition(head, tail, 7);
    print(head);
    

    return 0;
}
