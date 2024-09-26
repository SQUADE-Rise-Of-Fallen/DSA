// Take Input from the user of a 2d Array and print them
#include <iostream>
using namespace std;
int main()
{
    int row, column;
    cout << "Enter Rows and Columns : ";
    cin >> row >> column;
    int arr[row][column];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cout << "Enter Element " << i + 1 << " " << j + 1 << " : ";
            cin >> arr[i][j];
        }
    }
    cout << "2D Array is : " << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cout << arr[j][i] << "  ";
        }
        cout << endl;
    }
    return 0;
}