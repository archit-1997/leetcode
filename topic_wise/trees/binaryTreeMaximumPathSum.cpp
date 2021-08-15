/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : binaryTreeMaximumPathSum.cpp
 * @created     : Sunday Aug 15, 2021 20:05:30 IST
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
    
    int findMaxSum(TreeNode* root,int &ans){
        if(root==NULL)
            return 0;
        
        int leftSum=findMaxSum(root->left,ans);
        int rightSum=findMaxSum(root->right,ans);

        //update the value of answer for a particular node
        int leftPath=leftSum+root->val;
        int rightPath=rightSum+root->val;
        
        //find the max value of the chain
        int sum=max(root->val,max(leftPath,rightPath));

        //updating the answer variable
        ans=max(ans,max(sum,root->val+leftSum+rightSum));

        return sum;
    }

    int maxPathSum(TreeNode* root) {
        if(isLeaf(root))
            return root->val;
    
        int ans=INT_MIN;
        findMaxSum(root,ans);
        return ans;
    }
};
