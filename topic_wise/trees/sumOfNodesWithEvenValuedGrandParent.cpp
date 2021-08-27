/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : sumOfNodesWithEvenValuedGrandParent.cpp
 * @created     : Friday Aug 27, 2021 12:35:49 IST
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
    
    void findSum(TreeNode* root,vector<int> &path,int &ans){
        if(root==NULL)
            return;

        //we push the curr node into the path
        path.push_back(root->val);

        //we find if it has a grandparent which is even
        int n=path.size();
        if(n>=3){
            int parent=path[n-3];
            if(parent%2==0)
                ans+=root->val;
        }

        findSum(root->left,path,ans);
        findSum(root->right,path,ans);

        path.pop_back();
    }

    int sumEvenGrandparent(TreeNode* root) {
        int ans=0;
        //we will find the root to leaf path for all the nodes and extract the desired value
        vector<int> path;
        findSum(root,path,ans);

        return ans;
    }
};
