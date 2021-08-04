/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : pathSumII.cpp
 * @created     : Wednesday Aug 04, 2021 15:01:40 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isLeaf(TreeNode* root){
        return (root->left==NULL && root->right==NULL);
    }

    void findPaths(TreeNode* root,int sum,vector<int> &tmp,vector<vector<int>> &ans){
        if(root==NULL)
            return;

        tmp.push_back(root->val);
        sum-=root->val;
        //if sum=root->val and root is leaf node, then this is a valid path
        if(isLeaf(root) && sum==0){
            ans.push_back(tmp);
            tmp.pop_back();
            return;
        }

        //recur for the left and right part
        findPaths(root->left,sum,tmp,ans);
        findPaths(root->right,sum,tmp,ans);
        tmp.pop_back();

    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> tmp;

        findPaths(root,targetSum,tmp,ans);

        return ans;
    }
};

