// Singly Linked List Implementation
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    // Parameterized Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node() 
    {
        if (this->next != NULL) 
        {
        this->next = NULL;
        delete next;
        }
    }
};
// Inserting at Head in a List
void insertAtHead(Node *&head, Node *&tail, int data)
{

    Node *temp = new Node(data);

    if (head == NULL || tail == NULL)
    {
        head = tail = temp;
        return;
    }

    temp->next = head;
    head = temp;
}

// Insert At Tail in the List

void insertAtTail(Node *&head, Node *&tail, int data)
{
    Node *temp = new Node(data);

    if (tail == NULL || head == NULL)
    {
        head = tail = temp;
        return;
    }

    tail->next = temp;
    tail = temp;
}

// Insert at specific position whether at first last or middle

void insertAtPosition(Node *&head, Node *&tail, int data, int position)
{
    if (position <= 1)
    {
        insertAtHead(head, tail, data);
        return;
    }
    
    Node *temp = head;
    int count = 1;

    while (count < position - 1 && temp != NULL)
    {
        temp = temp->next;
        count++;
    }

    if (temp == NULL)
    {
        insertAtTail(head, tail, data);
        return;
    }

    Node *nodeToinsert = new Node(data);
    nodeToinsert->next = temp->next;
    temp->next = nodeToinsert;
    

    if (nodeToinsert->next == NULL)
    {
        tail = nodeToinsert;
    }
}

// Deleting at specific position in List with position
void deleteNode(Node *&head, Node* &tail, int position)
{
    if (head == NULL)
    {
        cout << "List is empty";
        return;
    }
    if (position <= 0)
    {
        cout << "Invalid position\n";
        return;
    }
    if (position == 1)
    {
        Node *previous = head;

        head = head->next;

        if (head != NULL)
        {
        previous->next = NULL;
        }
        
        else {
        head = tail = NULL; // If the list becomes empty
    }
        delete previous;
        
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
         cout << "deleting beyond list" << endl;
         return;
        }
        if (current != NULL) 
        {
        previous->next = current->next;
        current->next = NULL;
        delete current;
        
        }
    }
}

// delete node by value

void deleteNodeByValue(Node *&head, int data)
{
    if (head == NULL)
    {
        cout << "List is empty";
        return;
    }
    
    if (data == head->data)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        
    }

    else
    {
        Node *previous = NULL;
        Node *current = head;
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
    cout << "Value " << data << " not found in the list\n";
    
}
// Printing the List

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
// main function for list
int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    insertAtHead(head, tail, 20);
    printList(head);
    insertAtHead(head, tail, 30);
    printList(head);
    insertAtTail(head, tail, 35);
    printList(head);
    deleteNode(head, tail, 100);
    printList(head);
}