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

    void findNode(TreeNode *root, TreeNode *subroot, bool &ans) {
        if (root == NULL)
            return;

        findNode(root->left, subroot, ans);
        if (root->val == subroot->val)
            ans |= areIdentical(root, subroot);
        if (ans)
            return;
        findNode(root->right, subroot, ans);
    }

    bool areIdentical(TreeNode *r1, TreeNode *r2) {
        if (r1 == NULL && r2 == NULL)
            return true;
        else if (r1 == NULL || r2 == NULL)
            return false;

        return (r1->val == r2->val && areIdentical(r1->left, r2->left) && areIdentical(r1->right, r2->right));
    }

    bool isSubtree(TreeNode *root, TreeNode *subRoot) {
        //find the nodes in the root with values same as root of subroot
        bool res = false;
        findNode(root, subRoot, res);
        return res;

    }
};//
// Created by Archit Singh on 21/06/21.
//

