#include <iostream>
using namespace std;
class Node {
    public:
    int data;
    Node* next;
    Node* previousious;
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
void insertAtHead(Node*& head, Node*& tail, int data)
{
    Node* newNode = new Node(data);
    if (head == NULL || tail == NULL)
    {
        head = tail = newNode;
        return;
    }

    newNode->next = head;
    head->previousious = newNode;
    head = newNode;

}
void insertAtTail(Node*& head, Node*& tail, int data)
{
    Node* newNode = new Node(data);
    if (tail == NULL || head == NULL)
    {
        tail = head = newNode;
        return;
    }
    newNode->previousious = tail;
    tail->next = newNode;
    tail = newNode;
}
void insertAtPosition(Node*& head, Node*& tail, int data, int position)
{
    if (position <= 1)  // Insert at head
    {
        insertAtHead(head, tail, data);
        return;
    }

    Node* temp = head;
    int count = 1;

    while (temp != NULL && count < position - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp == NULL)  // Position is out of range
    {
        cout << "Position out of range!" << endl;
        return;
    }

    Node* newNode = new Node(data);

    // Insert at the last position
    if (temp->next == NULL)
    {
        insertAtTail(head, tail, data);
        return;
    }

    // Insert in the middle of the list
    newNode->next = temp->next;
    newNode->previousious = temp;
    temp->next->previousious = newNode;
    temp->next = newNode;
}

void deleteNode(Node*& head, Node*& tail, int data)
{
    if (head == NULL || tail == NULL)
        return; // previousent null pointer dereference

    if (head->data == data)
    {
        Node* temp = head;
        head = head->next;

        if (head != NULL) // Ensure next node exists before modifying previousious
            head->previousious = NULL;

        delete temp;
        return;
    }
    if (tail->data == data)
    {
        Node* temp = tail;
        tail = tail->previousious;
        if (tail != NULL)
        {
            tail->next = NULL;
        }
        delete temp;
        return;
    }
    
    else 
    {
        Node* currentent = head;
        
        while (currentent != NULL)
        {
            if (currentent->data == data)
            {
                if (currentent->next != NULL)  // Check if not the last node
                    currentent->next->previousious = currentent->previousious;

                if (currentent->previousious != NULL)  // Check if not the first node
                    currentent->previousious->next = currentent->next;

                delete currentent;
                return;
            }
             
            currentent = currentent->next;
        }
        
    }
}
void deleteNodeByPosition(Node *&head, Node *&tail, int position)
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

void printList(Node*& head)
{
    Node* temp = head;
    while (temp != NULL)
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
    insertAtHead(head, tail, 40);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 50);
    insertAtTail(head, tail, 60);
    insertAtTail(head, tail, 80);
    insertAtTail(head, tail, 90);
    insertAtPosition(head, tail, 300, 8);
    deleteNode(head, tail, 300);
   
    

    printList(head);


    
}