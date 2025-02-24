// implementing Doubly Linked List

#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *previousious;

    // parameterized Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->previousious = NULL;
    }
    ~Node()
    {
        this->next = NULL;
        this->previousious = NULL;
    }
};

// inserting at the head in a list

void insertAtHead(Node *&head, Node *&tail, int data)
{
    Node *temp = new Node(data);

    if (head == NULL && tail == NULL)
    {
        head = tail = temp;
        return;
    }
    temp->next = head;
    head->previousious = temp;
    head = temp;
}
// inserting at tail
void insertAtTail(Node *&head, Node *&tail, int data)
{
    Node *temp = new Node(data);

    if (head == NULL && tail == NULL)
    {
        head = tail = temp;
        return;
    }
    tail->next = temp;
    temp->previousious = tail;
    tail = temp;
}

// inserting at specific or desired position
void insertAtPosition(Node *&head, Node *&tail, int data, int position)
{
    if (position == 1)
    {
        insertAtHead(head, tail, data);
        return;
    }
    if (position <= 0)
    {
        cout << "Invalid Position!!!" << endl;
        return;
    }
    int count = 1;
    Node *temp = head;

    while (count < position - 1 && temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    // if insertion is beyond the list, insert At tail, instead of that place.
    if (temp == NULL)
    {
        insertAtTail(head, tail, data);
        return;
    }
    Node *nodeToinsert = new Node(data);
    nodeToinsert->next = temp->next;
    nodeToinsert->previousious = temp;
    temp->next = nodeToinsert;
    temp->next->previousious = nodeToinsert;

    if (nodeToinsert->next == NULL)
    {
        tail = nodeToinsert;
    }
}

// Deleting the elements in the list

void deleteNode(Node *&head, Node *&tail, int position)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    if (position <= 0)
    {
        cout << "Invalid Position" << endl;
        return;
    }
    if (position == 1)
    {
        Node *temp = head;
        head = temp->next;
        head -> previousious = NULL;
        if (head == NULL)
        {
            head = tail = NULL;
        }
        delete temp;
        return;
    }
    else
    {
        Node *previousious = NULL;
        Node *currentent = head;

        int count = 1;

        while (count < position && currentent != NULL)
        {
            previousious = currentent;
            currentent = currentent->next;
            count++;
        }
        if (currentent == NULL)
        {
            cout << "Deleting Beyond The list" << endl;
            return;
        }
        if (currentent != NULL)
        {
            previousious->next = currentent->next;
            if (currentent->next != NULL)
            {
                currentent->next->previousious = previousious; 
            }
            currentent->previousious = NULL;
            currentent->next = NULL;
            delete currentent;
        }
        if (currentent == tail)
        {
            tail = previousious;
        }
    }
}



// printing the list

void printList(Node *&head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
//main function of Linked List

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 40);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 50);
    insertAtTail(head, tail, 60);
    insertAtTail(head, tail, 80);
    insertAtTail(head, tail, 90);
    insertAtPosition(head, tail, 300, 8);
    deleteNode(head, tail, 8);
    printList(head);
}
