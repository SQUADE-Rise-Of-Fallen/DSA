// Implement a program to find the longest word in the input string and then calculate and print the number of characters in the word.
#include <iostream>
using namespace std;
int longestWordLength(string s)
{
    int maxLength = 0, current = 0, n = s.length();
    for (int i = 0; i < n; i++)
    {
        if (s[i] != ' ' && s[i] != '.')
        {
            current++;
        }
        else
        {
            maxLength = max(maxLength, current);
            current = 0;
        }
    }
    return max(maxLength, current);
}
int main()
{
    string word;
    cout << "Enter a string: ";
    getline(cin, word);
    cout << "String : " << word << endl;
    cout << "Length of the Longest Word : " << longestWordLength(word) << endl;
    return 0;
}