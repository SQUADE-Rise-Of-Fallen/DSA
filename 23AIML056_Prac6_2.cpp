/*Maximum Depth of Binary Tree
Given the root of a binary tree, return its maximum depth. A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
Example 1:
Input: root = [3,9,20, null, null,15,7]
Output: 3*/
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

    int maxDepth(TreeNode *node)
    {
        if (node == nullptr)
        {
            return 0;
        }

        int leftDepth = maxDepth(node->left);
        int rightDepth = maxDepth(node->right);

        return max(leftDepth, rightDepth) + 1;
    }

    int findMaxDepth()
    {
        return maxDepth(root);
    }
};

int main()
{
    BinaryTree bt;

    bt.root = new TreeNode(3);
    bt.root->left = new TreeNode(9);
    bt.root->right = new TreeNode(20);
    bt.root->right->left = new TreeNode(15);
    bt.root->right->right = new TreeNode(7);

    int depth = bt.findMaxDepth();
    cout << "Maximum depth of the binary tree: " << depth << endl;

    return 0;
}