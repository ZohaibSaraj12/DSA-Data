#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

// Function to insert at a specific position
void insertAtPosition(Node*& tail, int position, int val) {
    Node* newNode = new Node(val);

    if (tail == nullptr) {
        // Empty list
        tail = newNode;
        tail->next = tail;
        tail->prev = tail;
        return;
    }

    Node* current = tail->next; // Start from head
    if (position == 1) {
        // Insertion at head
        newNode->next = tail->next;
        newNode->prev = tail;
        tail->next->prev = newNode;
        tail->next = newNode;
        return;
    }

    int count = 1;
    while (count < position - 1 && current->next != tail->next) {
        current = current->next;
        count++;
    }

    newNode->next = current->next;
    newNode->prev = current;
    current->next->prev = newNode;
    current->next = newNode;

    if (current == tail) {
        tail = newNode; // Update tail if inserted at the end
    }
}

// Function to insert before a given data
void insertBefore(Node*& tail, int data, int val) {
    if (tail == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* current = tail->next; // Start from head
    do {
        if (current->data == data) {
            Node* newNode = new Node(val);
            newNode->next = current;
            newNode->prev = current->prev;
            current->prev->next = newNode;
            current->prev = newNode;

            if (current == tail->next) {
                // Update head if inserted before the head
                tail->next = newNode;
            }
            return;
        }
        current = current->next;
    } while (current != tail->next);

    cout << "Element " << data << " not found in the list." << endl;
}

// Function to insert after a given data
void insertAfter(Node*& tail, int data, int val) {
    if (tail == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* current = tail->next; // Start from head
    do {
        if (current->data == data) {
            Node* newNode = new Node(val);
            newNode->next = current->next;
            newNode->prev = current;
            current->next->prev = newNode;
            current->next = newNode;

            if (current == tail) {
                tail = newNode; // Update tail if inserted after the tail
            }
            return;
        }
        current = current->next;
    } while (current != tail->next);

    cout << "Element " << data << " not found in the list." << endl;
}

// Function to delete a node by data
void deleteByData(Node*& tail, int data) {
    if (tail == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* current = tail->next;
    do {
        if (current->data == data) {
            if (current == tail->next && current == tail) {
                // Only one node in the list
                delete current;
                tail = nullptr;
                return;
            }

            if (current == tail->next) {
                // Deleting head
                tail->next = current->next;
                current->next->prev = tail;
            } else if (current == tail) {
                // Deleting tail
                tail = current->prev;
                tail->next = current->next;
                current->next->prev = tail;
            } else {
                // Deleting any other node
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }

            delete current;
            return;
        }
        current = current->next;
    } while (current != tail->next);

    cout << "Element " << data << " not found in the list." << endl;
}

// Function to delete a node by position
void deleteByPosition(Node*& tail, int position) {
    if (tail == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* current = tail->next;
    if (position == 1) {
        // Deleting head
        if (current == tail) {
            delete current;
            tail = nullptr;
        } else {
            tail->next = current->next;
            current->next->prev = tail;
            delete current;
        }
        return;
    }

    int count = 1;
    while (count < position && current->next != tail->next) {
        current = current->next;
        count++;
    }

    if (count == position) {
        if (current == tail) {
            // Deleting tail
            tail = current->prev;
            tail->next = current->next;
            current->next->prev = tail;
        } else {
            // Deleting any other node
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }
        delete current;
    } else {
        cout << "Position out of range." << endl;
    }
}

// Function to print the list
void printList(Node* tail) {
    if (tail == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* current = tail->next;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != tail->next);
    cout << endl;
}

// Main function
int main() {
    Node* tail = nullptr;

    insertAtPosition(tail, 1, 10); // Insert at head
    printList(tail);

    insertAtPosition(tail, 2, 20); // Insert at position 2
    printList(tail);

    insertBefore(tail, 10, 5); // Insert before 10
    printList(tail);

    insertAfter(tail, 20, 30); // Insert after 20
    printList(tail);

    deleteByData(tail, 10); // Delete 10
    printList(tail);

    deleteByPosition(tail, 2); // Delete position 2
    printList(tail);

    return 0;
}
