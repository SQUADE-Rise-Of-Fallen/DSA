/*  You are given the heads of two sorted linked lists list1 and list2. Merge the two lists in a one sorted
list. The list should be made by splicing together the nodes of the first two lists. Return the merged
linked list. Example 1:
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]   */
#include <iostream>
using namespace std;
class list
{
    int data;
    list *next;
    list *head;

public:
    list(int d)
    {
        data = d;
        next = NULL;
        head = NULL;
    }
    list()
    {
        head = NULL;
    }
    void add(int d)
    {
        list *temp = new list(d);
        if (head == NULL)
            head = temp;
        else
        {
            list *last = head;
            while (last->next != NULL)
                last = last->next;
            last->next = temp;
        }
    }
    void display()
    {
        list *trav;
        trav = head;
        if (head == NULL)
        {
            cout << "Underflow" << endl;
            return;
        }
        cout << endl
             << "Linked List : " << endl;
        while (trav != NULL)
        {
            cout << trav->data << " ";
            trav = trav->next;
        }
    }
    void mergeSortedList(list &l2)
    {
        list *dummy = new list(); // Dummy node for the merged list
        list *merged = dummy;     // Pointer to the merged list

        list *curr1 = head;    // Pointer for list1
        list *curr2 = l2.head; // Pointer for list2

        while (curr1 != NULL && curr2 != NULL)
        {
            if (curr1->data < curr2->data)
            {
                merged->next = curr1;
                curr1 = curr1->next;
            }
            else
            {
                merged->next = curr2;
                curr2 = curr2->next;
            }
            merged = merged->next;
        }

        // Attach remaining nodes from list1 or list2
        if (curr1 != NULL)
            merged->next = curr1;
        else
            merged->next = curr2;

        // Update head of the merged list
        head = dummy->next;
        delete dummy; // Clean up dummy node
    }
};
int main()
{
    list l1;
    l1.add(1);
    l1.add(2);
    l1.add(4);
    l1.display();
    list l2;
    l2.add(3);
    l2.add(6);
    l2.add(9);
    l2.display();
    cout << endl
         << "Merged list : ";
    l1.mergeSortedList(l2);
    l1.display();
    return 0;
}