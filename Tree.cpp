#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// Binary Tree Node
class Node {
    public:
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(NULL), right(NULL) {}
};
void levelOrderTraversal(Node* root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node* temp = q.front(); 
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else 
        {
            cout << temp -> data << " ";

            if (temp->right)
            {
                q.push(temp->right);
            }
            if (temp->left)
            {
                q.push(temp->left);
            } 

        }
    }

}

// Reverse Level Order Traversal with NULL separator and newline
void reverseLevelOrder(Node* root) {
    if (!root) return;

    queue<Node*> q;
    stack<Node*> s;

    // Start with the root node
    q.push(root);
    q.push(NULL); // NULL as level separator

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        if (curr == NULL) {
            // Add a NULL to stack to indicate a level break
            s.push(NULL);

            // If the queue is not empty, push another NULL for the next level
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            // Push the current node into the stack
            s.push(curr);

            // Enqueue right child first, then left child
            if (curr->right) q.push(curr->right);
            if (curr->left) q.push(curr->left);
        }
    }

    // Print the reverse level order from the stack
    while (!s.empty()) {
        
        
        if (s.top() == NULL) {
            cout << endl; // Newline for a level break
        } else {
            cout << s.top()->data << " ";
        }
        s.pop();
    }
}

int main() {
    // Constructing the binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Perform Reverse Level Order Traversal
    cout << "Reverse Level Order Traversal with NULL separator:" << endl;
    reverseLevelOrder(root);

    cout << endl << endl << endl << endl;
    cout << "Level Order traversal" << endl;

    levelOrderTraversal(root);

    return 0;
}
