// Take Input from the user of a 2d Array and print their sum
#include <iostream>
using namespace std;
int main()
{
    int row, column, sum = 0;
    cout << "Enter Rows and Columns : ";
    cin >> row >> column;
    int arr[row][column];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cout << "Enter Element " << i + 1 << " " << j + 1 << " : ";
            cin >> arr[i][j];
            sum += arr[i][j];
        }
    }
    cout << "Sum of entire Matrix : " << sum << endl;
    return 0;
}