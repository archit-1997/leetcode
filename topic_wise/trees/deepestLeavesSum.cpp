/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : deepestLeavesSum.cpp
 * @created     : Saturday Aug 07, 2021 07:15:33 IST
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
    int maxHeight(TreeNode* root){
        if(root==NULL)
            return 0;

        int l=maxHeight(root->left);
        int r=maxHeight(root->right);

        return 1+max(l,r);
    }

    bool isLeaf(TreeNode* root){
        return (root->left==NULL && root->right==NULL);
    }

    void findMaxLeavesSum(TreeNode* root,int &ans,int h,int maxHeight){
        if(root==NULL)
            return;

        if(h==maxHeight)
            ans+=root->val;

        findMaxLeavesSum(root->left,ans,h+1,maxHeight);
        findMaxLeavesSum(root->right,ans,h+1,maxHeight);

    }

    int deepestLeavesSum(TreeNode* root) {
        if(root==NULL)
            return 0;

        if(isLeaf(root))
            return root->val;

        TreeNode* tmp=root;
        //find the max height of the binary tree
        int h=maxHeight(tmp);

        int ans=0;
        findMaxLeavesSum(root,ans,1,h);

        return ans;
    }
};
