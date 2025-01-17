#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : value(val), left(NULL), right(NULL) {}
};

void inorderTraversal(TreeNode* root) {
    stack<TreeNode*> s;
    TreeNode* current = root;
    
    while (current != NULL || !s.empty()) {
        // Reach the leftmost node
        while (current != NULL) {
            s.push(current);
            current = current->left;
        }
        
        // Process the node
        current = s.top();
        s.pop();
        cout << current->value << " ";
        
        // Move to the right subtree
        current = current->right;
    }
}
void preorderTraversal(TreeNode* root) {
    if (root == NULL) return;

    stack<TreeNode*> s;
    s.push(root);
    
    while (!s.empty()) {
        TreeNode* current = s.top();
        s.pop();
        
        cout << current->value << " ";
        
        // Right child is pushed first so left child is processed first
        if (current->right) s.push(current->right);
        if (current->left) s.push(current->left);
    }
}
void postorderTraversal(TreeNode* root) {
    if (root == NULL) return;

    stack<TreeNode*> s1, s2;
    s1.push(root);
    
    while (!s1.empty()) {
        TreeNode* current = s1.top();
        s1.pop();
        s2.push(current);
        
        // Push left and right children to s1
        if (current->left) s1.push(current->left);
        if (current->right) s1.push(current->right);
    }
    
    // Process nodes in s2 (which will be in post-order)
    while (!s2.empty()) {
        cout << s2.top()->value << " ";
        s2.pop();
    }
}
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    inorderTraversal(root);  // Output: 4 2 5 1 3
    cout << endl;
    preorderTraversal(root);
    return 0;
}
