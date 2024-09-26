//Implementation of Insertion Sort
#include <iostream>
using namespace std;
void InsertionSort(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}
int main()
{
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    InsertionSort(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}