#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int d) {
        data = d;
        next = NULL;
        prev = NULL;
    }

    ~Node() {
        next = NULL;
        prev = NULL;
    }
};

void insertNode(Node*& tail, int element, int d) {
    if (tail == NULL) {
        Node* newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    } else {
        Node* curr = tail;
        while (curr->data != element) {
            curr = curr->next;
        }
        Node* temp = new Node(d);
        temp->next = curr->next;
        temp->prev = curr;
        curr->next->prev = temp;
        curr->next = temp;
    }
}

void deleteNode(Node*& tail, int value) {
    if (tail == NULL) {
        cout << "List is empty, please check again" << endl;
        return;
    }

    Node* curr = tail;
    while (curr->data != value) {
        curr = curr->next;
    }

    if (curr->next == curr) {  // Single node case
        tail = NULL;
    } else {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        if (curr == tail) { 
            tail = curr->prev;  
        }
    }

    curr->next = NULL;
    curr->prev = NULL;
    delete curr;
}

void display(Node* tail) {
    if (tail == NULL) {
        cout << "List is empty!\n";
        return;
    }
    Node* temp = tail->next;
    do {
        cout << temp->data << " <-> ";
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

    cout << "Doubly Circular Linked List after insertions:\n";
    display(tail);

    deleteNode(tail, 20);
    cout << "Doubly Circular Linked List after deleting 20:\n";
    display(tail);

    deleteNode(tail, 10);
    cout << "Doubly Circular Linked List after deleting 10:\n";
    display(tail);

    return 0;
}
