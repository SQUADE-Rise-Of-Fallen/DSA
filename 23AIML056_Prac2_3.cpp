/*You will be given a zero - indexed array A.You need to rearrange its elements in such a way that the following conditions are satisfied :
A[i] ≤ A[i + 1] if i is even.
A[i] ≥ A[i + 1] if i is odd.
In other words, the following inequality should hold : A[0] ≤ A[1] ≥ A[2] ≤ A[3] ≥ A[4], and so on.Operations ≤ and ≥ should alter.
Input
The first line contains a single integer T denoting the number of test cases.
The first line of each test case contains an integer N, that is the size of the array A.
The second line of each test case contains the elements of array A
Output
For each test case, output a single line containing N space separated integers, which are the elements of
A arranged in the required order. If there are more than one valid arrangements, you can output any of
them.*/
#include <iostream>
using namespace std;
void BubbleSort(int a[], int n)
{
    int flag = -1;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                flag = 1;
            }
        }
        if (flag == -1)
            return;
    }
}
void sort(int a[], int n)
{
    BubbleSort(a, n);
    for (int i = 0; i < n - 1; i++)
    {
        if ((i % 2 == 0 && a[i] >= a[i + 1]))
            swap(a[i], a[i + 1]);
        else if (i % 2 == 1 && a[i] <= a[i + 1])
            swap(a[i], a[i + 1]);
    }
}
int main()
{
    int n, t;
    cout << "Enter test case : ";
    cin >> t;
    for (int j = 0; j < t; j++)
    {
        cout << "Enter Number of Elements : ";
        cin >> n;
        int a[n];
        cout << "Enter Elements of Array : ";
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, n);
        cout << "Sorted Array : ";
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
}