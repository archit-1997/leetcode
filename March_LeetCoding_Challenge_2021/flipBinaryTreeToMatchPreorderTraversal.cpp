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
  vector<int> ans;
  int index;

  bool isMatching(TreeNode *root, vector<int> &voyage) {
    if (root == NULL)
      return true;
    if (root->val != voyage[index++])
      return false;
    if (root->left && root->left->val != voyage[index]) {
      ans.push_back(root->val);
      // pass in the right one and then the left one
      return isMatching(root->right, voyage) && isMatching(root->left, voyage);
    }
    // pass as the ususal order, left node and then the right node
    return isMatching(root->left, voyage) && isMatching(root->right, voyage);
  }
  vector<int> flipMatchVoyage(TreeNode *root, vector<int> &voyage) {
    index = 0;
    if (isMatching(root, voyage) == true)
      return ans;
    return vector<int>{-1};
  }
};