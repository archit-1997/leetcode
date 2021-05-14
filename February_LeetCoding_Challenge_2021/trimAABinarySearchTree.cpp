/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  TreeNode *trimBST(TreeNode *root, int low, int high) {

    if (root == NULL)
      return root;
    // we are going to the left because we don't want to include the part which
    // is greater than high
    if (root->val > high)
      return trimBST(root->left, low, high);
    // similarly going to the right because we don't want to include the part
    // which is smaller than low
    if (root->val < low)
      return trimBST(root->right, low, high);

    // recursively calling for both the childs
    root->left = trimBST(root->left, low, high);
    root->right = trimBST(root->right, low, high);
    return root;
  }
};
