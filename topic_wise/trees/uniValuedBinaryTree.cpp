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

    bool isUnivalTree(TreeNode *root) {
        if (root == NULL || isLeaf(root))
            return true;

        if (isUnivalTree(root->left) && isUnivalTree(root->right)) {
            int val = root->val;
            int leftVal = val, rightVal = val;
            if (root->left)
                leftVal = root->left->val;
            if (root->right)
                rightVal = root->right->val;
            return (val == leftVal && val == rightVal);
        }

        return false;

    }
};//
// Created by Archit Singh on 19/06/21.
//

