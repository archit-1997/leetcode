/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : countGoodNodesInBinaryTree.cpp
 * @created     : Tuesday Aug 17, 2021 19:21:21 IST
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

    void countGoodNodes(TreeNode* root,int &ans,int msf){
        if(root==NULL)
            return;

        if(root->val>=msf)
            ans++;

        countGoodNodes(root->left,ans,max(msf,root->val));
        countGoodNodes(root->right,ans,max(msf,root->val));
    }

    int goodNodes(TreeNode* root) {
        int ans=0;
        countGoodNodes(root,ans,INT_MIN);
        return ans;
    }
};
