/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : totalSumIV_InputIsABST.cpp
 * @created     : Monday Aug 23, 2021 16:38:43 IST
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

    void inorder(TreeNode* root,unordered_map<int,int> &count,int k,bool& ans){
        if(root==NULL)
            return;

        inorder(root->left,count,k,ans);
        int sum=root->val,rem=k-sum;
        if(count.find(rem)!=count.end()){
            ans=true;
            return;
        }
        //else we can just push this element on the map
        count[sum]=1;
        inorder(root->right,count,k,ans);
    }

    bool findTarget(TreeNode* root, int k) {
        unordered_map<int,int> count;
        bool ans=false;

        inorder(root,count,k,ans);
        
        return ans;
    }
};
