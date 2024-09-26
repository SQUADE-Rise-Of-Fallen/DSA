// Take array input from user and count for duplicates
#include <iostream>
using namespace std;
int main()
{
    int a[10], n, duplicate_count = -1;
    cout << "Enter 10 Elements : " << endl;
    for (int i = 0; i < 10; i++)
    {
        cin >> a[i];
    }
    cout << "Enter The number you want Duplicate Count of : ";
    cin >> n;
    for (int i = 0; i < 10; i++)
    {
        if (a[i] == n)
        {
            duplicate_count++;
        }
    }
    if (duplicate_count == 0)
        cout << "No Duplicate Count" << endl;
    else
        cout << "Duplicate Count : " << duplicate_count << endl;
    return 0;
}