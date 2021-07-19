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

    int findTiltSum(TreeNode *root, int &ans) {
        if (root == NULL)
            return 0;

        int leftSum = findTiltSum(root->left, ans);
        int rightSum = findTiltSum(root->right, ans);

        int tilt = abs(leftSum - rightSum);
        ans += tilt;
        return leftSum + root->val + rightSum;
    }

    int findTilt(TreeNode *root) {
        if (root == NULL)
            return 0;

        int ans = 0;
        findTiltSum(root, ans);
        return ans;


    }
};