// C++ program to demonstrate
//  the use of rand()
#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter amount of random numbers you want : ";
    cin >> n;
    // This program will create some sequence of
    // random numbers on every program run
    for (int i = 0; i < n; i++)
        cout << rand() << " ";

    return 0;
}
