// Find Sum of Array Elements
#include <iostream>
using namespace std;
int main()
{
    int size, sum = 0;
    cout << "Enter Size of Array : ";
    cin >> size;
    int array[size];
    cout << "Enter Array Elements : ";
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
        sum += array[i];
    }
    cout << "Sum : " << sum;
}