//Take Input of String and print its length
#include <iostream>
using namespace std;
int main()
{
    char c[50];
    int length = 0;
    cout << "Enter String : ";
    gets(c);
    for (int i = 0; c[i] != '\0'; i++)
    {
        length++;
    }
    cout << "String " << c << " Length : " << length;
    return 0;
}