/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    bool isLeaf(TreeNode *root) {
        return (!root->left && !root->right);
    }

    void findSum(TreeNode *root, int &ans) {
        if (root == NULL)
            return;
        if (root->left && isLeaf(root->left))
            ans += root->left->val;
        else
            findSum(root->left, ans);

        findSum(root->right, ans);
    }

    int sumOfLeftLeaves(TreeNode *root) {
        if (isLeaf(root))
            return 0;

        int ans = 0;
        findSum(root, ans);
        return ans;
    }
};