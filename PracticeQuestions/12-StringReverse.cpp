// Take Input of String from user and reverse it
#include <iostream>
using namespace std;
int main()
{
    char c[50];
    int len = 0;
    cout << "Enter a String : ";
    gets(c);
    for (int i = 0; c[i] != '\0'; i++)
    {
        len++;
    }
    cout << "Reverse of the String is : ";
    for (int i = len; i >= 0; i--)
    {
        cout << c[i];
    }
    return 0;
}