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
        return root;
        
    }
    if (d > root->data)
    {
        root->right = insertIntoBST(root->right, d);

    }
    else
    {
        root->left = insertIntoBST(root->left, d);
        
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

    while (temp->left != NULL)
    {
        temp = temp->left;
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
        if ((root->left == NULL) && (root->right == NULL))
        {
            Node* temp = root;
            delete root;
            cout << "is ka koi child nahin to NULL return karrahy hain " << endl;
            return NULL;
        }
        // 1 child
        // left child
        if ((root->left != NULL) && (root->right == NULL))
        {
            cout << "left child agiya" << root->data << endl;
            Node* temp = root->left;
            delete root;
            cout << "ab current root ko delete kardia ham n return kar rahy hain" << endl;
            cout << temp->data << endl;
            return temp;
        }
        //right child
        if ((root->left == NULL) && (root->right != NULL))
        {
            Node* temp = root->right;
            
            delete root;
            cout << "Ab right mein aya haye to dekho " << temp->data << endl;
            return temp;
        }

        //2 child

        if ((root->left != NULL) && (root->right != NULL))
        {
            int mini = minValue(root->right)->data;
            root->data = mini;
            cout << "mini is " << mini << endl;
            cout << "root ka data" << root->data << endl;
            cout << "Right mein jao" << endl;
            root->right = deleteFromBST(root->right, mini);
            cout << "root ko return karrahy hain right subtree mein" << endl;
            cout << root->data << endl;
            return root;
        }
    }
    if (root->data > d)
    {
        cout << endl << "Left part men jao kionk " << root->data << endl;
        root->left = deleteFromBST(root->left, d);
        cout << endl << "Root ko return kar rahy hain ham " << endl;
        cout << root->data << endl << endl;
        return root;
    }
    else 
    {
        root->right = deleteFromBST(root->right, d);
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
    // 10 5 4 2 1 3 12 11 13 -1 
    Node* root1 = deleteFromBST(root, 10);
    levelOrderTraversal(root1);

}