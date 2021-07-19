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

    void inorder(TreeNode *root, unordered_map<int, int> &nodes) {
        if (root == NULL)
            return;
        inorder(root->left, nodes);
        nodes[root->val]++;
        inorder(root->right, nodes);
    }

    vector<int> findMode(TreeNode *root) {
        unordered_map<int, int> nodes;
        inorder(root, nodes);

        int maxCount = INT_MIN;
        for (auto it = nodes.begin(); it != nodes.end(); it++)
            maxCount = max(maxCount, it->second);

        vector<int> ans;

        for (auto it = nodes.begin(); it != nodes.end(); it++) {
            if (it->second == maxCount)
                ans.push_back(it->first);
        }

        return ans;
    }
};//
// Created by Archit Singh on 21/06/21.
//

