/*Kth smallest element in BST
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of
all the values of the nodes in the tree.
Example 1:
Input: root = [3,1,4,null,2], k = 1
Output: 1
Example 2:
Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3*/
#include <iostream>
#include <stack>
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
    void display(Node *root)
    {
        if (root == nullptr)
            return;
        cout << root->data << " ";
        display(root->left);
        display(root->right);
    }
    int kthSmallest(Node *root, int k)
    {
        stack<Node *> stack;
        int count = 0;

        while (true)
        {
            while (root)
            {
                stack.push(root);
                root = root->left;
            }
            if (stack.empty())
                break;
            root = stack.top();
            stack.pop();
            count++;
            if (count == k)
                return root->data;
            root = root->right;
        }
        return -1;
    }
};

int main()
{
    BST bst1, bst2;
    int answer, val;
    cout << "-----For the Binary Search Tree 1-----" << endl;
    bst1.root = new Node(3);
    bst1.root->left = new Node(1);
    bst1.root->right = new Node(4);
    bst1.root->left->right = new Node(2);
    cout << "Enter the value of K : ";
    cin >> val;
    answer = bst1.kthSmallest(bst1.root, val);
    if (answer != -1)
        cout << "The " << val << "th Smallest element is : " << answer << endl;
    cout << endl
         << endl
         << "-----For the Binary Search Tree 2-----" << endl;
    bst2.root = new Node(5);
    bst2.root->left = new Node(3);
    bst2.root->right = new Node(6);
    bst2.root->left->left = new Node(2);
    bst2.root->left->right = new Node(4);
    bst2.root->left->left->left = new Node(1);
    cout << "Enter the value of K : ";
    cin >> val;
    answer = bst2.kthSmallest(bst2.root, val);
    if (answer != -1)
        cout << "The " << val << "th Smallest element is : " << answer << endl;
    return 0;
}