#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

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

// Inserting a Node after a given element
void insertAfter(Node *&tail, int element, int data)
{
    if (tail == NULL)
    {
        // If list is empty, create a new node and make it the tail
        Node *temp = new Node(data);
        tail = temp;
        temp->next = temp;
        return;
    }

    Node *currentent = tail;
    do
    {
        if (currentent->data == element)
        {
            Node *temp = new Node(data);
            temp->next = currentent->next;
            currentent->next = temp;
            return;
        }
        currentent = currentent->next;
    } while (currentent != tail);

    cout << "Element " << element << " not found!" << endl;
}

// Inserting a Node before a given element
void insertBefore(Node *&tail, int element, int data)
{
    if (tail == NULL)
    {
        // If list is empty, create a new node and make it the tail
        Node *temp = new Node(data);
        tail = temp;
        temp->next = temp;
        return;
    }

    Node *currentent = tail;
    do
    {
        if (currentent->next->data == element)
        {
            Node *temp = new Node(data);
            temp->next = currentent->next;
            currentent->next = temp;
            // If the element is the tail node, update the tail to the new node
            return;
        }
        currentent = currentent->next;
    } while (currentent != tail);

    cout << "Element " << element << " not found!" << endl;
}

// Printing the circular linked list
void printList(Node *&tail)
{
    if (tail == NULL)
    {
        cout << "The list is empty." << endl;
        return;
    }

    Node *temp = tail -> next; // Start from the head of the list
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail->next); // Stop when we come back to the head
    cout << endl;
}

int main()
{
    Node *tail = NULL;

    // Inserting some nodes

    insertAfter(tail, 5, 4); // 3 is inserted after 5, but the list is empty, so 3 becomes the tail
    printList(tail);

    insertBefore(tail, 4, 3);
    printList(tail);

    insertAfter(tail, 4, 9); // 3 is inserted after 5, but the list is empty, so 3 becomes the tail
    printList(tail);

    insertBefore(tail, 9, 5);
    printList(tail);
    return 0;
}
