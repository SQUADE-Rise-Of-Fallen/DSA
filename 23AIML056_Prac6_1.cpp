/*Implement below operations on Binary Tree
(a) Insert a node at Left
(b) Delete a node at Right
(c) Binary Tree Inorder Traversal
(d) Binary Tree Preorder Traversal
(e) Binary Tree Postorder Traversal
(f) Binary Tree Level Order Traversal
Note: for (a) and (b) , First node will be the root node. Display the content of Binary Tree  as per Inorder, Preorder, Postorder and Level Order Traversal. */
#include <iostream>
#include <queue>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree
{
public:
    Node *root;

    BinaryTree()
    {
        root = nullptr;
    }

    void insertLeft(int value)
    {
        if (root == nullptr)
        {
            root = new Node(value);
        }
        else
        {
            Node *newNode = new Node(value);
            newNode->right = root->left;
            root->left = newNode;
        }
    }
    void insertRight(int value)
    {
        if (root == nullptr)
        {
            root = new Node(value);
        }
        else
        {
            Node *newNode = new Node(value);
            newNode->left = root->right;
            root->right = newNode;
        }
    }

    void deleteLeft()
    {
        if (root != nullptr && root->left != nullptr)
        {
            Node *toDelete = root->left;
            root->left = toDelete->right;
            delete toDelete;
        }
    }
    void deleteRight()
    {
        if (root != nullptr && root->right != nullptr)
        {
            Node *toDelete = root->right;
            root->right = toDelete->left;
            delete toDelete;
        }
    }

    void inorderTraversal(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }
        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }

    void preorderTraversal(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }
        cout << node->data << " ";
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }

    void postorderTraversal(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        cout << node->data << " ";
    }

    void levelOrderTraversal()
    {
        if (root == nullptr)
        {
            return;
        }

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            Node *current = q.front();
            q.pop();
            cout << current->data << " ";

            if (current->left != nullptr)
            {
                q.push(current->left);
            }
            if (current->right != nullptr)
            {
                q.push(current->right);
            }
        }
    }

    void menu()
    {
        char again, choice;
        int n;
        do
        {
            cout << "(a) Insert a node at Left" << endl
                 << "(b) Insert a node at Right" << endl
                 << "(c) Preorder Traversal" << endl
                 << "(d) Postorder Traversal" << endl
                 << "(e) inorder Traversal" << endl
                 << "(f) levelorder Traversal" << endl
                 << "(g) Delete Left" << endl
                 << "(h) Delete Right" << endl;
            cout << "Enter Your Choice : ";
            cin >> choice;
            switch (choice)
            {
            case 'a':
                cout << "Enter the value to insert at left: ";
                cin >> n;
                insertLeft(n);
                break;
            case 'b':
                cout << "Enter the value to insert at right: ";
                cin >> n;
                insertRight(n);
                break;
            case 'c':
                preorderTraversal(root);
                cout << endl;
                break;
            case 'd':
                postorderTraversal(root);
                cout << endl;
                break;
            case 'e':
                inorderTraversal(root);
                cout << endl;
                break;
            case 'f':
                levelOrderTraversal();
                cout << endl;
                break;
            case 'g':
                deleteLeft();
                break;
            case 'h':
                deleteRight();
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
    BinaryTree bt;
    bt.menu();
    return 0;
}