/*  Valid Parentheses
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',  determine if the input string is
valid.
An input string is valid if:
Open brackets must be closed by the same type of brackets. Open brackets must be closed in the correct
order.
Every close bracket has a corresponding open bracket of the same type.
Example 1:
Input: s = "()"
Output: true    */
#include <iostream>
using namespace std;
class Stack
{
    char s[50];
    int top = -1;
    int size = 50;

public:
    void get()
    {
        cout << "Enter Parentheses : ";
        cin >> s;
    }
    bool isValid()
    {
        char stack[50];
        int stackTop = -1;

        for (int i = 0; s[i] != '\0'; i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                stack[++stackTop] = s[i];
            }
            else
            {
                if (stackTop == -1)
                    return false;

                char topChar = stack[stackTop];
                if ((s[i] == ')' && topChar == '(') ||
                    (s[i] == '}' && topChar == '{') ||
                    (s[i] == ']' && topChar == '['))
                {
                    stackTop--;
                }
                else
                {
                    return false;
                }
            }
        }
        return stackTop == -1;
    }
    void pop()
    {
        if (top == -1)
            cout << "Stack Underflow" << endl;
        else
        {
            cout << "Popped Element : " << s[top] << endl;
            top--;
        }
    }
};
int main()
{
    Stack s;
    s.get();
    if (s.isValid())
        cout << "Parentheses is valid" << endl;
    else
        cout << "Parentheses is not valid" << endl;
    return 0;
}