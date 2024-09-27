/*Generate Binary Numbers from 1 to n using queue and its operations.
Given a number N, write a function that generates and prints all binary numbers with decimal values from 1 to N.
Example 1:
Input: n = 2  Output: 1, 10
Example 2:
Input: n = 5  Output: 1, 10, 11, 100, 101*/
#include <iostream>
#include <queue>
using namespace std;
string intToBinary(int n)
{
    string s = "";
    while (n > 0)
    {
        s = to_string(n % 2) + s;
        n /= 2;
    }
    return s;
}
void generateBinary(int n)
{
    queue<string> q;
    for (int i = 1; i <= n; i++)
    {
        q.push(intToBinary(i));
    }
    while (!q.empty())
    {
        cout << q.front() << ", ";
        q.pop();
    }
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    generateBinary(n);
    return 0;
}
