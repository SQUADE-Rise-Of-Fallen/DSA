/*  Given an infix expression, the task is to convert it to a postfix expression.
Infix Expression: The expression of type a ‘operator’ b (a+b, where + is an operator) i.e., when the
operator is between two operands.
Postfix Expression: The expression of the form “a b operator” (ab+) i.e., When every pair of operands
is followed by an operator.
Examples:
Input: A+B*C+D
Output: ABC*+D+
Input: ((A+B)–C*(D/E))+F
Output: A B + C D E / * - F + */
#include <iostream>
#include <stack>
using namespace std;
bool isOperand(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        return true;
    else
        return false;
}
int precedence(char c)
{
    switch (c)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return -1;
    }
}
bool isOperator(char c)
{
    switch (c)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '^':
        return true;
    default:
        return false;
    }
}
string infixToPostfix(string s)
{
    stack<char> st;
    string ans = "";
    for (int i = 0; i < (signed)s.size(); i++)
    {
        if (isOperand(s[i]))
            ans += s[i];
        else if (s[i] == '(')
            st.push(s[i]);
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else if (isOperator(s[i]))
        {
            while (!st.empty() && (precedence(s[i]) <= precedence(st.top())))
            {
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    return ans;
}
int main()
{
    string s;
    cout << "Enter infix expression : ";
    cin >> s;
    string postfix = infixToPostfix(s);
    cout << "Postfix expression is : " << postfix;
    return 0;
}
