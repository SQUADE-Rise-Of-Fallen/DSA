/*Implement below operations of singly linked list.
    (a) Insert a node at front
    (b) Delete a node at last
    (c) Delete Nth Node from End of List
    (d) Delete all nodes of linked list
Note: Display content of linked list after each operation.*/
#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct node *first = NULL;
void insert_front(int n)
{
    struct node *temp = new node;
    temp->data = n;
    temp->next = NULL;
    if (first == NULL)
    {
        first = temp;
    }
    else
    {
        temp->next = first;
        first = temp;
    }
}
void delete_last()
{
    struct node *temp, *prev;
    temp = first;
    if (first == NULL)
    {
        cout << "Underflow" << endl;
        return;
    }
    else if (first->next == NULL)
    {
        first = NULL;
        free(temp);
        return;
    }
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
}
void delete_all()
{
    struct node *temp = first, *next;
    while (temp != NULL)
    {
        next = temp->next;
        free(temp);
        temp = next;
    }
    first = NULL;
}
int sizeOfList()
{
    struct node *temp = first;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
void delete_nth(int n)
{
    if (first == NULL)
    {
        cout << "Underflow" << endl;
        return;
    }
    int size = sizeOfList();
    if (n <= 0 || n > size)
    {
        cout << "Invalid position" << endl;
        return;
    }
    struct node *slow = first;
    struct node *fast = first;
    for (int i = 0; i < n; ++i)
    {
        if (fast == NULL)
        {
            cout << "Position out of range" << endl;
            return;
        }
        fast = fast->next;
    }
    struct node *prev = NULL;
    while (fast != NULL)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next;
    }
    if (prev == NULL)
    {
        first = slow->next;
    }
    else
    {
        prev->next = slow->next;
    }
    free(slow);
    cout << n << "th Node from last deleted successfully" << endl;
}
void display()
{
    struct node *trav;
    trav = first;
    if (first == NULL)
    {
        cout << "Underflow" << endl;
        return;
    }
    cout << endl
         << "Linked List : " << endl;
    while (trav != NULL)
    {
        printf("%d ", trav->data);
        trav = trav->next;
    }
}
int main()
{
    int again;
    while (1)
    {
        char choice;
        cout << "Enter your choice\n(a) Insert at front\n(b) Delete a node at Last\n(c) Delete Nth node from last\n(d) Delete all Nodes from LinkedList\nEnter Your Choice : ";
        cin >> choice;
        int number, node;
        switch (choice)
        {
        case 'a':
            cout << "Enter the number to insert at front: ";
            cin >> number;
            insert_front(number);
            display();
            break;
        case 'b':
            delete_last();
            display();
            break;
        case 'c':
            cout << "Enter which node to delete from last : ";
            cin >> node;
            delete_nth(node);
            cin.ignore();
            display();
            break;
        case 'd':
            delete_all();
            cout << "Deleted All Nodes" << endl;
            break;
        default:
            cout << "Invalid Choice!";
            break;
        }
        cout << endl
             << "Enter 0 to Exit : ";
        cin >> again;
        cout << endl;
        if (again == 0)
            break;
    }
}