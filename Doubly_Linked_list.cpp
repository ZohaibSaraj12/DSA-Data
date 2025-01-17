// implementing Doubly Linked List

#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *previous;

    // parameterized Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->previous = NULL;
    }
    ~Node()
    {
        this->next = NULL;
        this->previous = NULL;
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
    head->previous = temp;
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
    temp->previous = tail;
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
    nodeToinsert->previous = temp;
    temp->next = nodeToinsert;
    temp->next->previous = nodeToinsert;

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
        head -> previous = NULL;
        if (head == NULL)
        {
            head = tail = NULL;
        }
        delete temp;
        return;
    }
    else
    {
        Node *previous = NULL;
        Node *current = head;

        int count = 1;

        while (count < position && current != NULL)
        {
            previous = current;
            current = current->next;
            count++;
        }
        if (current == NULL)
        {
            cout << "Deleting Beyond The list" << endl;
            return;
        }
        if (current != NULL)
        {
            previous->next = current->next;
            if (current->next != NULL)
            {
                current->next->previous = previous; 
            }
            current->previous = NULL;
            current->next = NULL;
            delete current;
        }
        if (current == tail)
        {
            tail = previous;
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
    printList(head);
    insertAtHead(head, tail, 30);
    printList(head);
    insertAtHead(head, tail, 40);
    printList(head);
    insertAtTail(head, tail, 50);
    printList(head);
    insertAtPosition(head, tail, 30, 3);
    printList(head);
    deleteNode(head, tail, 5);
    printList(head);
}
