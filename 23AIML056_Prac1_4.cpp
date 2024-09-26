// You are given an array nums of non-negative integers. nums is considered special if there exists a number x such that there are exactly x numbers in nums that are greater than or equal to x. Notice that x does not have to be an element in nums. Return x if the array is special, otherwise, return -1. It can be proven that if nums is special, the value for x is unique.

#include <iostream>
using namespace std;
int specialArray(int a[], int n)
{
    for (int x = 0; x < n; x++)
    {
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] >= x)
                count++;
        }
        if (count == x)
            return x;
    }
    return -1; // If no special Element Found
}
int main()
{
    int n;
    cout << "Enter Total number of Elements : ";
    cin >> n;
    int arr[n];
    cout << "Enter Numbers : ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int result = specialArray(arr, n);
    if (result == -1)
        cout << "Not A Special Array";
    else
        cout << "Special Element : " << result << endl;
    return 0;
}