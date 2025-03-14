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
        return root;
        
    }
    if (d > root->data)
    {
        root->q = insertIntoBST(root->q, d);

    }
    else
    {
        root->p = insertIntoBST(root->p, d);
        
    }
    return root;
    
}
void takeInput(Node*& root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
       root = insertIntoBST(root, data);
        cin >> data;
    }
}
Node* minValue(Node* root)
{
    Node* temp = root;

    while (temp->p != NULL)
    {
        temp = temp->p;
    }
    return temp;
    
}
Node* deleteFromBST(Node*& root, int d)
{
    if (root == NULL)
    {
        cout << "root ko return karrahy hain " << root->data << endl;
        return root;

    }
    if (root->data == d)
    {
        // 0 child
        if ((root->p == NULL) && (root->q == NULL))
        {
            Node* temp = root;
            delete root;
            cout << "is ka koi child nahin to NULL return karrahy hain " << endl;
            return NULL;
        }
        // 1 child
        // p child
        if ((root->p != NULL) && (root->q == NULL))
        {
            cout << "p child agiya" << root->data << endl;
            Node* temp = root->p;
            delete root;
            cout << "ab current root ko delete kardia ham n return kar rahy hain" << endl;
            cout << temp->data << endl;
            return temp;
        }
        //q child
        if ((root->p == NULL) && (root->q != NULL))
        {
            Node* temp = root->q;
            
            delete root;
            cout << "Ab q mein aya haye to dekho " << temp->data << endl;
            return temp;
        }

        //2 child

        if ((root->p != NULL) && (root->q != NULL))
        {
            int mini = minValue(root->q)->data;
            root->data = mini;
            cout << "mini is " << mini << endl;
            cout << "root ka data" << root->data << endl;
            cout << "q mein jao" << endl;
            root->q = deleteFromBST(root->q, mini);
            cout << "root ko return karrahy hain q subtree mein" << endl;
            cout << root->data << endl;
            return root;
        }
    }
    if (root->data > d)
    {
        cout << endl << "p part men jao kionk " << root->data << endl;
        root->p = deleteFromBST(root->p, d);
        cout << endl << "Root ko return kar rahy hain ham " << endl;
        cout << root->data << endl << endl;
        return root;
    }
    else 
    {
        root->q = deleteFromBST(root->q, d);
        cout << "ye else part haye " << endl;
        return root;
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
    // 10 5 4 2 1 3 12 11 13 -1 
    Node* root1 = deleteFromBST(root, 10);
    levelOrderTraversal(root1);

}