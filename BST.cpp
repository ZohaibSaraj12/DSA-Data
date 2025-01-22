#include <iostream>
#include <queue>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};
Node*  insertIntoBST(Node*& root, int d)
{
    if (root == NULL)
    {
        root = new Node(d);
        cout << "Root NULL haye and " << root->data << endl;
        return root;
        
    }
    if (root->data == d)
    {
        cout << "Sharam Kar same element teko pata BST chy koni hona Zalum" << endl;
        return root;
    }
    
    if (d > root->data)
    {
        cout << "Root ka right subtree" << endl;
        root->right = insertIntoBST(root->right, d);

    }
    else
    {
        cout << "root ka left subtree" << endl;
        root->left = insertIntoBST(root->left, d);
        
    }
    cout << "ab ham return kar rahy hain root dekh lena" << endl;
    return root;
    
}
void takeInput(Node*& root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
       root = insertIntoBST(root, data);
       cout << "root ka data haye jo return ho k aya haye : " << root->data << endl;
        cin >> data;
    }
}
void levelOrderTraversal(Node *&root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
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
            cout << temp->data << " ";

            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
int main()
{
    Node* root = NULL;

    takeInput(root);
    levelOrderTraversal(root);
}