#include <iostream>
#include <stack>
#include <string>

bool isBalanced(const string& str) {
    stack<char> s;

    for (char ch : str) {
        // If opening bracket, push to stack
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }
        // If closing bracket, check stack
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty()) return false; // No matching opening bracket
            
            char top = s.top();
            s.pop();

            // Check if the popped element matches the closing bracket
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }

    // After processing, stack should be empty
    return s.empty();
}

int main() {
    string expr;
    cout << "Enter an expression: ";
    cin >> expr;

    if (isBalanced(expr)) {
        cout << "The parentheses are balanced.\n";
    } else {
        cout << "The parentheses are NOT balanced.\n";
    }

    return 0;
}
