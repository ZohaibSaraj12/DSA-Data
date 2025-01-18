#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        data = d;
        left = right = NULL;
    }
};

// Function to insert a node into BST
Node* insertIntoBST(Node* root, int d) {
    if (root == NULL) {
        root = new Node(d);
        return root;
    }
    if (d > root->data) {
        root->right = insertIntoBST(root->right, d);
    } else {
        root->left = insertIntoBST(root->left, d);
    }
    return root;
}

// Function to take input for the BST
void takeInput(Node*& root) {
    int data;
    cin >> data;

    while (data != -1) {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

// Function to search for a value in the BST
bool searchInBST(Node* root, int d) {
    if (root == NULL) {
        return false;
    }
    if (root->data == d) {
        return true;
    }
    if (root->data > d) {
        return searchInBST(root->left, d);
    } else {
        return searchInBST(root->right, d);
    }
}

// Function for Level Order Traversal
void levelOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);  // Marker for new level

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        if (temp == NULL) {
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);  // Push marker for next level
            }
        } else {
            cout << temp->data << " ";
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}

int main() {
    Node* root = NULL;

    takeInput(root);
    levelOrderTraversal(root);

    bool x = searchInBST(root, 1);  // Searching for 1, you can change this to any value

    if (x) {
        cout << "Found" << endl;
    } else {
        cout << "Not found" << endl;
    }

    return 0;
}
