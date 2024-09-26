// Take input of 2 Matrix(Of any Rows and Columns) from user and Print their sum
#include <iostream>
using namespace std;
int main()
{
    int row, column;
    cout << "Enter the number of rows: ";
    cin >> row;
    cout << "Enter the number of columns: ";
    cin >> column;
    int arr1[row][column], arr2[row][column], sum[row][column];
    cout << "Enter the elements of first matrix: " << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cin >> arr1[i][j];
        }
    }
    cout << "Enter the elements of second matrix: " << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cin >> arr2[i][j];
        }
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            sum[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
    cout << "The sum of two matrices is: " << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cout << sum[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}