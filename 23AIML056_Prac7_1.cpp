/*Perform following operations on BST.
(a)Insert a node in BST
(b)Search a node in BST
You are given the root of a binary search tree (BST) and anintegerval.Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.
(c)display
Example 1:
Input: root = [4,2,7,1,3], val = 2
Output: [2,1,3]*/
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = right = nullptr;
    }
};

class BST
{
public:
    Node *root;

    BST()
    {
        root = nullptr;
    }
    Node *insert(Node *root, int val)
    {
        if (root == nullptr)
            return new Node(val);
        if (val < root->data)
            root->left = insert(root->left, val);
        else
            root->right = insert(root->right, val);
        return root;
    }

    Node *search(Node *root, int val)
    {
        if (root == nullptr || root->data == val)
            return root;
        if (val < root->data)
            return search(root->left, val);
        else
            return search(root->right, val);
    }

    void menu()
    {
        int choice, val;
        char again;
        do
        {
            cout << "1. Insert" << endl
                 << "2. Search" << endl
                 << "3. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                cout << "Enter the value to insert: ";
                cin >> val;
                root = insert(root, val);
                break;
            case 2:
            {
                cout << "Enter the value to search: ";
                cin >> val;
                Node *foundNode = search(root, val);
                if (foundNode != nullptr)
                    cout << "Found node: " << foundNode->data << endl;
                else
                    cout << "Node not found." << endl;
                break;
            }
            case 3:
                cout << "Exiting..." << endl;
                exit(0);
            default:
                cout << "Invalid choice. Please try again.\n";
            }
            cout << "Enter y to Continue : ";
            cin >> again;
        } while (again == 'Y' || again == 'y');
    }
};

int main()
{
    BST bst;
    bst.menu();
    return 0;
}