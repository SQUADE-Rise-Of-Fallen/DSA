// Sort an array in linear time if all of its items are in ascending order except for two swapped elements.
#include <iostream>
using namespace std;
void sort(int arr[], int n)
{
    int first = -1, second = -1;
    for (int i = 0; i < n - 1; ++i)
    {
        if (arr[i] > arr[i + 1])
        {
            if (first == -1)
                first = i;
            else
                second = i + 1;
        }
    }
    if (second == -1)
        second = first + 1;
    swap(arr[first], arr[second]);
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    sort(arr, n);
    cout << "Sorted Array : ";
    printArray(arr, n);
    return 0;
}