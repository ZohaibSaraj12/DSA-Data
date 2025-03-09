#include <iostream>
#include <queue>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this->data = data;
        this->right = NULL;
        this->left = NULL;
    }
    

};
void traversalOfTree(Node*& root)
{
    if (root == NULL)
    {
        return;
    }
    
    cout << root->data << " ";
    traversalOfTree(root->left);
    traversalOfTree(root->right);

}
void levelOrderTraversal(Node*& root)
{
    if (root == NULL)
    {
        return;
    }

    queue<Node*> q;
    q.push(root);
    while (!q.empty())
    {
        Node* temp = q.front();
        cout << temp->data << " ";
        q.pop();
        if (temp->left)
        q.push(temp->left);
        if (temp->right)
        q.push(temp->right);
    }

}
int main()
{
    Node* root = new Node(10);
    root->left = new Node(11);
    root->left->left = new Node(12);
    root->left->right = new Node(13);
    root->right = new Node(14);
    root->right->left = new Node(15);
    root->right->right = new Node(16);


    levelOrderTraversal(root);
    

}