/* Given a postfix expression, the task is to evaluate the postfix expression.
Postfix expression: The expression of the form “a b operator” (ab+) i.e., when a pair of operands is
followed by an operator.
Examples:
Input: str = “2 3 1 * + 9 -“
Output: -4
Explanation: If the expression is converted into an infix expression, it will be 2 + (3 * 1) – 9 = 5 – 9 = -4.*/
#include <iostream>
#include <stack>
#include <cmath>
using namespace std;
bool isDigit(char c)
{
    if (c >= '0' && c <= '9')
        return true;
    else
        return false;
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
int evaluatePostfix(string s)
{
    stack<int> st;
    for (int i = 0; i < (signed)s.length(); i++)
    {
        if (isDigit(s[i]))
            st.push(s[i] - '0');
        else if (isOperator(s[i]))
        {
            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();
            switch (s[i])
            {
            case '+':
                st.push(op1 + op2);
                break;
            case '-':
                st.push(op1 - op2);
                break;
            case '*':
                st.push(op1 * op2);
                break;
            case '/':
                st.push(op1 / op2);
                break;
            case '^':
                st.push(pow(op1, op2));
                break;
            }
        }
    }
    int a = st.top();
    st.pop();
    return a;
}
int main()
{
    string s;
    cout << "Enter a Postfix Expression : ";
    cin >> s;
    cout << "Result : " << evaluatePostfix(s) << endl;
    return 0;
}