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
        if (root->left == NULL && root->right == NULL)
            return true;
        return false;
    }

    void findPaths(TreeNode *root, vector<int> &res, vector <vector<int>> &paths) {
        if (root == NULL)
            return;
        res.push_back(root->val);
        if (isLeaf(root)) {
            paths.push_back(res);
            res.pop_back();
            return;
        }
        if (root->left)
            findPaths(root->left, res, paths);
        if (root->right)
            findPaths(root->right, res, paths);
        res.pop_back();
    }

    int toDecimal(vector<int> &binary) {
        reverse(binary.begin(), binary.end());
        int ans = 0;
        for (int i = 0; i < binary.size(); i++) {
            if (binary[i])
                ans += pow(2, i);
        }

        return ans;
    }

    int sumRootToLeaf(TreeNode *root) {
        vector <vector<int>> paths;
        vector<int> res;
        findPaths(root, res, paths);

        int ans = 0;
        for (vector<int> path : paths) {
            ans += toDecimal(path);
        }
        return ans;
    }
};