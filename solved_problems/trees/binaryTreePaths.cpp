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

    void findPaths(TreeNode *root, vector <vector<int>> &paths, vector<int> &res) {
        if (root == NULL)
            return;

        res.push_back(root->val);

        if (isLeaf(root)) {
            paths.push_back(res);
            res.pop_back();
            return;
        }

        findPaths(root->left, paths, res);
        findPaths(root->right, paths, res);

        res.pop_back();

    }

    vector <string> binaryTreePaths(TreeNode *root) {
        vector <vector<int>> paths;
        vector<int> res;
        findPaths(root, paths, res);

        vector <string> ans;

        for (vector<int> path : paths) {
            string res = "";
            for (int i = 0; i < path.size(); i++) {
                res = res + to_string(path[i]);
                if (i != (path.size() - 1))
                    res = res + "->";
            }
            ans.push_back(res);
        }

        return ans;
    }
};