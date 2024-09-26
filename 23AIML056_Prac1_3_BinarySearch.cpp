// Implement Linear Search and Binary Search using array data structure.
#include <iostream>
using namespace std;
int BinarySearch(int a[], int left, int right, int x)
{
    while (left <= right)
    {
        int mid = (right - left) / 2 + left;
        if (a[mid] == x)
            return mid;
        else if (a[mid] > x)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}
int main()
{
    int n, x;
    cout << "Enter Total number of Elements : ";
    cin >> n;
    int arr[n];
    cout << "Enter Numbers : ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter the Element to be Found : ";
    cin >> x;
    int result = BinarySearch(arr, 0, n - 1, x);
    if (result == -1)
        cout << "Element Not Found";
    else
        cout << "Element " << x << " at Index " << result;
    return 0;
}