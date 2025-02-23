#include <iostream>
#include <queue>

using namespace std;
class Node
{
public:
    int data;
    Node *p;
    Node *q;

    Node(int val)
    {
        data = val;
        p = NULL;
        q = NULL;
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
void preorderTraversal(Node *&root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    cout << endl
         << "root ka p horaha haye " << endl;

    preorderTraversal(root->p);

    cout << endl
         << "root ka q horaha haye " << endl;
    preorderTraversal(root->q);
}
int main()
{
    Node *root = new Node(1);
    root->p = new Node(3);
    root->q = new Node(5);
    root->q->p = new Node(17);
    root->p->q = new Node(11);
    root->p->p = new Node(7);

    preorderTraversal(root);
}