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

    void inorder(TreeNode *root, vector<int> &ans) {
        if (root == NULL)
            return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }

    int getMinimumDifference(TreeNode *root) {
        vector<int> v;
        inorder(root, v);
        int ans = INT_MAX;
        for (int i = 0; i < v.size() - 1; i++)
            ans = min(ans, abs(v[i] - v[i + 1]));
        return ans;
    }
};//
// Created by Archit Singh on 19/06/21.
//

