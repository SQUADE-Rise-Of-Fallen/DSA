// Multiply Two Matrix which are inputed by User
#include <iostream>
using namespace std;
int main()
{
    int aRow, bRow, aCol, bCol;
    cout << "Enter the number of rows and columns of the first matrix: ";
    cin >> aRow >> aCol;
    cout << "Enter the number of rows and columns of the second matrix: ";
    cin >> bRow >> bCol;
    if (aCol != bRow)
    {
        cout << "Multiplication is not possible";
    }
    else
    {
        int mul[aRow][bCol], a[aRow][aCol], b[bRow][bCol], sum = 0;
        cout << "Enter the elements of the first matrix: ";
        for (int i = 0; i < aRow; i++)
        {
            for (int j = 0; j < aCol; j++)
            {
                cin >> a[i][j];
            }
        }
        cout << "Enter the elements of the Second matrix: ";
        for (int i = 0; i < bRow; i++)
        {
            for (int j = 0; j < bCol; j++)
            {
                cin >> b[i][j];
            }
        }
        for (int i = 0; i < aRow; i++)
        {
            for (int j = 0; j < bCol; j++)
            {
                for (int k = 0; k < aCol; k++)
                {
                    sum += a[i][k] * b[k][j];
                }
                mul[i][j] = sum;
                sum = 0;
            }
        }
        cout << "The multiplication of the two matrix is: " << endl;
        for (int i = 0; i < aRow; i++)
        {
            for (int j = 0; j < bCol; j++)
            {
                cout << mul[i][j] << "  ";
            }
            cout << endl;
        }
    }
    return 0;
}