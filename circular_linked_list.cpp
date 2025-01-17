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


void insertAfter(Node *&tail, int element, int data)
{
    if (tail == NULL)
    {
        
        Node *temp = new Node(data);
        tail = temp;
        temp->next = temp;
        return;
    }

    Node *current = tail;
    do
    {
        if (current->data == element)
        {
            Node *temp = new Node(data);
            temp->next = current->next;
            current->next = temp;
            return;
        }
        current = current->next;
    } while (current != tail);

    cout << "Element " << element << " not found!" << endl;
}


void insertBefore(Node *&tail, int element, int data)
{
    if (tail == NULL)
    {
        
        Node *temp = new Node(data);
        tail = temp;
        temp->next = temp;
        return;
    }

    Node *current = tail;
    do
    {
        if (current->next->data == element)
        {
            Node *temp = new Node(data);
            temp->next = current->next;
            current->next = temp;
            
            return;
        }
        current = current->next;
    } while (current != tail);

    cout << "Element " << element << " not found!" << endl;
}


void printList(Node *&tail)
{
    if (tail == NULL)
    {
        cout << "The list is empty." << endl;
        return;
    }

    Node *temp = tail -> next; 
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail->next); 
    cout << endl;
}
// insert at position in the list 


// Inserting a node at a specific position
void insertAtPosition(Node* &tail, int position, int data) {
    // Case 1: If the list is empty
    if (tail == nullptr) {
        Node* temp = new Node(data);
        tail = temp;
        temp->next = temp;  // Tail points to itself (circular)
        return;
    }

    // Case 2: Insert at the head (position = 0)
    if (position == 1) {
        Node* temp = new Node(data);
        temp->next = tail->next; // Point to the current head
        tail->next = temp;       // Update tail's next to the new node
        return;
    }

    // Case 3: Insert at any other position
    Node* current = tail->next; // Start from head (tail's next)
    int count = 1;

    // Traverse to the node before the desired position
    while (count < position - 1 && current != tail) {
        current = current->next;
        count++;
    }

    // Now insert the node after `current`
    Node* temp = new Node(data);
    temp->next = current->next;  // Point to the next node of `current`
    current->next = temp;        // Insert `temp` after `current`

    // Special case: If inserted node is at the tail
    if (current == tail) {
        tail = temp; // Update the tail pointer
    }
}
// Function to delete a node by position
void deleteByPosition(Node*& tail, int position) {
    // Case 1: List is empty
    if (tail == NULL) {
        cout << "List is empty. Cannot delete." << endl;
        return;
    }

    // Case 2: Single node in the list
    if (tail->next == tail) {
        if (position == 0) { // If the position is 0, delete the only node
            delete tail;
            tail = NULL;
        } else {
            cout << "Invalid position." << endl;
        }
        return;
    }

    // Case 3: Deleting the head (position = 1)
    if (position == 1) {
        Node* head = tail->next;
        tail->next = head->next; // Update tail to skip the current head
        delete head;
        return;
    }

    // Case 4: Deleting any other position
    Node* current = tail->next; // Start from head
    int count = 1;

    // Traverse to the node just before the position
    while (count < position - 1 && current->next != tail->next) {
        current = current->next;
        count++;
    }

    // If position is invalid
    if (current->next == tail->next) {
        cout << "Invalid position." << endl;
        return;
    }

    // Delete the node at the position
    Node* temp = current->next;
    current->next = temp->next;
    if (temp == tail) { // If the node is the tail, update the tail
        tail = current;
    }
    delete temp;
}

// Function to delete a node by data
void deleteByData(Node*& tail, int key) {
    // Case 1: List is empty
    if (tail == NULL) {
        cout << "List is empty. Cannot delete." << endl;
        return;
    }

    // Case 2: Single node in the list
    if (tail->next == tail) {
        if (tail->data == key) { // If the key matches the single node
            delete tail;
            tail = NULL;
        } else {
            cout << "Element not found." << endl;
        }
        return;
    }

    // Case 3: Deleting the head node
    Node* current = tail;
    while (current->next != tail) {
        if (current->next->data == key) {
            Node* temp = current->next;
            current->next = temp->next;
            if (temp == tail) { // If the node is the tail, update the tail
                tail = current;
            }
            delete temp;
            return;
        }
        current = current->next;
    }

    // Case 4: Key not found
    cout << "Element not found." << endl;
}




int main()
{
    Node *tail = NULL;

   

    insertAfter(tail, 5, 4); 
    printList(tail);

    insertBefore(tail, 4, 3);
    printList(tail);

    insertAfter(tail, 4, 9); 
    printList(tail);

    insertBefore(tail, 9, 5);
    printList(tail);


    insertAtPosition(tail, 5, 30);
    printList(tail);
    deleteByPosition(tail, 2);
    printList(tail);
    return 0;
}
