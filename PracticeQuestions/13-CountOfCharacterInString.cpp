// Take input of String from user and see if a character is duplicated or not. If duplicated print the count of character
#include <iostream>
using namespace std;
int main()
{
    char c[50], ch;
    int count = 0;
    cout << "Enter a string: ";
    gets(c);
    cout << "Enter a character: ";
    cin >> ch;
    for (int i = 0; i < 50; i++)
    {
        if (c[i] == ch)
            count++;
        else if (c[i] == '\0')
            break;
    }
    if (count == 0)
        cout << ch << " is not present in the string";
    else
        cout << "Number of time " << ch << " Occurs : " << count;
    return 0;
}