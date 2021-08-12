/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : sumOfLeftLeaves.cpp
 * @created     : Thursday Aug 12, 2021 22:26:54 IST
 */

#include <bits/stdc++.h>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:

    bool isLeaf(TreeNode* root){
        return (root->left==NULL && root->right==NULL);
    }


    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL)
            return 0;

        int ans=0;
        if(root->left){
            if(isLeaf(root->left))
                ans+=root->left->val;
            else
                ans+=sumOfLeftLeaves(root->left);
        }
        ans+=sumOfLeftLeaves(root->right);

        return ans;
    }
};
