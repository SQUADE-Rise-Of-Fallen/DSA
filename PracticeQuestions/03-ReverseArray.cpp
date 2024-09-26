// Reverse The Array Element using Extra Array and Same Array
#include <iostream>
using namespace std;
int main()
{
    int size;
    cout << "Enter Size of Array : ";
    cin >> size;
    int array[size];
    cout << "Enter Array Elements : ";
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }
    int reverse_array[size];
    for (int i = 0; i < size; i++)
    {
        reverse_array[i] = array[size - 1 - i];
    }
    cout << "Reverse Array using second Array : ";
    for (int i = 0; i < size; i++)
    {
        cout << reverse_array[i] << " ";
    }
    cout << endl
         << "Reversed Array using same Array : ";
    for (int i = 0; i < size / 2; i++)
    {
        swap(array[i], array[size - i - 1]);
    }
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
}