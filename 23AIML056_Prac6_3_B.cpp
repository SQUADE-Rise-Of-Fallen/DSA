/*Binary Tree boundary
Given a binary tree, print boundary nodes of the binary tree Anti-Clockwise starting from the root.

The boundary includes:
left boundary (nodes on left excluding leaf nodes)
leaves (consist of only the leaf nodes)
right boundary (nodes on right excluding leaf nodes)
Example:
root : 20
left - boundary nodes: 8
leaf nodes: 4 10 14 25
right – boundary nodes: 22*/
#include <iostream>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *left, *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BinaryTree
{
public:
    TreeNode *root;

    BinaryTree() : root(nullptr) {}
    void printBoundaryLeft(TreeNode *root)
    {
        if (root == nullptr)
            return;
        if (root->left)
        {
            cout << root->val << " ";
            printBoundaryLeft(root->left);
        }
        else if (root->right)
        {
            cout << root->val << " ";
            printBoundaryLeft(root->right);
        }
    }
    void printBoundaryRight(TreeNode *root)
    {
        if (root == nullptr)
            return;
        if (root->right)
        {
            cout << root->val << " ";
            printBoundaryLeft(root->right);
        }
        else if (root->left)
        {
            cout << root->val << " ";
            printBoundaryLeft(root->left);
        }
    }
    void printLeaves(TreeNode *root)
    {
        if (root == nullptr)
            return;
        printLeaves(root->left);
        if (!(root->left) && !(root->right))
            cout << root->val << " ";
        printLeaves(root->right);
    }
};
int main()
{
    BinaryTree tree;
    tree.root = new TreeNode(20);
    tree.root->left = new TreeNode(8);
    tree.root->right = new TreeNode(22);
    tree.root->left->left = new TreeNode(4);
    tree.root->left->right = new TreeNode(10);
    tree.root->right->left = new TreeNode(14);
    tree.root->right->right = new TreeNode(25);
    cout << "Root : " << tree.root->val << endl;
    cout << "Left - Boundary Nodes : ";
    tree.printBoundaryLeft(tree.root->left);
    cout << endl;
    cout << "Leaf Nodes : ";
    tree.printLeaves(tree.root);
    cout << endl;
    cout << "Right - Boundary Nodes : ";
    tree.printBoundaryRight(tree.root->right);
    cout << endl;
    return 0;
}