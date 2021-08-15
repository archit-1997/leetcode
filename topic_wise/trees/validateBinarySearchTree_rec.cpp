/**
 * @author      : archit
 * @GitHub      : archit-1997
 * @Email       : architsingh456@gmail.com
 * @file        : validateBinarySearchTree_rec.cpp
 * @created     : Sunday Aug 15, 2021 18:57:59 IST
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isLeaf(TreeNode* root){
        return (root->left==NULL && root->right==NULL);
    }


    bool solve(TreeNode* root,long min,long max){
        if(root==NULL)
            return true;

        if(root->val<=min || root->val >= max)
            return false;
        
        return (solve(root->left,min,root->val) && solve(root->right,root->val,max));

    }

    bool isValidBST(TreeNode* root) {
        if(root==NULL || isLeaf(root))
            return true;
       return solve(root,LONG_MIN,LONG_MAX);
    }
};

