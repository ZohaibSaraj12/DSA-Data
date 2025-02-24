#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    // parameterized Constructor
    Node(int data)
    {
        this -> data = data;
        this -> next = NULL;
    }
    ~Node()
    {
        if (this -> next != NULL)
        {
            delete next;
            this -> next = NULL;
        }
    }
};

// insertion at head in the List
void insertAtHead(Node *&head, Node *&tail, int data)
{
    Node *temp = new Node(data);

    if (head == NULL)
    {
        head = tail = temp;
        return;
    }
    temp -> next = head;
    head = temp;
}

// insertion at tail in the list
void insertAtTail(Node *&head, Node *&tail, int data)
{
    Node *temp = new Node(data);

    if (head == NULL)
    {
        head = tail = temp;
        return;
    }

    tail -> next = temp;
    tail = temp;
}
// inserting at specific position
void insertAtPosition(Node *&head, Node *&tail, int data, int position)
{
    Node *temp = head;

    // insert at head or invalid position before head
    if (position <= 1)
    {
        insertAtHead(head, tail, data);
        return;
    }

    int count = 1;
    while (count < position - 1 && temp != NULL)
    {
        temp = temp -> next;
        count++;
    }
    //position beyond list length

    if (temp == NULL)
    {
        insertAtTail(head, tail, data);
        return;
    }

    Node *nodeToinsert = new Node(data);
    nodeToinsert -> next = temp -> next;
    temp -> next = nodeToinsert;
    
    // if node which is to be inserted, 
    // if it is pointing to NULL it means we have to update tail also

    if (nodeToinsert -> next == NULL)
    {
        tail = nodeToinsert;
    }
}
// Printing the List
void printList(Node *&head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}
// deleting the node in list whether on 1st last and middle
void deleteNode(int position, Node *&head)
{
    if (position == 1)
    {
        Node *previousious = head;
        head = head -> next;
        previousious -> next = NULL;

        delete previousious;
    }

    else
    {
        Node *currentent = head;
        Node *previousious = NULL;

        int count = 1;

        while (count < position && currentent != NULL)
        {
            previousious = currentent;
            currentent = currentent -> next;
            count++;
        }

        if (currentent != NULL)
        {
            previousious -> next = currentent -> next;
            currentent -> next = NULL;
            delete currentent;
        }
    }
}
// main function
int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    insertAtHead(head, tail, 20);
    printList(head);
    insertAtTail(head, tail, 30);
    printList(head);
    insertAtPosition(head, tail, 23, 2);
    printList(head);
    insertAtTail(head, tail, 3000);
    printList(head);
    deleteNode(4, head);
    printList(head);
    return 0;
}