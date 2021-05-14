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
  void inorder(TreeNode *root, vector<int> &ans) {
    if (root == NULL)
      return;
    inorder(root->left, ans);
    ans.push_back(root->val);
    inorder(root->right, ans);
  }
  int index, n;
  void assign_inorder(TreeNode *root, vector<int> &ans) {
    if (root == NULL)
      return;
    assign_inorder(root->left, ans);
    root->val = ans[index++];
    assign_inorder(root->right, ans);
  }

  TreeNode *convertBST(TreeNode *root) {

    if (root == NULL)
      return root;

    vector<int> ans;

    // do inorder traversal of bst and then store the values
    TreeNode *rep = root;
    inorder(rep, ans);

    // ans holds the inorder traversal
    index = 0;
    n = ans.size();

    int sum = ans[n - 1];
    for (int i = n - 2; i >= 0; i--)
      ans[i] += ans[i + 1];

    // now do inorder traversal of the three and assign the values

    rep = root;
    assign_inorder(rep, ans);

    vector<int> res;

    // do the preoder traversal of the tree and return the answer

    return root;
  }
};
