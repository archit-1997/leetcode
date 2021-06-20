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

    void inorder(TreeNode *root, vector<int> &v) {
        if (root == NULL)
            return;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }

    bool findTarget(TreeNode *root, int k) {
        vector<int> v;
        inorder(root, v);
        unordered_map<int, int> map;

        for (int num : v)
            map[num]++;

        for (int num : v) {
            int rem = k - num;
            if (rem != num && map[rem] > 0)
                return true;
            else if (rem == num && map[rem] >= 2)
                return true;
        }
        return false;
    }
};//
// Created by Archit Singh on 19/06/21.
//

