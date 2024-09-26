// Implement Linear Search and Binary Search using array data structure.
#include <iostream>
using namespace std;
int searchIndex(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
            return i;
    }
    return -1;
}
int main()
{
    int n, x;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter the element to search: ";
    cin >> x;
    int result = searchIndex(arr, n, x);
    if (result == -1)
        cout << "The Element " << x << " is not found";
    else
        cout << result << " is the index of the element " << x << " in the array";
}