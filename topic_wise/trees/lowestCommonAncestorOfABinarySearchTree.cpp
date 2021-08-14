/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : lowestCommonAncestorOfABinarySearchTree.cpp
 * @created     : Saturday Aug 14, 2021 19:52:44 IST
 */

#include <bits/stdc++.h>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val > root->val && q->val > root->val)
            return  lowestCommonAncestor(root->right,p,q);
        else if(p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left,p,q);
        else
            return root;
    }
};
