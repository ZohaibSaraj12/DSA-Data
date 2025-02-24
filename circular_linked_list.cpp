#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = NULL;
    }

    ~Node() {
        next = NULL;
    }
};

void insertNode(Node*& tail, int element, int d) {
    if (tail == NULL) 
    {
        Node* newNode = new Node(d);
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

void deleteNode(Node*& tail, int value) {
    if (tail == NULL) {
        cout << "List is empty, please check again" << endl;
        return;
    }

    Node* previous = tail;
    Node* current = previous->next;

    while (current->data != value) {
        previous = current;
        current = current->next;
    }

    previous->next = current->next;

    if (current == previous) {
        tail = NULL;
    }
    if (tail == current) {
        tail = previous;
    }

    current->next = NULL;
    delete current;
}
void display(Node* tail) {
    if (tail == NULL) {
        cout << "List is empty!\n";
        return;
    }
    Node* temp = tail->next;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != tail->next);
    cout << "(Back to head)\n";
}

int main() {
    Node* tail = NULL;

    insertNode(tail, 0, 10);
    insertNode(tail, 10, 20);
    insertNode(tail, 20, 30);
    insertNode(tail, 10, 15);

    cout << "Circular Linked List after insertions:\n";
    display(tail);

    deleteNode(tail, 20);
    cout << "Circular Linked List after deleting 20:\n";
    display(tail);

    deleteNode(tail, 10);
    cout << "Circular Linked List after deleting 10:\n";
    display(tail);

    return 0;
}
