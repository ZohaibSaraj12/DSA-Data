#include <iostream>
#include <queue>
using namespace std;

class Node {
    public:
        int data;
        Node* p;
        Node* q;

    Node(int d)
    {
        data = d;
        p = q = NULL;
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
        cout << "Root ka q subtree" << endl;
        root->q = insertIntoBST(root->q, d);

    }
    else
    {
        cout << "root ka p subtree" << endl;
        root->p = insertIntoBST(root->p, d);
        
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

            if (temp->p)
            {
                q.push(temp->p);
            }
            if (temp->q)
            {
                q.push(temp->q);
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