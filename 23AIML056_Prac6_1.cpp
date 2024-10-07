/*Implement below operations on Binary Tree
(a) Insert a node at Left
(b) Delete a node at Right
(c) Binary Tree Inorder Traversal
(d) Binary Tree Preorder Traversal
(e) Binary Tree Postorder Traversal
(f) Binary Tree Level Order Traversal
Note: for (a) and (b) , First node will be the root node. Display the content of Binary Tree  as per Inorder, Preorder, Postorder and Level Order Traversal. */
#include <iostream>
using namespace std;
class BinaryTree
{
    int data;
    BinaryTree *l, *r;
    BinaryTree *Root;

public:
    BinaryTree()
    {
        data = 0;
        l = NULL;
        r = NULL;
        Root = NULL;
    }
    BinaryTree(int value)
    {
        data = value;
        l = NULL;
        r = NULL;
        Root = NULL;
    }
    void insertLeft(BinaryTree *root, int val)
    {
        if (root == NULL)
            root = new BinaryTree(val);
        else if (root->l == NULL)
            root->l = new BinaryTree(val);
        else
            insertLeft(root->l, val);
    }
    void insertRight(BinaryTree *root, int val)
    {
        if (root == NULL)
            root = new BinaryTree(val);
        else if (root->r == NULL)
            root->r = new BinaryTree(val);
        else
            insertLeft(root->r, val);
    }
    void preorderTraversal(BinaryTree *root)
    {
        if (root != NULL)
        {
            cout << root->data << " ";
            preorderTraversal(root->l);
            preorderTraversal(root->r);
        }
    }
    void postorderTraversal(BinaryTree *root)
    {
        if (root != NULL)
        {
            postorderTraversal(root->l);
            postorderTraversal(root->r);
            cout << root->data << " ";
        }
    }
    void inorderTraversal(BinaryTree *root)
    {
        if (root != NULL)
        {
            inorderTraversal(root->l);
            cout << root->data << " ";
            inorderTraversal(root->r);
        }
    }
    void levelorderTraversal(BinaryTree *root)
    {
        int x;
    }
    void menu()
    {
        char again, choice;
        int n;
        do
        {
            cout << "(a) Insert a node at Left" << endl
                 << "(b) Insert a node at Right" << endl
                 << "(c) Preorder Traversal" << endl;
            cout << "Enter Your Choice : ";
            cin >> choice;
            switch (choice)
            {
            case 'a':
                cout << "Enter the value to insert at left: ";
                cin >> n;
                insertLeft(Root, n);
                break;
            case 'b':
                cout << "Enter the value to insert at right: ";
                cin >> n;
                insertRight(Root, n);
                break;
            case 'c':
                preorderTraversal(Root);
                break;
            case 'd':
                postorderTraversal(Root);
                break;
            case 'e':
                inorderTraversal(Root);
                break;
            case 'f':
                levelorderTraversal(Root);
                break;
            default:
                cout << "Invalid Choice" << endl;
            }
            cout << "Enter Y to continue : " << endl;
            cin >> again;
        } while (again == 'Y' || again == 'y');
    }
};
int main()
{
    BinaryTree t;
    t.menu();
}