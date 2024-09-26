// Take Input From User of array and print them
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
    cout << "Elements of Array : ";
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
}