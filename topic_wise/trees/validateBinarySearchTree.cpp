/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : validateBinarySearchTree.cpp
 * @created     : Sunday Aug 15, 2021 18:26:59 IST
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
    void inorder(TreeNode *root,vector<int> &ans){
        if(root==NULL)
            return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }

    bool isValidBST(TreeNode* root) {
        vector<int> v;
        inorder(root,v);
        int n=v.size();
        for(int i=0;i<n-1;i++){
            if(v[i]>=v[i+1])
                return false;
        }
        return true;
    }
};
