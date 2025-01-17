#include <iostream>
#include <string>
#include <stack>
#include <cctype>
#include <algorithm>

using namespace std;

int precedence (char ch)
{
    if (ch == '+' || ch == '-') 
    return 1;
    else if(ch == '*' || ch == '/')
    return 2;
    else if (ch == '^')
    return 3;
    else
    return 0;
}

string infixToPostfix(const string& infix)
{
    stack<char> s;
    string postfix = "";

    for (auto& ch : infix)
    {
        if (isalnum(ch))
        {
            postfix += ch;
        }
        else if (ch == '(')
        {
            s.push(ch);
        }
        else if (ch == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        }
        else
        {
            while(!s.empty() && precedence(s.top()) >= precedence(ch))
            {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }

    }
    while(!s.empty())
    {
        postfix += s.top();
        s.pop();
    }
    return postfix;
}
string infixToPrefix(string infix) 
{
    string reversedInfix = infix;
    reverse(reversedInfix.begin(), reversedInfix.end());

    for (auto& ch : reversedInfix)
    {
        if (ch == '(')
        ch = ')';
        else if (ch == ')')
        ch = '(';
    }

    string reversedPostfix = infixToPostfix(reversedInfix);
    reverse(reversedPostfix.begin(), reversedPostfix.end());
    return reversedPostfix;
}

main() 
{
    string infix;

    cout << "Enter an Infix notation to convert into Postfix : ";
    getline(cin, infix);

    string postfix = infixToPostfix(infix);
     
    cout << "Postfix Form is : " << postfix << endl;
    
    string prefix = infixToPrefix(infix);

    cout << "Prefix is : " << prefix << endl;
   
}