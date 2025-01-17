#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    // Destructor
    ~Node()
    {
        if (this->next != NULL)
        {
            // next of this node will be NULL
            this->next = NULL;
            delete next;
        }
    }
};

// Insert at Head
void insertAtHead(Node *&head, Node *&tail, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;

    // If the list was empty, update the tail
    if (tail == NULL)
    {
        tail = temp;
        return;
    }
}

// Insert at Tail
void insertAtTail(Node *&head, Node *&tail, int data)
{
    Node *temp = new Node(data);
    if (tail == NULL)
    { // Empty list
        head = tail = temp;
        return;
    }
    tail->next = temp;
    tail = temp;
}

// Insert at Position
void insertAtPosition(Node *&head, Node *&tail, int data, int position)
{
    if (position <= 1)
    { // Handle invalid or first position
        insertAtHead(head, tail, data);
        return;
    }

    Node *temp = head;
    int count = 1;

    // Traverse to the position before insertion point
    while (count < position - 1 && temp != NULL)
    {
        temp = temp->next;
        count++;
    }

    // If position is beyond the list length, insert at tail
    if (temp == NULL)
    {
        insertAtTail(head, tail, data);
        return;
    }

    // Insert in the middle
    Node *nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;

    // If inserting at the last position, update tail
    if (nodeToInsert->next == NULL)
    {
        tail = nodeToInsert;
    }
}

// Print the Linked List
void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
// deleting the node in list whether on 1st last and middle
void deleteNode(int position, Node *&head)
{

    if (head == NULL) {
        cout << "List is empty";
        return;
    }
    if (position == 1)
    {
        Node *previous = head;

        head = head->next;
        delete previous;
        previous->next = NULL;
    }

    else
    {
        Node *current = head;
        Node *previous = NULL;

        int count = 1;

        while (count < position && current != NULL)
        {
            previous = current;
            current = current -> next;
            count++;
        }
        if (current != NULL) {
            previous -> next = current -> next;
            delete current;
            current -> next = NULL;
        }
    }
}
// Main Function
int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    // Test Cases
    insertAtHead(head, tail, 10); // Insert at head
    printList(head);

    insertAtTail(head, tail, 20); // Insert at tail
    printList(head);

    insertAtHead(head, tail, 5); // Insert at head
    printList(head);

    insertAtPosition(head, tail, 15, 3); // Insert at position 3
    printList(head);

    insertAtPosition(head, tail, 25, 7); // Insert at tail (out of bounds)
    printList(head);

    insertAtPosition(head, tail, 1, 0); // Insert at head (invalid position)
    printList(head);
    


    deleteNode(3, head);
    printList(head);
    return 0;
}
