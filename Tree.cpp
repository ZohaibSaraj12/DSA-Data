#include <iostream>
#include <queue>

using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

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
void preorderTraversal(Node *&root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    cout << endl
         << "root ka left horaha haye " << endl;

    preorderTraversal(root->left);

    cout << endl
         << "root ka right horaha haye " << endl;
    preorderTraversal(root->right);
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(5);
    root->right->left = new Node(17);
    root->left->right = new Node(11);
    root->left->left = new Node(7);

    preorderTraversal(root);
}