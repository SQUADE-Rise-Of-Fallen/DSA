/*  Implement Queue using array
Implement a Queue using an Array. Queries in the Queue are of the  following type:
(i) 1 x (a query of this type means pushing 'x' into the queue) (ii) 2 (a query of this type means to pop
element from queue and print the popped element)
Example 1:
Input:
Q = 5
Queries =
1 2
1 3
2
1 4
2
Output: 2 3 */

#include <iostream>
using namespace std;
class Queue
{
    int a[5];
    int F, R, N = 5;

public:
    Queue() { F = R = -1; }
    void enqueue(int n)
    {
        if (R == N - 1)
        {
            cout << "Queue Overflow" << endl;
            return;
        }
        else
        {
            R = R + 1;
            a[R] = n;
            if (F == -1)
                F = 0;
        }
    }
    int dequeue()
    {
        if (F == -1)
        {
            cout << "Queue Overflow" << endl;
            return -1;
        }
        else if (F == R)
        {
            int x = a[F];
            F = 0;
            R = 0;
            return x;
        }
        else
        {
            int x = a[F];
            F = F + 1;
            return x;
        }
    }
    void display()
    {
        if (F == -1)
            cout << "Queue is empty" << endl;
        else
            cout << a[F] << endl;
    }
    void query()
    {
        int Q, queryType;
        cout << "Enter Total Queries : ";
        cin >> Q;
        for (int i = 0; i < Q; i++)
        {
            cin >> queryType;
            if (queryType == 1)
            {
                int x;
                cin >> x;
                enqueue(x);
            }
            else if (queryType == 2)
            {
                cout << "Popped Element : " << dequeue() << endl;
            }
        }
        cout << endl;
        cout << "Queue : ";
        display();
    }
};
int main()
{
    Queue Q;
    Q.query();
    return 0;
}