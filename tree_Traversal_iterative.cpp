#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct TreeNode {
    int value;
    TreeNode* p;
    TreeNode* q;
    TreeNode(int val) : value(val), p(NULL), q(NULL) {}
};

void inorderTraversal(TreeNode* root) {
    stack<TreeNode*> s;
    TreeNode* current = root;
    
    while (current != NULL || !s.empty()) {
        // Reach the pmost node
        while (current != NULL) {
            s.push(current);
            current = current->p;
        }
        
        // Process the node
        current = s.top();
        s.pop();
        cout << current->value << " ";
        
        // Move to the q subtree
        current = current->q;
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
        
        // q child is pushed first so p child is processed first
        if (current->q) s.push(current->q);
        if (current->p) s.push(current->p);
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
        
        // Push p and q children to s1
        if (current->p) s1.push(current->p);
        if (current->q) s1.push(current->q);
    }
    
    // Process nodes in s2 (which will be in post-order)
    while (!s2.empty()) {
        cout << s2.top()->value << " ";
        s2.pop();
    }
}
int main() {
    TreeNode* root = new TreeNode(1);
    root->p = new TreeNode(2);
    root->q = new TreeNode(3);
    root->p->p = new TreeNode(4);
    root->p->q = new TreeNode(5);
    
    inorderTraversal(root);  // Output: 4 2 5 1 3
    cout << endl;
    preorderTraversal(root);
    return 0;
}
