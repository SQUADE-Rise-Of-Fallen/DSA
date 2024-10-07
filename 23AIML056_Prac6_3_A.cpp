/*Binary Tree Right View
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes which you can see ordered from top to bottom.
Example 1:
Input: root = [1,2,3,4,5,null,null]
Output: [1,3,5]
Example 2:
Input: root = [1,null,3]
Output: [1,3]
Example 3:
Input: root = []
Output: []*/
#include<iostream>
#include<vector>
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

    void recursion(TreeNode *root, int level, vector<int> &ans)
    {
        if (root == NULL)
            return;

        if (ans.size() == (unsigned)level)
            ans.push_back(root->val);

        recursion(root->right, level + 1, ans);
        recursion(root->left, level + 1, ans);
    }

    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;
        recursion(root, 0, ans);
        return ans;
    }
};
int main()
{
    BinaryTree tree;
    tree.root = new TreeNode(1);
    tree.root->left = new TreeNode(2);
    tree.root->right = new TreeNode(3);
    tree.root->left->left = new TreeNode(4);
    tree.root->left->right = new TreeNode(5);
    vector<int> ans = tree.rightSideView(tree.root);
    for (int i : ans)
        cout << i << " ";
    return 0;
}