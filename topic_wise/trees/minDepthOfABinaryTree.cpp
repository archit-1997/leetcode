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

    void findDepth(TreeNode *root, int &ans, int count) {
        if (root == NULL)
            return;

        if (isLeaf(root)) {
            ans = min(ans, count + 1);
            return;
        }

        findDepth(root->left, ans, count + 1);
        findDepth(root->right, ans, count + 1);

    }

    int minDepth(TreeNode *root) {
        if (!root)
            return 0;

        int ans = INT_MAX, count = 0;
        findDepth(root, ans, count);
        return ans;
    }
};