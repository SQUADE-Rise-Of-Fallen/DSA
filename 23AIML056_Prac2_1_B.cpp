// Implement Selection Sort
#include <iostream>
using namespace std;
void SelectionSort(int a[], int n)
{
    int swap_count = 0, pass_count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min_idx])
            {
                pass_count++;
                min_idx = j;
            }
        }
        if (a[min_idx] != a[i])
        {
            swap(a[min_idx], a[i]);
            swap_count++;
        }
    }
    cout << "Number of passes: " << pass_count << endl
         << "Number of swaps: " << swap_count << endl;
}
int main()
{
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    SelectionSort(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}